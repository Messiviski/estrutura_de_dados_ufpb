#include <stdio.h>
#include "lista_duplamente_encadeada.h"

int main(void) {
  Lista *nova_lista = lst_cria(1);

  if(lst_insere_inicio(nova_lista, 3)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!");
  }

  if(lst_insere_fim(nova_lista, 4)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Lista: ");

  if(lst_remove_elemento(nova_lista, 1)) {
    printf("Valor removido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Lista: ");

  if(lst_remove_elemento(nova_lista, 4)) {
    printf("Valor removido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "Lista: ");

  lst_limpa(&nova_lista);

  if(lst_vazia(nova_lista)) printf("A lista esta vazia!\n");
}