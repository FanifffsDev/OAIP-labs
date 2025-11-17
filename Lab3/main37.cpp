#include <stdio.h>

int main(){
    int N;
    int s = 0;

    printf("Введите число N: ");
    if(scanf("%d", &N) != 1){
        printf("Введите именно число!");
        return -1;
    }

    
    while(N % 2 == 0){
        printf("*\n");
        N /= 2;
        s++;
    }

    for(int i = 3; i < N; i+= 2){
        while(N % i != 0){
            N /= i;
            s++;
        }
    }

    if(s != 1){
        printf("не простое");
    }
    else{
        printf("простое");
    }
    
    return 0;
}