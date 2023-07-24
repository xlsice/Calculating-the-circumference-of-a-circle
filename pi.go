package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"strings"
	"time"
)

func main() {
	var numberOfPoints int
	var numberOfInCircle int

	rand.Seed(time.Now().UnixNano())

	for {
		fmt.Print("请输入随机点的数量（输入'exit'退出）: ")
		var input string
		fmt.Scan(&input)

		if strings.ToLower(input) == "exit" {
			break
		}

		var err error
		numberOfPoints, err = strconv.Atoi(input)
		if err != nil {
			fmt.Println("输入错误，请输入一个整数。")
			continue
		}

		for i := 0; i < numberOfPoints; i++ {
			x := rand.Float64()
			y := rand.Float64()
			distance := math.Sqrt(x*x + y*y)

			if distance <= 1.0 {
				numberOfInCircle++
			}
		}

		piEstimate := 4.0 * float64(numberOfInCircle) / float64(numberOfPoints)
		fmt.Printf("Estimated value of Pi: %f\n", piEstimate)
	}
}
