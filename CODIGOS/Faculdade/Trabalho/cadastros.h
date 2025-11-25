#ifndef CADASTROS_H
#define CADASTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>

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

	/* FUNÇÕES DE CONVERSÃO WINDOWS/LINUX */
/* COMPATIBILIDADE LINUX/WINDOWS */


extern int total;
extern FILE *pont_arq;

#define CADASTRO "../arquivos/dadosCadastros.txt"
#define LIMITE 100
#define TAMNOME 50

/* STRUCTS */
typedef struct Pessoa {
    int id;
    char nome[TAMNOME];
    int idade;
    int cargo;
    std::string email;
	std::string senha;
} Pessoa;
/* STRUCTS */

/* Prototipação das funções */
void cadastrar(Pessoa Cadastro[], int cargo);
bool coletarDados(Pessoa Cadastro[]);
bool abrirArquivo(int tipo);
int checarLogin(Pessoa Cadastro[], std::string email, std::string senha);
bool editarUsuario(Pessoa Cadastro[], int id);
bool reescreverArquivo(Pessoa Cadastro[]);
/* Prototipação das funções */





#endif