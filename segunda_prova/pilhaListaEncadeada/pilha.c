#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#ifndef _PILHA_C
#define _PILHA_C

struct lista {
  char info;
  Lista *prox;
};

struct pilha {
  Lista *prim;
};

Pilha* pilha_cria(void) {
  Pilha *nova_pilha = NULL;

  nova_pilha = (Pilha*) malloc(sizeof(Pilha));
  if(!nova_pilha) return 0;

  nova_pilha->prim = NULL;

  return nova_pilha;
}

void pilha_push(Pilha *pilha, char caractere) {

  Lista *novo_elemento = NULL;

  novo_elemento = (Lista*) malloc(sizeof(Lista));
  if(novo_elemento) {
    novo_elemento->info = caractere;
    novo_elemento->prox = pilha->prim;

    pilha->prim = novo_elemento;
  }
}

char pilha_pop(Pilha *pilha) {
  Lista *aux = NULL;

  char elemento = pilha->prim->info;

  aux = pilha->prim;
  pilha->prim = aux->prox;

  free(aux);


  return elemento;
}

// 1 - Lista esta vazia (1 equivale a true)
// 0 - Lista nao esta vazia (0 equivale a false)
int pilha_vazia(Pilha *pilha) { 
  return (pilha == NULL); 
}

void pilha_libera(Pilha **pilha) {
  Pilha *aux = *pilha;
  Lista *lista = aux->prim;
  Lista *elemento_pilha = NULL;
  
  while(lista) {
    elemento_pilha = lista->prox;

    free(lista);
    lista = elemento_pilha;
  }

  free(aux);

  *pilha = NULL;
}

int pilha_balanceada(Pilha *pilha, char *expressao) {
  int chaves_abertura = 0, colchetes_abertura = 0, parenteses_abertura = 0;
  int chaves_fechamento = 0, colchetes_fechamento = 0, parenteses_fechamento = 0;
  char elemento;

  // Ira empilhar a expressao
  for (int i = 0; i < strlen(expressao); i++) {
    pilha_push(pilha, expressao[i]);
  }

  printf("%s\n", expressao);

  // Ira desempilhar e analisar os caracteres
  while (pilha->prim) {
    elemento = pilha_pop(pilha);

    if(elemento == '}') chaves_fechamento++;
    else if(elemento == ']') colchetes_fechamento++;
    else if(elemento == ')') parenteses_fechamento++;
    else if(elemento == '{') chaves_abertura++;
    else if(elemento == '[') colchetes_abertura++;
    else if(elemento == '(') parenteses_abertura++;

    if(chaves_abertura > 0 && chaves_fechamento == 0) return 0;
    if(colchetes_abertura > 0 && colchetes_fechamento == 0) return 0;
    if(parenteses_abertura > 0 && parenteses_fechamento == 0) return 0;
  }
  
  return 1;
}

#endif