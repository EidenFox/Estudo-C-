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
        if (token != NULL) Cadastro[i].id = atoi(token);

        token = strtok(NULL, "|");
        if (token != NULL) strncpy(Cadastro[i].nome, token, TAMNOME);

        token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].idade = atoi(token);

        token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].email = token;

		token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].cargo = atoi(token);

		token = strtok(NULL, "|");
        if (token != NULL) Cadastro[i].senha = token;

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
                Cadastro[total].id = 0; 
            } else {
                Cadastro[total].id = Cadastro[total - 1].id + 1;
            }
	        fprintf(pont_arq, "%d|", Cadastro[total].id);
	

				
	        cout << "Digite o nome do Usuário: ";
	        cin.getline(Cadastro[total].nome, 50);
	        fprintf(pont_arq, "%s|", Cadastro[total].nome);
	
	        cout << "Digite a idade: ";
			cin >> Cadastro[total].idade;
			cignore;
			fprintf(pont_arq, "%d|", Cadastro[total].idade);
	
	        cout << "Digite o email: ";
	        getline(cin, Cadastro[total].email);
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
	        fprintf(pont_arq, "%s\n", Cadastro[total].senha.c_str());
			
	
	        total++;
			
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
	for (int i = 0; i <= total; i++){
		lEmailCheck = toLower(Cadastro[i].email);

		if(lEmail == lEmailCheck && senha == Cadastro[i].senha){
			return i;
		}
	}
	return -1;
}
/* FUNÇÃO PARA CHECAR O LOGIN*/


/* FUNÇÃO PARA REESCREVER O ARQUIVO INTEIRO*/
bool reescreverArquivo(Pessoa Cadastro[]) {
    if(!abrirArquivo(3)) return false; // limpa o arquivo
    
    for (int i = 0; i <= total; i++) {
		if(Cadastro[i].nome[0] != '\0'){
			fprintf(pont_arq, "%d|%s|%d|%s|%d|%s\n", 
				Cadastro[i].id, 
				Cadastro[i].nome, 
				Cadastro[i].idade, 
				Cadastro[i].email.c_str(), 
				Cadastro[i].cargo, 
				Cadastro[i].senha.c_str()
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


    int op = 0;
	do{
		limparTela();
		cout << "Editando Usuário: [" << Cadastro[indice].id << "]" << endl;
		cout << "Nome: " << Cadastro[indice].nome << endl;
		cout << "Idade: " << Cadastro[indice].idade << endl;
		cout << "Email: " << Cadastro[indice].email << endl;
		cout << "Cargo: " << Cadastro[indice].cargo << endl;
		cout << "-----------------------" << endl;
		cout << "[1] Alterar Nome" << endl;
		cout << "[2] Alterar Idade" << endl;
		cout << "[3] Alterar Email" << endl;
		cout << "[4] Alterar Senha" << endl;
		cout << "[5] Alterar Cargo" << endl;
		cout << "[9] CANCELAR" << endl;
		cout << "[0] SALVAR" << endl;
		cin >> op;
		cignore;

		switch (op) {
			case 1:
				cout << "Novo Nome: ";
				cin.getline(Cadastro[indice].nome, TAMNOME);
				break;
			case 2:
				cout << "Nova Idade: ";
				cin >> Cadastro[indice].idade;
				cignore;
				break;
			case 3:
				cout << "Novo Email: ";
				getline(cin, Cadastro[indice].email);
				break;
			case 4:
				cout << "Nova Senha: ";
				getline(cin, Cadastro[indice].senha);
				break;
			case 5:
				cout << "Novo cargo:\n[0] Administrador\n[1] Funcionário\n[2] Cliente" << endl;
				cin >> Cadastro[indice].cargo;
				break;
			case 9:
				cout << "Edição Cancelada" << endl;
				timer(3);
				return false;
			case 0:
				cout << "Saindo" << endl;
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

