#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

#ifndef PONTO_C
#define PONTO_C

struct ponto {
  float c[2];
};

Ponto *cria_ponto(float x, float y) {
  Ponto* novo_ponto = NULL;
  novo_ponto = (Ponto*) malloc(sizeof(Ponto));
  if(!novo_ponto) return 0;

  novo_ponto->c[0] = x;
  novo_ponto->c[1] = y;

  return novo_ponto;
}

void libera_ponto(Ponto *ponto) {
  if(ponto) {
    free(ponto);
  }
}

int pega_ponto(Ponto *ponto, float *x, float *y) {
  if(ponto) {
    *x = ponto->c[0];
    *y = ponto->c[1];

    return 1;
  }

  return 0;
}

int seta_ponto(Ponto *ponto, float x, float y) {
  if(ponto) {
    ponto->c[0] = x;
    ponto->c[1] = y;

    return 1;
  }

  return 0;
}

float calcula_distancia(Ponto *primeiro_ponto, Ponto *segundo_ponto) {
  if(primeiro_ponto && segundo_ponto) {
    return (
      sqrt(
        pow(
          primeiro_ponto->c[0] - segundo_ponto->c[0], 2
        ) + 
        pow(
          primeiro_ponto->c[1] - segundo_ponto->c[1], 2
        )
      )
    );
  }

  return -1.0f;
}

#endif