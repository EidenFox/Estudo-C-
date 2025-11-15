#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <string>

/* CONSTANTES E VARIAVEIS GLOBAIS */
#define ARQUIVO ".\\arquivos\\dados.txt"
#define LIMITE 100
#define TAMNOME 50

int total = 0;

/* CONSTANTES E VARIAVEIS GLOBAIS */

FILE *pont_arq;

using namespace std;


/* STRUCTS */
typedef struct Pessoa {
    int id;
    char nome[TAMNOME];
    int idade;
    string email;
} Pessoa;
/* STRUCTS */

/* Prototipação das funções */
void cadastrar(Pessoa Cadastro[]);
bool coletarDados(Pessoa Cadastro[]);
bool abrirArquivo(bool tipo);
/* Prototipação das funções */

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Pessoa Cadastro[LIMITE];
    int i;
		
		
	cout << "cadastro 1:" << Cadastro[1].nome << endl;    
    if(coletarDados(Cadastro)){
    	cadastrar(Cadastro)
;	}else cout << "Erro critico na leitura do arquivo, programa encerrado!" << endl;
    fclose(pont_arq);
    
    
    cout << "cadastro 1:" << Cadastro[1].nome << endl; 
	
    
    
    
    
    

    return 0;
}




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

        i++;
        total++;
    }

    fclose(pont_arq);
    return true;
}


/* FIM DA FUNÇÃO DE COLETA*/



/* FUNÇÃO PARA CADASTRAR*/
void cadastrar(Pessoa Cadastro[]) {
    bool sair = false;
    char sairC;
	bool ok = false;

	if(abrirArquivo(true)){
		if (pont_arq != NULL) fprintf(pont_arq, "\n");
	    do {
	        Cadastro[total].id = total + 1;
	        fprintf(pont_arq, "%d|", Cadastro[total].id);
	
	//		do{
				
	        cout << "Digite o nome: ";
			fflush(stdin);
	        cin.getline(Cadastro[total].nome, 50);
	        fprintf(pont_arq, "%s|", Cadastro[total].nome);
	//		}while (!ok);
	
	        cout << "Digite a idade: ";
			scanf("%d", &Cadastro[total].idade);
			fprintf(pont_arq, "%d|", Cadastro[total].idade);
	
	        cout << "Digite o email: ";
	        fflush(stdin);
	        getline(cin, Cadastro[total].email);
	        fprintf(pont_arq, "%s\n", Cadastro[total].email.c_str());
	
	        cout << "Realizar novo cadastro? [S/N]: ";
	        fflush(stdin);
	        cin >> sairC;
	        sair = (tolower(sairC) != 's');
	
	        total++;
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
		pont_arq = fopen(ARQUIVO, "a");
		
	}else{//		tipo falso = ler
		pont_arq = fopen(ARQUIVO, "r");
	}

    if (pont_arq == NULL) {
        printf("Erro na abertura do arquivo!");
        fclose(pont_arq);
	    return false;
    } else {
        cout << "Arquivo aberto com sucesso!" << endl;
		return true;
	}
}
/* FIM DA ABERTURA DE ARQUIVO */



