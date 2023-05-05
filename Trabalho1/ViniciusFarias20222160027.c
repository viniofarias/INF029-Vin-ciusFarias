// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016vc 

// #################################################

#include "ViniciusFarias20222160027.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    if(data[i]>=48 && data[i]<=57){
			sDia[i] = data[i];
		}else{
			dq.valido = 0;
			return dq;
		}
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    if(data[j]>=48 && data[j]<=57){
			sMes[i] = data[j];
			i++;
		}else{
			dq.valido = 0;
			return dq;
		}
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    if(data[j]>=48 && data[j]<=57){
			sAno[i] = data[j];
			i++;
		}else{
			dq.valido = 0;
			return dq;
		}
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }


  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

	if(i==2){
		dq.iAno = dq.iAno + 2000;
	}
	
  dq.valido = 1;
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

int validaData(struct DQ *dataQuebrada){
	if(dataQuebrada->valido == 1){
		switch(dataQuebrada->iMes){
			case 1:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31)
					return 1;
				else{
					return 0;
				}
			}
			case 2:{
				if((dataQuebrada->iAno % 4 == 0) && !(dataQuebrada->iAno % 100 == 0^dataQuebrada->iAno % 400 == 0)){
					if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 29)
						return 1;
					else{
						return 0;
					}
				}else{
					if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 28)
						return 1;
					else{
						return 0;
					}
				}
			}
			case 3:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31){
					return 1;
				}else{
					return 0;
				}
			}
			case 4:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 30){
					return 1;
				}else{
					return 0;
				}
			}
			case 5:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31){
					return 1;
				}else{
					return 0;
				}
			}
			case 6:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 30){
					return 1;
				}else{
					return 0;
				}
			}
			case 7:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31){
					return 1;
				}else{
					return 0;
				}
			}
			case 8:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31){
					return 1;
				}else{
					return 0;
				}
			}
			case 9:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 30){
					return 1;
				}else{
					return 0;
				}
			}
			case 10:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31){
					return 1;
				}else{
					return 0;
				}
			}
			case 11:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 30){
					return 1;
				}else{
					return 0;
				}
			}
			case 12:{
				if(dataQuebrada->iDia > 0 && dataQuebrada->iDia <= 31){
					return 1;
				}else{
					return 0;
				}
			}
			default:{
				return 0;
			}
		}
	}else{
		return 0;
	}
}

int q1(char data[]) {
  int datavalida = 1;

  // quebrar a string data em strings sDia, sMes, sAno

  DataQuebrada dataQuebrada = quebraData(data);
  if (dataQuebrada.valido == 0) return 0;
	datavalida = validaData(&dataQuebrada);

  // printf("%s\n", data);

  if (datavalida)
    return 1;
  else
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */
int DiasMes(int mes, int ano){
	switch(mes){
		case 1:{
			return 31;
		}
		case 2:{
			if((ano % 4 == 0) && !(ano % 100 == 0^ano % 400 == 0)){
				return 29;
			}else{
				return 28;
			}
		}
		case 3:{
			return 31;
		}
		case 4:{
			return 30;
		}
		case 5:{
			return 31;
		}
		case 6:{
			return 30;
		}
		case 7:{
			return 31;
		}
		case 8:{
			return 31;
		}
		case 9:{
			return 30;
		}
		case 10:{
			return 31;
		}
		case 11:{
			return 30;
		}
		case 12:{
			return 31;
		}
		default:{
			return 0;
		}
	}
}

int DiasAno(int ano){
	if((ano % 4 == 0) && !(ano % 100 == 0^ano % 400 == 0)){
		return 366;
	}else{
		return 365;
	}
}

DiasMesesAnos q2(char datainicial[], char datafinal[]) {

  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
	DataQuebrada Dinicial = quebraData(datainicial);
	DataQuebrada Dfinal = quebraData(datafinal);
  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  } else if(Dinicial.iAno > Dfinal.iAno || (Dinicial.iAno == Dfinal.iAno)&&(Dinicial.iMes > Dfinal.iMes) || (Dinicial.iAno == Dfinal.iAno)&&(Dinicial.iMes == Dfinal.iMes)&&(Dinicial.iDia > Dfinal.iDia)) {
		dma.retorno = 4;
	}else{
    // verifique se a data final não é menor que a data inicial
		long int DiasFinal = (Dfinal.iAno * 365) + (Dfinal.iMes * 30) + Dfinal.iDia;
		long int DiasInicial = (Dinicial.iAno * 365) + (Dinicial.iMes * 30) + Dinicial.iDia;
		long int Dias = DiasFinal - DiasInicial;
		if(Dias >= 365){
			dma.qtdAnos = Dias / 365;
			if(Dias%365 >= 30){
				dma.qtdMeses = (Dias%365)/30;
				dma.qtdDias = (Dias%365)%30;
			}else{
				dma.qtdMeses = 0;
				dma.qtdDias = Dias%365;
			}
		}else if(Dias >= 30){
			dma.qtdAnos = 0;
			dma.qtdMeses = Dias/30;
			dma.qtdDias = Dias%30;
		}else{
			dma.qtdAnos = 0;
			dma.qtdMeses = 0;
			dma.qtdDias = Dias;
		}

    // calcule a distancia entre as datas

    // se tudo der certo
    dma.retorno = 1;
	}
  return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int sensitive(char x, char y){
	if(x == y+32 || y == x+32 || x==y){
		return 1;
	}else{
		return 0;
	}
}

int q3(char *texto, char c, int isCaseSensitive) {
	
  int qtdOcorrencias = 0;
	int size = strlen(texto);
	for(int i = 0; i<size; i++){
		if(isCaseSensitive == 1){
			if(texto[i] == c){
				qtdOcorrencias++;
			}
		}else{
			if(sensitive(texto[i], c)){
				qtdOcorrencias++;
			}
		}
	}
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int qtdOcorrencias = 0;
	int x = 0;
	int sizeTexto = strlen(strTexto);
	int sizeBusca = strlen(strBusca);

  for(int c = 0; strTexto[c] != '\0'; c++){
    if(strTexto[c] == -61){
      for(int i = c;strTexto[i] != '\0';i++){
        strTexto[i] = strTexto[i + 1];
      }
    }
  }
  for(int c = 0; strBusca[c] != '\0'; c++){
    if(strBusca[c] == -61){
      for(int i = c;strBusca[i] != '\0';i++){
        strBusca[i] = strBusca[i + 1];
      }
    }
  }
	
	for(int i=0, j=0	;	strTexto[i]	!=	'\0'	;	i++){ 
		if(strBusca[j]	==	strTexto[i]) 
			j++;
		else
			j=0;
		if(j	==	sizeBusca){ 
			j=0;
			posicoes[x]	=	i+1	- (sizeBusca-1); 
			x++;
			posicoes[x]	=	i+1; 
			qtdOcorrencias++;
			x++;
		}
	}
	return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
  int bufferNum = 0;
  int restoNum = 0;
  int expo = 10;
  int tamNum = Tamanho(num);
  bufferNum = 0;
  for (int i = tamNum; i > 0; i--) {
    restoNum = num % expo;
    num /= expo;
    restoNum *= pow(10, i - 1);
    bufferNum += restoNum;
  }
  num = bufferNum;
	return num; 
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */



int Tamanho(int num){
  int contador = 1;
  while(num > 9){
    num = num / 10;
    contador++;
  }
  return contador;
}

int q6(int numerobase, int numerobusca) {	

  int qtdocorrencias = 0;

  int Tambusca = Tamanho(numerobusca);

  int contador = 0, bufferBusca = numerobusca;
  
  while(numerobase !=  0){
    int restobase,restobusca;
    restobase=numerobase % 10;
    numerobase /= 10;
    if(bufferBusca / 10  !=  0){
      restobusca  = bufferBusca%10;
      bufferBusca  /= 10;
    }else{
      restobusca = bufferBusca%10;
      bufferBusca = numerobusca;
      
    }
    if(restobusca ==  restobase){
      contador++;
    }else{
      bufferBusca = numerobusca;
      contador=0;
    }
    if(contador == Tambusca){
      qtdocorrencias++;
      contador=0;
    }
    if(Tambusca ==  1){
      contador=0;
    }
  }
  return qtdocorrencias;
}
