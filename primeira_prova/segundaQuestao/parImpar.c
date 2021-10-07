#include <stdio.h>

int main() {

  int number = 0;

  printf("Digite um numero: ");
  scanf("%d", &number);

  if( ( number % 2 ) == 0) {
    printf("O Numero é par!\n");
  } else {
    printf("O Numero é impar!\n");
  }
}