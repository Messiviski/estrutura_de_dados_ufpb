#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matriz.h"

#ifndef _MATRIZ_C
#define _MATRIZ_C

struct matriz {
  int lin;
  int col;
  float **valor;
};

Matriz *cria_matriz(int linhas, int colunas) {
  Matriz *mat = NULL;

  mat->lin = linhas;
  mat->col = colunas;
  mat->valor = (float**) malloc(linhas * sizeof(float*));

  for (int i = 0; i < linhas; i++) {
    mat->valor[i] = (float*) malloc(colunas * sizeof(float));
  }
  
  return mat;
}

void libera_matriz(Matriz *mat) {
  for (int i = 0; i < mat->lin; i++) {
    free(mat->valor[i]);
  }

  free(mat);
}

// If returns 1 means that all goes as it should
// but if returns 0 it means that something went wrong

int acessa_matriz(Matriz *mat, int i, int j, float *valor_desejado) {
  if(mat->valor[i][j]) {
    *valor_desejado = mat->valor[i][j];
    return 1;
  }

  return 0;
}

// The function below will check if in the given position exists something
// If exists it will ask to the user if he want to overwrite the value
// If yes returns 1 if not return 0

int atribui_matriz(Matriz *mat, int i, int j, float novo_valor) {
  int opcao_usuario;

  if(mat->valor[i][j]) {
    printf("Ja existe um valor nessa posicao! Deseja sobrescrever?\n");
    printf("1 - Sim\n2 - Nao\nDigite sua opcao: ");
    scanf("%d", &opcao_usuario);

    if(opcao_usuario == 1) {
      mat->valor[i][j] = novo_valor;

      return 1;
    }
  }

  return 0;
}

int nlinhas(Matriz *mat) {
  return mat->lin;
}

int ncolunas(Matriz *mat) {
  return mat->col;
}

#endif