#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "cadastros.h"
using namespace std;


/* CONSTANTES E VARIAVEIS GLOBAIS */
FILE *pont_arq;
int total = -1;
/* CONSTANTES E VARIAVEIS GLOBAIS */




/* FUNÇÃO PARA COLETAR OS DADOS DO ARQUIVO */
bool coletarDados(Pessoa Cadastro[]) {
    if (!abrirArquivo(2)) {
        return false;
    }
    if (pont_arq == NULL) return false;

    char linha[256];
    int i = 0;
	total = -1;

    while (fgets(linha, sizeof(linha), pont_arq) && i < LIMITE) {
      
        linha[strcspn(linha, "\n")] = '\0';   // Remove \n do final da linha

		
        char *token = strtok(linha, "|");
        if (token != NULL) Cadastro[i].id = atoi(token);	//ID

        token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].nome = token;	//Nome

        token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].idade = atoi(token);	//Idade

        token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].email = token;	//Email

		token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].cargo = atoi(token);	//Cargo

		token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].senha = token;	//Senha
		
		token = strtok(NULL, "|");
        if (token != NULL) {
            Cadastro[i].status = (atoi(token) == 1); //Status
        } else {
            Cadastro[i].status = true;	//se nn tiver status considera "ativo" 
        }
    	total = i; 
        i++;
    }

    fclose(pont_arq);
    return true;
}
/* FIM DA FUNÇÃO DE COLETA*/



/* FUNÇÃO PARA CADASTRAR*/
void cadastrar(Pessoa Cadastro[], int cargo) {
    bool sair = false;
    char sairC;
	bool ok = false;

	if(abrirArquivo(1)){
		cignore;
	    do {
			total++;

			if (total >= LIMITE) {
                cout << "Limite de cadastros atingido." << endl;
                total--;
                break;
            }

			if (total == 0) {
                Cadastro[total].id = 1; 
            } else {
				int maiorID = 0;
				for(int i = 0; i < total; i++) {
					if(Cadastro[i].id > maiorID) maiorID = Cadastro[i].id;
				}
				Cadastro[total].id = maiorID + 1;
            }

			fprintf(pont_arq, "%d|", Cadastro[total].id);
				
	        cout << "Digite o nome do Usuário: ";
	        getline(cin, Cadastro[total].nome);
			if (Cadastro[total].nome.empty()) {
				Cadastro[total].nome = "-";
			}
	        fprintf(pont_arq, "%s|", Cadastro[total].nome.c_str());
	
	        cout << "Digite a idade: ";
			cin >> Cadastro[total].idade;
			cignore;
			fprintf(pont_arq, "%d|", Cadastro[total].idade);
	
	        cout << "Digite o email: ";
	        getline(cin, Cadastro[total].email);
			if (Cadastro[total].email.empty()) {
				Cadastro[total].email = "-";
			}
	        fprintf(pont_arq, "%s|", Cadastro[total].email.c_str());


			/**
			*	0 = Administrador
			*	1 = Funcionário
			*	2 = Cliente
			**/
			Cadastro[total].cargo = cargo;
	        fprintf(pont_arq, "%d|", Cadastro[total].cargo);

			cout << "Peça para que o usuário digite uma Senha: ";
	        getline(cin, Cadastro[total].senha);
			if (Cadastro[total].senha.empty()) {
				Cadastro[total].senha = "-";
			}
	        fprintf(pont_arq, "%s|", Cadastro[total].senha.c_str());

			Cadastro[total].status = true; 
	        fprintf(pont_arq, "%d\n", 1);
			
	        cout << "Realizar novo cadastro? [S/N]: ";
	        cin >> sairC;
			cignore;
	        sair = (tolower(sairC) != 's');
	        if (total >= LIMITE) {
	            cout << "Limite de cadastros atingido." << endl;
	            sair = true;
	        }
	
	    } while (!sair);
	}
    fclose(pont_arq);
}
/* FIM DA FUNÇÃO DE CADASTRO */

/* FUNÇÃO PARA ABRIR O ARQUIVO */
bool abrirArquivo(int tipo){
	if(tipo == 1){//		tipo 1 = escrever
		pont_arq = fopen(CADASTRO, "a");		
	}else if(tipo == 2){//		tipo 2 = ler
		pont_arq = fopen(CADASTRO, "r");
	}else if (tipo == 3){//		tipo 3 = reescrever arquivo
		pont_arq = fopen(CADASTRO, "w");	
	}

    if (pont_arq == NULL) {
        printf("Erro na abertura do arquivo!");
	    return false;
    } else {
        cout << "Arquivo aberto com sucesso!" << endl;
		return true;
	}
}
/* FIM DA ABERTURA DE ARQUIVO */



/* FUNÇÃO PARA CHECAR O LOGIN*/
int checarLogin(Pessoa Cadastro[], string email, string senha){

	string lEmail = toLower(email);
	string lEmailCheck;
	// cout << "CHECANDO LOGIN" << endl;
	for (int i = 0; i <= total; i++){
		lEmailCheck = toLower(Cadastro[i].email);
		// cout << "EMAILCHECK: " << lEmailCheck << endl;
		// cout << "SENHACHECK: " << Cadastro[i].senha << endl;
		if(lEmail == lEmailCheck && senha == Cadastro[i].senha){
			return i;
			timer (3);
		}
	}
	timer (3);
	return -1;
}
/* FUNÇÃO PARA CHECAR O LOGIN*/


/* FUNÇÃO PARA REESCREVER O ARQUIVO INTEIRO*/
bool reescreverArquivo(Pessoa Cadastro[]) {
    if(!abrirArquivo(3)) return false; // limpa o arquivo
    
    for (int i = 0; i <= total; i++) {
		if(Cadastro[i].nome[0] != '\0'){
			fprintf(pont_arq, "%d|%s|%d|%s|%d|%s|%d\n", 
				Cadastro[i].id, 
				Cadastro[i].nome.c_str(), 
				Cadastro[i].idade, 
				Cadastro[i].email.c_str(), 
				Cadastro[i].cargo, 
				Cadastro[i].senha.c_str(),
				(Cadastro[i].status ? 1 : 0)	// true = 1 | false = 0
			);
		}
    }
    fclose(pont_arq);
	return true;
}
/* FUNÇÃO PARA REESCREVER O ARQUIVO INTEIRO*/



/* FUNÇÃO PARA EDITAR UM USUÁRIO */
bool editarUsuario(Pessoa Cadastro[], int id) {
	//reinicia o total para fazer a coleta novamente do struct (pra garantir q esta atualizado antes de reescrever)
    total = -1; 
    if (!coletarDados(Cadastro)) {
        cout << "Banco de dados Vazio ou Erro ao ler dados para edição." << endl;
        return false;
    }

    int indice = -1;
    for(int i = 0; i <= total; i++){
        if(Cadastro[i].id == id){
            indice = i;	//captura qual indice tem o ID que queremos alterar
            break;
        }
    }

    if (indice == -1) {	//se o indice for -1 é pq nn achou o id
        cout << "Usuário com ID " << id << " não encontrado." << endl;
        timer(3);
        return false;
    }

	string status;
    int op = 0;
	do{
		limparTela();
		cout << "Editando Usuário: [" << Cadastro[indice].id << "]" << endl;
		cout << "Nome: " << Cadastro[indice].nome << endl;
		cout << "Idade: " << Cadastro[indice].idade << endl;
		cout << "Email: " << Cadastro[indice].email << endl;
		cout << "Cargo: " << Cadastro[indice].cargo << endl;
		cout << "Status: "<< (Cadastro[indice].status ? "Ativo" : "Inativo") << endl;
		cout << "-----------------------" << endl;
		cout << "[1] Alterar Nome" << endl;
		cout << "[2] Alterar Idade" << endl;
		cout << "[3] Alterar Email" << endl;
		cout << "[4] Alterar Senha" << endl;
		cout << "[5] Alterar Cargo" << endl;
		cout << "[6] Açternar Status" << endl;
		cout << "[9] CANCELAR" << endl;
		cout << "[0] SALVAR" << endl;
		cin >> op;
		cignore;

		switch (op) {
			case 1:
				cout << "Novo Nome: ";
				getline(cin, Cadastro[indice].nome);
				if (Cadastro[indice].nome.empty()) {
					Cadastro[indice].nome = "-";
				}
				break;
			case 2:
				cout << "Nova Idade: ";
				cin >> Cadastro[indice].idade;
				cignore;
				break;
			case 3:
				cout << "Novo Email: ";
				getline(cin, Cadastro[indice].email);
				if (Cadastro[indice].email.empty()) {
					Cadastro[indice].email = "-";
				}
				break;
			case 4:
				cout << "Nova Senha: ";
				getline(cin, Cadastro[indice].senha);
				if (Cadastro[indice].senha.empty()) {
					Cadastro[indice].senha = "-";
				}
				break;
			case 5:
				cout << "Novo cargo:\n[0] Administrador\n[1] Funcionário\n[2] Cliente" << endl;
				cin >> Cadastro[indice].cargo;
				break;
			case 6:
				Cadastro[indice].status = !Cadastro[indice].status;
                cout << "Status alterado." << endl;
                timer(1);
                break;
			case 9:
				cout << "Edição Cancelada" << endl;
				timer(3);
				return false;
			case 0:
				cout << "Salvando..." << endl;
				timer(3);
				break;
			default:
				cout << "Opção inválida." << endl;
				break;
		}
	}while(op != 0);

	//chama a função q reescreve o arquivo
    if(reescreverArquivo(Cadastro)){
		cout << "Dados atualizados com sucesso!" << endl;
		timer(2);
		return true;
	}else{
		cout << "Erro ao atualizar arquivo!" << endl;
		timer(2);
		return false;
	}
}
/* FUNÇÃO PARA EDITAR UM USUÁRIO */


/* FUNÇÃO PARA LISTAR USUÁRIOS */
void listarUsuarios(Pessoa Cadastro[], int x, bool mode){
	char sair;
	cout << "--------------------\n-------LISTAR-------\n--------------------\n" << endl;

	if(!mode){
		for (int i = 0; i <= total; i++){
			if (x == 9 && Cadastro[i].status){	// se for 9 lista TODOS os ativos
				cout << "ID: " << Cadastro[i].id << endl;
				cout << "Nome: " << Cadastro[i].nome << endl;
				cout << "----------" << endl;
			}else if (x == 10 && !Cadastro[i].status){	// se for 10 lista só os inativos
				cout << "ID: " << Cadastro[i].id << endl;
				cout << "Nome: " << Cadastro[i].nome << endl;
				cout << "----------" << endl;		
			}else if ((x == Cadastro[i].cargo) && Cadastro[i].status){	// se x for igual ao cargo, lista os ativos com este cargo
				cout << "ID: " << Cadastro[i].id << endl;
				cout << "Nome: " << Cadastro[i].nome << endl;
				cout << "----------" << endl;
			}
			
		}
		pausar();
	}else{
		for (int i = 0; i <= total; i++){
			if (x == 9 && Cadastro[i].status){	// se for 9 lista TODOS os ativos
				cout << "ID: [" << Cadastro[i].id << "]" << endl;
				cout << "Nome: " << Cadastro[i].nome << endl;
				cout << "Email: " << Cadastro[i].email << endl;
				cout << "Idade: " << Cadastro[i].idade << endl;
				cout << "Cargo: "; switch(Cadastro[i].cargo){case 0: cout << "Administrador";  break; case 1: cout << "Funcionário"; break; case 2: cout << "Cliente"; break;} cout << endl;
				cout << "----------" << endl;
			}else if (x == 10 && !Cadastro[i].status){	// se for 10 lista só os inativos
				cout << "ID: [" << Cadastro[i].id << "]" << endl;
				cout << "Nome: " << Cadastro[i].nome << endl;
				cout << "Email: " << Cadastro[i].email << endl;
				cout << "Idade: " << Cadastro[i].idade << endl;
				cout << "Cargo: "; switch(Cadastro[i].cargo){case 0: cout << "Administrador";  break; case 1: cout << "Funcionário"; break; case 2: cout << "Cliente"; break;} cout << endl;
				cout << "----------" << endl;	
			}else if ((x == Cadastro[i].cargo) && Cadastro[i].status){	// se x for igual ao cargo, lista os ativos com este cargo
				cout << "ID: [" << Cadastro[i].id << "]" << endl;
				cout << "Nome: " << Cadastro[i].nome << endl;
				cout << "Email: " << Cadastro[i].email << endl;
				cout << "Idade: " << Cadastro[i].idade << endl;
				cout << "Cargo: "; switch(Cadastro[i].cargo){case 0: cout << "Administrador";  break; case 1: cout << "Funcionário"; break; case 2: cout << "Cliente"; break;} cout << endl;
				cout << "----------" << endl;
			}
			
		}
		pausar();
	}
}
/* FUNÇÃO PARA LISTAR USUÁRIOS */