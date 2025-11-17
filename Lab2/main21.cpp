#include <stdio.h>

int main(){
    int number;

    printf("Введите число: ");
  
    if(scanf("%d", &number) != 1){
        printf("Введите именно число!");
        return -1;
    }

    int a, b, c;

    a = number / 100; 
    b = (number - a * 100) / 10;
    c = number - a * 100 - b * 10;

    const char *answer;

    answer = (b - a == c - b) ? "образуют" : "не образуют";

    printf("%s\n", answer);
    return 0;
}