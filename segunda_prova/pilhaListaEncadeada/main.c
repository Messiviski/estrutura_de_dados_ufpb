#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
  Pilha *pilha = NULL;

  pilha = pilha_cria();

  pilha_push(pilha, "r");
  pilha_push(pilha, "e");
  pilha_push(pilha, "v");
  pilha_push(pilha, "i");
  pilha_push(pilha, "v");
  pilha_push(pilha, "e");
  pilha_push(pilha, "r");

  printf(" %c ", pilha_pop(pilha));

  pilha_libera(&pilha);

  if(!pilha) printf("\nPilha limpa com sucesso!\n");
}