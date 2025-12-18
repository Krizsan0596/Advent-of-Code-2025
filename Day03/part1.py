with open("input", "r") as f:
    counter = 0
    for line in f:
        upper_max = 0
        lower_max = 0
        for index in range(100):
            digit = int(line[index])
            if digit > upper_max:
                if index + 1 < 100:
                    upper_max = digit
                    lower_max = 0
                else:
                    lower_max = digit
            elif digit > lower_max:
                lower_max = digit
        counter += 10 * upper_max + lower_max
    print(f"The answer is: {counter}.")
