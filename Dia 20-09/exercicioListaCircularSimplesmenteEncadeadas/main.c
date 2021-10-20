#include <stdio.h>
#include "lista_circular.h"

int main(void) {
  Lista *nova_lista = lst_cria(10);

  if(lst_insere_inicio(&nova_lista, 8)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  lst_mostra(nova_lista, "XAMAAA: ");

  lst_limpa(&nova_lista);

  if(lst_vazia(nova_lista)) printf("Lista limpa com sucesso!\n");
}