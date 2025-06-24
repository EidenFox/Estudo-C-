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

//	Declaração de variaveis	
//	Variable Declaration
	int i, num;
	
		printf ("Digite o valor para a multiplicação: \n");
		printf ("Type the value for the multiplication: \n");
		
//		Recebe o valor da variavel "num"
//		Get the variable valor
		scanf("%d", &num);
		
//	For, loop de repetição: for ( <inicio da variavel>; <condição de repetição>; <incremento> ) {}
//	For, Repetition loop: for ( <variable start>; <repetition condition>; <increment> ) {}	
	for (i=1; i<=10; i++){
		
//		escreve a resposta na tela, %d é substituido pelo valor inteiro de uma variavel. depois da virgula, fora das aspas, coloque as variaveis em ordem
//		print the answer on the screen, %d is replaced with the valor of the varable. after the commas, outside the quotation marks, you put the variables in order
		printf("%d * %d = %d \n", num, i, num*i);
	}




    return 0;
}
