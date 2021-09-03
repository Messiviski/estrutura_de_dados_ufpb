#include <stdio.h>

// Usando WHILE
/* int main() {
  int firstValue = 0, secondValue = 0, cont = 0;

  printf("Digite o primeiro valor: ");
  scanf("%d", &firstValue);
  
  printf("Digite o segundo valor: ");
  scanf("%d", &secondValue);

  cont = firstValue;

  while ( cont != secondValue ) {
    printf("%d\t", cont);
    cont += 1;
  }
  
  printf("%d\n", cont);
} */

// Usando DO-WHILE
/* int main() {
  int firstValue = 0, secondValue = 0, cont = 0;

  printf("Digite o primeiro valor: ");
  scanf("%d", &firstValue);
  
  printf("Digite o segundo valor: ");
  scanf("%d", &secondValue);

  cont = firstValue;

  do {
    printf("%d\t", cont);
    cont += 1;
  } while ( cont != secondValue );
  
  printf("%d\n", cont);
} */

// Usando FOR 
int main() {
  int firstValue = 0, secondValue = 0;

  printf("Digite o primeiro valor: ");
  scanf("%d", &firstValue);
  
  printf("Digite o segundo valor: ");
  scanf("%d", &secondValue);

  for ( int i = firstValue; i <= secondValue; i++ ) {
    printf("%d\t", i);
  }
  
  printf("\n");
}
