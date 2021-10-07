#include <stdio.h>

int main() {
  int userValue = 0, result = 0;

  printf("Digite um número: ");
  scanf("%d", &userValue);

  for (int i = 2; i < userValue; i++) {
    if( userValue % i == 0 ) {
      result++;
      break;
    }
  }

  if(result == 0){
    printf("O número digitado é um número primo!\n");
  } else {
    printf("O número digitado não é um número primo!\n");
  }
}