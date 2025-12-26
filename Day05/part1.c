#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("input", "r");
    if (f == NULL) return 1;
    uint64_t ranges[190][2] = {0};
    char buffer[100];
    int i = 0;
    while (i < 190) {
        fgets(buffer, 100, f);
        sscanf(buffer, "%lu-%lu", &ranges[i][0], &ranges[i][1]);
        i++;
    }
    fgets(buffer, 100, f);
    int counter = 0;
    while (fgets(buffer, 100, f) != NULL) {
        uint64_t num = strtoull(buffer, NULL, 10);
        for (int j = 0; j < 190; j++) {
            if (ranges[j][0] < num && num < ranges[j][1]) {
                counter++;
                break;
            }
        }
    }
    printf("The answer is: %d.", counter);
    return 0;
}
