#include <stdio.h>
#include <math.h>

struct Point {
  double x;
  double y;
};

double distance(struct Point a, struct Point b)
{
  double axisX = a.x > b.x ? a.x - b.x : b.x - a.x;
  double axisY = a.y > b.y ? a.y - b.y : b.y - a.y;
  return sqrt(pow(axisX, 2) + pow(axisY, 2));
}

int main(int argc, char const *argv[]) {
  struct Point a, b;
  printf("Digite o primeiro ponto: ");
  scanf("%lf %lf", &a.x, &a.y);
  printf("Digite o segundo ponto: ");
  scanf("%lf %lf", &b.x, &b.y);
  printf("A distância é: %.2lf\n", distance(a, b));
  return 0;
}
