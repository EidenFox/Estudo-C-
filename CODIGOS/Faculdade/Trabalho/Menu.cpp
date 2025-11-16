#include <iostream>
#include <locale.h>
using namespace std;

#include "clientes.h"


/**
*	INDICES DE CARGO:
* 	Cadastro[i].cargo ->
*	0 = Administrador
*	1 = Funcionário
*	2 = Cliente
**/



void listarDisponiveis();
// void cadastroCliente();	// substituido por cadastro unico com "Cargo"
void solicitarReparo();
void listarAlugadas();
// int checarLogin();		// Função transferia para "./cliente.cpp" 
void devolucao();
void alugar();

int main() {
	setlocale(LC_ALL, "Portuguese");
	cout << "|  _ \\(_)    (_)/ ____|        | |       "		   <<endl;
	cout << "| |_) |_| ___|_| |     _ __ ___| |_ __ _ "			   <<endl;
	cout << "|  _ <| |/ __| | |    | '__/ _ \\ __/ _` |"		   <<endl;
	cout << "| |_) | | (__| | |____| | |  __/ |_ (_| |"			   <<endl;
	cout << "|____/|_|\\___|_|\\_____|_|  \\___|\\__\\__,_|"	   <<endl;
	cout << "                                        #####        "<<endl;
	cout << "                                     *####*          "<<endl;
	cout << "                    **##*             ###            "<<endl;
	cout << "               *########*             ###            "<<endl;
	cout << "                   ####               *##*           "<<endl;
	cout << "                    ######################           "<<endl;
	cout << "                   *####***###############*          "<<endl;
	cout << "                  *######          *### ###          "<<endl;
	cout << "                *###   ###*       ###*  +##*         "<<endl;
	cout << "    *#############      ###*    ####  *#########*    "<<endl;
	cout << "  #####*   *#####        ###   ###* #####*##**#####  "<<endl;
	cout << " ###       *##*##*       *### ###  *##*   ###    ####"<<endl;
	cout << "###      *###*#########****#####  *##     ###*    ###"<<endl;
	cout << "##*     ######################    ##*     ####    *##"<<endl;
	cout << "##*             *##               ##*      ###    *##"<<endl;
	cout << "### ###         ###               ### *##*        ###"<<endl;
	cout << "*### *###      ###                 *## *###      ####"<<endl;
	cout << "  #####    *#####                   ######    #####* "<<endl;
	cout << "    ##########*                       *##########    "<<endl;
	timer(5);
	limparTela();

	Pessoa Cadastro[LIMITE];
	string email, senha;
	bool continuar = false;
	int op = -1;
	int indice = -1;
	coletarDados(Cadastro);
	limparTela();
	
	
	
	/* LOGIN INICIAL (ADM (0) OU FUNCIONÁRIO (1))*/
	do{
		cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
		cout << "Bem vindo ao BiciCreta!\nPara continuar faça o login: " << endl; 
		cout << "Digite seu Email: "; cin >> email;
		cout << "Digite sua Senha: "; cin >> senha;
		
		indice = checarLogin(Cadastro, email, senha);
		if (indice != -1){
			cout << "Bem vindo " << Cadastro[indice].nome << ", Redirecionando para o menu..." << endl;
			continuar = true;
			timer(3);
		}else{
			limparTela();
			continuar = false;
			cout << "Dados incorretos, tente novamente!" << endl;
		}
	}while(!continuar);
	/* LOGIN INICIAL (ADM (0) OU FUNCIONÁRIO (1))*/

	/* CHECA SE O LOGIN FOI DE UM ADMINISTRADOR */
	if(Cadastro[indice].cargo == 0){		
		do{
			limparTela();
			cout << "Bem Vindo Administrador " << Cadastro[indice].nome << " Selecione uma opção:" << endl;
			cout << "[1] Cadastrar Funcionário" << endl;
			cout << "[0] Ir para o Menu." << endl;
			cin >> op;
			switch(op){
				case 1:
					cadastrar(Cadastro, 1);
					break;
				case 0:
					cout << "Redirecionando..." << endl;
					timer(3);
					break;
				default:
					break;
			}
		}while (op!=0);
		op = -1;
	}
	/* CHECA SE O LOGIN FOI DE UM ADMINISTRADOR */
	
	/* MENU PINCIPAL */
	do{
		limparTela();
		cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
		cout << "[1] Cadastrar Cliente" << endl;
		cout << "[2] Listar Bicicletas" << endl;
		cout << "[3] Alugar Bicicleta" << endl;
		cout << "[4] Checar Bicibletas alugadas" << endl;
		cout << "[5] Solicitar Reparo" << endl;
		cout << "[6] Registrar Devolução" << endl;
		cout << "[0] Sair" << endl;
		cin >> op;
		
		switch(op){
			case 1:
				cadastrar(Cadastro, 2);
				break;
			case 2:
//				listarDisponiveis();
				break;
			case 3:
//				alugar();
				break;
			case 4:
//				listarAlugadas();
				break;
			case 5:
//				solicitarReparo();
			case 6:
//				devolucao();
				break;
			case 0:
				limparTela();
				cout << "Saindo";
				for (int i = 0; i < 5; i++){
					timer(1);
					cout << "." << endl;
				}
				break;
			default:
				cout << "Opção Inválida, tente novamente" << endl;
				timer(3);
				break;
		}
		
	}while (op != 0);
	/* MENU PINCIPAL */




    return 0;
}

