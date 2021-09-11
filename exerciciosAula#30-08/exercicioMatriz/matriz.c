#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matriz.h"

#ifndef MATRIZ_C
#define MATRIZ_C

struct matriz {
  int lin;
  int col;
  float **valor;
};

// Ao inicializar um ponteiro ele 

Matriz *cria_matriz(int linhas, int colunas) {
  if(!(linhas > 0 && colunas > 0)) return 0;

  Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
  if(!mat) return 0;

  mat->lin = linhas;
  mat->col = colunas;
  mat->valor = (float**) malloc(colunas * sizeof(float*));
  if(!mat->valor) {
    free(mat);
    return 0;
  }

  // If it fails in the middle of the execution????
  for (int i = 0; i < colunas; i++) {
    mat->valor[i] = (float*) malloc(linhas * sizeof(float));
    if(!mat->valor[i]) {
      libera_matriz(&mat);
      return 0;
    }
  }
  
  return mat;
}

// Give to the aux variable the pointer that mat pointers
// By doing so the aux variable can be released
// After that, mat variable needs to pointer to NULL meaning that is empty

void libera_matriz(Matriz **mat) {
  Matriz* aux = *mat;

  if(aux) {
    for (int i = 0; i < aux->col; i++) {
      // Checks if it contains something
      if(aux->valor[i]) {
        free(aux->valor[i]);
      };
    }

    free(aux->valor);
    free(aux);

    *mat = NULL;
  }
}

// If returns 1 means that all goes as it should
// but if returns 0 it means that something went wrong

int acessa_matriz(Matriz *mat, int i, int j, float *valor_desejado) {

  if(mat->lin > 0 && mat->col > 0 ) {
    if(mat->valor[i] != NULL && mat->valor[i][j] > 0) {
      *valor_desejado = mat->valor[i][j];
      return 1;
    }
  }

  return 0;
}


// Checks if the columns and the lines are bigger than 0
// After that checks if the value i is null, and if the column value is bigger than 0

int atribui_matriz(Matriz *mat, int i, int j, float novo_valor) {

  if(mat->lin > 0 && mat->col > 0) {
    if(mat->valor[i] != NULL && mat->valor[i][j] == 0) {
      mat->valor[i][j] = novo_valor;

      return 1;
    }
  }
  
  return 0;
}

// Adicionar tratativa de erro
int nlinhas(Matriz *mat) {
  if(mat != NULL) {
    return mat->lin;
  }

  return 0;
}

int ncolunas(Matriz *mat) {
  if(mat != NULL) {
    return mat->col;
  }

  return 0;
}

#endif