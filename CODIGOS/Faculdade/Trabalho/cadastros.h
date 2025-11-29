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


extern int total;
extern int totalB;
extern FILE *pont_arq;
extern FILE *pont_arq2;

#define CADASTRO "../arquivos/dadosCadastros.txt"
#define BICICLETAS "../arquivos/bicicletas.txt"
#define LIMITE 100
#define TAMNOME 50
#define TAMDESC 100


/* STRUCTS */
typedef struct Pessoa {
    int id;
    std::string nome;
    int idade;
    int cargo;
    std::string email;
	std::string senha;
	bool status;
} Pessoa;

typedef struct Bicicletas {
    int id;
	std::string modelo;
	int idPessoa;	//	FK, armazena o ID da pessoa que alugou
    std::string descricao;
	bool status;
} Bicicletas;
/* STRUCTS */

/* Prototipação das funções Clientes */
void cadastrar(Pessoa Cadastro[], int cargo);
bool coletarDados(Pessoa Cadastro[]);
bool abrirArquivo(int tipo);
int checarLogin(Pessoa Cadastro[], std::string email, std::string senha);
bool editarUsuario(Pessoa Cadastro[], int id);
bool reescreverArquivo(Pessoa Cadastro[]);
void listarUsuarios(Pessoa Cadastro[], int x, bool mode);	// Listar usuários
/* Prototipação das funções Clientes */


/* Prototipação das funções Bicicletas */
void cadastrarB(Bicicletas Bicicleta[]);
bool coletarDadosB(Bicicletas Bicicleta[]);
bool abrirArquivoB(int tipo);
bool reescreverArquivoB(Bicicletas Bicicleta[]);
bool editarBicicleta(Bicicletas Bicicleta[], Pessoa Cadastro[], int id);
void listarBicicletas(Bicicletas Bicicleta[], Pessoa Cadastro[], int x);
void devolucao(Bicicletas Bicicleta[], Pessoa Cadastro[], int id);
void aluguel(Bicicletas Bicicleta[], Pessoa Cadastro[], int id, int idP);
// int getIndiceB (Bicicletas Bicicleta[], Pessoa Cadastro[], id);
/* Prototipação das funções Bicicletas */




#endif