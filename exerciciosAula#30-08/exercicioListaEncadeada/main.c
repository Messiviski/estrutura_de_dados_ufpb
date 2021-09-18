#include <stdio.h>
#include "lista_encadeada.h"

int main(void) {
  Lista *nova_lista = NULL;

  nova_lista = lst_cria(10);
  if(!nova_lista) printf("Algo de errado aconteceu!\n");

  if(lst_insere_fim(&nova_lista, 20)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Minha lista -> ");

  if(lst_insere_inicio(&nova_lista, 8)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Minha lista -> ");

  if(lst_insere_ordenado(&nova_lista, 9)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Minha lista -> ");

  if(lst_insere_ordenado(&nova_lista, 7)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Minha lista -> ");

  if(lst_insere_ordenado(&nova_lista, 21)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Minha lista -> ");

  printf("\nTamanho -> %d\n", lst_tamanho(nova_lista));

  if(lst_remove_elemento(&nova_lista, 10)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Minha lista -> ");
  
  printf("\nTamanho -> %d\n", lst_tamanho(nova_lista));

  lst_limpa(&nova_lista);

  if(!nova_lista) printf("Lista limpa com sucesso!\n");
}