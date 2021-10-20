#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {

  Pilha *pilha = NULL;

  pilha = pilha_cria();

  if(pilha_balanceada(pilha, "[{()()}{}]")) {
    printf("Pilha esta balanceada\n");
  } else {
    printf("A Pilha nao esta balanceada!\n");
  }

  if(pilha_balanceada(pilha, "{[([{}])]}")) {
    printf("Pilha esta balanceada\n");
  } else {
    printf("A Pilha nao esta balanceada!\n");
  }

  if(pilha_balanceada(pilha, "{[(}])")) {
    printf("Pilha esta balanceada\n");
  } else {
    printf("A Pilha nao esta balanceada!\n");
  }

  if(pilha_balanceada(pilha, "{[)()(]}")) {
    printf("Pilha esta balanceada\n");
  } else {
    printf("A Pilha nao esta balanceada!\n");
  }

  pilha_libera(&pilha);

  if(!pilha) printf("\nPilha limpa com sucesso!\n");
}