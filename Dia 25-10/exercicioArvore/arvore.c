#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#ifndef _ARVORE_C
#define _ARVORE_C

struct arvno {
  char info;
  ArvoreNo* esq;
  ArvoreNo* dir;
};

struct arv {
  ArvoreNo* raiz;
};

Arvore* arv_cria(ArvoreNo *raiz) {
  Arvore *nova_arvore = NULL;

  nova_arvore = (Arvore*) malloc(sizeof(Arvore));
  if(!nova_arvore) return 0;

  nova_arvore->raiz = raiz;

  return nova_arvore;
}

ArvoreNo* arv_criano(char caractere, ArvoreNo *esq, ArvoreNo *dir) {
  ArvoreNo *novo_no = NULL;

  novo_no = (ArvoreNo*) malloc(sizeof(ArvoreNo));
  if(!novo_no) return 0;

  novo_no->info = caractere;
  novo_no->dir = dir;
  novo_no->esq = esq;

  return novo_no;
}

// Pos-ordem
void libera(ArvoreNo *raiz) {
  if(!raiz) return;

  libera(raiz->esq);
  libera(raiz->dir);
  free(raiz);
}

void arv_libera(Arvore *arvore_principal) {
  if(arvore_principal) {
    libera(arvore_principal->raiz);
    free(arvore_principal);
  }
}

// Pre-ordem
void imprime(ArvoreNo *raiz) {
  if(!raiz) return;

  printf(" %c ", raiz->info);
  imprime(raiz->esq);
  imprime(raiz->dir);
}

void arv_imprime(Arvore *arvore_principal) {
  imprime(arvore_principal->raiz);
}

// Pre-ordem
int pertence(ArvoreNo *raiz, char caractere) {
  if(!raiz) return 0;

  return caractere == raiz->info ||
    pertence(raiz->esq, caractere) ||
    pertence(raiz->dir, caractere);
}

int arv_pertence(Arvore *arvore_principal, char caractere) {
  return (pertence(arvore_principal->raiz, caractere));
}

ArvoreNo* busca(ArvoreNo *raiz, char caractere) {
  if(!raiz) {
    return NULL;
  } else if(caractere == raiz->info) {
    return raiz;
  } else {
    ArvoreNo *aux = busca(raiz->esq, caractere);
    if(aux) {
      return aux;
    } else {
      return busca(raiz->dir, caractere);
    }
  }
}

ArvoreNo* arv_busca(Arvore *arvore_principal, char caractere) {
  return busca(arvore_principal->raiz, caractere);
}

#endif