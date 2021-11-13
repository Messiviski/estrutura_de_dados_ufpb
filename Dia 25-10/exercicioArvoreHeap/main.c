#include <stdio.h>
#include "arvore.h"

int main(void) {
  Heap *arvore_heap = NULL;

  arvore_heap = heap_cria(10);

  for (int i = 1; i < 11; i++) {
    if(heap_insere(arvore_heap, i)) {
      printf("Inserido!\n");
    } else {
      printf("Algo de errado aconteceu ou a arvore esta cheia!\n");
    }
  }

  while(!heap_vazia(arvore_heap)) {
    int valor = heap_retira(arvore_heap);
    printf(" %d ", valor);
  }
  
  heap_libera(&arvore_heap);

  if(!arvore_heap) printf("\n\nArvore limpa com sucesso!\n");
}