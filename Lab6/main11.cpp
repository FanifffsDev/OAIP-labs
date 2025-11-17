#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "../inputUtils.h"

int main() {
    int n;
    
    std::cout << "Enter the amount of elements in the array: " << std::endl;
    n = getInt();

    float *array = (float*)malloc(n * sizeof(float));
    if (array == NULL) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Enter the " << i << "/" << n << " element" << std::endl;
        array[i] = getInt();
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (fabs(array[i]) > fabs(array[maxIndex])) {
            maxIndex = i;
        }
    }

    double sum = 0;
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (index) {
            sum += array[i];
        }
        if (!index && array[i] > 0) {
            index = 1; 
        }
    }

    std::cout << "Index of the maximum absolute value element: " << maxIndex << std::endl;
    std::cout << "Sum of elements after the first positive element: " << sum << std::endl;

    free(array);

    return 0;
}