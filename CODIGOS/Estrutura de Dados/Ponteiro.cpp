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



int main() {
    SetConsoleOutputCP(CP_UTF8);

	int x = 42;
	int *ponteiro = &x;
	//se usar void ler linha 29
//	void *ponteiro = &x;
	
	cout << "Endereço de memoria de X: " << &x << endl;
	cout << "Valor de x: " << x << endl;
	
	cout << "\nEndereço de memoria do *ponteiro: " << &ponteiro << endl;
	cout << "Valor do ponteiro: " << ponteiro << endl; 
	
	// "*(int *)ponteiro" faz a conversão do tipo do ponteiro para INT (caso tenha usado "Void" como tipo de variavel)
	cout << "Valor para onde o ponteiro aponta: " << *(int *)ponteiro << endl; 


	// *ponteiro é equivalente a X, então se eu mudar o valor de *ponteiro eu mudo tambem o de X
	*ponteiro = 100;
	// equivalente a "x = 100" pois "*ponteiro" interage com e endereço de memória de X, anterando o seu valor
	
	cout << "Valor para onde o ponteiro aponta: " << *(int *)ponteiro << endl; 
	cout << "Valor de x: " << x << endl;
	
	
	
	
	



    return 0;
}
