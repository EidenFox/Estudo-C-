#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

// Programs will be made in both Portuguese and English
// Programas serão feitos em Português e Inglês

	//we're considering the legal age and voting age in Brazil which are: 18 for drinking and 16 for voting
	

int main() {
    SetConsoleOutputCP(CP_UTF8);

	int age;
	
	printf("Digite sua Idade:");
	printf("\nType your Age:\n");
	scanf("%d", &age);
	
	if (age < 16){
		printf("com %d anos você é Menor de idade!", age);
		printf("\nWith %d years you are Underage!", age);
	} else if (age < 18){
		printf("Com %d anos você é Menor de idade mas PODE Votar!", age);
		printf("\nWith %d years you are Underage but you CAN Vote!", age);
	} else {
		printf("Com %d anos você é Maior de Idade!", age);
		printf("\nWith %d years you are of Age!", age);
	}



    return 0;
}
