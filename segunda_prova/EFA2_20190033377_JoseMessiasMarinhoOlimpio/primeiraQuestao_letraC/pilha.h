#ifndef _PILHA_H
#define _PILHA_H

typedef struct pilha Pilha;
typedef struct lista Lista;

Pilha* pilha_cria(void);
int pilha_push(Pilha *pilha, char caractere);
char pilha_pop(Pilha *pilha);
int pilha_vazia(Pilha *pilha);
void pilha_libera(Pilha **pilha);
int pilha_balanceada(Pilha *pilha, char *expressao);

#endif