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

void listarDisponiveis();
void cadastroCliente();
void solicitarReparo();
void listarAlugadas();
void devolucao();
void alugar();
	
bool checarLogin(){
	return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
	cout << "|  _ \\(_)    (_)/ ____|        | |       "<<endl;
	cout << "| |_) |_| ___|_| |     _ __ ___| |_ __ _ "<<endl;
	cout << "|  _ <| |/ __| | |    | '__/ _ \\ __/ _` |"<<endl;
	cout << "| |_) | | (__| | |____| | |  __/ |_ (_| |"<<endl;
	cout << "|____/|_|\\___|_|\\_____|_|  \\___|\\__\\__,_|"<<endl;
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
	Sleep(5000);
	system("cls");
	
	string email, senha;
	bool continuar = false;
	int op;
	
	do{
		cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
		cout << "Bem vindo ao BiciCreta!\nPara continuar faça o login: " << endl; 
		cout << "Digite seu Email: "; cin >> email;
		cout << "Digite sua Senha: "; cin >> senha;
		
		if (checarLogin()){
			continuar = true;
		}else{
			system("cls");
			cout << "Dados incorretos, tente novamente!" << endl;
		}
	}while(!continuar);
	
	do{
		cout << "[1] Cadastrar Funcionário" << endl;
		cout << "[0] Ir para o Menu." << endl;
		cin >> op;
	}while (op!=0);
	op = 1;
	
	do{
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
//				cadastroCliente();
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
				cout << "Saindo";
				for (int i = 0; i < 5; i++){
					sleep(500);
					cout << "." << endl;
				}
				break;
		}
		
	}while (op != 0);




    return 0;
}
