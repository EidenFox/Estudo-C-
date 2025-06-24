#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <string.h>

/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/


typedef struct {
	int idaluno;
	char nome[100];
	float telefone;
} alunos;


int main() {
    SetConsoleOutputCP(CP_UTF8);
	int i, id;
	
	alunos cadastro[10];
	
	for (i=0; i<2; i++){
	cadastro[i].idaluno = i+1;
	
	printf("\nDigite seu Nome: ");
	fflush(stdin);
	gets(cadastro[i].nome);
	
	printf("\nDigite seu Telefone: ");
	scanf("%f", &cadastro[i].telefone);
	
	system("cls");
	}

	printf("Dados Cadastrados:\n");
	
	for (i=0; i<10; i++){
		printf("\n-------------\n");
		printf("Id do Aluno: %d\n", cadastro[i].idaluno);
		printf("Nome do Aluno: %s\n", cadastro[i].nome);
		printf("Telefone do Aluno: %.0f\n", cadastro[i].telefone);
	
	}
	system("pause");
	system("cls");
	
	printf("Digite o Numero do ID que deseja alterar: ");
	scanf("%d", &id);
	for (i=0; i<10; i++){
		if(id == cadastro[i].idaluno){
	
			printf("\nDigite seu Nome: ");
			fflush(stdin);
			gets(cadastro[i].nome);
			
			printf("\nDigite seu Telefone: ");
			scanf("%f", &cadastro[i].telefone);
			
			break;	
		}
	}
		
			
	for (i=0; i<10; i++){
		printf("\n-------------\n");
		printf("Id do Aluno: %d\n", cadastro[i].idaluno);
		printf("Nome do Aluno: %s\n", cadastro[i].nome);
		printf("Telefone do Aluno: %.0f\n", cadastro[i].telefone);
	
	}


    return 0;
}
