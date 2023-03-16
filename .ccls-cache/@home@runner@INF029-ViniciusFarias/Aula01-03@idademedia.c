#include <stdio.h>

int main(void) {
  int N=0, soma=0;
  float media = 0;
  printf("Digite o valor de N ");
  scanf("%d", &N);
  printf("%d\n",N);
  int idade[N];
  for(int i = 0; i<N ; i++){
    printf("Digite a idade %d ", i+1);
    scanf("%d", &idade[i]);
  }
  for(int i=0; i<N; i++){
   soma += idade[i]; 
  }

  printf("%d\n", soma);
  printf("%d\n",N);
  media = soma/N;
  printf("%f\n", media);

  for(int i = 0; i<N; i++){
    if(idade[i]> media)
      printf("%d\n",idade[i]);
  }
  return 0;
}