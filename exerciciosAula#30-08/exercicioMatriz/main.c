#include <stdio.h>
#include "matriz.h"

int main(void) {

  Matriz* matriz_principal = NULL;
  float valor_usuario = 0;

  matriz_principal = cria_matriz(10, 12);

  // if(atribui_matriz(matriz_principal, 1, 1, 20)) {
  //   printf("Valor atribuido com sucesso!");
  // } else {
  //   printf("Algo de errado aconteceu!!!");
  // }

  // if(acessa_matriz(matriz_principal, 1, 1, &valor_usuario)) {
  //   printf("Valor atribuido com sucesso!\n");
  //   printf("Valor -> %f\n", valor_usuario);
  // } else {
  //   printf("Algo de errado aconteceu!!!");
  // }

  // libera_matriz(matriz_principal);

  return 0;
}