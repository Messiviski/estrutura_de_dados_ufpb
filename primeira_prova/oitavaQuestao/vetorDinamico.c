#include<stdio.h>
#include<stdlib.h>

int main() {
  int *integerVector = NULL, size = 0, aux = 0;
  
  printf("Defina o tamanho do vetor: ");
  scanf("%d", &size);

  integerVector = (int*) malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    printf("Digite um numero: ");
    scanf("%d", &aux);

    integerVector[i] = aux;
  }

  for (int i = 0; i < size; i++) {
    printf("-> %d\n", integerVector[i]);
  }

  free(integerVector);
}