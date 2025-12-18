with open("input", "r") as f:
    counter = 0
    for line in f:
        digits = [0] * 12
        for index in range(100):
            digit = int(line[index])
            for out_index in range(max([0, 12 - (100 - index)]),len(digits)):
                if digit > digits[out_index]:
                    digits[out_index] = digit
                    for old_digit in range(out_index + 1, len(digits)):
                        digits[old_digit] = 0
                    break
        counter += int("".join(map(str, digits)))
    print(f"The answer is: {counter}.")
