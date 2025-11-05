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

	short int a;
	int b;
	long int c;
	long long d;
	double e;
	char f;
	bool g;
	printf("Tamanho de short int: %d bytes\n", sizeof(a));
	printf("Tamanho de Int: %d bytes\n ", sizeof(b));
	printf("Tamanho de Long: %d bytes\n", sizeof(c));
	printf("Tamanho de Lon Long: %d bytes\n", sizeof(d));
	printf("Tamanho de Double: %d bytes\n", sizeof(e));
	printf("Tamanho de Char: %d bytes\n", sizeof(f));
	printf("Tamanho de Bool: %d bytes\n", sizeof(g));
	



    return 0;
}
