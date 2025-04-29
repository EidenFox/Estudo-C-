#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>





int main() {
    SetConsoleOutputCP(CP_UTF8);

	float n1, n2;
	int n3, n4;
	
	printf("Digite o primeiro numero: ");
	scanf("%f", &n1);
	printf("Digite o segundo numero: ");
	scanf("%f", &n2);
	
	n3 = n1;
	n4 = n2;
	printf("%d", n3);
	printf("\n%d", n4);
	
	printf("\nO Resultado da soma é: %.2f", n1 + n2);
	printf("\nO Resultado da subtração é: %.2f", n1 - n2);
	printf("\nO Resultado da divisão é: %.2f", n1 / n2);
	printf("\nO Resultado da mutiplicaçã é: %.2f", n1 * n2);
	printf("\nO Resto da divisão é: %d", n3 % n4);
	
	


    return 0;
}
