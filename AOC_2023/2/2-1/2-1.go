package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	var gameSum int
	var gameNumber = 1
	var gamePossible = true

	file, err := os.Open("input")
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {

		//fmt.Println(scanner.Text())
		var line = scanner.Text()

		// split off the game number from front, we want game[1] moving fwd
		var game = strings.Split(line, ":")

		// break each game into individual sets of 1-3 bag color results
		var rawGameSets = strings.Split(game[1], ";")

		// loop through each game set and split the results into an array (gameSet) of individual colors
		// and numbers (e.g. gameSet[0] = "12 blue")
		for i := 0; i < len(rawGameSets); i++ {

			gameSet := strings.Split(rawGameSets[i], ",")

			fmt.Println("GameSet:", gameSet)

			// j = each color bag in one game (there are 1-3 in each game)
			for j := 0; j < len(gameSet); j++ {

				var bag = strings.Split(gameSet[j], " ")

				// I'm sure there is a much better way than using hard coded array index here but it works....
				// get the number of blocks taken from the bag
				var numBlocks, _ = strconv.Atoi(bag[1])
				// get the block color
				var blockColor = bag[2]

				// if the number is less than 12, the game is still "possible" and continue on
				if numBlocks > 11 {

					if blockColor == "red" && numBlocks > 12 {
						gamePossible = false
					}
					if blockColor == "green" && numBlocks > 13 {
						gamePossible = false
					}
					if blockColor == "blue" && numBlocks > 14 {
						gamePossible = false
					}
				}
			}

		}

		if gamePossible {
			gameSum += gameNumber
		}
		// prep for next loop iteration
		gameNumber++
		gamePossible = true

	} // Done loading file
	fmt.Println("Game ID sum is: ", gameSum)
}
