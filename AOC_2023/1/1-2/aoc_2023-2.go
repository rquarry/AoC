package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	var cal_values = "1234567890"

	// total cal values
	var cal_valuesSum, fileLineNum int

	var firstDigit, lastDigit string

	// create map of text and int values
	calVals := map[string]int{

		"one":   1,
		"two":   2,
		"three": 3,
		"four":  4,
		"five":  5,
		"six":   6,
		"seven": 7,
		"eight": 8,
		"nine":  9,
		"zero":  0,
	}

	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		//fmt.Println(scanner.Text())
		var line = scanner.Text()

		fileLineNum++

		// Print test that index functions work as expected
		//fmt.Println(strings.IndexAny(line, cal_values), strings.LastIndexAny(line, cal_values))

		// get index of first digit from line; result is int
		var first_AsciiDigitIndex = strings.IndexAny(line, cal_values)

		// set the initial value of the first digit
		firstDigit = string(line[first_AsciiDigitIndex])

		// get index of last digit from line; result is int
		var last_AsciiDigitIndex = strings.LastIndexAny(line, cal_values)

		// set the initial value of the last digit
		lastDigit = string(line[last_AsciiDigitIndex])

		// test print that it works; it does :-)
		//fmt.Println("initial digits for line ", fileLineNum, ":", firstDigit, lastDigit)

		for k, v := range calVals {

			// Look for first text word in line. returns -1 if not found, index of first char of string if found
			var lineStringNum = strings.Index(line, k)

			// More efficient loop?
			if lineStringNum == -1 {
				continue
			}

			// if the number has more than one instance, print a warning
			var numCount = strings.Count(line, k)

			// If there is a result found and it's closer to the start than the Ascii val in line 53
			if lineStringNum > -1 && lineStringNum < first_AsciiDigitIndex {
				// Use the integer value of the word the first digit
				firstDigit = strconv.Itoa(v)
				// update first_AsciiDigitIndex
				first_AsciiDigitIndex = lineStringNum
			}

			// If there is more than one number instance, get the last instance before checking end
			if numCount > 1 {
				lineStringNum = strings.LastIndex(line, k)
			}

			if lineStringNum > -1 && lineStringNum > last_AsciiDigitIndex {

				// make the word the last
				lastDigit = strconv.Itoa(v)
				// update last_AsciiDigitIndex
				last_AsciiDigitIndex = lineStringNum
			}

		}

		// test print that it works; it does :-)
		//fmt.Println("final digits for line ", fileLineNum, ":", firstDigit, lastDigit)

		// Use Atio to integers and sum
		// https://gobyexample.com/number-parsing
		var cal_ValueString = firstDigit + lastDigit

		cal_Value, _ := strconv.Atoi(cal_ValueString)

		fmt.Println("Cal value for line", fileLineNum, "is:", cal_Value)

		cal_valuesSum += cal_Value

	}

	fmt.Println("final value is:", cal_valuesSum)

	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}
}
