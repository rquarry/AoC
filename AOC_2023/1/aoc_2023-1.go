package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	var cal_values = "1234567890"

	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		//fmt.Println(scanner.Text())
		var line = scanner.Text()
		fmt.Println(strings.IndexAny(line, cal_values), strings.LastIndexAny(line, cal_values))
	}

	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}
}
