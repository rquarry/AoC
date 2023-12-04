package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	var cal_values = "1234567890"

	// placeholder; won't compile otherwise
	//var cal_valuesSum int

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

		// pull out first number from line; result is ascii number val
		var first_AsciiDigit = line[strings.IndexAny(line, cal_values)]

		// pull out last number from line; result is ascii number val
		var last_AsciiDigit = line[strings.LastIndexAny(line, cal_values)]

		// test print that it work; it does :-)
		fmt.Println(first_AsciiDigit, last_AsciiDigit)

		// Use Atio or ParseInt to convert to integers and sum
		// https://gobyexample.com/number-parsing

	}

	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}
}
