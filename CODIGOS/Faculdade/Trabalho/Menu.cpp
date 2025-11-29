#include <iostream>
#include <locale.h>
#include "cadastros.h"
using namespace std;


/**
*	INDICES DE CARGO:
* 	Cadastro[i].cargo ->
*	0 = Administrador
*	1 = Funcionário
*	2 = Cliente
**/

/**
*	Ordem no arquivo TXT
*	- ID
*	- Nome
*	- Idade
*	- Email
*	- Cargo
*	- Senha
*	- Status
**/

/**
*	Ordem no arquivo TXT
*	- ID
*	- Modelo
*	- Descrição
*	- IdPessoa
*	- Status
**/


void solicitarReparo();			// transferir para outro arquivo
void alugar();					// transferir para outro arquivo
void menuCadastro(Pessoa Cadastro[], Bicicletas Bicicleta[]);
void menuServico(Pessoa Cadastro[], Bicicletas Bicicleta[]);
void menuListar(Pessoa Cadastro[], Bicicletas Bicicleta[]);

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
	Bicicletas Bicicleta[LIMITE];
	string email, senha;
	bool continuar = false;
	int op = -1;
	int indice = -1;
	coletarDados(Cadastro);
	coletarDadosB(Bicicleta);
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
			//limparTela();
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
		cout << "[1] Area de Cadastros" << endl;
		cout << "[2] Area de Serviços" << endl;
		cout << "[0] SAIR!" << endl;
		cin >> op;
		
		switch(op){
			case 1:
				menuCadastro(Cadastro, Bicicleta);
				break;
			case 2:
				menuServico(Cadastro, Bicicleta);
				break;
			case 0:
				limparTela();
				cout << "Encerrando programa";
				for (int i = 0; i < 5; i++){
					cout << ".";
					timer(1);
				}
				break;
			default:
				cout << "Opção Inválida, tente novamente" << endl;
				timer(2);
				break;
		}
		
	}while (op != 0);
	/* MENU PINCIPAL */




    return 0;
}



void menuCadastro(Pessoa Cadastro[], Bicicletas Bicicleta[]){
	int op = 0;
	do{
		int id = -1;
		limparTela();
		cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
		cout << "[1] Cadastrar Cliente" << endl;
		cout << "[2] Editar Cadastro de Usuário" << endl;
		cout << "[3] Cadatrar Bicicletas" << endl;
		cout << "[4] Editar Cadastro de Bicicleta" << endl;
		cout << "[5] Menu de Listagem" << endl;
		cout << "[0] Voltar" << endl;
		cin >> op;
		
		switch(op){
			case 1:
				cadastrar(Cadastro, 2);
				break;
			case 2:
				//inserir "listarUsuarios(9)" para poder ver o ID do usuário
				listarUsuarios(Cadastro, 9, false);
				cout << "digite o ID do usuário que deseja editar: " << endl;
				cin >> id;
				editarUsuario(Cadastro, id);
				break;
			case 3:
				cadastrarB(Bicicleta);
				break;
			case 4:
				cout << "digite o ID da Bicicleta que deseja editar: " << endl;
				cin >> id;
				editarBicicleta(Bicicleta, Cadastro, id);
				break;
			case 5:
				menuListar(Cadastro, Bicicleta);
				break;
			case 0:
				limparTela();
				cout << "Retornando..." << endl;
				timer(3);
				break;
			default:
				cout << "Opção Inválida, tente novamente" << endl;
				timer(3);
				break;
		}
		
	}while (op != 0);

}


void menuListar(Pessoa Cadastro[], Bicicletas Bicicleta[]){
	int op = 0;
	do{
		int lop = 0;
		int id = 0;
		limparTela();
		cout << "--------------------\n-------LISTAR-------\n--------------------\n" << endl;
		cout << "[1] Listar TODOS os Usuários ATIVOS" << endl;
		cout << "[2] Listar Usuários por Cargo" << endl;
		cout << "[3] Listar Usuários INATIVOS" << endl;
		cout << "[4] Listar TODAS as Bicicletas ATIVAS" << endl;
		cout << "[5] Listar Bicicletas Disponiveis" << endl;
		cout << "[6] Listar Bicicletas Alugadas" << endl;
		cout << "[7] Listar Bicicletas por Cliente" << endl;
		cout << "[8] Listar APENAS as Bicicletas INATIVAS" << endl;
		cout << "[0] Voltar para o Menu Principal" << endl;
		cin >> op;
		
		switch(op){
			case 1:
				listarUsuarios(Cadastro, 9, false);
				break;
			case 2:				
				do{
					lop = -1;
					cout << "Selecione uma opção: " << endl;
					cout << "[1] Listar Administradores" << endl;
					cout << "[2] Listar Funcionários" << endl;
					cout << "[3] Listar Clientes" << endl;
					cout << "[0] Voltar" << endl;
					cin >> lop;
					switch(lop){
						case 1:
							listarUsuarios(Cadastro, 0, false);
							lop = 0;
							break;
						case 2:
							listarUsuarios(Cadastro, 1, false);
							lop = 0;
							break;
						case 3:
							listarUsuarios(Cadastro, 2, false);
							lop = 0;
							break;
						case 0:
							cout << "Voltando..." << endl;
							timer(2);
							break;
						default:
							cout << "Opção Inválida, tente novamente" << endl;
							timer(3);
							break;
					}
				}while (lop != 0);

				break;
			case 3:	
				listarUsuarios(Cadastro, 10, false);
				break;
			case 4:
				listarBicicletas(Bicicleta, Cadastro, 9);
				break;
			case 5:
				listarBicicletas(Bicicleta, Cadastro, 2);
				break;
			case 6:
				listarBicicletas(Bicicleta, Cadastro, 1);
				break;
			case 7:
				listarBicicletas(Bicicleta, Cadastro, 3);
				break;
			case 8:
				listarBicicletas(Bicicleta, Cadastro, 10);
				break;
			case 0:
				limparTela();
				cout << "Saindo..." << endl;
				timer(2);
				break;
			default:
				cout << "Opção Inválida, tente novamente" << endl;
				timer(3);
				break;
		}
		
	}while (op != 0);
}

void menuServico(Pessoa Cadastro[], Bicicletas Bicicleta[]){
	int op = 0;
	do{
		int idP = 0;
		int idB = 0;
		limparTela();
		cout << "--------------------\n--------MENU--------\n--------------------\n" << endl;
		cout << "[1] Alugar Bicicleta" << endl;
		cout << "[2] Checar Bicibletas disponiveis" << endl;
		cout << "[3] Registrar Devolução" << endl;
		cout << "[0] Sair" << endl;
		cin >> op;
		
		switch(op){
			case 1:
				cout << "Digite o ID da bicicleta que deseja alugar:" << endl;
				cin >> idB;
				cout << "Digite o ID do Usuário que deseja atribuir à Bicicleta" << endl;
				cin >> idP;
				aluguel(Bicicleta, Cadastro, idB, idP);
				break;
			case 2:
				listarBicicletas(Bicicleta, Cadastro, 2);
				break;
			case 3:
				cout << "Digite o ID da Bicicleta que deseja Devolver" << endl;
				cin >> idB;
				devolucao(Bicicleta, Cadastro, idB);
				break;
			case 0:
				limparTela();
				cout << "Saindo..." << endl;
				timer(2);
				break;
			default:
				cout << "Opção Inválida, tente novamente" << endl;
				timer(2);
				break;
		}
		
	}while (op != 0);
}