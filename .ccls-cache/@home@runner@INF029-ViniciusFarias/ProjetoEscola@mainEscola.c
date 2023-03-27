#include <stdio.h>
#include <string.h>
#define max_Alunos 5
#define max_Prof 5
#define max_Disciplina 5

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

typedef struct Pessoa {
  int Matricula;
  char Nome[30];
  char CPF[15];
  char Sexo;
  data dataNasc;
} Pessoa;

typedef struct Disciplina {
  char Nome[30];
  int Codigo;
  int Semestre;
  int Matricula_Professor;
  int listaMatriculados[max_Alunos];
} Disciplina;

int menuGeral(void);
int menuAluno(void);
int menuProf(void);
int menuDisciplina(void);
int menuRelatorio(void);
void cadastro(struct Pessoa *lista, int numero);
int excluirCadastro(struct Pessoa *lista, int matricula, int numero);
void inserirDisciplina(struct Disciplina *listaDisciplina, struct Pessoa *listaProf, int numero_Prof, int numero_Disciplina);
int deletarDisciplina(struct Disciplina *listaDisciplina, int numero_Disciplina);
int inserirAlunoDisciplina(struct Disciplina *listaDisciplina, struct Pessoa *listaAlunos, int numero_Aluno, int numero_Disciplina, int numero_Matriculado);
int deletarAlunoDisciplina(struct Disciplina *listaDisciplina, int numero_Disciplina, int numero_Matriculado);
void listagem(struct Pessoa *lista, int numero);
void listagemDisciplina(struct Disciplina *listaDisciplina, struct Pessoa *listaProf, struct Pessoa *listaAlunos, int numero_Matriculado, int numero_Disciplina, int numero_Prof, int numero_Aluno);

int main(void) {
  Pessoa listaAlunos[max_Alunos];
  Pessoa listaProf[max_Prof];
	Disciplina listaDisciplina[max_Disciplina];
  int opcao = 1, numero_Aluno = 0, numero_Prof = 0, numero_Disciplina = 0, numero_Matriculado = 0;
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
				int opcaoDisciplina = 1;
				while(opcaoDisciplina !=0){
					opcaoDisciplina = menuDisciplina();
					switch (opcaoDisciplina){
						case 0:{
							break;
						}
						case 1:{
							if(numero_Disciplina == max_Disciplina){
								puts("******A lista de Disciplinas ja está completa******");
							}else if(numero_Prof == 0){
								puts("******É nescessário ter um professor cadastrado para Cadastrar uma Disciplina");
							}
							else{
								puts("===============Inserir Disciplina===============");
								inserirDisciplina(listaDisciplina, listaProf, numero_Prof, numero_Disciplina);
								numero_Disciplina++;
							}					
							break;
						}
						case 2:{
							int validaCodigo, disciplinaAtiva = 0, posicao;
							puts("===============Editar Disciplina===============");
							puts("Digite o código da Disciplina a ser editada");
							scanf("%d",&validaCodigo);
							for(int i = 0; i<numero_Disciplina; i++){
								if(listaDisciplina[i].Codigo == validaCodigo){
									disciplinaAtiva = 1;
									posicao = i;
									break;
								}
							}
							if(disciplinaAtiva == 1){
								inserirDisciplina(listaDisciplina, listaProf, numero_Prof, posicao);
							}else{
								puts("Essa disciplina ainda não existe");
							}
							break;
						}
						case 3:{
							puts("===============Deletar Disciplina===============");
							int deletaDisciplina = deletarDisciplina(listaDisciplina, numero_Disciplina);
							if(deletaDisciplina == 1){
								numero_Disciplina--;
							}else{
								puts("Código Inválido! Essa Disciplina ainda não existe");
							}
							break;
						}
						case 4:{
							int status = 0;
							if(numero_Aluno!=0 && numero_Matriculado<max_Alunos){
								status = inserirAlunoDisciplina(listaDisciplina,listaAlunos,numero_Aluno,numero_Disciplina,numero_Matriculado);
								if(status == 1){
									numero_Matriculado++;
								}
							}else{
								puts("Não foi possível inserir a matrícula");
							}
							break;
						}
						case 5:{
							int status = deletarAlunoDisciplina(listaDisciplina,numero_Disciplina,numero_Matriculado);
							if(status == 1){
								puts("Aluno removido da disciplina");
								numero_Matriculado--;
							}else{
								puts("Não foi possivel deletar aluno da disciplina");
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
							puts("=============Alunos Cadastrados=============");
							listagem(listaAlunos, numero_Aluno);
      	      break;
	          }
	          case 2:{
							puts("=============Professores Cadastrados=============");
	            listagem(listaProf, numero_Prof);
      	      break;
	          }
						case 3:{
							listagemDisciplina(listaDisciplina,listaProf,listaAlunos,numero_Matriculado,numero_Disciplina,numero_Prof,numero_Aluno);
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

int menuGeral() {
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

int menuDisciplina(){
  int select = 0;
  printf("Selecione uma opção\n");
  printf("voltar -- 0\n");
  printf("Inserir Disciplina -- 1\n");
  printf("Editar Disciplina -- 2\n");
  printf("Deletar Disciplina -- 3\n");
	printf("Inserir Aluno na Disciplina -- 4\n");
	printf("Excluiir Aluno da Disciplina -- 5\n");
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

void cadastro(struct Pessoa *lista, int numero) {
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

int excluirCadastro(struct Pessoa *lista, int matricula, int numero) {
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

void inserirDisciplina(struct Disciplina *listaDisciplina, struct Pessoa *listaProf, int numero_Prof, int numero_Disciplina){
	setbuf(stdin, 0);
	int ln = 0;
	int validaCodigo = 0, validaMatricula = 0, validaSemestre;
	puts("Digite o nome da disciplina: ");
	fgets(listaDisciplina[numero_Disciplina].Nome, 30, stdin);
	ln = strlen(listaDisciplina[numero_Disciplina].Nome) - 1;
	if (listaDisciplina[numero_Disciplina].Nome[ln] == '\n') {
		listaDisciplina[numero_Disciplina].Nome[ln] = '\0';
	}

	while(1){
		int codigoAtivo = 0;
		puts("Digite o código da disciplina: ");
		scanf("%d", &validaCodigo);
		if(validaCodigo > 0){
			for(int i = 0; i<numero_Disciplina; i++){
				if(listaDisciplina[i].Codigo == validaCodigo){
					codigoAtivo = 1;
					break;
				}
			}
			if(codigoAtivo == 0){
				listaDisciplina[numero_Disciplina].Codigo = validaCodigo;
				break;
			}else{
				puts("Esse código já existe");
			}
		}else{
			puts("Código Inválido");
		}
	}
	while(1){
		puts("Digite o semestre");
		scanf("%d", &validaSemestre);
		if(validaSemestre>0 && validaSemestre <= 13){
			listaDisciplina[numero_Disciplina].Semestre = validaSemestre;
			break;
		}else{
			puts("Semestre inválido");
		}		
	}


	while(1){
		int professorAtivo = 0;
		puts("Digite a matrícula do Professor");
		scanf("%d",&validaMatricula);

		for(int i = 0; i<numero_Prof;i++){									//Fazer função(Valida matricula);
			if(listaProf[i].Matricula == validaMatricula){
				listaDisciplina[numero_Disciplina].Matricula_Professor = validaMatricula;
				professorAtivo = 1;
				break;
			}
		}
		if(professorAtivo == 1){
			break;
		}else{
			puts("Essa matrícula não existe");
		}		
	}
}

int deletarDisciplina(struct Disciplina *listaDisciplina, int numero_Disciplina){
	int validaCodigo = 0, disciplinaAtiva = 0, posicao = 0;
	setbuf(stdin, 0);
	puts("Digite o codigo da disciplina que voce quer apagar");
	scanf("%d", &validaCodigo);
	for(int i = 0; i<numero_Disciplina;i++){
		if(listaDisciplina[i].Codigo == validaCodigo){
			disciplinaAtiva = 1;
			posicao = i;
			break;
		}
	}
	if(disciplinaAtiva == 1){
		listaDisciplina[posicao].Codigo = 0;
		listaDisciplina[posicao].Nome[0] = '\0';
		listaDisciplina[posicao].Semestre = 0;
		listaDisciplina[posicao].Matricula_Professor = 0;
		for(int repeat = 0; repeat<max_Alunos; repeat++){
			listaDisciplina[posicao].listaMatriculados[repeat] = 0;
		}
		for(int i = 0; i<numero_Disciplina - 1; i++){
			listaDisciplina[posicao].Codigo = listaDisciplina[posicao+1].Codigo;
			listaDisciplina[posicao].Semestre = listaDisciplina[posicao+1].Semestre;
			listaDisciplina[posicao].Matricula_Professor = listaDisciplina[posicao+1].Matricula_Professor;
			strcpy(listaDisciplina[posicao].Nome, listaDisciplina[posicao+1].Nome);
			for(int j = 0; j<max_Alunos; j++){
				listaDisciplina[posicao].listaMatriculados[j] = listaDisciplina[posicao+1].listaMatriculados[j];
			}
		}
		puts("Disciplina Deletada");
		return 1;
	}else{
		return 0;
	}
}

int inserirAlunoDisciplina(struct Disciplina *listaDisciplina, struct Pessoa *listaAlunos, int numero_Aluno, int numero_Disciplina, int numero_Matriculado){
	setbuf(stdin,0);
	int posicao = 0, validaCodigo = 0, validaMatricula = 0, statusMatricula = 0, existeCodigo = 0;
	puts("===============Cadastrar aluno na Disciplina===============");
	puts("Digite o código da disciplina");
	scanf("%d", &validaCodigo);
	for(int i = 0; i<numero_Disciplina; i++){
		if(listaDisciplina[i].Codigo == validaCodigo){
			posicao = i;
			existeCodigo = 1;
			break;
		}
	}
	if(existeCodigo == 1){
		puts("Digite a matricula do aluno a ser cadastrado na disciplina");
		scanf("%d", &validaMatricula);
		for(int i = 0; i<numero_Aluno; i++){
			if(listaAlunos[i].Matricula == validaMatricula){
				for(int j = 0; j<max_Alunos; j++){
					if(listaDisciplina[posicao].listaMatriculados[j] == validaMatricula){
						statusMatricula = 0;
						break;
					}else{
						statusMatricula = 1;
					}
				}
			}
		}
		if(statusMatricula == 1){
			puts("***ALUNO MATRICULADO***");
			listaDisciplina[posicao].listaMatriculados[numero_Matriculado] = validaMatricula;
			return  1;
		}else{
			puts("Matrícula Inválida!");
			return 0;
		}
	}else{
		puts("Não existe disciplina com esse código");
		return 0;
	}
}

int deletarAlunoDisciplina(struct Disciplina *listaDisciplina, int numero_Disciplina, int numero_Matriculado){
	int validaCodigo, posicaoDisciplina = 0, posicaoAluno = 0, validaMatricula;
	puts("===============Deletar aluno da Disciplina===============");
	puts("digite o codigo da disciplina que voce quer deletar o aluno");
	scanf("%d",&validaCodigo);
	for(int i = 0; i<numero_Disciplina; i++){
		if(listaDisciplina[i].Codigo == validaCodigo){
			posicaoDisciplina = i;
			break;
		}
	}
	puts("digite a matricula do aluno que voce quer deletar");
	scanf("%d",&validaMatricula);
	for(int i = 0; i<numero_Matriculado; i++){
		if(listaDisciplina[posicaoDisciplina].listaMatriculados[i] == validaMatricula){
			posicaoAluno = i;
		}
	}
	listaDisciplina[posicaoDisciplina].listaMatriculados[posicaoAluno] = 0;
	for(int i = posicaoAluno; i<numero_Matriculado-1;i++){
		listaDisciplina[posicaoDisciplina].listaMatriculados[i] = listaDisciplina[posicaoDisciplina].listaMatriculados[i+1];
	}
	return 1;
}

void listagem(struct Pessoa *lista, int numero){
	for (int i = 0; i < numero; i++) {
		if (lista[i].Matricula != 0) {
		printf("\n%d\n", lista[i].Matricula);
		printf("%s\n", lista[i].Nome);
		printf("%s\n", lista[i].CPF);
		printf("%c\n", lista[i].Sexo);
		printf("%d/%d/%d\n", lista[i].dataNasc.dia,
					 lista[i].dataNasc.mes, lista[i].dataNasc.ano);
		}
	}
}

void listagemDisciplina(struct Disciplina *listaDisciplina, struct Pessoa *listaProf, struct Pessoa *listaAlunos, int numero_Matriculado, int numero_Disciplina, int numero_Prof, int numero_Aluno){
	puts("=============Disciplinas Cadastradas=============");
	for(int i = 0; i<numero_Disciplina; i++){
		if(listaDisciplina[i].Codigo != 0){
			printf("\n%d\n", listaDisciplina[i].Codigo);
			printf("%s\n", listaDisciplina[i].Nome);
			printf("%d\n", listaDisciplina[i].Semestre);
			for (int j = 0; j < numero_Prof; j++) {
				if (listaProf[j].Matricula == listaDisciplina[i].Matricula_Professor) {
					puts("***Professor que leciona a Disciplina***");
					printf("\n%d\n", listaProf[j].Matricula);
					printf("%s\n", listaProf[j].Nome);
					printf("%s\n", listaProf[j].CPF);
					printf("%c\n", listaProf[j].Sexo);
					printf("%d/%d/%d\n", listaProf[j].dataNasc.dia,
								 listaProf[j].dataNasc.mes, listaProf[j].dataNasc.ano);
					break;
				}
			}
			puts("***Alunos Cadastrados***");
			for(int j = 0; j < numero_Matriculado; j++){
				for(int k = 0; k < numero_Aluno; k++){
					if(listaDisciplina[i].listaMatriculados[j] == listaAlunos[k].Matricula){
						printf("\n%d\n", listaAlunos[k].Matricula);
						printf("%s\n", listaAlunos[k].Nome);
						printf("%s\n", listaAlunos[k].CPF);
						printf("%c\n", listaAlunos[k].Sexo);
						printf("%d/%d/%d\n", listaAlunos[k].dataNasc.dia,
									 listaAlunos[k].dataNasc.mes, listaAlunos[k].dataNasc.ano);
					}
				}
			}
		}
	}
}