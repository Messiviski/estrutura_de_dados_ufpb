#include <stdio.h>
#include <stdlib.h>
#include "vetor_realocavel.h"

#ifndef VETOR_REALOCAVEL_C
#define VETOR_REALOCAVEL_C

struct vetordin{
  int n;
  int v_dim;
  float *v;
};

VetorDin *cria_vetor(int dim) {
  // Caso a dimensao passada seja igual a 0 a funcao nao sera executada
  if(dim <= 0) return 0;

  VetorDin *novo_vetor = NULL;

  // Aloco um espaco de memoria do tipo VetorDin
  novo_vetor = (VetorDin*) malloc(sizeof(VetorDin));
  if(!novo_vetor) return 0;

  // Defino os primeiros valores para o vetor
  // Como a lista inicia vazia o primeiro valor sera 0
  novo_vetor->n = 0;
  novo_vetor->v_dim = dim;
  // Aloco um espaco de memoria do tamanho da dimensao recebido na funcao
  novo_vetor->v = (float*) malloc(dim * sizeof(float));
  if(!novo_vetor->v) return 0;

  return novo_vetor;
}

int insere_vetord(VetorDin *vetor_dinamico, float novo_valor) {

  // Verifico se o vetor dinamico existe e se o vetor v tambem existe
  if(vetor_dinamico && vetor_dinamico->v) {
    // Verifico que a quantidade de elementos inseridos é igual a dimensão
    // Caso seja igual o valor da dimensão é dobrado e uma nova memória é alocada
    // Essa nova memória alocada possuí o tamanho da nova dimensão.
    // Caso a quantidade de elementos não seja igual a dimensão
    // O novo valor sera inserido e quantidade de elementos inseridos no vetor é atualizada
    if(vetor_dinamico->n == vetor_dinamico->v_dim) {
      vetor_dinamico->v_dim *= 2;
      vetor_dinamico->v = (float*) realloc(
        vetor_dinamico->v,
        vetor_dinamico->v_dim * sizeof(float)
      );
      if(!vetor_dinamico->v) return 0;

      vetor_dinamico->v[vetor_dinamico->n] = novo_valor;
      vetor_dinamico->n += 1;

      return 1;
    } else {
      vetor_dinamico->v[vetor_dinamico->n] = novo_valor;
      vetor_dinamico->n += 1;

      return 1;
    }
  }

  return 0;
}

int tamanho_vetord(VetorDin *vetor_dinamico) {
  if(vetor_dinamico) return vetor_dinamico->n;

  return 0;
}

int acessa_vetord(VetorDin *vetor_dinamico, int pos, float *valor) {
  // Caso a quantidade de elementos inseridos no vetor dinamico seja igual a 0
  // Isso significa que nenhum elemento foi inserido
  if(vetor_dinamico->n > 0 && vetor_dinamico->v_dim > 0) { 
    if(vetor_dinamico->v[pos]) {
      *valor = vetor_dinamico->v[pos];

      return 1;
    }
  }

  return 0;
}

void libera_vetord(VetorDin **vetor_dinamico) {
  VetorDin *aux = *vetor_dinamico;

  if(aux) {
    free(aux->v);

    free(aux);

    *vetor_dinamico = NULL;
  }
}

#endif