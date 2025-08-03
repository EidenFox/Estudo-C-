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

#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"


//Função para checar se o jogador quer jogar novamente
bool desejaContinuar(void) {
	char reset;
    cout << "\nDeseja jogar novamente? [s/n] ";
    cin.ignore();
	cin >> reset;
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



int main() {
	SetConsoleOutputCP(CP_UTF8);
	
	int i, j, max, chances, ganhou, jogada;
	
	do{
		ganhou = 0;
		jogada = 0;
		//decide o numero de letras da palavra alvo
		cin.ignore();
		cout << "Digite o numero de letras desejado: "; cin >> max;
		char palavra[max];
		//recebe a palavra alvo
		cin.ignore();
		cout << "\nAgora digite a palavra desejada: "; cin >> palavra;
		
		//substitui todas as letras por minusculas
		tratamento(palavra, max);		
		
		//decide o numero de tentativas do jogador
		cin.ignore();
		cout << "\nDigte quantas chances o jogador terá: "; cin >> chances;
		system("cls");
		
		char palpite[max+1];	
		char acerto[max];
		char quase[max];
		char tentativas[chances][max];
		
		//reseta as variaveis de palavras para "-" ou NULL
		for (i = 0; i < max; i ++){
			acerto[i] = '-';
			quase[i] = '-';
			palpite[i] = '\0';
		}
		
		for (i = 0; i < chances; i++) {
		    for (j = 0; j < max; j++) {
		        tentativas[i][j] = '-';
		    }
		}
		
		do{
				
			//Escreve as instruções na tela		
			cout <<"Bem vindo ao jogo, seu objetivo é acertar a palavra abaixo\n";
			cout << COLOR_GREEN << "[*] Letras VERDES estão no lugar correto.\n";
			cout << COLOR_YELLOW << "[*] Letras AMARELAS estão no lugar errado.\n";
			cout << COLOR_RESET << "[*] Letras BRANCAS não estão na palavra.\n" << endl;
						
			//Escreve os campos de letra com as determinadas cores se houverem.
			for (i = 0; i < max; i++){
				if(quase[i] != '-'){
					cout << COLOR_YELLOW << "[";
					cout << quase[i];
					cout << "] " << COLOR_RESET;			
				}else if(acerto[i] != '-'){	
					cout << COLOR_GREEN << "[";
					cout << acerto[i];
					cout << "] " << COLOR_RESET;
					ganhou ++;
				}else{
					cout << "[";
					cout << palpite[i];
					cout << "] ";
				}
			}
			//Reseta as tentativas e o palpite para "-" ou NU*LL
			for (i = 0; i < max; i ++){
				acerto[i] = '-';
				quase[i] = '-';
				palpite[i] = '\0';
			}

			//checa se a quantidade de acertos é igual ao tamanho da palavra
			//se for, sai do programa
			if(ganhou == max){
				cout << "Parabéns, Você Ganhou" << endl;
				sleep(3);
				system("cls");
				break;
			}else{
				ganhou = 0;
			}
			
			//pede o palpite do usuário
			cin.ignore();
			cout << endl << "\nDigite sua palavra:\n"; cin >> palpite;
			//substitui todas as letras por minusculas
			tratamento(palpite, max);
		
			
			//roda o bloco o mesmo numero de vezes que o tamanho da palavra
			for (i = 0; i < max; i++){
				//roda o bloco o mesmo numero de vezes que o tamanho da palavra
				for (j = 0; j < max; j++){
					//checa se cada letra é IGUAL a letra da palavra na MESMA posição
					if (palpite[i] == palavra[i]){
						acerto[i] = palavra[i];
					//checa se cada letra é IGUAL a letra da palavra em outras posições
					}else if(palpite[i] == palavra[j]){
						quase[i] = palpite[i];
					}
				}
			}
			

		// Log para teste dos vetores (palavras)			
//		cout << "Quase: ";
//		for (i = 0; i < max; i ++){
//		cout << "[" << quase[i] <<"] ";
//		}
//		cout << endl << "Acertou: ";
//		for (i = 0; i < max; i ++){
//		cout <<"[" << acerto[i] <<"] ";
//		}
			
		//diminui 1 chance	
		chances --;
		jogada ++;
		
	//checa se acabaram as chances ou se o jogador ganhou
	}while((chances > 0) && (ganhou != max));
	
	//se o jogador não ganhou, escreve "sinto muito"
	if(ganhou != max){
			system("cls");
			cout << "Sinto Muito, Você Perdeu" << endl;
	}
	
	//checa se quer tentar novamente
	}while(desejaContinuar() != false);
	return 0;
}
