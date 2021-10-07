#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h" 

#ifndef LISTA_ENCADEADA_C
#define LISTA_ENCADEADA_C

struct no {
  int info;
  Lista* prox;
};

Lista *lst_cria(int info) {
  Lista *nova_lista = (Lista*) malloc(sizeof(Lista));
  if(!nova_lista) return 0;

  // A lista já será iniciada com um valor passado na função principal
  // E por ser o primeiro elemento da lista o proximo elemento não existe
  // Então aponta para NULL
  nova_lista->info = info;
  nova_lista->prox = NULL;

  return nova_lista;
}

int lst_vazia(Lista *lista) {
  return (lista->prox == NULL);
}

int lst_tamanho(Lista *lista) {
  int cont = 0;

  // Ira percorrer toda lista ate o ultimo elemento
  // Quando chegar no ultimo elemento o valor de lista sera NULL
  // NULL e um valor false
  // O while percorrer ate o ultimo elemento, vai ate n-1 e sim ate n
  while (lista) {
    cont++;
    lista = lista->prox;
  }

  return cont;
}

int lst_insere_inicio(Lista **lista, int info) {
  Lista *novo_elemento = NULL;

  // Verifica se a lista existe
  if(*lista) {
    novo_elemento = (Lista*) malloc(sizeof(Lista));
    if(!novo_elemento) return 0;

    novo_elemento->info = info;
    novo_elemento->prox = *lista;
    *lista = novo_elemento;

    return 1;
  }

  return 0;
}

int lst_insere_fim(Lista **lista, int info) {
  Lista *novo_elemento = NULL;

  if(*lista) {
    novo_elemento = (Lista*) malloc(sizeof(Lista));
    if(!novo_elemento) return 0;

    Lista *aux = *lista;

    // Ira percorrer a lista ate o penultimo elemento, ou seja, n-1
    while (aux->prox) aux = aux->prox;

    novo_elemento->info = info;
    novo_elemento->prox = NULL;
    aux->prox = novo_elemento;

    return 1;
  }

  return 0;
}

int lst_existe(Lista *lista, int info) {
  while (lista) {
    if(lista->info == info) return 1;

    lista = lista->prox;
  }

  return 0;
}

void lst_mostra(Lista *lista, char *mensagem) {
  // Mensagem customizada que sera passada pelo funcao principal
  printf("%s ", mensagem);

  while (lista) {
    printf("%d ", lista->info);
    lista = lista->prox;
  }

  printf("\n");
}

void lst_limpa(Lista **lista) {
  Lista *elemento_lista = NULL;
  Lista *aux = *lista;

  while (aux) {
    elemento_lista = aux->prox;
    free(aux);

    aux = elemento_lista;
  }

  *lista = NULL;
}

int lst_remove_elemento(Lista **lista, int info) {
  Lista *elemento_anterior = NULL;
  Lista *aux = *lista;
  int status = 0;
  
  while (aux) {
    if(aux->info == info) {
      status = 1;
      break;
    }

    elemento_anterior = aux;
    aux = aux->prox;
  }

  if(status) {
    // Se o elemento for NULL quer dizer que o primeiro elemento seria retirado
    // Atribuo o proximo elemento para a lista e remove o elemento atual
    // Caso o proximo seja nulo a lista sera limpa
    if(!elemento_anterior) {
      *lista = aux->prox;
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
  Lista *novo_elemento = NULL;
  Lista *elemento_anterior = NULL;
  Lista *aux = *lista;

  // Verifica se a lista e vazia
  if(aux) {
    // Ira percorrer a lista enquanto ela existir
    // E enquanto a info do elemento for menor que o info passado para funcao
    while (aux && aux->info < info) {
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
      return 1;
    }

    novo_elemento->prox = elemento_anterior->prox;
    elemento_anterior->prox = novo_elemento;
    return 1;
  }

  return 0;
}

#endif