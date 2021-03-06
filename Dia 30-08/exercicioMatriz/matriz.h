#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

Matriz* cria_matriz(int m, int n);
void libera_matriz(Matriz** mat);
int acessa_matriz(Matriz* mat, int i, int j, float *valor_desejado);
int atribui_matriz(Matriz* mat, int i, int j, float novo_valor);
int nlinhas(Matriz* mat);
int ncolunas(Matriz* mat);

#endif