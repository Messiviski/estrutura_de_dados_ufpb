#include <stdio.h>
#include <string.h>
#include "./includes/fila.h"
#include "./includes/pilha.h"

struct fila {
  NoLista* prim;
  NoLista* ult;
};

struct pilha {
  Lista *topo;
};

int verifica_palindroma(Pilha *pilha_main, Fila *fila_main, char *frase);

int main(void) {
  Pilha *pilha_principal = NULL;
  Fila *fila_principal = NULL;

  pilha_principal = pilha_cria();
  fila_principal = fila_cria();

  if(verifica_palindroma(pilha_principal, fila_principal, "subi no onibus")) {
    printf("A palavra e palindroma!\n");
  } else {
    printf("A palavra nao e palindroma!\n");
  }

  pilha_libera(&pilha_principal);
  fila_libera(&fila_principal);

  if(!pilha_principal && !fila_principal) {
    printf("As estruturas foram liberadas com sucesso!\n");
  }

  return 0;
}

int verifica_palindroma(Pilha *pilha_main, Fila *fila_main, char *frase) {
  for (int i = 0; i < strlen(frase); i++) {
    // Pula os espacos em branco e insere sem eles
    if(frase[i] == ' ') {
      pilha_push(pilha_main, frase[i]);
      fila_insere(fila_main, frase[i]);
    }
  }

  // Verifica se algum caractere foi inserido
  if(!pilha_main->topo && !fila_main->prim) return 0;

  // Retira todos os elementos da pilha e da fila ate que estejam vazios
  while(pilha_main->topo && fila_main->prim) {
    if(pilha_pop(pilha_main) != fila_retira(fila_main)) return 0;
  }

  return 1;
}