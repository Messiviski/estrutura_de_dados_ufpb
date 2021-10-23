#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#ifndef _FILA_C
#define _FILA_C

struct no {
  char info;
  NoLista* ant;
  NoLista* prox;
};

struct fila {
  NoLista* prim;
  NoLista* ult;
};

Fila* fila_cria(void) {
  Fila *nova_fila = NULL;

  nova_fila = (Fila*) malloc(sizeof(Fila));
  if(!nova_fila) return 0;

  nova_fila->prim = NULL;
  nova_fila->ult = NULL;

  return nova_fila;
}

int fila_insere(Fila* fila_main, char caractere) {
  if(!fila_main) return 0;

  NoLista *novo_elemento = NULL;

  novo_elemento = (NoLista*) malloc(sizeof(NoLista));
  if(novo_elemento) {
    // Caso onde ta sendo inserido o primeiro elemento na fila
    if(!fila_main->prim && !fila_main->ult) {
      novo_elemento->info = caractere;
      novo_elemento->ant = fila_main->ult;
      novo_elemento->prox = fila_main->prim;

      fila_main->prim = novo_elemento;
      fila_main->ult = novo_elemento;
    } else {
      novo_elemento->info = caractere;
      novo_elemento->ant = fila_main->ult;
      novo_elemento->prox = NULL;

      fila_main->ult->prox = novo_elemento;
      fila_main->ult = novo_elemento;
    }

    return 1;
  }

  return 0;
}

char fila_retira(Fila* fila_main) {
  NoLista *aux = fila_main->prim;
  char elemento = aux->info;

  fila_main->prim = aux->prox;
  
  // Caso onde a fila possui um unico elemento e ele sera removido
  if(fila_main->prim) {
    fila_main->prim->ant = NULL;
  } else {
    fila_main->ult = NULL;
  }

  free(aux);

  return elemento;
}

int fila_vazia(Fila* fila_main) {
  return (fila_main->prim == NULL && fila_main->ult == NULL);
}

void fila_libera(Fila** fila_main) {
  Fila *aux_fila = *fila_main;
  NoLista *aux_no = aux_fila->prim;
  NoLista *elemento_lista = NULL;

  while(aux_no) {
    elemento_lista = aux_no->prox;

    free(aux_no);
    aux_no = elemento_lista;
  }

  free(aux_fila);
  
  *fila_main = NULL;
}

#endif