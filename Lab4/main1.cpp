#include <stdio.h>
#include "inputUtils.h"

int main(){
    int n;

    printf("Введите размер массива: ");
    n = getInt();

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("%d/%d Введите число: ", i, n);
        arr[i] = getInt();
    }

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max = 0, min = arr[0], sum = 0, mul = 1;

    for (int i = 0; i < n; i++)
    {
        if(max < arr[i])
            max = arr[i];

        if(min > arr[i])
            min = arr[i];

        sum += arr[i];
        mul *= arr[i];    
    }

    int tmp;
    tmp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = tmp;

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Sum: %d\n", sum);
    printf("Mul: %d\n", mul);

    printf("Переставленный массив:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}