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
    
    int secret, guess, tries, i;
	
	printf("Numero secreto (1 a 10): \n");
	printf("Secret Number (1 to 10): \n");
	scanf("%d", &guess);
	
	printf("Numero de tentativas:\n");
	printf("Number of tries:\n");
	scanf("%d", &tries);
	
	sleep (5);
	system ("cls");
	
	
	
	
	for (i=1; i<= tries; i++){
		printf("Digite seu Palpite (1 a 10):\n");
		printf("Type your guess (1 to 10):\n");
		
		scanf("%d", &guess);
		
		if(guess == secret){
			printf("Parabéns, Você Ganhou");
			break;	
		} else {
			printf ("Que Pena, Tente novamente\n");
			printf ("Too bad, Try again");
			sleep (5);
			system ("cls");
		}
	}
	
	if(guess != secret){
		printf("Game Over!");
	}



    return 0;
}
