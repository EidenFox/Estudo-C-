#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define COLOR_PINK   "\x1b[35m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"


//Função para checar se o jogador quer jogar novamente
bool desejaContinuar(void) {
	char reset;
    cout << "\nDeseja jogar novamente? [s/n] ";
	cin >> reset;
    cin.ignore();
	reset = tolower(reset);
    if (reset == 's') {
        system("cls");
        return true; 
    }else{
    return false; 
	}
}

//Função para tratar os vetores trocando todas as letras por minusculas
void tratamento(char* palavra, int max){
	for (int i = 0; i < max; i++){
		palavra[i] = tolower(palavra[i]);
	}
}




// Função do jogo, quse toda a funcionalidade do jogo está aki
bool anotaTentativas(char tentativas[][100], char palpite[], char palavra[], int max, int jogada){
	int i, j, k;
	int ganhou = 0;
	bool quase = 0;
	
	//Pede ao jogador o palpite dele
	cout << endl << "\nDigite sua palavra:\n"; cin >> palpite;
	cin.ignore();
	system("cls");
	//substitui todas as letras por minusculas
	tratamento(palpite, max);
	
	//checa quantas letras corretas tem no palpite (para cada letra correta incrementa o "ganhou")
	for (i=0; i<max; i++){
		tentativas[jogada][i] = palpite[i];
		if(palpite[i] == palavra[i]){
			ganhou ++;
		}
	}
	
	//Escreve as regras do jogo (de novo ;-;)
	cout <<"Bem vindo ao jogo, seu objetivo é acertar a palavra abaixo\n";
	cout << COLOR_GREEN << "[*] Letras VERDES estão no lugar correto.\n";
	cout << COLOR_YELLOW << "[*] Letras AMARELAS estão no lugar errado.\n";
	cout << COLOR_RESET << "[*] Letras BRANCAS não estão na palavra.\n\n\n" << endl;
	
	//laço de repetição para escrever as linhas da tentativas na tela
	for (j=0; j<jogada+1; j++){
		cout << endl;
		
		//laço de repetição para escrever as colunas da tentativas na tela
		for (i=0; i<max; i++){
			//checa se a letra da tentativa está correta e, se estiver, escreve ela em VERDE
			if(tentativas[j][i] == palavra[i]){	
				cout << COLOR_GREEN << "[";
				cout << tentativas[j][i];
				cout << "] " << COLOR_RESET;
			//se não estiver correta...
			}else{
				//laço de repetição para comparar a letra atual da tentativa com TODAS as letras da palavra secreta
				for (k=0; k<max; k++){
					//se a letra atual for igual a alguma das letras da palavra secreta
					if(tentativas[j][i] == palavra[k]){
						//declara que existe (mesmo se houver letras repetidas continua = 1)
						quase = 1;
					}
				}
				//fora da repetição, se "quase = 1" escreve a letra atual da tentativa em AMARELO
				if (quase == 1){
					cout << COLOR_YELLOW << "[";
					cout << tentativas[j][i];
					cout << "] " << COLOR_RESET;
					//retorna o "quase" para 0 para próximo loop do laço
					quase = 0;
				//caso a letra atual nn seja nem correta e nem igual a outra letra da palavra, escreve ela em BRANCO
				}else{
					cout << "[";
					cout << tentativas[j][i];
					cout << "] ";
				}
				
			}
		}
	}
	cout << endl;
	//se a quantidade de letras corretas ta TENTATIVA ATUAL (ignora as anteriores)
	//escreve o texto em rosa e retorna o valor 1 para a variavel "ganhou" que chamou esta função
	if (ganhou == max){
		cout << COLOR_PINK << "\nParabéns, Você Ganhou" << COLOR_RESET << endl;
		sleep(3);
		system("cls");
		return 1;
	}
	//caso contratio, reseta a variavel local "ganhou"
	//e retorna o valor 0 para a variavel "ganhou" que chamou esta função (no main)
	ganhou = 0;
	return 0;
	
}



int main() {
	SetConsoleOutputCP(CP_UTF8);
	
	int i, j, max, chances, ganhou, jogada;
	
	do{
		//inicia as variaveis nescessárias com 0
		chances = 0;
		ganhou = 0;
		jogada = 0;
		max = 0;
		//decide o numero de letras da palavra alvo
		cout << "Digite o numero de letras desejado: "; cin >> max;
		cin.ignore();
		char palavra[max];
		//recebe a palavra alvo
		cout << "\nAgora digite a palavra desejada: "; cin >> palavra;
		cin.ignore();
		
		//substitui todas as letras por minusculas
		tratamento(palavra, max);		
		
		//decide o numero de tentativas do jogador
		cout << "\nDigte quantas chances o jogador terá: "; cin >> chances;
		cin.ignore();
		system("cls");
		
		char palpite[max+1];	
		char tentativas[chances][100];
		
		//Escreve as instruções na tela	
		cout <<"Bem vindo ao jogo, seu objetivo é acertar a palavra abaixo\n";
		cout << COLOR_GREEN << "[*] Letras VERDES estão no lugar correto.\n";
		cout << COLOR_YELLOW << "[*] Letras AMARELAS estão no lugar errado.\n";
		cout << COLOR_RESET << "[*] Letras BRANCAS não estão na palavra.\n\n\n\n" << endl;
		
		//reseta as variaveis de palavras para "-" ou NULL
		for (i = 0; i < max; i ++){
			palpite[i] = '\0';
			cout << "[-";
			cout << "] ";
		}
		
		//reseta todos os indices da tentativa para "-"
		for (i = 0; i < chances; i++) {
		    for (j = 0; j < max; j++) {
		        tentativas[i][j] = '-';
		    }
		}
		
		do{		
			//Reseta o palpite atual para "-" ou NULL
			for (i = 0; i < max; i ++){
				palpite[i] = '\0';
			}
			//chama a função do jogo
			ganhou = anotaTentativas(tentativas, palpite, palavra, max, jogada);

			//incremento/decremento das variaveis do jogo
			chances --;
			jogada ++;
		//checa se acabaram as chances ou se o jogador ganhou
		}while((chances > 0) && (ganhou == 0));
	
		//se o jogador não ganhou, escreve "sinto muito"
		if(ganhou != 1){
				system("cls");
				cout << "Sinto Muito, Você Perdeu" << endl;
				cout << "A palavra era: " << palavra << endl;
		}
	//checa se quer tentar novamente
	}while(desejaContinuar() != false);
	return 0;
}