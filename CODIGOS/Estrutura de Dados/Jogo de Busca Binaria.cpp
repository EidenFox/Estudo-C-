#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/


int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    
    srand(time(NULL));
    
    int res, count;
    int i = 0;
    int j = 0;
    int limit, x, sec;
    
    printf("Digite o numero maximo do jogo (de 0 a _ ): ");
    scanf("%d", &x);
    printf("Digite o numero de tentativas permitidas: ");
    scanf("%d", &limit);
    
    sec = (rand() % x);
    
    int tentativas[limit];
  	
	  system("cls");  
    	puts("Explicação: Busca binária serve para encontrar um valor dentro de um numero grande de possibilidades");
    	puts("Este método consiste em cortar sempre pela metade o numero de possibilidades,\nescolhendo o numero do meio e checando se a resposta está acima ou abaixo");
    	puts("Ao checar o numero do meio, deve-se ignorar todos os valores opostos à checagem\n(de 1 a 20, testar 10, se o numero estiver a Cima, ignorar todos os numeros de 1 a 9)\n\n");
    	
    for (j = 0; j < limit; j++){
    	
    	printf("Números Já usados:\n");
    	for (count = 0; count < i; count++){
    		printf("[%d] ", tentativas[count]);
		}
    	printf("\nDigite um Número entre 0 e %d: \n", x);
    	scanf("%d", &res);
    	
    	if (res == sec){
    		printf("Parabêns, você Ganhou!");
    		break;
		}else{
			
    		system("cls");
			if (res > sec){
				printf("Numero está para Baixo");
			}else{
				printf("Numero está para Cima");
			}
			printf("\nO Número %d está incorreto, Tente novamente\n", res);
			tentativas[i] = res;
			i++;
		}
    	
	}
	
	printf("Numero correto %d", sec);





    return 0;
}
