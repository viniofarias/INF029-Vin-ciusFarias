#include <stdio.h>
#include <string.h>
#define max_Alunos 5
#define max_Prof 5

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

typedef struct Cadastro {
  int Matricula;
  char Nome[30];
  char CPF[15];
  char Sexo;
  data dataNasc;
} Cadastro;

/*typedef struct {
  int Matricula;
  char Nome[30];
  char CPF[15];
  char Sexo;
  data dataNasc;
} Professor;*/

int menuGeral(void);
int menuAluno(void);
int menuProf(void);
int menuRelatorio(void);
void cadastro(struct Cadastro *listaAlunos, int numero_Aluno);
int excluirCadastro(struct Cadastro *listaAlunos, int matricula, int numero_Aluno);

int main(void) {
  Cadastro listaAlunos[max_Alunos];
  Cadastro listaProf[max_Prof];
  int opcao = 1, numero_Aluno = 0, numero_Prof = 0;
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
		            cadastro(listaAlunos, numero_Aluno);
		            numero_Aluno++;
		          }
		          break;
		        }
		        case 2: {
		          int validaPosicao = 0;
		          puts("Editar Aluno");
		          while (1) {
		            puts("Digite a posição do Aluno cadastrado na lista que você quer "
		                 "Editar");
		            scanf("%d", &validaPosicao);
		            if (validaPosicao < numero_Aluno) {
		              cadastro(listaAlunos, validaPosicao);
		              break;
		            } else {
		              puts("A posição não existe ou não possuem aluno cadastrado");
		            }
		          }
		          break;
		        }
		        case 3: {
		          puts("Deletar Aluno");
		          setbuf(stdin, 0);
		          int matricula = 0;
		          int validaMatricula = 0;
		          while (1) {
		            puts("Digite a matrícula do Aluno cadastrado que voce deseja "
		                 "DELETAR");
		            scanf("%d", &matricula);
		            validaMatricula =
		                excluirCadastro(listaAlunos, matricula, numero_Aluno);
		            if (validaMatricula == 1) {
		              puts("Aluno deletado");
		              numero_Aluno--;
		              break;
		            } else {
		              puts("******A matrícula digitada ainda não existe******");
		            }
		          }
		          break;
		        }
		        default:{
		          puts("Opção Inválida");
		          break;
		        }
	        }
	      }
	      break;
	    }
	    case 2: {
	      puts("modulo professor");
	      int opcaoProf = 1;
	      while (opcaoProf != 0) {
	        opcaoProf = menuProf();
	
	        switch (opcaoProf) {
		        case 0: {
		          break;
		        }
		        case 1: {
		          puts("Inserir Professor");
		          if (numero_Prof == max_Prof) {
		            puts("A lista de Professores está cheia");
		          } else {
		            cadastro(listaProf, numero_Prof);
		            numero_Prof++;
		          }
		          break;
		        }
		        case 2: {
		          int validaPosicao = 0;
		          puts("Editar Professor");
		          while (1) {
		            puts("Digite a posição do Professor cadastrado na lista que você quer "
		                 "Editar");
		            scanf("%d", &validaPosicao);
		            if (validaPosicao < numero_Prof) {
		              cadastro(listaProf, validaPosicao);
		              break;
		            } else {
		              puts("A posição não existe ou não possui professor cadastrado");
		            }
		          }
		          break;
		        }
		        case 3: {
		          puts("Deletar professor");
		          setbuf(stdin, 0);
		          int matricula = 0;
		          int validaMatricula = 0;
		          while (1) {
		            puts("Digite a matrícula do professor cadastrado que voce deseja "
		                 "DELETAR");
		            scanf("%d", &matricula);
		            validaMatricula =
		                excluirCadastro(listaProf, matricula, numero_Prof);
		            if (validaMatricula == 1) {
		              puts("Professor deletado");
		              numero_Prof--;
		              break;
		            } else {
		              puts("******A matrícula digitada ainda não existe******");
		            }
		          }
		          break;
		        }
		        default: {
		          puts("Opção INVÁLIDA");
		          break;
		        }
	        }
	      }
	      break;
	    }
	    case 3: {
	      puts("modulo disciplina");
	      break;
	    }
	    case 4: {
	      puts("modulo Relatórios");
	      int opcaoRelatorio = 1;
	      while(opcaoRelatorio != 0){
	        opcaoRelatorio = menuRelatorio();
	        switch (opcaoRelatorio){
	          case 0:{
	            break;
	          }
	          case 1:{
	            for (int i = 0; i < numero_Aluno; i++) {
	              if (listaAlunos[i].Matricula != 0) {
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
	          case 2:{
	            for (int i = 0; i < numero_Prof; i++) {
	              if (listaProf[i].Matricula != 0) {
    	          printf("\n%d\n", listaProf[i].Matricula);
    	          printf("%s\n", listaProf[i].Nome);
    	          printf("%s\n", listaProf[i].CPF);
    	          printf("%c\n", listaProf[i].Sexo);
    	          printf("%d/%d/%d\n", listaProf[i].dataNasc.dia,
    	                 listaProf[i].dataNasc.mes, listaProf[i].dataNasc.ano);
      	        }
      	      }
      	      break;
	          }
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

int menuProf() {
  int select = 0;
  printf("Selecione uma opção\n");
  printf("voltar -- 0\n");
  printf("Inserir Professor -- 1\n");
  printf("Editar Professor -- 2\n");
  printf("Deletar Professor -- 3\n");
  scanf("%d", &select);
  return select;
}

int menuRelatorio(){
  int select = 0;
  printf("Selecione uma opção\n");
  printf("voltar -- 0\n");
  printf("listar Alunos -- 1\n");
  printf("listar Professores -- 2\n");
  printf("Listar Disciplinas -- 3\n");
  scanf("%d", &select);
  return select;
}

void cadastro(struct Cadastro *lista, int numero) {
  setbuf(stdin, 0);
  int ln = 0;
  char validacpf[15];
  int cpfvalido = 0;
  int validaMatricula;

  while (1) {
    puts("digite a matricula");
    scanf("%d", &validaMatricula);
    if (validaMatricula > 0) {
      lista[numero].Matricula = validaMatricula;
      break;
    }
    puts("Matricula inválida");
  }

  puts("digite o Nome");
  getchar();
  fgets(lista[numero].Nome, 30, stdin);
  ln = strlen(lista[numero].Nome) - 1;
  if (lista[numero].Nome[ln] == '\n') {
    lista[numero].Nome[ln] = '\0';
  }

  while (cpfvalido == 0) {
    puts("digite o cpf: ");
    scanf("%s", validacpf);
    if (validacpf[3] == '.' && validacpf[7] == '.' && validacpf[11] == '-') {
      strcpy(lista[numero].CPF, validacpf);
      cpfvalido = 1;
    } else {
      puts("CPF INVÁLIDO");
    }
  }

  puts("digite o sexo");
  getchar();
  scanf("%c", &lista[numero].Sexo);
  puts("digite a data de nascimento");
  scanf("%d%d%d", &lista[numero].dataNasc.dia,
        &lista[numero].dataNasc.mes,
        &lista[numero].dataNasc.ano);
}

int excluirCadastro(struct Cadastro *lista, int matricula, int numero) {
  for (int repeat = 0; repeat < numero; repeat++) {
    if (matricula == lista[repeat].Matricula) {
      lista[repeat].Matricula = 0;
      lista[repeat].Nome[0] = '\0';
      lista[repeat].CPF[0] = '\0';
      lista[repeat].Sexo = '\0';
      lista[repeat].dataNasc.dia = 0;
      lista[repeat].dataNasc.mes = 0;
      lista[repeat].dataNasc.ano = 0;

      for (int reposiciona = repeat; reposiciona < numero - 1;
           reposiciona++) {
        lista[reposiciona].Matricula =
            lista[reposiciona + 1].Matricula;
        strcpy(lista[reposiciona].Nome,
               lista[reposiciona + 1].Nome);
        strcpy(lista[reposiciona].CPF, lista[reposiciona + 1].CPF);
        lista[reposiciona].Sexo = lista[reposiciona + 1].Sexo;
        lista[reposiciona].dataNasc.dia =
            lista[reposiciona + 1].dataNasc.dia;
        lista[reposiciona].dataNasc.mes =
            lista[reposiciona + 1].dataNasc.mes;
        lista[reposiciona].dataNasc.ano =
            lista[reposiciona + 1].dataNasc.ano;
      }
      break;
    }
  }
	return 1;
}
