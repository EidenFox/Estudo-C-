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
    
    //Gera uma seed de valor aleatório baseado no tempo
    srand(time(NULL));
    
    //variaveis
    int res, count;
    int i = 0;
    int j = 0;
    int limit, x, sec;
    int dist;
    
    //Definit valores iniciais e limites de tentativas
    printf("Digite o numero maximo do jogo (de 0 a _ ): ");
    scanf("%d", &x);
    printf("Digite o numero de tentativas permitidas: ");
    scanf("%d", &limit);
    
    //decide um numero aleatoriamente para o jogo
    sec = (rand() % x);
    
    //vetor "tentativas" para guartar as tentativas ja feitas 
	//(a quantidade do vetor é = ao numero maximo de tentativas para não faltar nem disperdiçar memória)
    int tentativas[limit];
    
    //contador para rodar o programa até o numero limite de tentativas se exceder (a menos que seja parado por um "Break")
    for (j = 0; j < limit; j++){
    	
    	
    	printf("Números Já usados:\n");
    	//Esvreve na tela os numeros ja tentados ("[1] [4] [...]")
    	for (count = 0; count < i; count++){
    		printf("[%d] ", tentativas[count]);
		}
		
		//Lê o palpite do jogador		
    	printf("\nDigite um Número entre 0 e %d: \n", x);
    	scanf("%d", &res);
    	
    	//se o palpite por igual ao numero secreto encerra o jogo com o comando "break;" saindo do "for" (laço de repetição)
    	if (res == sec){
    		printf("Parabêns, você Ganhou!");
    		break;
		}else{
			//caso a resposta não esteja correta limpa a tela e executa os processos sobre resposta incorreta
    		system("cls");
			
			//Calcula a distancia entre o palpite e a resposta
			dist = res - sec;
			//printf ("\ndistance: %d\n", dist);
			
			//se a distancia for negativa pega o valor absoluto da distância
			// (ex: palpite = 5; resposta = 20;	distancia = -15; distancia absoluta = 15 )
			if (dist < 0){
				dist = dist * -1;
				//printf("Absolute distance: %d \n\n", dist);
			}
			
			//Mais facil: "abs();" (Absolute), apenas o numero positivo. ex: abs(-15); = 15			
			//dist = abs (dist)
			
			// Checa a distancia entre o palpite e a resposta e manda uma mensagem sobre
			if (dist <= 5){
				printf("O numero %d está Quente\n", res);
			}else if (dist <= 10){
				printf("numero %d está Morno\n", res);
			}else{
				printf("Numero %d está frio\n", res);
			}
			
			//Incrementa o "i" que determina a posição do vetor da tentativa
			tentativas[i] = res;
			i++;
			//adiciona o palpite atual à lista de tentativas ja efetuavas (vetor tentativa na posição atual)
		}
    	
	}
	
	printf("\n\nNumero correto %d", sec);





    return 0;
}
