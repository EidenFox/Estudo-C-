#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//recebe o endereço de memoria de uma variavel e atribui a um ponteiro
void mostra(int *num){
	cout << *num << endl;
	
	//permite a manipulação de uma variavel fora deste escopo por ter acesso ao endereço de memória desta variavel.
	*num = 50;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

	int idade = 22;
	//envio o endereço de memória da variavel como parametro
	mostra(&idade);
	mostra(&idade);




    return 0;
}
