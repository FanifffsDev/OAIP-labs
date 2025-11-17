#include <stdio.h>
#include <math.h>

int main() {
    float v1, v2, s, t;

    printf("Введите скорость первого автомобиля (v1): ");
    scanf("%f", &v1);

    printf("Введите скорость второго автомобиля (v2): ");
    scanf("%f", &v2);

    printf("Введите начальное расстояние между автомобилями (S): ");
    scanf("%f", &s);

    printf("Введите время (t): ");
    scanf("%f", &t);

    float distance = s - (v1 + v2) * t;


    //Возникает вопрос, учитываем ли мы ситуацию, когда автомобили начинают разъезжаться в разные стороны
    //Если нет, то distance >= 0
    //Если да, то distance = fabs(distance)

    if (distance >= 0) {
        printf("Расстояние между автомобилями %.2f км\n", distance);
    }
    else {
        printf("Расстояние между автомобилями %.2f км\n", fabs(distance));
    }

    return 0;
}