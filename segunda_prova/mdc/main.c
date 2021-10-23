#include <stdio.h>

int mdc(int a, int b);

int main(void) {
  printf(" %d ", mdc(12, -5));
}

// Irá verificar o mdc dos valores recebidos através de recursao
// A cada chamada ira realizar algumas verificacoes e chamar de novo a funcao
// Passando o valor de b no primeiro argumento e o resto da divisao de
// a por b como segundo argumento ate que o segundo argumento seja 0
// Apos isso ira retornar o valor de a
int mdc(int a, int b) {
  if(b == 0) return a;
  else if(b < 0) return mdc(a, -b);

  return mdc(b, a % b);
}