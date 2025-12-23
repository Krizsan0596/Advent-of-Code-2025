#include <stdbool.h>
#include <stdio.h>

int main(void) {
    char input[137][139];  // +2 for \n\0
    FILE *f = fopen("input", "r");
    if (f == NULL) return 1;
    int i = 0;
    while (fgets(input[i], 139, f) != NULL) {
        i++;
    }
    int counter = 0;
    while (true) {
        int current_round = 0;
        for (int j = 0; j < 137; j++) {
            for (int k = 0; k < 137; k++) {
                if (input[j][k] != '@') continue;
                int surrounding = 0;
                if (k != 0) if (input[j][k - 1] == '@') surrounding++;
                if (k != 136) if (input[j][k + 1] == '@') surrounding++;
                if (j != 0) if (input[j - 1][k] == '@') surrounding++;
                if (j != 136) if (input[j + 1][k] == '@') surrounding++;
                if (j != 0 && k != 0) if (input[j - 1][k - 1] == '@') surrounding++;
                if (j != 136 && k != 0) if (input[j + 1][k - 1] == '@') surrounding++;
                if (j != 0 && k != 136) if (input[j - 1][k + 1] == '@') surrounding++;
                if (j != 136 && k != 136) if (input[j + 1][k + 1] == '@') surrounding++;
                if (surrounding < 4) {
                    input[j][k] = 'x';
                    current_round++;
                }
            }
        }
        counter += current_round;
        if (current_round == 0) break;
    }
    printf("The answer is: %d.\n", counter);
    return 0;
}
