with open("input", "r") as f:
    lines = ["" for _ in range(137)]
    for index, line in enumerate(f):
        lines[index] = line
    counter = 0
    while True:
        current_round = 0
        for i in range(137):
            for j in range(137):
                surrounding = 0
                if lines[i][j] != "@":
                    continue
                if i != 0:
                    if j != 0:
                        if lines[i - 1][j - 1] == "@":
                            surrounding += 1
                    if j != 136:
                        if lines[i - 1][j + 1] == "@":
                            surrounding += 1
                    if lines[i - 1][j] == "@":
                        surrounding += 1
                if i != 136:
                    if j != 0:
                        if lines[i + 1][j - 1] == "@":
                            surrounding += 1
                    if j != 136:
                        if lines[i + 1][j + 1] == "@":
                            surrounding += 1
                    if lines[i + 1][j] == "@":
                        surrounding += 1
                if j != 0:
                    if lines[i][j - 1] == "@":
                        surrounding += 1
                if j != 136:
                    if lines[i][j + 1] == "@":
                        surrounding += 1
                if surrounding < 4:
                    current_round += 1
                    new_line = lines[i][:j] + "x" + lines[i][j + 1:]
                    lines[i] = new_line
        counter += current_round
        if current_round == 0:
            break
    print(f"The answer is: {counter}.")
