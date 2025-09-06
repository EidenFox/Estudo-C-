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
	
	int qtd, i;


	printf("Digite a quantidade de pessoas: ");
	scanf("%d", &qtd);

	float peso[qtd], altura[qtd], IMC[qtd];

	for(i=0; i<qtd; i++){
		printf("Digite o peso da pessoa %d: ", i+1);
		scanf("%f", &peso[i]);
		printf("Digite a altura da pessoa: %d ", i+1);
		scanf("%f", &altura[i]);
		
		IMC[i] = peso[i] / (altura[i]*altura[i]);
		
	}
	
	for (i=0; i<qtd; i++){
		printf("\n%i Pessoa\n", i+1);
		printf("Peso: %.2f\n", peso[i]);
		printf("Altura: %.2f\n", altura[i]);
		printf("IMC: %.2f\n", IMC[i]);
	}

    return 0;
}
