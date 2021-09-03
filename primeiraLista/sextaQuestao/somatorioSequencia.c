#include <stdio.h>

int main() {
  int firstValue = 0, secondValue = 0, summation = 0;

  printf("Digite o primeiro valor: ");
  scanf("%d", &firstValue);
  
  printf("Digite o segundo valor: ");
  scanf("%d", &secondValue);

  for ( int i = firstValue; i <= secondValue; i++ ) summation += i;

  printf("Somatorio: ");
  printf("%d\n", summation);
}