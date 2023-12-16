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

	file, err := os.Open("input")
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {

		gameColors := map[string]int{
			"red":   0,
			"green": 0,
			"blue":  0,
		}

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

			//fmt.Println("GameSet:", gameSet)

			// j = each color bag in one game (there are 1-3 in each game)
			for j := 0; j < len(gameSet); j++ {

				var bag = strings.Split(gameSet[j], " ")

				// I'm sure there is a much better way than using hard coded array index here but it works....
				// get the number of blocks taken from the bag
				var numBlocks, _ = strconv.Atoi(bag[1])
				// get the block color
				var blockColor = bag[2]

				var colorNumberCubes = gameColors[blockColor]

				if numBlocks > colorNumberCubes {
					gameColors[blockColor] = numBlocks
				}
			}

		}

		gameSum += (gameColors["red"] * gameColors["blue"] * gameColors["green"])

		// prep for next loop iteration
		gameNumber++

	} // Done loading file
	fmt.Println("Game ID sum is: ", gameSum)
}
