#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/


/* COMPATIBILIDADE LINUX/WINDOWS */
#ifdef _WIN32           // Se o compilador for Windows (definindo _WIN32)
    #include <windows.h>
#else                   // Caso contrário (Linux)
    #include <unistd.h>
#endif
	/* FUNÇÕES DE CONVERSÃO WINDOWS/LINUX */
		/* Função para limpar a tela (linux/windows) */
		void limparTela(){
		    #ifdef _WIN32
		        system("cls");
		    #else
		        system("clear"); // Comando para limpar tela no Linux
		    #endif
		}
		
		/* Função para pausar por X segundos (linux/windows) */
		void timer(int x){
		    #ifdef _WIN32
		        Sleep(x*1000); // x*1000 = x segundos
		    #else
		        sleep(x); // x segundos
		    #endif	
		}
	/* FUNÇÕES DE CONVERSÃO WINDOWS/LINUX */
/* COMPATIBILIDADE LINUX/WINDOWS */


int main() {
    SetConsoleOutputCP(CP_UTF8);





    return 0;
}
