#include <stdio.h>

int soma(int n1, int n2);

int main(void) {
  int firstNumber = 0, secondNumber = 0, total = 0;
  printf("Digite o primeiro número: ");
  scanf("%d", &firstNumber);
  printf("Digite o segundo número: ");
  scanf("%d", &secondNumber);
  total = soma(firstNumber, secondNumber);   
  printf("A soma é: %d", total);
}

int soma(int n1, int n2){
  return n1+n2;
}