#include <stdio.h>
#include <math.h>

int main(){
    float r, x, y;

    printf("Введите r: ");
    if(scanf("%f", &r) != 1){
        printf("Введите именно число!");
        return -1;
    }

    printf("Введите x: ");
    if(scanf("%f", &x) != 1){
        printf("Введите именно число!");
        return -1;
    }

    printf("Введите y: ");
    if(scanf("%f", &y) != 1){
        printf("Введите именно число!");
        return -1;
    }

    float res;

    x = fabs(x);

    if(y < 0){
        float tmpR = sqrt(x * x + y * y);
         
        res = fabs(r - tmpR);

        res = res > fabs(y) ? fabs(y) : res;
    }
    else if(y == 0){
        res = fabs(r - x);
    }
    else{
        res = y;

        float tmpR = sqrt(pow(fabs(x - r), fabs(x - r)) + y * y);
        res = fabs(x) > r ? tmpR : res;
    }

    printf("Расстояние: %f\n", res);
    return 0;
}