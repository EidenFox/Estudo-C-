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
//Define o tempo em que a informação é mostrada na tela antes de passar para a proxima etapa
#define timer 0

//Velocidade real do cavalo base
#define Vbase 2	

//Velocidade apresentada no Jade do cavalo base
#define Vjade 20

//Pulo real do cavalo base
#define Jbase 1

//Pulo apresentado no Jade do cavalo base
#define Jjade 20

//variavel global para a cor do cavalo
string corFinal;

float calculo (float z, int calc) {
	float res;

	if(calc == 1){	
		res = (z*Vbase)/Vjade;
	}else if(calc == 2){
		res = (z*Jbase)/Jjade;
	}else{
		cout << "Erro interno";
	}
	
	
	      return res;

}

int escolherCavalo(){

	int i, cor, escolha;
	int fim = 0;	
	
	
	do{
		
		system("cls");	
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
	
		cout << "\nQual a cor desejada? "; cin >> escolha;
		
		
		
		 if (escolha > 0 && escolha < (racas.size() +1) ) {
			cor=racasID[escolha-1];
			fim = 1;
			cout << "\n\nA cor escolhida foi: " << racas[escolha-1] << endl;
			corFinal = racas[escolha-1];
		} else {
	        cout << "\nOpcao invalida!" << endl;
	        sleep(timer);
	    }
	}while (fim != 1);

    return cor;
}

void Copiar(string& texto){
	//abre a area de transferencia
	if (OpenClipboard(nullptr)) {
		//limpa a area de transferencia
		EmptyClipboard();
		
		//Aloca espaço na area de transferencia (tamanho do texto + 1)
        HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, texto.size() + 1);
		
		if (hGlob) {
            memcpy(GlobalLock(hGlob), texto.c_str(), texto.size() + 1);
            GlobalUnlock(hGlob);

            // Define o conteúdo da área de transferência como texto
            SetClipboardData(CF_TEXT, hGlob);
        }

        // Fecha a área de transferência
        CloseClipboard();
	}

}
	

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int Health, Color, choice, exit, calc;
	float Jump, Speed, Fjump, Fspeed, healthMax;
	string Name, Armor, comando, armorFinal;

	cout << "Bem vindo ao programa de conversão e summon de cavalos.\nNo Minecraft cavalos tem statisticas em relação a sua velocidade, vida, cor, força de pulo e etc. no servidor em que eu jogo existe um plugin em que esses detalhes são apresentados, mas eles não coincidem com o que o minecraft aceita, por este motivo criei este programa para converter estes valores e criar um comando para sumonar o cavalo" << endl;
	cout << "\nVamos começar!\n\nPrimeiramente me conte o NOME do seu cavalo: "; cin >> Name;
	cout << "\nPerfeito, o nome será \"" << Name << "\"!" << endl;
	sleep(timer);
	
	exit = 0;
	do{
		system("cls");	
		cout << "Vamos para a parte estética.\nSeu cavalo usa armadura? selecione uma opção:\n[1] Nenhuma\n[2] Armadura de Couro\n[3] Armadura de Ferro\n[4] Armadura de Ouro\n[5] Armadura de Diamante\n\nEscola sua opção: ";
		cin >> choice;
		switch (choice) {
	        case 1: 
	        	cout << "Armadura escolhida: Nenhuma";
	        	Armor = "";
	        	armorFinal = "não usará nenhuma armadura";
	        	exit = 1;
	        	break;
	        case 2: 
	        	cout << "Armadura escolhida: Armadura de Couro";
	        	Armor = "minecraft:leather_horse_armor";
	        	armorFinal = "usará uma armadura de Couro";
				exit = 1;
				break;
	        case 3: 
	        	cout << "Armadura escolhida: Armadura de Ferro";
	        	Armor = "minecraft:iron_horse_armor";
	        	armorFinal = "usará uma armadura de Ferro";
	        	exit = 1;
				break;
	        case 4: 
	        	cout << "Armadura escolhida: Armadura de Ouro";
	        	Armor = "minecraft:golden_horse_armor";
	        	armorFinal = "usará uma armadura de Ouro";
	        	exit = 1;
				break;
	        case 5: 
	        	cout << "Armadura escolhida: Armadura de Diamantes";
	        	Armor = "minecraft:diamond_horse_armor";
	        	armorFinal = "usará uma armadura de Diamante";
	        	exit = 1;
	        	break;
	        default: 
	        	cout << "Opção Invalida, tente novamente!" << endl;
	        	exit = 0;
				sleep(timer);
			break;	
		}

	} while (exit != 1);
	
	sleep(timer);
	
	Color = escolherCavalo();
	
	sleep(timer);
	
	system("cls");
	cout << "Decididas as caracteristicas estéticas, vamos para as caracteristicas Fisicas." << endl;
	cout << "Vamos começar com a Vida, Digite a VIDA MAXIMA (numero de corações * 2) do seu cavalo: "; cin >> Health;
	healthMax = (Health/2.0);
	
	cout << "\nPerfeito, seu cavalo terá " << Health << " de vida (equivalente a " << healthMax << " corações)." << endl;
	sleep(timer);
	system("cls");
	
	cout << "Agora decida a Velocidade do seu Cavalo. Olhe para o cavalo com o mod Jade instalado e escreva o valor \"Speed\": "; cin >> Speed;
	Fspeed = calculo(Speed,1);
	cout << "Ok, a velocidade " << Speed << " do seu cavalo equivale a " << Fspeed << endl;
	sleep(timer);
	system("cls");
	
	cout << "Agora decida a Força de Pulo do seu Cavalo. Olhe para o cavalo com o mod Jade instalado e escreva o valor \"Jump Strenght\": "; cin >> Jump;
	Fjump = calculo(Jump,2);
	cout << "Ok, a força de Pulo " << Jump << " do seu cavalo equivale a " << Fjump << endl;
	sleep(timer);
	system("cls");
	
 
	comando = "/minecraft:summon horse ~ ~1 ~ {Health:" + to_string(Health) + "f,Temper:100,Variant:" + to_string(Color) + ",CustomName:'\"" + Name + "\"',ArmorItems:[{},{},{id:\"" + Armor + "\",count:1},{}],attributes:[{id:\"minecraft:jump_strength\",base:" + to_string(Fjump) + "},{id:\"minecraft:max_health\",base:" + to_string(Health) + "},{id:\"minecraft:movement_speed\",base:" + to_string(Fspeed) + "}],SaddleItem:{id:\"minecraft:saddle\",count:1b}}";
	//	print the command on the console so the user can copy it
	cout << "----------------------------------" << endl;
	cout << "Seu comando está pronto:\nA vida do cavalo ficou " << healthMax << " corações;\nSeu cavalo " << armorFinal << ";\nSua cor será " << corFinal << ";\nSua velocidade será: " << Speed << " e seu pulo será " << Jump << ".\n\n" << endl;
	cout << comando << endl;
	cout << "----------------------------------" << endl;
	
    Copiar(comando);
    cout << "\nComando copiado para a área de transferência!" << endl;

	return 0;
}


