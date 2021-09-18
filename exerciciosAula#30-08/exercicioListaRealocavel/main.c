#include <stdio.h>
#include "vetor_realocavel.h"

int main(void) {
  VetorDin *novo_vetor = NULL;
  float valor_acessado = 0;

  novo_vetor = cria_vetor(10);

  if(insere_vetord(novo_vetor, 13.7f)) {
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Algo de errado aconteceu!");
  }

  if(acessa_vetord(novo_vetor, 0, &valor_acessado)) {
    printf("Valor -> %f\n", valor_acessado);
  } else {
    printf("Algo de errado aconteceu!\n");
  }

  printf("Elementos inseridos no vetor -> %d\n", tamanho_vetord(novo_vetor));

  libera_vetord(&novo_vetor);

  if(novo_vetor == NULL) printf("Vetor limpo com sucesso!!!\n");
}