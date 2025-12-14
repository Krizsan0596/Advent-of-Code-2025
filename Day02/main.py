with open("input", "r") as f:
    input = f.read()
    ranges = input.split(",")
    counter = 0
    for item in ranges:
        start, end = item.split("-")
        for num in range(int(start), int(end)):
            string = str(num)
            if len(string) % 2 != 0:
                continue
            mid = len(string) // 2
            first_half = string[:mid]
            second_half = string[mid:]
            if first_half == second_half:
                counter += num
    print(f"The answer is {counter}.")
