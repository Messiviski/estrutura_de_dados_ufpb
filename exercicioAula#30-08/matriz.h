#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct matriz Matriz;

Matriz* cria_matriz(int m, int n);
void libera_matriz(Matriz* mat);
int acessa_matriz(Matriz* mat, int i, int j, float *valor_matriz);
int atribui_matriz(Matriz* mat, int i, int j, float novo_valor);
int nlinhas(Matriz* mat);
int ncolunas(Matriz* mat);

#endif