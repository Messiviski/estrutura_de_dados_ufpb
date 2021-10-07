#include <stdio.h>

int main() {
  float firstGrade = 0, secondGrade = 0, thirdGrade = 0;
  double mean = 0;

  printf("Digite sua primeira nota: ");
  scanf("%f", &firstGrade);

  printf("Digite sua segunda nota: ");
  scanf("%f", &secondGrade);

  printf("Digite sua terceira nota: ");
  scanf("%f", &thirdGrade);

  mean = (firstGrade + secondGrade + thirdGrade) / 3;

  if(mean >= 4 && mean < 7) {
    printf("Sua media foi %.2f e voce ira para final!\n", mean);
  } else if(mean >= 7) {
    printf("Aprovado!\n");
  } else {
    printf("Só lamento :(\n");
  }
}