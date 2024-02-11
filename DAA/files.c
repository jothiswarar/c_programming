#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Generate random numbers
    int random_numbers[ARRAY_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        random_numbers[i] = rand() % 999999 + 1;
    }

    // Save random numbers to file
    FILE *file = fopen("random.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            fprintf(file, "%d\n", random_numbers[i]);
        }
        fclose(file);
    }

    // Sort numbers
    int sorted_numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sorted_numbers[i] = random_numbers[i];
    }
    qsort(sorted_numbers, ARRAY_SIZE, sizeof(int), compare);

    // Save sorted numbers to file
    file = fopen("sorted.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            fprintf(file, "%d\n", sorted_numbers[i]);
        }
        fclose(file);
    }

    // Introduce clumps
    int clumps_numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        clumps_numbers[i] = sorted_numbers[i];
    }

    for (int i = 0; i < 10; i++) {
        int clump_start = rand() % (ARRAY_SIZE - 100);
        int clump_end = clump_start + rand() % 51 + 50;

        for (int j = clump_start; j < clump_end; j++) {
            int temp = clumps_numbers[j];
            int random_index = clump_start + rand() % (clump_end - clump_start);
            clumps_numbers[j] = clumps_numbers[random_index];
            clumps_numbers[random_index] = temp;
        }
    }

    // Save clumped numbers to file
    file = fopen("clumps.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            fprintf(file, "%d\n", clumps_numbers[i]);
        }
        fclose(file);
    }

    // Sort numbers in reverse order
    int reverse_numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        reverse_numbers[i] = sorted_numbers[ARRAY_SIZE - i - 1];
    }

    // Save reverse sorted numbers to file
    file = fopen("reverse.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            fprintf(file, "%d\n", reverse_numbers[i]);
        }
        fclose(file);
    }

    printf("Files generated successfully.\n");

    return 0;
}
