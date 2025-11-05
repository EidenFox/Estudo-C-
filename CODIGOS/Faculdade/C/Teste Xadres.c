#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
//#include <Windows.h>

/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/

#define AMARELO   "\x1b[33m"
#define CIANO  "\x1b[36m"
#define RESET   "\x1b[0m"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int i, j;
	
	
	
char xadres[8][8] = {
        {'H', 'N', 'B', 'K', 'Q', 'B', 'N', 'H'}, // Linha 0: Peças brancas de trás (Rook, Knight, Bishop, King, Queen)
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // Linha 1: Peões brancos
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Linha 2: Vazio
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Linha 3: Vazio
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Linha 4: Vazio
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Linha 5: Vazio
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // Linha 6: Peões pretos
        {'h', 'n', 'b', 'q', 'k', 'b', 'n', 'k'}  // Linha 7: Peças pretas de trás (Rook, Knight, Bishop, Queen, King)
    };



	printf(CIANO "    |A| |B| |C| |D| |E| |F| |G| |H|\n" RESET);
	for (int i = 0; i < 8; i++) {
		printf("     —   —   —   —   —   —   —   —\n");
		printf(AMARELO"|%d| "RESET, 8 - i);	// Números das linhas (8 a 1)
		
		for (int j = 0; j < 8; j++) {
		printf("|%c| ", xadres[i][j]);
		}
		printf("\n");
		}


    return 0;
}
