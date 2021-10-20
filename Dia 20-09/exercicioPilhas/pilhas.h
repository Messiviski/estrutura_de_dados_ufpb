#ifndef _PILHA_H
#define _PILHA_H

typedef struct pilha Pilha;

Pilha *pilha_cria(void);
void pilha_push(Pilha *pilha, float valor);
float pilha_pop(Pilha *pilha);
int pilha_vazia(Pilha *pilha);
void pilha_libera(Pilha *pilha);

#endif