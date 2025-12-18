#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t process_line(char *line) {
    int i = 0;
    char digits[13] = {0};
    while (100 > i) {
        int start = 12 - (100 - i);
        if (start < 0) start = 0;
        for (int j = start; j < 12; j++) {
            if (line[i] > digits[j]) {
                digits[j] = line[i];
                j++;
                while (j < 12) {
                    digits[j] = '0';
                    j++;
                }
                break;
            }
        }
        i++;
    }
    return strtoull(digits, NULL, 10);
}

int main(void) {
    FILE *f = fopen("input", "r");
    if (f == NULL) return 1;
    char buffer[102];
    uint64_t counter = 0;
    while (fgets(buffer, 102, f) != NULL) {
        counter += process_line(buffer);
    }
    printf("The answer is: %lu.", counter);
    fclose(f);
    return 0;
}
