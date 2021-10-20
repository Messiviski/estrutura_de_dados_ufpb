#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

#ifndef _LISTA_CIRCULAR_C
#define _LISTA_CIRCULAR_C

struct lista {
  int info;
  Lista *prox;
};

Lista *lst_cria(int info) {
  Lista *nova_lista = (Lista*) malloc(sizeof(Lista));
  if(!nova_lista) return 0;

  // O proximo elemento ira apontar para si mesmo
  nova_lista->info = info;
  nova_lista->prox = nova_lista;

  return nova_lista;
}

int lst_vazia(Lista *lista) {
  return (lista == NULL);
}

int lst_tamanho(Lista *lista) {
  if(lst_vazia(lista)) return 0;

  Lista *primeiro_elemento = lista;
  int cont = 0;

  while (lista) {
    // Essa condicao e para que o while nao seja finalizado na primeira execucao
    if(lista == primeiro_elemento && cont != 0) break;

    cont++;
    lista = lista->prox;
  }

  return cont;
}

int lst_insere_inicio(Lista **lista, int info) {
  if(lst_vazia(*lista)) return 0;

  Lista *novo_elemento = NULL;
  Lista *aux = *lista;

  novo_elemento = (Lista*) malloc(sizeof(Lista));
  if(!novo_elemento) return 0;

  novo_elemento->info = info;
  novo_elemento->prox = *lista;

  while (aux) {
    if(aux->prox == *lista) break;

    aux = aux->prox;
  }

  aux->prox = novo_elemento;

  *lista = novo_elemento;
  
  return 1;
}

int lst_insere_fim(Lista **lista, int info) {
  if(lst_vazia(*lista)) return 0;

  Lista *novo_elemento = NULL;
  Lista *aux = *lista;

  novo_elemento = (Lista*) malloc(sizeof(Lista));
  if(!novo_elemento) return 0;
  
  while (aux) {
    if(aux->prox == *lista) break;

    aux = aux->prox;
  }

  aux->prox = novo_elemento;

  novo_elemento->info = info;
  novo_elemento->prox = *lista;

  return 1;
}

int lst_existe(Lista *lista, int info) {
  if(lst_vazia(lista)) return 0;

  Lista *aux = lista;

  while (aux) {
    if(aux->info == info) return 1;

    if(aux->prox == lista) break;

    aux = aux->prox;
  }

  return 0;
}

void lst_mostra(Lista *lista, char *mensagem) {
  if(lst_vazia(lista)) return;
  
  Lista *aux = lista;

  // Mensagem customizada que sera passada pelo funcao principal
  printf("%s ", mensagem);

  while (lista) {    
    printf("%d ", lista->info);
    if (lista->prox == aux) break;
    lista = lista->prox;
  }

  printf("\n");
}

void lst_limpa(Lista **lista) {
  if(lst_vazia(*lista)) return;

  Lista *elemento_lista = NULL;
  Lista *aux = *lista;
  aux = aux->prox;

  // Will iterate from the
  while (aux) {
    if(aux == *lista) break;
    elemento_lista = aux->prox;
    free(aux);

    aux = elemento_lista;
  }

  free(aux);

  *lista = NULL;
}

int lst_remove_elemento(Lista **lista, int info) {
  if(lst_vazia(*lista)) return 0;

  Lista *elemento_anterior = NULL;
  Lista *aux = *lista;
  int status = 0;
  
  while (aux) {
    if(aux->info == info) {
      status = 1;
      break;
    }

    if(aux->prox == *lista) break;

    elemento_anterior = aux;
    aux = aux->prox;
  }

  if(status) {
    // Se o elemento for NULL quer dizer que o primeiro elemento seria retirado
    // Atribuo o proximo elemento para a lista e remove o elemento atual
    // Caso o proximo seja nulo a lista sera limpa
    if(!elemento_anterior) {
      Lista *aux2 = *lista;

      // Verifica se a lista tem apenas 1 elemento
      if(aux2->prox == *lista) {
        free(aux2);
        *lista = NULL;
        return 1;
      }

      // Aux2 tera que ter a referencia do ultimo elemento para que ele seja atualizado
      while(aux2) {
        if(aux2->prox == *lista) break;
      }

      *lista = aux->prox;
      aux2->prox = *lista;
      free(aux);
      return 1;
    }

    // Caso o elemento a ser retirado nao seja o primeiro
    // O elemento anterior ira apontar pra o proximo de aux
    // E depois libera-lo
    elemento_anterior->prox = aux->prox;
    free(aux);
    return 1;
  }
  return 0;
}

int lst_insere_ordenado(Lista **lista, int info) {
  if(lst_vazia(*lista)) return 0;

  Lista *novo_elemento = NULL;
  Lista *elemento_anterior = NULL;
  Lista *ultimo_elemento = *lista;
  Lista *aux = *lista;

  // Pega ultimo elemento
  while(ultimo_elemento) {
    if(ultimo_elemento->prox == *lista) break;
  }

  while (aux && aux->info < info) {
    if(aux->prox == *lista) break;

    elemento_anterior = aux;
    aux = aux->prox;
  }

  // Cria novo elemento e atribui o valor recebido na funcao com parametro
  novo_elemento = (Lista*) malloc(sizeof(Lista));
  novo_elemento->info = info;

  // Significa que o primeiro elemento da lista e maior que o recebido na funcao
  // Portanto, ira fazer uma insercao no inicio
  if(!elemento_anterior) {
    novo_elemento->prox = *lista;
    *lista = novo_elemento;
    ultimo_elemento = novo_elemento;
    return 1;
  }

  novo_elemento->prox = elemento_anterior->prox;
  elemento_anterior->prox = novo_elemento;
  return 1;
}

#endif