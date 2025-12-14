with open("input", "r") as f:
    input = f.read()
    ranges = input.split(",")
    counter = 0
    for item in ranges:
        start, end = item.split("-")
        for num in range(int(start), int(end) + 1):
            string = str(num)
            for sublen in range(1, len(string) // 2 + 1):
                if len(string) % sublen != 0:
                    continue
                match = True
                for i in range(len(string)):
                    if string[i] != string[i % sublen]:
                        match = False
                if match:
                    counter += num
                    break
    print(f"The answer is {counter}.")
