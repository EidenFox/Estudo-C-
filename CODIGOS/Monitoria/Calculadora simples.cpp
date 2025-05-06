#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>



// Programs will be made in both Portuguese and English
// Programas serão feitos em Português e Inglês

int main() {
    SetConsoleOutputCP(CP_UTF8);

	float n1, n2;
	int n3, n4;
	
	printf("Digite o primeiro numero: \n");
		printf("Type the first number: \n");
	scanf("%f", &n1);
	
	printf("\nDigite o segundo numero: \n");
		printf("Type the second number: \n");
	scanf("%f", &n2);
	
	n3 = n1;
	n4 = n2;
	
	printf("\n\n\n--------------\nPortuguês\n\n");
	printf("\nO Resultado da soma é: %.2f", n1 + n2);
	printf("\nO Resultado da subtração é: %.2f", n1 - n2);
	printf("\nO Resultado da divisão é: %.2f", n1 / n2);
	printf("\nO Resultado da mutiplicaçã é: %.2f", n1 * n2);
	printf("\nO Resto da divisão é: %d", n3 % n4);
	
	printf("\n\n--------------\nEnglish\n\n");
	printf("\nThe Sum is: %.2f", n1 + n2);
	printf("\nThe Subtraction: %.2f", n1 - n2);
	printf("\nThe  Division is: %.2f", n1 / n2);
	printf("\nThe Multiply is: %.2f", n1 * n2);
	printf("\nThe Rest of the division is: %d", n3 % n4);


    return 0;
}
