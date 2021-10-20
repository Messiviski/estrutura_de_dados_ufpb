#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
  Pilha *pilha = NULL;

  pilha = pilha_cria();

  pilha_push(pilha, 'r');
  pilha_push(pilha, 'e');
  pilha_push(pilha, 'v');
  pilha_push(pilha, 'i');
  pilha_push(pilha, 'v');
  pilha_push(pilha, 'e');
  pilha_push(pilha, 'r');

  printf("\n%c", pilha_pop(pilha));
  printf("%c", pilha_pop(pilha));
  printf("%c", pilha_pop(pilha));
  printf("%c", pilha_pop(pilha));
  printf("%c", pilha_pop(pilha));
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