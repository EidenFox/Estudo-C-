#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Define as constantes do programa
//Velocidade real do cavalo base
#define Vbase 2	

//Velocidade apresentada no Jade do cavalo base
#define Vjade 2

//Pulo real do cavalo base
#define Jbase 2

//Pulo apresentado no Jade do cavalo base
#define Jjade 2




int main() {
	SetConsoleOutputCP(CP_UTF8);
	
	int i, cor, escolha;
	
	cout << "Agora vamos escolher a Cor do seu cavalo!\nTemos algumas opções:\n";
		
	//Criação dos Vetores com nomes e ID das raças de Cavalo
	vector<string> racas;
	vector<int> racasID;
	
	//Inserindo dados na tabela, sempre 1 nome e 1 id em sequencia (Nome i equivale a ID i)	
	racas.push_back("Branco");
	racasID.push_back(0);
	
	racas.push_back("Branco/Branco");		
	racasID.push_back(256);	
		
	racas.push_back("Branco/Campos Brancos");		
	racasID.push_back(512);
	
	racas.push_back("Branco/Manchas Brancas");		
	racasID.push_back(768);
	
	racas.push_back("Branco/Manchas Pretas");		
	racasID.push_back(1024);
	
	racas.push_back("Creme");	
	racasID.push_back(1);	
	
	racas.push_back("Creme/Branco");		
	racasID.push_back(257);
	
	racas.push_back("Creme/Campos Brancos");		
	racasID.push_back(513);		
	
	racas.push_back("Creme/Manchas Brancas");		
	racasID.push_back(769);
			
	racas.push_back("Creme/Manchas Pretas");		
	racasID.push_back(1025);		
	
	racas.push_back("Castanho");		
	racasID.push_back(2);		
	
	racas.push_back("Castanho/Branco");	
	racasID.push_back(258);
	
	racas.push_back("Castanho/Campos Brancos");		
	racasID.push_back(514);		
	
	racas.push_back("Castanho/Manchas Brancas");		
	racasID.push_back(770);		
	
	racas.push_back("Castanho/Manchas Pretas");		
	racasID.push_back(1026);		
	
	racas.push_back("Marrom");		
	racasID.push_back(3);		
	
	racas.push_back("Marrom/Branco");		
	racasID.push_back(259);		
	
	racas.push_back("Marrom/Campos Brancos");	
	racasID.push_back(515);		
	
	racas.push_back("Marrom/Manchas Brancas");		
	racasID.push_back(771);
	
	racas.push_back("Marrom/Manchas Pretas");		
	racasID.push_back(1027);		
	
	racas.push_back("Preto");		
	racasID.push_back(4);		
	
	racas.push_back("Preto/Branco");		
	racasID.push_back(260);		
	
	racas.push_back("Preto/Campos Brancos");		
	racasID.push_back(516);		
	
	racas.push_back("Preto/Manchas Brancas");		
	racasID.push_back(772);		
	
	racas.push_back("Preto/Manchas Pretas");		
	racasID.push_back(1028);		
	
	racas.push_back("Cinza");		
	racasID.push_back(5);		
	
	racas.push_back("Cinza/Branco");		
	racasID.push_back(261);		
	
	racas.push_back("Cinza/Campos Brancos");		
	racasID.push_back(517);		
	
	racas.push_back("Cinza/Manchas Brancas");	
	racasID.push_back(773);		
	
	racas.push_back("Cinza/Manchas Pretas");		
	racasID.push_back(1029);		
	
	racas.push_back("Marrom Escuro");
	racasID.push_back(6);		
	
	racas.push_back("Marrom Escuro/Branco");		
	racasID.push_back(262);		
	
	racas.push_back("Marrom Escuro/Campos Brancos");		
	racasID.push_back(518);		
	
	racas.push_back("Marrom Escuro/Manchas Brancas");		
	racasID.push_back(774);	
	
	racas.push_back("Marrom Escuro/Manchas Pretas");		
	racasID.push_back(1030);
	
	for (i = 0; i < racas.size(); i++){
		cout << "[" << i+1 << "] " << racas[i] << endl;
	}

	cout << "\nQual a cor desejada?"; cin >> escolha;
	
	
	
	 if (escolha > 0 && escolha < (racas.size() +1) ) {
		cor=racasID[escolha-1];
		
		cout << "\n\n A cor escolhida foi: " << racas[escolha-1] << " com o código: " << cor << endl;
	} else {
        cout << "\nOpcao invalida!" << endl;
    }

    return 0;
}
