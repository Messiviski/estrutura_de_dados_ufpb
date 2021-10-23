#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maior_valor(int *vetor, size_t tamanho);

int main(void) {
  int vetor_numeros[10] = {2, 1, 4, 6, 5, 10, 3, 7, 9, 8};

  // Ira dividir o tamanho do vetor pelo tamanho do primeiro elemento
  // Nesse caso o tamanho de um int e 4 bytes, o vetor tem 40 bytes
  // 40 / 10 = 4
  size_t tamanho_vetor = sizeof(vetor_numeros) / sizeof(vetor_numeros[0]);

  printf("Maior numero -> %d\n", maior_valor(vetor_numeros, tamanho_vetor));
}

int maior_valor(int *vetor, size_t tamanho) {
  int maior_numero = 0;

  for (int i = 0; i < tamanho; i++) {
    if(vetor[i] > maior_numero) maior_numero = vetor[i];
  }

  return maior_numero;
}