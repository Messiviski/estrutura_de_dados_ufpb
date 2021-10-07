#include <stdio.h>

int main() {

  int radius = 0;

  printf("Digite o valor do raio: ");
  scanf("%d", &radius);

  printf("Area: %.2f\n", 3.14 * (radius * radius));
}