# only 12 red cubes, 13 green cubes, and 14 blue cubes


# file = "example.txt"
file = "input.txt"

ans = 0
with open(file) as f:
    for line in f:
        # "Game 1: 3 blue, 4 red\n"
        if line[-1] == "\n":
            line = line[:-1]

        # "Game 1: 3 blue, 4 red"
        arr = line.split(":")

        id = int(arr[0][5:])
        # " 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"
        games = arr[1].split(";")

        # 记录每种颜色的数量
        red_limit = 0
        green_limit = 0
        blue_limit = 0

        for game in games:
            blue_cnt = 0
            red_cnt = 0
            green_cnt = 0
            # " 3 blue, 4 red"
            items = game.split(",")
            for item in items:
                # " 3 blue"
                detail = item.split(" ")
                num = int(detail[1])
                match detail[2]:
                    case "blue":
                        blue_cnt += num
                    case "red":
                        red_cnt += num
                    case "green":
                        green_cnt += num
                    case _ as e:
                        print(f"error: {e}")

            blue_limit = max(blue_limit, blue_cnt)
            red_limit = max(red_limit, red_cnt)
            green_limit = max(green_limit, green_cnt)

        ans += red_limit * green_limit * blue_limit

print(ans)
