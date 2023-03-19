#include <stdio.h>
#include <string.h>
#define max_Alunos 5
#define max_Prof 5



typedef struct{
  int dia;
  int mes;
  int ano;
} data;

typedef struct Aluno{
  int Matricula;
  char Nome[30];
  char CPF[15];
  char Sexo;
  data dataNasc;
} Aluno;

typedef struct{
  int Matricula;
  char Nome[30];
  char CPF[15];
  char Sexo;
  data dataNasc;
} Professor;

int menuGeral(void);
int menuAluno(void);
void cadastroAluno(struct Aluno* listaAlunos, int numero_Aluno);


int main(void) {
  Aluno listaAlunos[max_Alunos];
  Professor listaProf[max_Prof];
  int opcao = 1, numero_Aluno = 0;
  printf("Projeto Escola\n");
  while (opcao != 0) {
    opcao = menuGeral();
    switch (opcao) {
	    case 0: {
	      break;
	    }
	    case 1: {
	      puts("Modulo de Aluno: ");
	      int opcaoAluno = 1;
	      while (opcaoAluno != 0) {
	        opcaoAluno = menuAluno();
	        
	        switch (opcaoAluno) {
		        case 0: {
		          break;
		        }
		        case 1: {
		          puts("Inserir Aluno");
		          if (numero_Aluno == max_Alunos) {
		            puts("A lista de alunos está cheia");
		          } else {
		            cadastroAluno(listaAlunos, numero_Aluno);
		            numero_Aluno++;
		          }
		          break;
		        }
		        case 2: {
		          int validaPosicao = 0;
		          puts("Editar Aluno");
		          while(1){
		            puts("Digite a posição do Aluno cadastrado na lista que você quer Editar");
		            scanf("%d",&validaPosicao);
		            if(validaPosicao < numero_Aluno){
		              cadastroAluno(listaAlunos, validaPosicao);
		              break;
		            }else{
		              puts("A posição não existe ou não possuem aluno cadastrado");
		            }
		          }
		          break;
		        }
		        case 3: {
							int matricula = 0;
							int validaMatricula = 0;
		          puts("Deletar Aluno");
		          setbuf(stdin, 0);
		          while(1){
		            puts("Digite a matrícula do Aluno cadastrado que voce deseja DELETAR");
		            scanf("%d",&matricula);
		            for(int repeat = 0; repeat<numero_Aluno; repeat++){
		              if(matricula == listaAlunos[repeat].Matricula){
		                listaAlunos[repeat].Matricula = 0;
		                listaAlunos[repeat].Nome[0] = '\0';
		                listaAlunos[repeat].CPF[0] = '\0';
		                listaAlunos[repeat].Sexo = '\0';
		                listaAlunos[repeat].dataNasc.dia = 0;
		                listaAlunos[repeat].dataNasc.mes = 0;
		                listaAlunos[repeat].dataNasc.ano = 0;
		                
		                for(int reposiciona = repeat; reposiciona < numero_Aluno - 1; reposiciona++){
		                  listaAlunos[reposiciona].Matricula = listaAlunos[reposiciona+1].Matricula;
		                  strcpy(listaAlunos[reposiciona].Nome, listaAlunos[reposiciona+1].Nome);
		                  strcpy(listaAlunos[reposiciona].CPF, listaAlunos[reposiciona+1].CPF);
		                  listaAlunos[reposiciona].Sexo = listaAlunos[reposiciona+1].Sexo;
		                  listaAlunos[reposiciona].dataNasc.dia = listaAlunos[reposiciona+1].dataNasc.dia;
		                  listaAlunos[reposiciona].dataNasc.mes = listaAlunos[reposiciona+1].dataNasc.mes;
		                  listaAlunos[reposiciona].dataNasc.mes = listaAlunos[reposiciona+1].dataNasc.mes;
		                }
		                
		                validaMatricula = 1;
		                break;
		              }
		            }
		            if(validaMatricula == 1){
		              puts("Aluno deletado");
		              numero_Aluno--;
		              break;
		            }else{
		              puts("******A matrícula digitada ainda não existe******");
		            }
		          }
		          break;
		        }
	        }
	      }
	      break;
	    }
	    case 2: {
	      puts("modulo professor");
	      break;
	    }
	    case 3: {
	      puts("modulo disciplina");
	      break;
	    }
	    case 4: {
	      puts("modulo Relatórios");
	      for (int i = 0; i < numero_Aluno; i++) {
	        if(listaAlunos[i].Matricula != 0){
  	        printf("\n%d\n", listaAlunos[i].Matricula);
  	        printf("%s\n", listaAlunos[i].Nome);
  	        printf("%s\n", listaAlunos[i].CPF);
  	        printf("%c\n", listaAlunos[i].Sexo);
  	        printf("%d/%d/%d\n", listaAlunos[i].dataNasc.dia,
  	               listaAlunos[i].dataNasc.mes, listaAlunos[i].dataNasc.ano);
	        }
	      }
	      break;
	    }
	    default: {
	      puts("OPÇÃO INVÁLIDA");
	      break;
	    }
    }
  }
  return 1;
}

int menuGeral(void) {
  int select = 0;
  printf("Selecione uma opção\n");
  printf("Sair -- 0\n");
  printf("Aluno -- 1\n");
  printf("Professor -- 2\n");
  printf("Disciplina -- 3\n");
  printf("Relatórios -- 4\n");
  scanf("%d", &select);
  return select;
}

int menuAluno() {
  int select = 0;
  printf("Selecione uma opção\n");
  printf("voltar -- 0\n");
  printf("Inserir Aluno -- 1\n");
  printf("Editar Aluno -- 2\n");
  printf("Deletar Aluno -- 3\n");
  scanf("%d", &select);
  return select;
  
}
void cadastroAluno(struct Aluno* listaAlunos, int numero_Aluno){
    setbuf(stdin, 0);
    int ln = 0;
    char validacpf[15];
    int cpfvalido = 0;
    int validaMatricula;

    while (1) {
      puts("digite a matricula");
      scanf("%d", &validaMatricula);
      if (validaMatricula > 0) {
        listaAlunos[numero_Aluno].Matricula = validaMatricula;
        break;
      }
      puts("Matricula inválida");
    }

    puts("digite o nome do aluno");
    getchar();
    fgets(listaAlunos[numero_Aluno].Nome, 30, stdin);
    ln = strlen(listaAlunos[numero_Aluno].Nome) - 1;
    if (listaAlunos[numero_Aluno].Nome[ln] == '\n') {
      listaAlunos[numero_Aluno].Nome[ln] = '\0';
    }

    while (cpfvalido == 0) {
      puts("digite o cpf: ");
      scanf("%s", validacpf);
      if (validacpf[3] == '.' && validacpf[7] == '.' &&
          validacpf[11] == '-') {
        strcpy(listaAlunos[numero_Aluno].CPF, validacpf);
        cpfvalido = 1;
      } else {
        puts("CPF INVÁLIDO");
      }
    }

    puts("digite o sexo");
    getchar();
    scanf("%c", &listaAlunos[numero_Aluno].Sexo);
    puts("digite a data de nascimento");
    scanf("%d%d%d", &listaAlunos[numero_Aluno].dataNasc.dia,
          &listaAlunos[numero_Aluno].dataNasc.mes,
          &listaAlunos[numero_Aluno].dataNasc.ano);
}




