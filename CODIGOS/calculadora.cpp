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
	int loop = 0;
	
	cin >> n1;
	
	system("cls");
	
	do {
		system("cls");
		
		cout << n1; cin >> op >> n2;
		
		switch(op){
			case "+":
				n1 = n1 + n2;
			
	       		break;
			case "-":
        		n1 = n1 - n2
        	
        		break;
			case "/":
				if (n1 or n2 == 0){
					cout >> "Impossivel fazer a operação com 0"
				}else {
        		n1 = / n2 
 				}
 				
        		break;
			case "*":
	        	n1 = n1 * n2

	       		break;
			case "=":
        		
        		system("cls");
        		cout << "Resultado da conta: " << n1; endln;
        		break;
			default:
				system("cls");
				cout << "Operador não reconhecido";
				system("pause");				
        		break;	
		} while (loop != 1);
		
	}
	
	cout << n1 << op << n2; endln;
	
	system("pause");
	
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
	cout << "| 2. Avançada                |" << endl;
	cout << "| 3. Sair                    |" << endl;
	cout << "+----------------------------+" << endl; cin >> menu;
	
	switch (menu) {
    case 1:
        
        break;
    case 2:
        avancado(n1, n2, op);
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