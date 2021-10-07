#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

#ifndef _LISTA_DUPLAMENTE_ENCADEADA_C
#define _LISTA_DUPLAMENTE_ENCADEADA_C

struct no {
  int info;
  NoLista* ant;
  NoLista* prox;
};

struct lista {
  NoLista* prim;
  NoLista* ult;
};

Lista* lst_cria(int info) {
  Lista* nova_lista = (Lista*) malloc(sizeof(Lista));
  if(!nova_lista) return 0;

  NoLista* novo_no = (NoLista*) malloc(sizeof(NoLista));
  if(!novo_no) return 0;

  novo_no->info = info;
  novo_no->ant = NULL;
  novo_no->prox = NULL;

  nova_lista->prim = novo_no;
  nova_lista->ult = novo_no;

  return nova_lista;
}

// Will return 1 if the list be equals to NULL and 0 if not
int lst_vazia(Lista *lista) {
  return (lista == NULL);
}

int lst_tamanho(Lista *lista) {
  if(lst_vazia(lista)) return 0;

  NoLista *aux = lista->prim;
  int cont = 0;
  
  while(aux) {
    cont++;
    aux = aux->prox;
  }

  return cont;
}

int lst_insere_inicio(Lista *lista, int info) {
  if(lst_vazia(lista)) return 0;

  NoLista* novo_no = (NoLista*) malloc(sizeof(NoLista));
  if(!novo_no) return 0;

  novo_no->info = info;
  novo_no->ant = NULL;
  novo_no->prox = lista->prim;

  lista->prim = novo_no;

  return 1;
}

int lst_insere_fim(Lista *lista, int info) {
  if(lst_vazia(lista)) return 0;

  NoLista* novo_no = (NoLista*) malloc(sizeof(NoLista));
  if(!novo_no) return 0;

  novo_no->info = info;
  novo_no->prox = NULL;
  novo_no->ant = lista->ult;

  lista->ult->prox = novo_no;
  lista->ult = novo_no;

  return 1;
}

int lst_existe(Lista *lista, int info) {
  if(lst_vazia(lista)) return 0;

  NoLista *aux = lista->prim;

  while(aux) {
    if(aux->info == info) return 1;
    aux = aux->prox;
  }

  return 0;
}

void lst_mostra(Lista *lista, char *messagem) {
  NoLista *aux = lista->prim;

  printf("%s ", messagem);

  while(aux) {
    printf("%d ", aux->info);
    aux = aux->prox;
  }

  printf("\n");
}

void lst_limpa(Lista **lista) {
  NoLista *elemento = NULL;
  Lista *aux = *lista;
  NoLista *aux2 = aux->prim;

  while(aux2) {
    elemento = aux2->prox;
    free(aux2);

    aux2 = elemento;
  }

  aux->prim = NULL;
  aux->ult = NULL;

  *lista = NULL;
}

int lst_remove_elemento(Lista *lista, int info) {
  if(lst_vazia(lista)) return 0;

  NoLista *elemento_anterior = NULL;
  NoLista *aux = lista->prim;

  int status = 0;

  while(aux) {
    if(aux->info == info) {
      status = 1;
      break;
    }

    elemento_anterior = aux;
    aux = aux->prox;
  }

  if(status) {
    if(!elemento_anterior) {
      lista->prim = aux->prox;
      lista->prim->ant = NULL;
      free(aux);
      return 1;
    }

    // This condition will be satisfied if the next element of aux is valid
    // Being valid means that is not null
    if(aux->prox) {
      elemento_anterior->prox = aux->prox;
      aux->prox->ant = elemento_anterior;
      free(aux);
      return 1;
    }

    elemento_anterior->prox = aux->prox;
    free(aux);
    return 1;
  }

  return 0;
}


#endif