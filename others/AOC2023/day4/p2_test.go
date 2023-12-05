package day4

import (
	"os"
	"strings"
	"testing"
)

func caclWinNum(winnum []int, mynum []int) int {
	var res int = 0

	for _, i := range mynum {
		for _, j := range winnum {
			if i == j {
				res++
				break
			}
		}
	}

	return res
}

func TestPart2(t *testing.T) {
	// file := "example.txt"
	file := "input.txt"

	content, err := os.ReadFile(file)
	if err != nil {
		t.Fatalf("Failed to read file")
	}
	contents := string(content)
	cards := strings.Split(contents, "\n")

	cardCnt := make([]int, len(cards))
	for i := range cardCnt {
		cardCnt[i] = 1
	}

	for i, card := range cards {
		t := strings.Split(card, ":")
		nums := strings.Split(t[1], "|")
		winnum := getNumbers(nums[0])
		mynum := getNumbers(nums[1])
		point := caclWinNum(winnum, mynum)
		for j := 1; j <= point; j++ {
			cardCnt[i+j] += cardCnt[i]
		}
	}

	var ans int = 0
	for _, v := range cardCnt {
		ans += v
	}

	println("Answer: ", ans)
}
