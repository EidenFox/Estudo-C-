#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>


// Programs will be made in both Portuguese and English
// Programas serão feitos em Português e Inglês

int main() {
    SetConsoleOutputCP(CP_UTF8);

	int m, n;
	
		
	printf("Escreva o valor:");
	printf("\nType your number:\n");
	scanf("%d", &n);
	
	if( n == 0){
		printf("\nO numero %d não é Impar nem Par!\n", n);
		printf("The number %d in neither Odd nor Even!\n", n);
	}else if( n % 2 == 0){
		printf("\n\nO numero %d é Par!", n);
		printf("\nThe number %d is Even!", n);
	} else {
		printf("\n\nO numero %d é Impar!", n);
		printf("\nThe number %d is Odd!",n);
	}
	

    return 0;
}
