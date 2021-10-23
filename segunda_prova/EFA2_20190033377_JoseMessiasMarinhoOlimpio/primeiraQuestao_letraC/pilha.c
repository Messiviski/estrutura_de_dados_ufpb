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
  Lista *topo;
};

Pilha* pilha_cria(void) {
  Pilha *nova_pilha = NULL;

  nova_pilha = (Pilha*) malloc(sizeof(Pilha));
  if(!nova_pilha) return 0;

  nova_pilha->topo = NULL;

  return nova_pilha;
}

int pilha_push(Pilha *pilha, char caractere) {
  if(!pilha) return 0;

  Lista *novo_elemento = NULL;

  novo_elemento = (Lista*) malloc(sizeof(Lista));
  if(novo_elemento) {
    novo_elemento->info = caractere;

    // O novo elemento ira apontar para o elemento que esta no topo
    novo_elemento->prox = pilha->topo;
    
    // O topo ira apontar para o novo elemento
    pilha->topo = novo_elemento;

    return 1;
  }

  return 0;
}

char pilha_pop(Pilha *pilha) {
  Lista *aux = NULL;

  char elemento = pilha->topo->info;

  aux = pilha->topo;
  pilha->topo = aux->prox;

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
  Lista *lista = aux->topo;
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
  int chaves = 0, colchetes = 0, parenteses = 0;
  char elemento;

  // Ira empilhar a expressao
  for (int i = 0; i < strlen(expressao); i++) {
    pilha_push(pilha, expressao[i]);
  }

  printf("%s\n", expressao);

  // Ira desempilhar e analisar os caracteres
  // A cada fechamento e somado um ao valor do caractere
  // A cada fechamento ira subtrair 1
  // Ao final de tudo todas as variaves terao que ser iguais a 0
  while (pilha->topo) {
    elemento = pilha_pop(pilha);

    if(elemento == '}') chaves++;
    else if(elemento == ']') colchetes++;
    else if(elemento == ')') parenteses++;
    else if(elemento == '{') chaves--;
    else if(elemento == '[') colchetes--;
    else if(elemento == '(') parenteses--;

    // Retorna caso algum valor negativo
    // O valor sera negativo se houve uma abertura antes do fechamento
    if(chaves < 0 || colchetes < 0 || parenteses< 0) return 0;
  }
  
  return 1;
}

#endif