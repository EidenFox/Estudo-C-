#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


#define TAM 10


struct tipo_fila{
	int dados[TAM];
	int start = 0;
	int end = 0;
};

struct tipo_fila fila;

void enfileirar(int elemento){
	if (fila.end == TAM){
		cout << "Fila Cheia!" << endl;
		system("pause");
	}else{
		fila.dados[fila.end] = elemento;
		fila.end++;
	}
}

int desenfileirar(){
	int elemento;
	if (fila.end == fila.start){
		cout << "Fila Vazia!" << endl;
		system("pause");
	}else{
		elemento = fila.dados[fila.start];
		for (int i=0; i<fila.end; i++){
			fila.dados[i] = fila.dados[i+1];
		}
		fila.dados[fila.end] = 0;
		fila.end--;
	}
	return elemento;
}

void desenfileirar2(int elemento){
	int retorno;
	if (fila.end == fila.start){
		cout << "Fila Vazia!" << endl;
		system("pause");
	}else{
		for(int i = 0; i<fila.end; i++){
			if(elemento == fila.dados[i]){
				for (int j=i; j<fila.end; j++){
				fila.dados[j] = fila.dados[j+1];
				}
				fila.dados[fila.end] = 0;
				fila.end--;
				
				break;
			}
		}
	}
}


void mostrafila(){
	for (int i = 0; i < fila.end; i++){
		cout << "[" << fila.dados[i] << "]";
	}
	sleep(3);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
	int op, elemento;
	do{
		elemento = 0;
		system("cls");
		cout << "--------MENU--------\n[1]Adicionar Valor\n[2]Remover primeiro Valor\n[3]Mostrar Fila\n[4]Remover Valor Especifico\n[0]SAIR" << endl << "-> ";cin >> op;
		switch(op){
			case 1:
				cout << "Digite o elemento: ";cin >> elemento;
				enfileirar(elemento);
				break;
			case 2:
				elemento = desenfileirar();
				cout << "Elemento [" << elemento << "] removido!";
				break;
			case 3:
				mostrafila();
				break;
			case 4:
				cout << "Digite o valor que gostaria de remover da fila: "; cin >> elemento;
				desenfileirar2(elemento);
				mostrafila();
				break;
			case 0:
				system("cls");
				cout << "Saindo...";
				break;
			default:
				system("cls");
				cout << "Opção Invalida, tente novamente;";
				sleep(3);
		}
	}while(op != 0);



    return 0;
}
