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

	// placeholder; won't compile otherwise
	var cal_valuesSum int

	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		//fmt.Println(scanner.Text())
		var line = scanner.Text()

		// Print test that index functions work as expected
		//fmt.Println(strings.IndexAny(line, cal_values), strings.LastIndexAny(line, cal_values))

		// pull out first number from line; result is byte number val
		var first_AsciiDigit = line[strings.IndexAny(line, cal_values)]

		// pull out last number from line; result is byte number val
		var last_AsciiDigit = line[strings.LastIndexAny(line, cal_values)]

		// test print that it works; it does :-)
		//fmt.Println(first_AsciiDigit, last_AsciiDigit)

		// Use Atio or ParseInt to convert to integers and sum
		// https://gobyexample.com/number-parsing
		var first_Digit = string(first_AsciiDigit)

		var last_Digit = string(last_AsciiDigit)

		var cal_ValueString = first_Digit + last_Digit

		cal_Value, _ := strconv.Atoi(cal_ValueString)

		//fmt.Println(first_Digit, last_Digit)

		cal_valuesSum = cal_valuesSum + cal_Value

	}

	fmt.Println("final value is:", cal_valuesSum)

	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}
}
