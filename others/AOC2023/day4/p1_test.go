package day4

import (
	"math"
	"os"
	"strconv"
	"strings"
	"testing"
)

func getNumbers(s string) (res []int) {
	nums := strings.Split(s, " ")

	for _, v := range nums {
		if v == "" {
			continue
		}
		value, err := strconv.Atoi(v)
		if err == nil {
			res = append(res, value)
		}
	}
	return
}

func caclPoint(winnum []int, mynum []int) int {
	var res int = 0

	for _, i := range mynum {
		for _, j := range winnum {
			if i == j {
				res++
				break
			}
		}
	}

	return int(math.Pow(2, float64(res)-1))
}

func TestPart1(t *testing.T) {
	// file := "example.txt"
	file := "input.txt"

	content, err := os.ReadFile(file)
	if err != nil {
		t.Fatalf("Failed to read file")
	}
	contents := string(content)
	cards := strings.Split(contents, "\n")
	var ans int = 0

	for _, card := range cards {
		t := strings.Split(card, ":")
		nums := strings.Split(t[1], "|")
		winnum := getNumbers(nums[0])
		mynum := getNumbers(nums[1])
		ans += caclPoint(winnum, mynum)
	}

	println("Answer: ", ans)
}
