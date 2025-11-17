#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inputUtils.h"
#include <iostream>
#include <math.h>
#define ARR_SIZE 25

int main(){
    int arr[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d/%d Введите число: ", i, ARR_SIZE);

        arr[i] = getInt();
    }

    printf("Исходный массив:\n");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if(abs(arr[i]) % 2 == 1 && arr[i]<0)
            sum += arr[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}