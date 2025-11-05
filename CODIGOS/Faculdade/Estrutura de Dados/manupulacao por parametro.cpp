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


void imprimir(int vet[], int tam){
	for(int i = 0; i < tam; i++){
		cout << "[" << vet[i] << "] ";
	}
}

void alterar(int vet[], int tam){
	for(int i = 0; i < tam; i++){
		vet[i]=vet[i]+2;
	}
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

	int vet[15]={1,2,3,4,5,6,7,8,9,10};
	int tam = sizeof(vet)/sizeof(int);
	imprimir(vet, tam);
	alterar(vet, tam);
	cout << "\n";
	imprimir(vet, tam);



    return 0;
}
