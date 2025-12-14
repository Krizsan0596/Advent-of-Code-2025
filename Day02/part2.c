#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

bool is_invalid(uint64_t num) {
    char buf[11];
    snprintf(buf, sizeof(buf), "%lu", num);
    int len = strlen(buf);
    for (int sublen = 1; sublen < len/2 + 1; sublen++) {
        if (len % sublen != 0) continue;
        bool match = true;
        for (int i = 0; i < len; i++) {
            if (buf[i] != buf[i % sublen]) match = false;
        }
        if (match) return true;
    }
    return false;
}

int main(void) {
    FILE *f = fopen("input", "r");
    if (f == NULL) {
        printf("Failed to open input file.");
        return 1;
    }
    struct stat st;
    stat("input", &st);
    char *input = malloc(st.st_size + 1);
    char *current = input;
    fscanf(f, "%s", input);
    uint64_t counter = 0;
    char *sep = NULL;
    while (1) {
        sep = strchr(current, ',');
        if (sep == NULL) sep = input + strlen(input);
        char *buffer = malloc(sep - current + 1);
        strncpy(buffer, current, sep - current);
        buffer[sep - current] = '\0';
        uint64_t start;
        uint64_t end;
        sscanf(buffer, "%lu-%lu", &start, &end);
        for (uint64_t i = start; i < end + 1; i++) {
            if (is_invalid(i)) counter += i;
        }
        free(buffer);
        if (sep == input + strlen(input)) break;
        current = sep + 1;
    }
    free(input);
    fclose(f);
    printf("The answer is: %lu.", counter);
}
