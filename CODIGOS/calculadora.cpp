#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;



void simplificada (){
		
}


void avancado (double n1, double n2, char op){
	cin >> n1 >> op >> n2;
	
}



int main(){
  SetConsoleOutputCP(CP_UTF8);
  
  int menu = 0;
  double n1, n2 = 0;
  char op;
	
	do {
	system("cls");
	cout << "+----------------------------+" << endl;
	cout << "|        Calculadora         |" << endl;
	cout << "| 1. Simplificada            |" << endl;
	cout << "| 1. Avançada                |" << endl;
	cout << "| 3. Sair                    |" << endl;
	cout << "+----------------------------+" << endl; cin >> menu;
	
	switch (menu) {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    default:
        cout << "Não Reconhecido" << endl;
        break;
	}
	
	} while (menu != 3);

return 0;
}