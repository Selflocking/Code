# only 12 red cubes, 13 green cubes, and 14 blue cubes


red_limit = 12
green_limit = 13
blue_limit = 14


def check(blue_cnt: int, red_cnt: int, green_cnt: int):
    if blue_cnt > blue_limit:
        return False
    if red_cnt > red_limit:
        return False
    if green_cnt > green_limit:
        return False
    return True


# file = "example.txt"
file = "input.txt"

count = 0
ans = 0
with open(file) as f:
    for line in f:
        count = count + 1
        # "Game 1: 3 blue, 4 red\n"
        if line[-1] == "\n":
            line = line[:-1]

        # "Game 1: 3 blue, 4 red"
        arr = line.split(":")

        id = int(arr[0][5:])
        # " 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"
        games = arr[1].split(";")
        res = True
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

            res = check(blue_cnt, red_cnt, green_cnt)
            if res == False:
                break

        if res == False:
            continue

        ans += id

print(ans)
