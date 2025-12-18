#include <stdio.h>
#include <stdlib.h>

int process_line(char *line) {
    int bigger_max = 0;
    int smaller_max = 0;
    for (int i = 0; i < 100; i++) {
        if (line[i] - '0' > bigger_max) {
            if (i + 1 < 100) {
                smaller_max = 0;
                bigger_max = line[i] - '0';
            }
            else {
                smaller_max = line[i] - '0';
            }
        }
        else if (line[i] - '0' > smaller_max) smaller_max = line[i] - '0';
    }
    return 10 * bigger_max + smaller_max;
}

int main(void) {
    FILE *f = fopen("input", "r");
    if (f == NULL) return 1;
    char buffer[102];
    int counter = 0;
    while (fgets(buffer, 102, f) != NULL) {
        counter += process_line(buffer);
    }
    printf("The answer is: %d.", counter);
    fclose(f);
    return 0;
}
