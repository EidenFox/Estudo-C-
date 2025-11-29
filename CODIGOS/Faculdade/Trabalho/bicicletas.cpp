#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "cadastros.h"
using namespace std;


/* CONSTANTES E VARIAVEIS GLOBAIS */
FILE *pont_arq2;
int totalB = -1;
/* CONSTANTES E VARIAVEIS GLOBAIS */




/* FUNÇÃO PARA COLETAR OS DADOS DO ARQUIVO */
/* Formato no TXT: ID|MODELO|DESCRICAO|ID_PESSOA|STATUS(0/1) */
bool coletarDadosB(Bicicletas Bicicleta[]) {
    if (!abrirArquivoB(2)) {
        return false;
    }
    if (pont_arq2 == NULL) return false;

    char linha[256];
    int i = 0;
	totalB = -1;

    while (fgets(linha, sizeof(linha), pont_arq2) && i < LIMITE) {
      
        linha[strcspn(linha, "\n")] = '\0';   // Remove \n do final da linha

        char *token = strtok(linha, "|");
        if (token != NULL) Bicicleta[i].id = atoi(token);	//ID

		token = strtok(NULL, "|");
        if (token != NULL) Bicicleta[i].modelo = token;	//Modelo

        token = strtok(NULL, "|");
        if (token != NULL) Bicicleta[i].descricao = token;	//Descrição

		token = strtok(NULL, "|");
        if (token != NULL) Bicicleta[i].idPessoa = atoi(token);	//idPessoa
		
		token = strtok(NULL, "|");
        if (token != NULL) {
            Bicicleta[i].status = (atoi(token) == 1); //Status
        } else {
            Bicicleta[i].status = true;	//se nn tiver status considera "ativo" 
        }
    	totalB = i; 
        i++;
    }

    fclose(pont_arq2);
    return true;
}
/* FIM DA FUNÇÃO DE COLETA*/



/* FUNÇÃO PARA CADASTRAR BICICLETAS*/
void cadastrarB(Bicicletas Bicicleta[]) {
    bool sair = false;
    char sairC;
	bool ok = false;

	if(abrirArquivoB(1)){
		cignore;
	    do {
			totalB++;

			if (totalB >= LIMITE) {
                cout << "Limite de cadastros atingido." << endl;
                totalB--;
                break;
            }

			if (totalB == 0) {
                Bicicleta[totalB].id = 1; 
            } else {
				int maiorID = 0;
				for(int i = 0; i < totalB; i++) {
					if(Bicicleta[i].id > maiorID) maiorID = Bicicleta[i].id;
				}
				Bicicleta[totalB].id = maiorID + 1;
            }


	        fprintf(pont_arq2, "%d|", Bicicleta[totalB].id);
				
	        cout << "Digite o Modelo do Bicicleta: ";
	        getline(cin, Bicicleta[totalB].modelo);
			if (Bicicleta[totalB].modelo.empty()) {
				Bicicleta[totalB].modelo = "-";
			}
	        fprintf(pont_arq2, "%s|", Bicicleta[totalB].modelo.c_str());
	
	        cout << "Digite uma descrição Bicicleta: ";
	        getline(cin, Bicicleta[totalB].descricao);
			if (Bicicleta[totalB].descricao.empty()) {
				Bicicleta[totalB].descricao = "-";
			}
            fprintf(pont_arq2, "%s|", Bicicleta[totalB].descricao.c_str());

			Bicicleta[totalB].idPessoa = 0; //no cadastro o idPessoa é 0, indicando que não está alugada
	        fprintf(pont_arq2, "%d|", 0);

			Bicicleta[totalB].status = true; //Status true no cadastro
	        fprintf(pont_arq2, "%d\n", 1);
			
	        cout << "Realizar novo cadastro? [S/N]: ";
	        cin >> sairC;
			cignore;
	        sair = (tolower(sairC) != 's');
	        if (totalB >= LIMITE) {
	            cout << "Limite de cadastros atingido." << endl;
	            sair = true;
	        }
	
	    } while (!sair);
	}
    fclose(pont_arq2);
}
/* FIM DA FUNÇÃO DE CADASTRAR BICICLETAS */

/* FUNÇÃO PARA ABRIR O ARQUIVO */
bool abrirArquivoB(int tipo){
	if(tipo == 1){//		tipo 1 = escrever
		pont_arq2 = fopen(BICICLETAS, "a");		
	}else if(tipo == 2){//		tipo 2 = ler
		pont_arq2 = fopen(BICICLETAS, "r");
	}else if (tipo == 3){//		tipo 3 = reescrever arquivo
		pont_arq2 = fopen(BICICLETAS, "w");	
	}

    if (pont_arq2 == NULL) {
        printf("Erro na abertura do arquivo!");
	    return false;
    } else {
        cout << "Arquivo aberto com sucesso!" << endl;
		return true;
	}
}
/* FIM DA ABERTURA DE ARQUIVO */


/* FUNÇÃO PARA REESCREVER O ARQUIVO INTEIRO*/
bool reescreverArquivoB(Bicicletas Bicicleta[]) {
    if(!abrirArquivoB(3)) return false; // limpa o arquivo
    
    for (int i = 0; i <= totalB; i++) {
		if(!Bicicleta[i].modelo.empty()){
			fprintf(pont_arq2, "%d|%s|%s|%d|%d\n", 
                Bicicleta[i].id, 
                Bicicleta[i].modelo.c_str(),
                Bicicleta[i].descricao.c_str(),
                Bicicleta[i].idPessoa,
                (Bicicleta[i].status ? 1 : 0)
            );
		}
    }
    fclose(pont_arq2);
	return true;
}
/* FUNÇÃO PARA REESCREVER O ARQUIVO INTEIRO*/



/* FUNÇÃO PARA EDITAR UMA BICICLETA */
bool editarBicicleta(Bicicletas Bicicleta[], Pessoa Cadastro[], int id) {
	//reinicia o totalB para fazer a coleta novamente do struct (pra garantir q esta atualizado antes de reescrever)
    totalB = -1; 
    if (!coletarDadosB(Bicicleta)) {
        cout << "Banco de dados Vazio ou Erro ao ler dados para edição." << endl;
        return false;
    }

    int indice = -1;
    for(int i = 0; i <= totalB; i++){
        if(Bicicleta[i].id == id){
            indice = i;	//captura qual indice tem o ID que queremos alterar
            break;
        }
    }

    if (indice == -1) {	//se o indice for -1 é pq nn achou o id
        cout << "Bicicleta com ID " << id << " não encontrado." << endl;
        timer(3);
        return false;
    }

	// string status;
    int op = 0;
	do{
		limparTela();
		cout << "Editando Bicicleta: [" << Bicicleta[indice].id << "]" << endl;
		cout << "Modelo: " << Bicicleta[indice].modelo << endl;
		cout << "Descrição: " << Bicicleta[indice].descricao << endl;
		cout << "Alugada por: ";
			if (Bicicleta[indice].idPessoa != 0){
				int indicePessoa = -1;
				for (int i = 0; i <= total; i++){
					if(Cadastro[i].id == Bicicleta[indice].idPessoa){
						indicePessoa = i;
						break;
					}
				}
				if(indicePessoa != -1){
					cout << Cadastro[indicePessoa].nome << " (ID: " << Cadastro[indicePessoa].id << ")" << endl;
				}else{
					cout << "[ERRO] Usuário ID " << Bicicleta[indice].idPessoa << " não encontrado!" << endl;
				}
			}else{
				cout << "!- Disponível -!" << endl;
			}
		cout << "Status: "<< (Bicicleta[indice].status ? "Ativo" : "Inativo") << endl;
		cout << "-----------------------" << endl;
		cout << "[1] Alterar Modelo" << endl;
		cout << "[2] Alterar Descrição" << endl;
		cout << "[3] Alterar Usuário" << endl;
		cout << "[4] Alternar Status" << endl;
		if (Bicicleta[indice].idPessoa != 0) {
			cout << "[5] Devolver Bicicleta" << endl;
		}
		cout << "[9] CANCELAR" << endl;
		cout << "[0] SALVAR" << endl;
		cin >> op;
		cignore;

		switch (op) {
			case 1:
				cout << "Novo Modelo: ";
				getline(cin, Bicicleta[indice].modelo);
				if (Bicicleta[indice].modelo.empty()) {
					Bicicleta[indice].modelo = "-";
				}
				break;
			case 2:
				cout << "Nova descrição: ";
				getline(cin, Bicicleta[indice].descricao);
				if (Bicicleta[indice].descricao.empty()) {
					Bicicleta[indice].descricao = "-";
				}
				break;
			case 3:
				cout << "Novo ID de Usuário: ";
				cin >> Bicicleta[indice].idPessoa;
                cignore;
				break;
			case 4:
				Bicicleta[indice].status = !Bicicleta[indice].status;
                cout << "Status alterado." << endl;
                timer(1);
                break;
			case 5:
				if (Bicicleta[indice].idPessoa != 0){
					Bicicleta[indice].idPessoa = 0;
					cout << "BICICLETA DEVOLVIDA" << endl;
					timer(3);
				}else{
					cout << "Opção inválida." << endl;
					timer(3);
				}
				break;
			case 9:
				cout << "Edição Cancelada" << endl;
				timer(2);
				return false;
			case 0:
				cout << "Salvando..." << endl;
				timer(3);
				break;
			default:
				cout << "Opção inválida." << endl;
				timer(3);
				break;
		}
	}while(op != 0);

	//chama a função q reescreve o arquivo
    if(reescreverArquivoB(Bicicleta)){
		cout << "Dados atualizados com sucesso!" << endl;
		timer(2);
		return true;
	}else{
		cout << "Erro ao atualizar arquivo!" << endl;
		timer(2);
		return false;
	}
}
/* FUNÇÃO PARA EDITAR UMA BICICLETA */


/* FUNÇÃO PARA LISTAR BICICLETAS*/
void listarBicicletas(Bicicletas Bicicleta[], Pessoa Cadastro[], int x){
	char sair;
	int id;
	totalB = 0;
	if (!coletarDadosB(Bicicleta)) {
		cout << "Banco de dados Vazio ou Erro ao ler dados para edição." << endl;
		return;
	}


	cout << "--------------------\n-------LISTAR-------\n--------------------\n" << endl;
	if (x == 3){
		cout << "Digite o ID da pessoa que deseja listar: "; cin >> id;
	}
	for (int i = 0; i <= totalB; i++){
		string nome = "[Erro: Usuario nao encontrado]";


		if (Bicicleta[i].idPessoa == 0) {
            nome = "!- Disponivel -";
        } else {
            for (int j = 0; j <= total; j++) {
                if (Bicicleta[i].idPessoa == Cadastro[j].id) {
                    nome = Cadastro[j].nome;	// pega a string do nome baseado no id da pessoa
                    break;
                }
            }
        }


		
		if ((x == 9) && (Bicicleta[i].status)){	// se for 9 lista TODOS os ativos
			cout << "ID: " << Bicicleta[i].id << endl;
			cout << "Modelo: " << Bicicleta[i].modelo << endl;
			cout << "Alugada por: " << nome << endl;
			cout << "----------" << endl;
		}else if ((x == 10) && (!Bicicleta[i].status)){	// se for 10 lista só os inativos
			cout << "ID: " << Bicicleta[i].id << endl;
			cout << "Modelo: " << Bicicleta[i].modelo << endl;
			cout << "Alugada por: " << nome << endl;
			cout << "----------" << endl;		
		}else if ((x == 1) && (Bicicleta[i].status)){	// se for 1 lista todas as ALUGADAS
			cout << "ID: " << Bicicleta[i].id << endl;
			cout << "Modelo: " << Bicicleta[i].modelo << endl;
			cout << "Alugada por: " << nome << endl;
			cout << "----------" << endl;
		}else if ((x == 2) && (Bicicleta[i].idPessoa == 0) && (Bicicleta[i].status)){	// se for 2 lista todas as DISPONIVEIS
			cout << "ID: " << Bicicleta[i].id << endl;
			cout << "Modelo: " << Bicicleta[i].modelo << endl;
			cout << "Alugada por: " << nome << endl;
			cout << "----------" << endl;
		}else if ((x == 3) && (Bicicleta[i].idPessoa == id)){	// se for 3 e id for igual ao IdPessoa, lista os deste usuário
			cout << "ID: " << Bicicleta[i].id << endl;
			cout << "Modelo: " << Bicicleta[i].modelo << endl;
			cout << "Alugada por: " << nome << endl;
			cout << "----------" << endl;
		}
	}
	
	pausar();
}
/* FUNÇÃO PARA LISTAR BICICLETAS */

/* FUNÇÃO PARA DEVOLVER BICICLETA */
void devolucao(Bicicletas Bicicleta[], Pessoa Cadastro[], int id){
    char confirmC;
	string nome = "[Erro: Usuario nao encontrado]";
	int indice = -1;
	bool check = false;
    for(int i = 0; i <= totalB; i++){
        if(Bicicleta[i].id == id){
            indice = i;	//captura qual indice tem o ID que queremos alterar
            break;
        }
    }

    if (indice == -1) {	//se o indice for -1 é pq nn achou o id
        cout << "Bicicleta com ID " << id << " não encontrado." << endl;
        timer(3);
        return;
    }


	for (int j = 0; j <= total; j++) {
		if (Bicicleta[indice].idPessoa == Cadastro[j].id) {
			nome = Cadastro[j].nome;	// pega a string do nome baseado no id da pessoa
			check = true;
			break;
		}
	}

	if (!check){
		cout << "Bicicleta não se encontra alugada!" << endl;
		timer(3);
		return;
	}


	cout << "--DEVOLUÇÃO-DE-BICICLETA--" << endl;
	cout << "ID: " << Bicicleta[indice].id << endl;
	cout << "Modelo: " << Bicicleta[indice].modelo << endl;
	cout << "Alugada por: " << nome << endl;
	cout << "\nTem certeza que deseja Devolver? [s/n]" << endl;
	cin >> confirmC;
	cignore;
	if (tolower(confirmC) == 's'){
		Bicicleta[indice].idPessoa = 0;

		//chama a função q reescreve o arquivo
		if(reescreverArquivoB(Bicicleta)){
			cout << "Bicicleta Devolvida com Sucesso!" << endl;
		}else{
			cout << "Erro ao atualizar arquivo!" << endl;
		}
		timer(2);
		return;
	}
	cout << "Operação Cancelada!" << endl;
	timer(3);	
}
/* FUNÇÃO PARA DEVOLVER BICICLETA */



/* FUNÇÃO PARA ALUGAR BICICLETA */
void aluguel(Bicicletas Bicicleta[], Pessoa Cadastro[], int id, int idP){
    char confirmC;
	string nome = "[Erro: Usuario nao encontrado]";
	int indice = -1;
	int indiceP = -1;
	bool check = false;
	
    
	for(int i = 0; i <= totalB; i++){
		if(Bicicleta[i].id == id){
			indice = i;	//captura qual indice tem o ID que queremos alterar
            break;
        }
    }
	
	if (indice == -1) {	//se o indice for -1 é pq nn achou o id
		cout << "Bicicleta com ID " << id << " não encontrado." << endl;
		timer(3);
		return;
	}


	for (int j = 0; j <= total; j++) {
		if (Cadastro[j].id == idP) {
			nome = Cadastro[j].nome;	// pega a string do nome baseado no id da pessoa
			indiceP = j;
			check = true;
			break;
		}
	}

	if (Bicicleta[indice].idPessoa != 0){
		cout << "Bicicleta já Alugada!" << endl;
		timer(3);
		return;
	}

	if (indiceP == -1){	//se o indice for -1 é pq nn achou o id do usuário
		cout << nome << endl;
		return;
	}


	cout << "--ALUGUEL-DE-BICICLETA--" << endl;
	cout << "ID: " << Bicicleta[indice].id << endl;
	cout << "Modelo: " << Bicicleta[indice].modelo << endl;
	cout << "Alugar para: " << nome << endl;
	cout << "\nTem certeza que deseja Alugar? [s/n]" << endl;
	cin >> confirmC;
	cignore;
	if (tolower(confirmC) == 's'){
		Bicicleta[indice].idPessoa = idP;

		//chama a função q reescreve o arquivo
		if(reescreverArquivoB(Bicicleta)){
			cout << "Bicicleta Alugada com Sucesso!" << endl;
		}else{
			cout << "Erro ao atualizar arquivo!" << endl;
		}
		timer(2);
		return;
	}
	cout << "Operação Cancelada!" << endl;
	timer(3);	
}
/* FUNÇÃO PARA ALUGAR BICICLETA */


