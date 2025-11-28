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


/* Usado no lugar de "fflush(stdin);" pq eu estou fazendo no linux q no linux não funciona */
#define cignore std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

/* COMPATIBILIDADE LINUX/WINDOWS */
#ifdef _WIN32           // Se o compilador for Windows (definindo _WIN32)
    #include <windows.h>
#else                   // Caso contrário (Linux)
    #include <unistd.h>
#endif
	/* FUNÇÕES DE CONVERSÃO WINDOWS/LINUX */
		/* Função para limpar a tela (linux/windows) */
		inline void limparTela(){
		    #ifdef _WIN32
		        system("cls");
		    #else
		        system("clear"); // Comando para limpar tela no Linux
		    #endif
		}
		
		/* Função para pausar por X segundos (linux/windows) */
		inline void timer(int x){
		    #ifdef _WIN32
		        Sleep(x*1000); // x*1000 = x segundos
		    #else
		        sleep(x); // x segundos
		    #endif	
		}

		/* Função para transformar string de maiusculo para minusculo*/
		inline std::string toLower(const std::string& str) {
			std::string lower = str;
			std::transform(lower.begin(), lower.end(), lower.begin(),
						[](unsigned char c){ return std::tolower(c); });
			return lower;
		}

		inline void pausar() {
			#ifdef _WIN32
				system("pause"); 
			#else
				system("read -n 1 -s -r -p 'Pressione qualquer tecla para continuar...'");
				std::cout << std::endl;
			#endif
		}

	/* FUNÇÕES DE CONVERSÃO WINDOWS/LINUX */
/* COMPATIBILIDADE LINUX/WINDOWS */


int main() {
    setlocale(LC_ALL, "Portuguese");





    return 0;
}
