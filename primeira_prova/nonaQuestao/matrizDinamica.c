#include<stdio.h>
#include<stdlib.h>

int main() {
  int **integerMatrix = NULL, columnQty = 0, rowQty = 0, length = 0, aux = 0;
  
  printf("Defina a quantidade de colunas: ");
  scanf("%d", &columnQty);

  printf("Defina a quantidade de linhas: ");
  scanf("%d", &rowQty);

  printf("Defina o tamanho das linhas: ");
  scanf("%d", &length);

  printf("==========================\n");

  integerMatrix = (int**) malloc(sizeof(int*) * columnQty);

  if(integerMatrix == NULL) {
    printf("Memoria insuficiente.\n");
    exit(1);
  }

  for (int i = 0; i < rowQty; i++) {
    integerMatrix[i] = (int*) malloc(sizeof(int) * length);
    if(integerMatrix[i] == NULL) {
      printf("Memoria insuficiente.\n");
      exit(1);
    }
  }

  for (int i = 0; i < columnQty; i++) {
    for (int j = 0; j < rowQty; j++) {
      printf("Digite um numero: ");
      scanf("%d", &aux);

      integerMatrix[i][j] = aux;

    }
    printf("-----------------------\n");
  }
  for (int i = 0; i < columnQty; i++) {
    for (int j = 0; j < rowQty; j++) {
      printf("-> %d\n", integerMatrix[i][j]);
    }
    printf("-----------------------\n");
  }
  for (int i = 0; i < columnQty; i++) {
    free(integerMatrix[i]);
  }

  free(integerMatrix);
}