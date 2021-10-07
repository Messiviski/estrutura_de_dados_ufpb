#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_setr.h"

#ifndef LISTA_ENCADEADA_SETR_C
#define LISTA_ENCADEADA_SETR_C

struct no {
  float info;
  Lista* prox;
};

Lista *lst_setr_cria(float info) {
  Lista *nova_lista = (Lista*) malloc(sizeof(Lista));
  if(!nova_lista) return 0;

  // A lista já será iniciada com um valor passado na função principal
  // E por ser o primeiro elemento da lista o proximo elemento não existe
  // Então aponta para NULL
  nova_lista->info = info;
  nova_lista->prox = NULL;

  return nova_lista;
}

// Clonar uma lista para uma nova lista
// Apos isso inserir ordenado os elementos da proxima lista
Lista *lst_setr_uniao(Lista *primeira_lista, Lista *segunda_lista) {
  Lista *uniao_lista = NULL;

  if(primeira_lista && segunda_lista) {
    Lista *aux = primeira_lista->prox;

    uniao_lista = lst_setr_cria(primeira_lista->info);
  
    while (aux) {
      // A primeira_lista sera clonada
      if(!lst_setr_insere_fim(&uniao_lista, aux->info)) return 0;

      aux = aux->prox;
    }

    aux = segunda_lista;

    while (aux) {
      // A segunda lista sera inserida no fim
      if(!lst_setr_insere_fim(&uniao_lista, aux->info)) return 0;

      aux = aux->prox;
    }

    return uniao_lista;
  }

  return 0;
}

int lst_setr_insere_fim(Lista **lista, float info) {
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

int lst_setr_remove_elemento(Lista **lista, float info) {
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

Lista *lst_setr_intersec(Lista *primeira_lista, Lista *segunda_lista) {
  Lista *intersec_lista = NULL;
  Lista *aux_lista_1 = NULL;
  Lista *aux_lista_2 = NULL;

  int status_nova_lista = 0;

  if(primeira_lista && segunda_lista) {
    aux_lista_1 = primeira_lista;
    aux_lista_2 = segunda_lista;

    // Sera necessario iterar sobre as duas listas
    // De forma que todos os elementos sejam comparados
    while (aux_lista_1) {
      while (aux_lista_2) {

        // Caso encontre que o valor sera igual
        // O if recebera valor true e verificara se lista foi criada
        // O valor da variavel status_nova_lista contem o status da nova lista
        // 0 - Lista nao criada, 1 - Lista criada
        if(aux_lista_1->info == aux_lista_2->info) {
          if(!status_nova_lista) {
            intersec_lista = lst_setr_cria(aux_lista_1->info);

            status_nova_lista++;
          } else {
            // Caso a lista ja esteja criada, o valor sera inserido no fim
            if(!lst_setr_insere_fim(&intersec_lista, aux_lista_1->info)) return 0;
          }
        }

        aux_lista_2 = aux_lista_2->prox;
      }

      aux_lista_1 = aux_lista_1->prox;
      // E necessario reatribuir o a segunda lista para o aux
      // Para as proximas iteracoes
      aux_lista_2 = segunda_lista;
    }

    return intersec_lista;
  }

  return 0;
}

int lst_setr_existe(Lista *lista, float info) {
  while (lista) {
    if(lista->info == info) return 1;

    lista = lista->prox;
  }

  return 0;
}

//J

int lst_setr_igual(Lista *primeira_lista, Lista *segunda_lista) {
  int cont = 0;

  if(primeira_lista && segunda_lista) {

    if(lst_setr_tamanho(primeira_lista) != lst_setr_tamanho(segunda_lista)) {
      return 0;
    }

    Lista *aux_lista_1 = primeira_lista;
    Lista *aux_lista_2 = segunda_lista;

    // Como o tamanho sera o mesmo, da pra usar qualquer lista no while
    while (aux_lista_1) {
      if(aux_lista_1->info == aux_lista_2->info) {
        cont++;
      } else {
        break;
      }

      aux_lista_1 = aux_lista_1->prox;
      aux_lista_2 = aux_lista_2->prox;
    }

    return 1;
  }

  return 0;
}

// K)
int lst_setr_tamanho(Lista *lista) {
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

// L)
int lst_setr_vazia(Lista *lista) {
  return (lista == NULL);
}

void lst_setr_limpa(Lista **lista) {
  Lista *elemento_lista = NULL;
  Lista *aux = *lista;

  while (aux) {
    elemento_lista = aux->prox;
    free(aux);

    aux = elemento_lista;
  }

  *lista = NULL;
}

void lst_setr_mostra(Lista *lista, char *mensagem) {
  // Mensagem customizada que sera passada pelo funcao principal
  printf("%s ", mensagem);

  while (lista) {
    printf("%.2f ", lista->info);
    lista = lista->prox;
  }

  printf("\n");
}

#endif