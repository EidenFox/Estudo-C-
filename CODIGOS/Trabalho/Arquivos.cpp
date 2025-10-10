#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>


/*DEFINIÇÃO DE CONSTANTES*/
#define ARQUIVO ".\\arquivos\\dados.txt"
#define LIMITE 100


FILE *pont_arq;

using namespace std;

typedef struct Pessoa{
	int id;
    char nome[50];
    int idade;
    string email;
} Pessoa;


void cadastrar(Pessoa Cadastro[]);




int main() {
    SetConsoleOutputCP(CP_UTF8);
	
	Pessoa Cadastro[LIMITE];
	char dataIn[100];
	int i;

	pont_arq = fopen (ARQUIVO, "w");
	
	if(pont_arq == NULL) {
       printf("Erro na abertura do arquivo!");
       return 1;
    } else cout << "Aqruivo aberto com sucesso!" << endl;
	
	
	cadastrar(Cadastro);


    return 0;
}



void cadastrar(Pessoa Cadastro[]){
	bool sair = false;
	char sairC;
	do{
		Cadastro.id -> 1;
		fprintf(pont_arq, "%d|", Cadastro.id);
		cout << "Digite o nome: " << cin >> Cadastro.nome;
		fprintf(pont_arq, "%s", Cadastro[i].nome);
	
	
		cout << "Realizar novo cadastro?\n[S/N]" << endl; cin >> sairC;
		if(tolower(sairC) == 's'){
			sair = true;
		}
	}while(!sair);	
	
}










