#include <stdio.h>
#include "ponto.h"

int main(void) {
  Ponto * primeiro_ponto = cria_ponto(2.0f, 1.0f);
  Ponto * segundo_ponto = cria_ponto(3.4f, 2.1f);

  float distancia = calcula_distancia(primeiro_ponto, segundo_ponto);

  if(distancia >= 0){
    printf("Distancia entre pontos %f\n", distancia);
  } else {
    printf("Falha na memória: %f\n", distancia);
  }

  libera_ponto(primeiro_ponto);
  libera_ponto(segundo_ponto);
}