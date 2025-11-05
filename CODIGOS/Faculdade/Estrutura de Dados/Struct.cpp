#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/

typedef struct dependente{
	char nome[50];
	char telefone[50];
	int idade;
}dependente;


typedef struct dadosPessoa{
	char nome[50];
	char email[50];
	int idade;
	char telefone[11];
	dependente dep;
	
}dadosPessoa;




int main() {
    SetConsoleOutputCP(CP_UTF8);

	dadosPessoa pessoa;


	printf("Digite o nome: ");
	gets(pessoa.nome);
	fflush(stdin);
	
	printf("Digite o email: ");
	gets(pessoa.email);
	fflush(stdin);
	
	printf("Digite o telefone: ");
	gets(pessoa.telefone);
	fflush(stdin);
	
	printf("Digite a idade: ");
	scanf("%d", &pessoa.idade);
	
	int choice;
	printf("Possui algum dependente? \n[1] SIM.\n[2] Não.\n");
	scanf("%d", &choice);
	
	
	if (choice == 1){
	
		fflush(stdin);
		printf("Digite o nome do dependente: ");
		gets(pessoa.dep.nome);
		fflush(stdin);
		
		printf("Digite o telefone do dependente: ");
		gets(pessoa.dep.telefone);
		fflush(stdin);
		
		printf("Digite a idade: ");
		scanf("%d", &pessoa.dep.idade);
	}


	system("cls");
	
	
	printf("\nNome: %s", pessoa.nome);
	printf("\nEmail: %s", pessoa.email);
	printf("\nTelefone: %s", pessoa.telefone);
	printf("\nIdade: %d", pessoa.idade);
	if(choice == 1){
		printf("\nNome do dependente: %s", pessoa.dep.nome);
		printf("\nTelefone do Dependente: %s", pessoa.dep.telefone);
		printf("\nIdade do Dependente: %d", pessoa.dep.idade);
	}else{
		printf("\nNenhum dependente cadastrado.");
	}

    return 0;
}
