counter = 0
with open("input", "r") as f:
    current_position = 50
    for line in f:
        dir = line[0]
        dist = int(line[1:])
        if dir == "R":
            current_position += dist
        else:
            current_position -= dist
        current_position = current_position % 100
        if current_position == 0:
            counter += 1
print(f"The password is {counter}.")
