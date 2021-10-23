#ifndef _FILA_H
#define _FILA_H

typedef struct no NoLista;
typedef struct fila Fila;

Fila* fila_cria(void);
int fila_insere(Fila* fila_main, char caractere);
char fila_retira(Fila* fila_main);
int fila_vazia(Fila* fila_main);
void fila_libera(Fila** fila_main);

#endif