#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#include "cadastros.h"

/* CONSTANTES E VARIAVEIS GLOBAIS */
FILE *pont_arq;
int total = -1;
/* CONSTANTES E VARIAVEIS GLOBAIS */




/* FUNÇÃO PARA COLETAR OS DADOS DO ARQUIVO */
bool coletarDados(Pessoa Cadastro[]) {
    if (!abrirArquivo(false)) {
        return false;
    }
    if (pont_arq == NULL) return false;

    char linha[256];
    int i = 0;

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

        i++;
        total++;
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

	if(abrirArquivo(true)){
		cignore;
	    do {
	        Cadastro[total].id = total + 1;
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
bool abrirArquivo(bool tipo){
	if(tipo){//		tipo verdadeiro = escrever
		pont_arq = fopen(CADASTRO, "a");
		
	}else{//		tipo falso = ler
		pont_arq = fopen(CADASTRO, "r");
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
	for (int i = 0; i < total; i++){
		lEmailCheck = toLower(Cadastro[i].email);

		if(lEmail == lEmailCheck && senha == Cadastro[i].senha){
			return i;
		}
	}
	return -1;
}
/* FUNÇÃO PARA CHECAR O LOGIN*/

