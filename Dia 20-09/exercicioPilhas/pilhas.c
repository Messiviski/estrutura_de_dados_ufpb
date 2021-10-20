#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

#ifndef _PILHA_C
#define _PILHA_C

struct pilha {
  int n; // Quantidade de elementos ja inseridos
  int dim; // Quantidade maxima de elementos (pode ser aumentada)
  float *vetor; // Vetor dinamico de elementos
};

Pilha *pilha_cria(void) {
  Pilha *nova_pilha = (Pilha*) malloc(sizeof(Pilha));
  if(!nova_pilha) return 0;

  nova_pilha -> n = -1;
  nova_pilha -> dim = 2;

  nova_pilha->vetor = (float*) malloc(nova_pilha->dim * sizeof(float));
  if(!nova_pilha->vetor) return 0;

  return nova_pilha;
}

void pilha_push(Pilha *pilha, float valor) {
  if(pilha->n == pilha->dim) {
    pilha->dim *= 2;

    pilha->vetor = (float*) realloc(pilha->vetor, pilha->dim * sizeof(Pilha));
  }

  pilha->n++;

  pilha->vetor[pilha->n];
}

float pilha_pop(Pilha *pilha) {
  
}


#endif