#include <stdio.h>
#include "arvore.h"

int main(void) {
  Arvore *arvore = NULL;
  int numeros_aleatorios[7] = {10, 6, 8, 4, 14, 16, 12};

  arvore = arv_cria();

  for (size_t i = 0; i < 7; i++) {
    arv_insere(arvore, numeros_aleatorios[i]);
  }

  arv_imprime(arvore);

  printf("A arvore possui %d folha(s)\n", arv_qntd_folhas(arvore));

  arv_retira(arvore, 14);

  arv_imprime(arvore);

  printf("A arvore possui %d folha(s)\n", arv_qntd_folhas(arvore));

  arv_libera(arvore);
}