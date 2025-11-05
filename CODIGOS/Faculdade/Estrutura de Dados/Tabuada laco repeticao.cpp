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


int main() {
    SetConsoleOutputCP(CP_UTF8);

	/*RESPOSTA QUESTÃO 6*/
	int num, res;
		
		printf("Digite numero: ");
		scanf ("%d", &num);
		
	for (int i = 0; i < 10; i++){
//		printf("teste");
		res = (i+1) * num;
		printf("%d * %d = %d\n", num, i+1, res);
	}
	/*RESPOSTA QUESTÃO 6*/
	/*------------------*/
	/*RESPOSTA QUESTÃO 7*/
	int numero;
	
	do{
		printf("Digite um numero: ");
		scanf("%d", &numero);	
	}while((numero <= 0) && (numero <= 100));
	
	/*RESPOSTA QUESTÃO 7*/


    return 0;
}
