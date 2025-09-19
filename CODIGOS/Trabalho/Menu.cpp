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
	
	do{
		cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
		cout << "Bem vindo ao BiciCreta!\nPara continuar faça o login: " << endl; 
		cout << "Digite seu Email: "; cin >> email;
		cout << "Digite sua Senha: "; cin >> senha;
		
		if (checarLogin(email, senha){
			continuar = true;
		}else{
			system("cls");
			cout << "Dados incorretos, tente novamente!" << endl;
		}
	}while(!continuar);




    return 0;
}
