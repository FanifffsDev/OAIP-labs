#include <stdio.h>

int main(){
    float m, n;

    printf("Введите числа m и n, m < n: ");
    
    if(scanf("%f %f", &m, &n) != 1){
        printf("Введите именно число!");
        return -1;
    }

    if(m >= n || m <= 0 || n <= 0){
        printf("Условие задачи нарушено!");
        return -1;
    }

    float S = 0, F = 1, A = 0, B = 1, Y = 0, X = 0, S2 = 0;

    //S
    for (int i = 0; i <= n; i++)
    {
        S += i;
    }

    //F
    for (int i = 1; i <= n; i++)
    {
        F *= i;
    }

    //A
    for (int i = 0; i <= n; i++)
    {
        A += m + i;
    }

    //B
    for (int i = 0; i <= n; i++)
    {
        B *= m + i;
    }

    //Y
    for (float i = 1; i <= n; i++)
    {
        Y += 1 / i;
    }

     //X
    for (float i = 0; i <= n; i++)
    {
        X += 1 / (m + i);
    }

     //S2
    for (int i = 1; i <= n; i++)
    {
        float tmp = 1;
        for (int j = 1; j <= i; j++)
        {
           tmp *= j;
        }
        S2 += tmp;
    } 

    printf("S: %.1f\n", S);
    printf("F: %.1f\n", F);
    printf("A: %.1f\n", A);   
    printf("B: %.1f\n", B);
    printf("Y: %.1f\n", Y);
    printf("X: %.1f\n", X);
    printf("S1: %.1f\n", S2);

    return 0;
}