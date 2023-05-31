#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

Celula vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {

  // se posição é um valor válido {entre 1 e 10}
  if (posicao - 1 < 0 || posicao - 1 > 9)
    return POSICAO_INVALIDA;

  // o tamanho nao pode ser menor que 1
  if (tamanho < 1 || tamanho > TAM)
    return TAMANHO_INVALIDO;

  // a posicao pode já existir estrutura auxiliar
  if (vetorPrincipal[posicao - 1].vetorAux != NULL)
    return JA_TEM_ESTRUTURA_AUXILIAR;

  // o tamanho ser muito grande
  vetorPrincipal[posicao - 1].vetorAux = (int *)malloc(tamanho * sizeof(int));
  if (!vetorPrincipal[posicao - 1].vetorAux)
    return SEM_ESPACO_DE_MEMORIA;

  // deu tudo certo, crie
  vetorPrincipal[posicao - 1].tamanho = tamanho;
  return SUCESSO; // Vetor auxiliar criado
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  int retorno = 0;
  if (posicao - 1 < 0 || posicao - 1 > 9)
    retorno = POSICAO_INVALIDA;
  else {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao - 1].vetorAux != NULL) {
      if (vetorPrincipal[posicao - 1].topo <
          vetorPrincipal[posicao - 1].tamanho) {
        vetorPrincipal[posicao - 1].vetorAux[vetorPrincipal[posicao - 1].topo] =
            valor;
        vetorPrincipal[posicao - 1].topo++;
        retorno = SUCESSO;
      } else {
        retorno = SEM_ESPACO;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }

  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int retorno = 0;
  if (posicao - 1 < 0 || posicao - 1 > 9)
    retorno = POSICAO_INVALIDA;
  else {
    if (vetorPrincipal[posicao - 1].vetorAux != NULL) {
      if (vetorPrincipal[posicao - 1].topo == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      else {
        vetorPrincipal[posicao - 1].topo--;
        retorno = SUCESSO;
      }
    } else
      retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  int retorno = 0;
  int buffer = -1;
  if (posicao - 1 < 0 || posicao - 1 > 9)
    retorno = POSICAO_INVALIDA;
  else {
    if (vetorPrincipal[posicao - 1].vetorAux != NULL) {
      if (vetorPrincipal[posicao - 1].topo == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      else {
        for (int i = 0; i <= vetorPrincipal[posicao - 1].topo; i++) {
          if (vetorPrincipal[posicao - 1].vetorAux[i] == valor) {
            buffer = i;
            i = vetorPrincipal[posicao - 1].topo + 1;
          }
        }
        if (buffer == -1)
          retorno = NUMERO_INEXISTENTE;
        else {
          for (int i = buffer; i < (vetorPrincipal[posicao - 1].topo); i++) {
            vetorPrincipal[posicao - 1].vetorAux[i] =
                vetorPrincipal[posicao - 1].vetorAux[i + 1];
            vetorPrincipal[posicao - 1].topo--;
            retorno = SUCESSO;
          }
        }
      }
    } else
      retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  if (posicao < 1 || posicao > 10) {
    return POSICAO_INVALIDA;
  }
  if (vetorPrincipal[posicao - 1].vetorAux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  for (int i = 0; i < vetorPrincipal[posicao - 1].topo; i++) {
    vetorAux[i] = vetorPrincipal[posicao - 1].vetorAux[i];
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  int k, j, aux;
  if (posicao < 1 || posicao > 10) {
    return POSICAO_INVALIDA;
  }
  if (vetorPrincipal[posicao - 1].vetorAux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  for (int i = 0; i < vetorPrincipal[posicao - 1].topo; i++) {
    vetorAux[i] = vetorPrincipal[posicao - 1].vetorAux[i];
  }

  for (k = 1; k < vetorPrincipal[posicao - 1].topo; k++) {
    aux = vetorAux[k];
    j = k - 1;
    while (j >= 0 && aux < vetorAux[j]) {
      vetorAux[j + 1] = vetorAux[j];
      j--;
    }

    vetorAux[j + 1] = aux;
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int contador = 0;
  int j = 0;
  for (int i = 0; i < 10; i++) {
    if (vetorPrincipal[i].topo == 0)
      contador++;
  }
  if (contador == 10)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  else {
    for (int i = 0; i < 10; i++) {
      if (vetorPrincipal[i].vetorAux != NULL) {
        for (int k = 0; k < vetorPrincipal[i].topo; k++) {
          vetorAux[j] = vetorPrincipal[i].vetorAux[k];
          j++;
        }
      }
    }
    return SUCESSO;
  }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int x, y, aux;
  int contador = 0;
  int j = 0;
  for (int i = 0; i < 10; i++) {
    if (vetorPrincipal[i].topo == 0)
      contador++;
  }
  if (contador == 10)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  else {
    for (int i = 0; i < 10; i++) {
      if (vetorPrincipal[i].vetorAux != NULL) {
        for (int k = 0; k < vetorPrincipal[i].topo; k++) {
          vetorAux[j] = vetorPrincipal[i].vetorAux[k];
          j++;
        }
      }
    }
    for (x = 1; x < j; x++) {
      aux = vetorAux[x];
      y = x - 1;
      while (y >= 0 && aux < vetorAux[y]) {
        vetorAux[y + 1] = vetorAux[y];
        y--;
      }

      vetorAux[y + 1] = aux;
    }
    return SUCESSO;
  }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;
  if (vetorPrincipal[posicao - 1].vetorAux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
  if ((vetorPrincipal[posicao - 1].tamanho + novoTamanho) < 1)
    return NOVO_TAMANHO_INVALIDO;

  vetorPrincipal[posicao - 1].vetorAux = realloc(
      vetorPrincipal[posicao - 1].vetorAux,
      sizeof(int) * (vetorPrincipal[posicao - 1].tamanho + novoTamanho));
  vetorPrincipal[posicao - 1].tamanho =
      (vetorPrincipal[posicao - 1].tamanho + novoTamanho);
  if (vetorPrincipal[posicao - 1].topo > vetorPrincipal[posicao - 1].tamanho)
    vetorPrincipal[posicao - 1].topo = vetorPrincipal[posicao - 1].tamanho;
  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
  int quantidade = 0;
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;
  if (vetorPrincipal[posicao - 1].vetorAux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
  if (vetorPrincipal[posicao - 1].topo == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;
  quantidade = vetorPrincipal[posicao - 1].topo;
  return quantidade;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {
  int contador = 0;
  int qtdeElementos = 0;
  for (int i = 0; i < 10; i++) {
    if (vetorPrincipal[i].topo > 0)
      contador++;
  }
  if (contador == 0)
    return NULL;
  else {
    No *inicio = malloc(sizeof(No));
    inicio->prox = NULL;
    for (int i = 0; i < 10; i++) {
      if (getQuantidadeElementosEstruturaAuxiliar(i) > 0)
        qtdeElementos += getQuantidadeElementosEstruturaAuxiliar(i);
    }
    int vet[qtdeElementos];
    getDadosDeTodasEstruturasAuxiliares(vet);
    for (int i = 0; i < qtdeElementos; i++) {
      No *novo = malloc(sizeof(No));
      novo->conteudo = vet[i];
      novo->prox = NULL;
      if (inicio->prox == NULL) {
        inicio->prox = novo;
      } else {
        No *atual = inicio;
        while (atual->prox != NULL) {
          atual = atual->prox;
        }
        atual->prox = novo;
      }
    }
    return inicio;
  }
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
  No *atual = inicio;
  int i = 0;
  atual = atual->prox;
  while (atual->prox != NULL) {
    vetorAux[i] = atual->conteudo;
    atual = atual->prox;
    i++;
  }
  vetorAux[i] = atual->conteudo;
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
  No *atual = *inicio;
  No *buffer = NULL;
  while (atual->prox != NULL) {
    buffer = atual->prox;
    free(atual);
    atual = buffer;
  }
  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < 10; i++) {
    vetorPrincipal[i].vetorAux = NULL;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  for (int i = 0; i < 10; i++) {
    vetorPrincipal[i].vetorAux = NULL;
  }
}