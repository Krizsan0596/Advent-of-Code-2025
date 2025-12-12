#include <stdio.h>

#define FILE_LEN 4493
#define DIAL_SIZE 100
#define mod(a, m) (((a % m) + m) % m) // Mathematical modulus operation using remainders

int main(void) {
    FILE *f = fopen("input", "r");
    if (f == NULL) {
        printf("Failed to open file.");
        return 1;
    }
    int current_line = 0;
    int current_position = 50;
    int counter = 0;
    while (current_line < FILE_LEN + 1) {
        char dir;
        int dist;
        fscanf(f, " %c%d", &dir, &dist);
        if (dir == 'R') current_position += dist;
        else current_position -= dist;
        current_position = mod(current_position, DIAL_SIZE);
        if (current_position == 0) counter++;
        current_line++;
    }
    fclose(f);
    printf("%d lines processed. Password is %d", current_line - 1, counter);
    return 0;
}
