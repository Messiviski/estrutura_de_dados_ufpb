#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
  Pilha *pilha = NULL;

  pilha = pilha_cria();

  if(pilha_push(pilha, 'o')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(pilha_push(pilha, 'v')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(pilha_push(pilha, 'o')) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  printf("\n%c", pilha_pop(pilha));
  printf("%c", pilha_pop(pilha));
  printf("%c\n", pilha_pop(pilha));

  if(pilha_vazia(pilha)) {
    printf("A pilha esta vazia!\n");
  } else {
    printf("A pilha nao esta vazia!\n");
  }

  pilha_libera(&pilha);

  if(!pilha) printf("\nPilha limpa com sucesso!\n");
}