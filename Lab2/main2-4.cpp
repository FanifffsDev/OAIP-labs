#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(0, "");

    int season;

    printf("Введите номер поры года: \n");
    printf("1 - лето. \n");
    printf("2 - осень. \n");
    printf("3 - зима. \n");
    printf("4 - весна.\n ");

    scanf("%d", &season);
    if(scanf("%d", &season) != 1){
        printf("Введите именно число!");
        return -1;
    }
    
    switch (season)
    {
    case 1:
        printf("%s\n", "Июнь");
        printf("%s\n", "Июль");
        printf("%s\n", "Август");
        break;

    case 2:
        printf("%s\n", "Сентябрь");
        printf("%s\n", "Октябрь");  
        printf("%s\n", "Ноябрь");
        break;

    case 3:
        printf("%s\n", "Декабрь");
        printf("%s\n", "Январь");
        printf("%s\n", "Февраль");
        break;

    case 4:
        printf("%s\n", "Март");
        printf("%s\n", "Апрель");
        printf("%s\n", "Май"); 
        break;
    
    default:
        printf("Я не знаю такого сезона\n");
        break;
    }
    return 0;
}