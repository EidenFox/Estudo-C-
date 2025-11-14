#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <string>

#define ARQUIVO ".\\arquivos\\dados.txt"
#define LIMITE 100
#define TAMNOME 50

FILE *pont_arq;

using namespace std;

/* Prototipação das funções */
void cadastrar(Pessoa Cadastro[]);
bool coletarDados(Pessoa Cadastro[]);
bool abrirArquivo(bool tipo);
/* Prototipação das funções */

/* STRUCTS */
typedef struct Pessoa {
    int id;
    char nome[TAMNOME];
    int idade;
    string email;
} Pessoa;
/* STRUCTS */


int main() {
    SetConsoleOutputCP(CP_UTF8);

    Pessoa Cadastro[LIMITE];
    int i;
    
    if(coletarDados(Cadastro)){
    	cadastrar(Cadastro);
	}else cout << "Erro critico na leitura do arquivo, programa encerrado!" << endl;
	
    fclose(pont_arq);

    return 0;
}




/* FUNÇÃO PARA COLETAR OS DADOS DO ARQUIVO */
bool coletarDados(Pessoa Cadastro[]) {
    if (!abrirArquivo(false)) {
        return false;
    }

    pont_arq = fopen(ARQUIVO, "r");		//Abre o arquivo
    if (pont_arq == NULL) return false;

    char linha[256]
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
    }

    fclose(pont_arq);
    return true;
}

bool coletarDados(Pessoa Cadastro[]){
	if(abrirArquivo(false)){
		
		while (fgets (frase, 100, pont_arq)){ // enquanto não chegar ao fim do arquivo
            if (ferror(pont_arq)){	// verifica se houve erros na leitura
                printf ("Erro na leitura!");
            }else{
            	char campo[TAMNOME];
            	for (int i = 0; i < 100; i++){
            		do{
            			//implementar a lógica que faz funcionar pq agr nn ta funcionando nn!
					}while (campo == '|')
				}	
			}
                
        }



	}else{
		fclose(pont_arq);
		return false;
	}
	fclose(pont_arq);
}

/* FIM DA FUNÇÃO DE COLETA*/



/* FUNÇÃO PARA CADASTRAR*/
void cadastrar(Pessoa Cadastro[]) {
    bool sair = false;
    char sairC;
    int i = 0;
	bool ok = false;

	if(abrirArquivo(true)){
	    do {
	        Cadastro[i].id = i + 1;
	        fprintf(pont_arq, "%d|", Cadastro[i].id);
	
	//		do{
				
	        cout << "Digite o nome: ";
			fflush(stdin);
	        cin.getline(Cadastro[i].nome, 50);
	        fprintf(pont_arq, "%s|", Cadastro[i].nome);
	//		}while (!ok);
	
	        cout << "Digite a idade: ";
			scanf("%d", &Cadastro[i].idade);
			fprintf(pont_arq, "%d|", Cadastro[i].idade);
	
	        cout << "Digite o email: ";
	        fflush(stdin);
	        getline(cin, Cadastro[i].email);
	        fprintf(pont_arq, "%s\n", Cadastro[i].email.c_str());
	
	        cout << "Realizar novo cadastro? [S/N]: ";
	        fflush(stdin);
	        cin >> sairC;
	        sair = (tolower(sairC) != 's');
	
	        i++;
	        if (i >= LIMITE) {
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
		fclose(pont_arq);
		return true;
	}
}
/* FIM DA ABERTURA DE ARQUIVO */



