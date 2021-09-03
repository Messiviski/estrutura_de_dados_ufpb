#include <stdio.h>
#include <math.h>

struct roots {
  int firstRoot;
  int secondRoot;
};

typedef struct roots Roots;

double delta(int, int, int);
Roots equationRoots(double, int, int);

int main(){
  int firstElement = 0, secondElement = 0, thirdElement = 0;
  double deltaResult = 0;
  Roots solution;

  printf("Vamos montar a equacao!\n");
  printf("Digite o valor a: ");
  scanf("%d", &firstElement);

  printf("Digite o valor b: ");
  scanf("%d", &secondElement);

  printf("Digite o valor c: ");
  scanf("%d", &thirdElement);

  deltaResult = delta(firstElement, secondElement, thirdElement);

  solution = equationRoots(deltaResult, firstElement, secondElement);

  printf("As raizes encontradas foram: \n");
  printf("Primeira Raiz: %d\n", solution.firstRoot);
  printf("Segunda Raiz: %d\n", solution.secondRoot);
}

double delta(int a, int b, int c) {
  double deltaResult = ( b * b) - ( 4 * a * c );

  return deltaResult;
}

Roots equationRoots(double deltaValue, int a, int b) {
  Roots equationResults;
  equationResults.firstRoot = ( ( -b + sqrt(deltaValue) ) / 2 * a );
  equationResults.secondRoot = ( ( -b - sqrt(deltaValue) ) / 2 * a );

  return equationResults;
}