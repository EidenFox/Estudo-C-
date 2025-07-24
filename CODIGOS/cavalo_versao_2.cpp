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
#define Vbase 2		//Velocidade real do cavalo base
#define Vjade 2		//Velocidade apresentada no Jade do cavalo base
#define Jbase 2		//Pulo real do cavalo base
#define Jjade 2		//Pulo apresentado no Jade do cavalo base

#define numRacas 35		// Define o numero de raças possiveis (para serem apresentadas na tela)
						// numero deve ser igual ao da tabela para não apresentar informações erradas
						// editar informações na própria tabela



//float calculo (float z, int calc) {
//	float res;
//
//	if(calc == 1){	
//		res = (z*Vbase)/Vjade;
//	}else if(calc == 2){
//		res = (z*Jbase)/Jjade;
//	}else{
//		cout << "Erro interno"
//	}
//	
//	
//	      return res;
//
//}
	

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int Health, Color, choice, exit, calc;
	float Jump, Speed, Fjump, Fspeed;
	string Name, Armor;

	cout << "Bem vindo ao programa de conversão e summon de cavalos.\nNo Minecraft cavalos tem statisticas em relação a sua velocidade, vida, cor, força de pulo e etc. no servidor em que eu jogo existe um plugin em que esses detalhes são apresentados, mas eles não coincidem com o que o minecraft aceita, por este motivo criei este programa para converter estes valores e criar um comando para sumonar o cavalo" << endl;
	cout << "\nVamos começar!\n\nPrimeiramente me conte o NOME do seu cavalo: "; cin >> Name;
	cout << "\nPerfeito, o nome será \"" << Name << "\"!" << endl;
	sleep(3);
	
	exit = 0;
	do{
		system("cls");	
		cout << "Vamos para a parte estética.\nSeu cavalo usa armadura? selecione uma opção:\n[1] Nenhuma\n[2] Armadura de Couro\n[3] Armadura de Ferro\n[4] Armadura de Ouro\n[5] Armadura de Diamante\n\nEscola sua opção: ";
		cin >> choice;
		switch (choice) {
	        case 1: 
	        	Armor = "";
	        	exit = 1;
	        	break;
	        case 2: 
	        	Armor = "minecraft:leather_horse_armor";
	        	exit = 1;
				break;
	        case 3: 
	        	Armor = "minecraft:iron_horse_armor";
	        	exit = 1;
				break;
	        case 4: 
	        	Armor = "minecraft:golden_horse_armor";
	        	exit = 1;
				break;
	        case 5: 
	        	Armor = "minecraft:diamond_horse_armor";
	        	exit = 1;
	        	break;
	        default: 
	        	cout << "Opção Invalida, tente novamente!" << endl;
	        	exit = 0;
				sleep(3);
	        	
			break;	
		}

	} while (exit != 1);
	
	


	//	print the command on the console so the user can copy it
	cout << "----------------------------------" << endl;
	cout << "\n\n\n/minecraft:summon horse ~ ~1 ~ {Health:" << Health <<"f,Temper:100,Variant:" << Color << "0,CustomName:'\"" << Name << "\"',ArmorItems:[{},{},{id:\"" << Armor << "\",count:1},{}],attributes:[{id:\"minecraft:jump_strength\",base:" << Fjump << ",{id:\"minecraft:max_health\",base:" << Health << "},{id:\"minecraft:movement_speed\",base:" << Fspeed <<"}],SaddleItem:{id:\"minecraft:saddle\",count:1b}}\n\n\n" << endl;
	cout << "----------------------------------" << endl;

	return 0;
}
