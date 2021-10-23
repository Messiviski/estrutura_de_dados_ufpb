#include <stdio.h>
#include "fila.h"

int main(void) {
  Fila *fila_principal = NULL;

  fila_principal = fila_cria();

  if(fila_insere(fila_principal, '1')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(fila_insere(fila_principal, '2')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(fila_insere(fila_principal, '3')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(fila_insere(fila_principal, '4')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(fila_insere(fila_principal, '5')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(fila_vazia(fila_principal)) {
    printf("A fila esta vazia!\n");
  } else {
    printf("A fila nao esta vazia!\n");
  }

  printf("\n%c", fila_retira(fila_principal));
  printf("%c", fila_retira(fila_principal));
  printf("%c", fila_retira(fila_principal));
  printf("%c", fila_retira(fila_principal));
  printf("%c\n", fila_retira(fila_principal));

  if(fila_vazia(fila_principal)) {
    printf("A fila esta vazia!\n");
  } else {
    printf("A fila nao esta vazia!\n");
  }

  fila_libera(&fila_principal);

  if(!fila_principal) printf("A fila foi limpa!\n");
}