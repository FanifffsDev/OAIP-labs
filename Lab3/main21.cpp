#include <stdio.h>
#include <iostream>
#include "main21.h"

int main(){
    int n;

    printf("Введите число: ");
    n = getIntValue();

    printf("\nВсе простые делители числа %d: ", n);

    while(n % 2 == 0){
        printf("2 ");
        n /= 2;
    }

    for (int i = 3; i <= n; i += 2)
    {
        while(n % i == 0){
            printf("%d ", i);
            n /= i;
        }      
    }
    
    printf("\n");

    return 0;
}