#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#ifndef _ARVORE_HEAP_C
#define _ARVORE_HEAP_C

#define pai(i) ((i-1)/2)
#define filho_esq(i) (2*i+1)
#define filho_dir(i) (2*i+2)

struct heap {
  int n;
  int nmax;
  int *vetor;
};

Heap* heap_cria(int nmax) {
  if(nmax < 1) return 0;

  Heap *nova_arvore = NULL;

  nova_arvore = (Heap*) malloc(nmax * sizeof(Heap));
  if(!nova_arvore) return 0;

  nova_arvore->n = 0;
  nova_arvore->nmax = nmax;
  nova_arvore->vetor = (int*) malloc(nmax * sizeof(int));

  return nova_arvore;
}

void heap_libera(Heap **arvore_heap) {
  Heap *aux = *arvore_heap;

  free(aux->vetor);
  free(*arvore_heap);

  *arvore_heap = NULL;
}

int heap_vazia(Heap *arvore_heap) {
  return (arvore_heap->vetor == NULL);
}

void troca(Heap *arvore_heap, int pos_pai, int pos_filho) {
  int temp = arvore_heap->vetor[pos_pai];
  arvore_heap->vetor[pos_pai] = arvore_heap->vetor[pos_filho];
  arvore_heap->vetor[pos_filho] = temp;
}

void sobe(Heap *arvore_heap, int pos_novo_elem) {
  while (pos_novo_elem > 0) {
    int pos_pai = pai(pos_novo_elem);

    if(arvore_heap->vetor[pos_pai] > arvore_heap->vetor[pos_novo_elem]) {
      break;
    }

    troca(arvore_heap, pos_pai, pos_novo_elem);
    pos_novo_elem = pos_pai;
  }
}

int heap_insere(Heap *arvore_heap, int valor) {
  if(arvore_heap->n == arvore_heap->nmax) return 0;

  arvore_heap->vetor[arvore_heap->n] = valor;
  arvore_heap->n += 1;

  sobe(arvore_heap, arvore_heap->n - 1);
  return 1;
}

void desce(Heap *arvore_heap, int pos_elem) {
  int pos_1 = filho_esq(pos_elem);

  while(pos_1 < arvore_heap->n) {
    int pos_2 = filho_dir(pos_elem);

    if(pos_2 > arvore_heap->n && 
      arvore_heap->vetor[pos_2] > arvore_heap->vetor[pos_1]
    ) {
      pos_1 = pos_2;
    }

    if(arvore_heap->vetor[pos_1] < arvore_heap->vetor[pos_2]) {
      break;
    }

    troca(arvore_heap, pos_elem, pos_1);
    pos_elem = pos_1;
    pos_1 = filho_esq(pos_elem);
  }
}

int heap_retira(Heap *arvore_heap) {
  if(arvore_heap->n == 0) {
    free(arvore_heap->vetor);

    arvore_heap->vetor = NULL;
  } else {
    int raiz = arvore_heap->vetor[0];

    arvore_heap->n -= 1;

    arvore_heap->vetor[0] = arvore_heap->vetor[arvore_heap->n];

    desce(arvore_heap, 0);

    return raiz;
  }

  return 0;
}

#endif