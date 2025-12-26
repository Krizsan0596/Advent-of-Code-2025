with open("input", "r") as f:
    ranges = [[0] * 2] * 190
    lines = f.readlines()
    for index in range(189):
        ranges[index] = list(map(int, lines[index].split("-")))
    counter = 0
    for index in range(191, len(lines)):
        for i in range(len(ranges)):
            if int(lines[index][:-1]) in range(ranges[i][0] + 1, ranges[i][1]):
                counter += 1
                break
    print(f"The answer is: {counter}.")
