#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#ifndef _ARVORE_C
#define _ARVORE_C

struct arvno {
  int info;
  ArvoreNo* esq;
  ArvoreNo* dir;
};

struct arv {
  ArvoreNo* raiz;
};

Arvore* arv_cria(void) {
  Arvore *nova_arvore = NULL;

  nova_arvore = (Arvore*) malloc(sizeof(Arvore));
  if(!nova_arvore) return 0;

  nova_arvore->raiz = NULL;

  return nova_arvore;
}

ArvoreNo* insere(ArvoreNo *raiz, int valor) {
  if(!raiz) {
    ArvoreNo *novo_elemento = NULL;

    novo_elemento = (ArvoreNo*) malloc(sizeof(ArvoreNo));
    if(!novo_elemento) return NULL;

    novo_elemento->info = valor;
    novo_elemento->dir = NULL;
    novo_elemento->esq = NULL;

    return novo_elemento;
  } else {
    if (valor < raiz->info) {
      raiz->esq = insere(raiz->esq, valor);
    } else {
      raiz->dir = insere(raiz->dir, valor);
    }
    
    return raiz;
  }
}

void arv_insere(Arvore* arvore_principal, int valor) {
  arvore_principal->raiz = insere(arvore_principal->raiz, valor);
}

ArvoreNo* retira(ArvoreNo *raiz, int valor) {

  if(!raiz) {
    // Caso o elemento nao exista na arvore
    return NULL;
  } else if(valor > raiz->info) {
    raiz->dir = retira(raiz->dir, valor);
  } else if(valor < raiz->info) {
    raiz->esq = retira(raiz->esq, valor);
  } else {
    // Se o no nao possuir filhos
    if(!raiz->esq && !raiz->dir) {
      free(raiz);
      raiz = NULL;
    } else if(!raiz->esq) {
      ArvoreNo *aux = raiz;
      raiz = raiz->dir;
      free(aux);
    } else if(!raiz->dir) {
      ArvoreNo *aux = raiz;
      raiz = raiz->esq;
      free(aux);
    } else {
      ArvoreNo *aux = raiz->esq;

      // Ira percorrer a arvore ate achar um filho da direita que seja nulo
      while(aux->dir) {
        aux = aux->dir;
      }

      // Troca as informacoes com o elemento que sera removido
      raiz->info = aux->info;
      aux->info = valor;

      raiz->esq = retira(raiz->esq, valor);
    }
  }

  return raiz;
}

void arv_retira(Arvore *arvore_principal, int valor) {
  arvore_principal->raiz = retira(arvore_principal->raiz, valor);
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

void imprime(ArvoreNo *raiz) {
  if(!raiz) return;

  imprime(raiz->esq);
  imprime(raiz->dir);
  printf(" %d ", raiz->info);
}

void arv_imprime(Arvore *arvore_principal) {
  imprime(arvore_principal->raiz);
  printf("\n");
}

int pertence(ArvoreNo *raiz, int valor) {
  if(!raiz) return 0;

  return valor == raiz->info ||
    pertence(raiz->esq, valor) ||
    pertence(raiz->dir, valor);
}

int arv_pertence(Arvore *arvore_principal, int valor) {
  return (pertence(arvore_principal->raiz, valor));
}

ArvoreNo* busca(ArvoreNo *raiz, int valor) {
  if(!raiz) {
    return NULL;
  } else if(valor > raiz->info) {
    return busca(raiz->dir, valor);
  } else if(valor < raiz->info) {
    return busca(raiz->esq, valor);
  } else {
    return raiz;
  }
}

void arv_busca(Arvore *arvore_principal, int valor) {
  arvore_principal->raiz = busca(arvore_principal->raiz, valor);
}

int conta_folha(ArvoreNo *raiz) {
  if(!raiz) {
    return 0;
  } else if(raiz->esq == NULL && raiz->dir == NULL) {
    return 1;
  } else {
    return conta_folha(raiz->esq) + conta_folha(raiz->dir);
  }
}

int arv_qntd_folhas(Arvore *arvore_principal) {
  return conta_folha(arvore_principal->raiz);
}

#endif