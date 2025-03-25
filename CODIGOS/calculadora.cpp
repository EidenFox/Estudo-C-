#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void simplificada() {
    // Implementação da função simplificada
    cout << "Ainda Não Implementado" << endl;
	system("pause");
}

void avancado(double n1, double n2, char op) {
    int loop = 0;
    
     

    cin >> n1;

    do {
        system("cls");
		
		
		
		
		
        cout << n1 << " "; 
		cin >> op;
        
		
		/*cout << op << endl;
		system ("pause");
		*/
		
		if(op != '=') {
            cout << " "; cin >> n2;
        }

        switch(op) {
            case '+':
                n1 = n1 + n2;
                break;
            case '-':
                n1 = n1 - n2;
                break;
            case '/':
                if (n2 == 0) {
                    cout << "Impossível fazer a operação com 0" << endl;
                    system("pause");
                } else {
                    n1 = n1 / n2;
                }
                break;
            case '*':
                n1 = n1 * n2;
                break;
            case 's':
                cout << "Conta de raiz" << endl;
                break;
            case '=':
                system("cls");
                cout << "Resultado da conta: " << n1 << endl;
                system("pause");
                loop = 1;
                break;
            default:
                system("cls");
                cout << "Operador não reconhecido" << endl;
                system("pause");
                break;
        }
    } while (loop != 1);
}

int main() {
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
        cout << "+----------------------------+" << endl; 
        cin >> menu;
        system("cls");

        switch (menu) {
            case 1:
                simplificada();
                break;
            case 2:
            	cout << "Calculadora Avançada" << endl; cout << "Escreva \"=\" para sair" << endl;
                avancado(n1, n2, op);
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Não Reconhecido" << endl;
                system("pause");
                break;
        }

    } while (menu != 3);

    return 0;
}