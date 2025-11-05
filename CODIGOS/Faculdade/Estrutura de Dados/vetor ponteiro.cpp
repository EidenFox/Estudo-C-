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


void imprimir(int vet[], int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("%d ", vet[i]);
	}
}
void alterar(int vet[], int tam){
	int i;
	for(i=0; i<tam; i++){
		vet[i]=vet[i]*2;
	}
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
	
	int vet[10]={12,15,14,45,13,10,22,18,30,27};
	int tam=sizeof(vet)/sizeof(int);
	
	imprimir(vet, tam);
	alterar(vet, tam);
	printf("\n\n");
	imprimir(vet, tam);
	
	
	
	
	
	
	
	
}