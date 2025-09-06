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
	int i = 0;

	int matriz[4][6];
	
	for (int linha = 0; linha < 4; linha++){
		for (int coluna = 0; coluna < 6; linha++){
			matriz[linha][coluna] = i;
			i++;
		}
	}

	for (int linha = 0; linha < 4; linha++){
		printf("\n");
		for (int coluna = 0; coluna < 6; linha++){
			printf("%d", matriz[linha][coluna]);
		}
	}


    return 0;
}
