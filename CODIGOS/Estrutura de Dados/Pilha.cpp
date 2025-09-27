#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

//Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define TAM 10

struct tipoPilha{
	int dados[TAM];
	int ini, topo;
};

struct tipoPilha pilha;

void empilha(int elemento){
	if(pilha.topo == TAM){
		printf("Fila cheia.\n");
		system ("pause");
	}else{
		pilha.dados[pilha.topo] = elemento;
		pilha.topo++;
	}
}

int desempilha(){
	int elemento;
	if (pilha.topo == pilha.ini){
		printf("Fila vazia.\n");
		system("pause");
	}else{
		elemento = pilha.dados[pilha.topo-1];
		pilha.dados[pilha.topo]=NULL;
		pilha.topo--;
		return elemento;
	}
	return elemento;
}

void listaPilha(){
	if (pilha.topo == pilha.ini){
		printf("Pilha vazia.\n");
		system("pause");
	}else{
		printf("Pilha de valores:");
		for(int i = 0; i < pilha.topo; i++){
			printf("%d - ", pilha.dados[i]);
		}
		cout << endl;
		system("pause");
	}
}

void listaPilhaR(){
	if (pilha.topo == pilha.ini){
		printf("Pilha vazia.\n");
		system("pause");
	}else{
		printf("Pilha de valores:");
		for(int i = pilha.topo-1; i > pilha.ini-1; i--){
			cout << pilha.dados[i] << endl;			
		}
		cout << endl;
		system("pause");
	}
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
		int op, num;
		do{
			system("cls");
			cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
			cout << "[1] Inserir Valor" << endl;
			cout << "[2] Remover Valor" << endl;
			cout << "[3] Listar items" << endl;
			cout << "[4] Listar pilha de traz pra frente" << endl;
			cout << "[0] Sair" << endl;
			cin >> op;
		
			switch(op){
				case 1:
					cout << "qual valor deseja inserir? " << endl; cin >> num;
					empilha(num);
					break;
				case 2:
					cout << "Elemento removido: " << desempilha() << endl;
					system("pause");
					break;
				case 3:
					listaPilha();
					break;
				case 4:
					listaPilhaR();
					break;
				case 0:
					cout << "Saindo";
					for (int i = 0; i < 5; i++){
						Sleep(500);
						cout << ".";
					}
					break;
			}
		}while(op != 0);
    return 0;
}
