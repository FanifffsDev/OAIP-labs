#include <iostream>
#include <stdlib.h>
#include "../inputUtils.h"

#define MAX_VALUE 1000

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: " << std::endl;
    rows = getInt();
    std::cout << "Enter the number of columns: " << std::endl;
    cols = getInt();

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter the " << i << "/" << j << " element" << std::endl;
            matrix[i][j] = getIntInRange(0, 1000);
        }
    }

    int *count = (int *)calloc(MAX_VALUE + 1, sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = matrix[i][j];
            if (value <= MAX_VALUE) {
                count[value]++;
            }
        }
    }

    int maxDuplicate = -1;
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (count[i] > 1 && i > maxDuplicate) {
            maxDuplicate = i;
        }
    }

    if (maxDuplicate == -1) {
        std::cout << "No numbers more than once.\n";
    } else {
        std::cout << "The maximum number that appears more than once is: " << maxDuplicate << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(count);

    return 0;
}