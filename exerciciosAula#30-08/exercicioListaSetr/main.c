#include <stdio.h>
#include "lista_encadeada_setr.h"

int main(void) {
  Lista *primeira_lista = NULL;
  Lista *segunda_lista = NULL;
  Lista *lista_uniao = NULL;
  Lista *lista_intersec = NULL;

  // Cria primeira lista e adiciona os elementos
  primeira_lista = lst_setr_cria(2.0f);
  if (primeira_lista) printf("Lista criada com sucesso!\n");

  if(lst_setr_insere_fim(&primeira_lista, 5.1f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(lst_setr_insere_fim(&primeira_lista, 6.2f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(lst_setr_insere_fim(&primeira_lista, 4.0f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  // Cria segunda_lista e adiciona os elementos
  segunda_lista = lst_setr_cria(3.0f);
  if (segunda_lista) printf("Lista criada com sucesso!\n");

  if(lst_setr_insere_fim(&segunda_lista, 8.5f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(lst_setr_insere_fim(&segunda_lista, 2.0f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(lst_setr_insere_fim(&segunda_lista, 4.0f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  // Uniao
  lista_uniao = lst_setr_uniao(primeira_lista, segunda_lista);
  if(lista_uniao) {
    printf("Uniao feita com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }
  
  // Interseccao
  lista_intersec = lst_setr_intersec(primeira_lista, segunda_lista);
  if(lista_intersec) {
    printf("Intersecção feita com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }


  if(lst_setr_igual(primeira_lista, segunda_lista)) {
    printf("As listas sao iguais!\n");
  } else {
    printf("As listas nao sao iguais!\n");
  }

  printf("Tamanho primeira lista -> %d\n", lst_setr_tamanho(primeira_lista));
  printf("Tamanho segunda lista -> %d\n", lst_setr_tamanho(segunda_lista));

  if(!lst_setr_vazia(segunda_lista)) {
    printf("A lista nao esta vazia!\n");
  } else {
    printf("A lista esta vazia!\n");
  }

  if(lst_setr_existe(primeira_lista, 5.1f)) {
    printf("O valor existe na lista!\n");
  } else {
    printf("O valor nao existe na lista!\n");
  }

  if(lst_setr_remove_elemento(&primeira_lista, 5.1f)) {
    printf("Valor removido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  if(lst_setr_existe(primeira_lista, 5.1f)) {
    printf("O valor existe na lista!\n");
  } else {
    printf("O valor nao existe na lista!\n");
  }

  lst_setr_mostra(lista_uniao, "Uniao: ");

  lst_setr_mostra(lista_intersec, "Interseccao: ");

  lst_setr_limpa(&primeira_lista);
  lst_setr_limpa(&segunda_lista);

  if(primeira_lista && segunda_lista) printf("Lista limpa com sucesso!\n");
}
