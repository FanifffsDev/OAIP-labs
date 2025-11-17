#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inputUtils.h"

int main(){
    int n;

    printf("Введите размер массива (n): ");
    n = getInt();

    int arr[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = -10 + rand()%20;
    }

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int min = 0, minIndex = 0, sum = 0, mul = 1;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            mul *= arr[i];

        if(min > arr[i]){
            min = arr[i];
            minIndex = i;
        }
    }

    for (int i = 0; i < minIndex; i++)
    {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);
    printf("Mul: %d\n", mul);

    return 0;
}