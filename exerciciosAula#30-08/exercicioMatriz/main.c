#include <stdio.h>
#include "matriz.h"

int main(void) {

  Matriz* matriz_principal = NULL;
  float valor_usuario = 0;
  
  matriz_principal = cria_matriz(10, 12);

  printf("Digite o valor que deseja atribuir: ");
  scanf("%f", &valor_usuario);

  if(atribui_matriz(matriz_principal, 1, 1, valor_usuario)) {
    printf("Valor atribuido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!!!\n");
  }

  printf("Digite um número que deseja acessar: ");
  scanf("%f", &valor_usuario);

  if(acessa_matriz(matriz_principal, 1, 1, &valor_usuario)) {
    printf("Valor -> %f\n", valor_usuario);
  } else {
    printf("Algo de errado aconteceu!!!\n");
  }

  libera_matriz(&matriz_principal);

  return 0;
}





// Perhaps the code is failing because of function scope
// Once the function is executed the variable is destroyed
// Should i pass it as an argument?