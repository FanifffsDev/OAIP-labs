#include <stdio.h>
#include <locale.h>
#include <math.h>
#define PI 3.14
int main() {
  setlocale(0, "");

  float r, c, l;
  float o = 0.2;

  printf("Введите активное сопротивление (r): ");
  scanf("%f", &r);

  printf("Введите емкость (c): ");
  scanf("%f", &c);
  printf("Введите индуктивность (l): ");
  scanf("%f", &l);

  float tmp = o * l - 1 / (o * c);
  float res = sqrt(r * r + tmp * tmp);

  printf("Полное сопротивление цепи: %.4f\n", res);

  return 0;
}