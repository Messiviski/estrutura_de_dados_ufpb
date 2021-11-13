#ifndef _ARVORE_HEAP_H
#define _ARVORE_HEAP_H

typedef struct heap Heap;

Heap* heap_cria(int nmax);
void heap_libera(Heap **arvore_heap);
int heap_vazia(Heap *arvore_heap);
int heap_insere(Heap *arvore_heap, int valor);
int heap_retira(Heap *arvore_heap);

#endif