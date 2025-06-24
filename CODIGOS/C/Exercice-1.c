#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <string.h>

/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
using namespace std;
*/


int main() {
    SetConsoleOutputCP(CP_UTF8);
	int escolha, qtd, sair;
	float total;
	char menu;
		
	do{
		
		escolha = 0;
		qtd = 0;
		sair = 0;
		total = 0;

			printf("Bem vindo a Cafeteria Café\n");
			printf("Temos as seguintes opções de bebida:\n\n");
			printf("1. Café Forte\n");
			printf("	↳ R$ 5,00\n\n");
			printf("2. Café Extra-Forte\n");
			printf("	↳ R$ 7,00\n\n");
			printf("3. Café Especial\n");
			printf("	↳ R$ 9,00\n\n");
			printf("Escolha sua Bebida: ");
			scanf("%d", &escolha);
			
			switch(escolha){
				case 1:
					total = 5;
					sair = 1;
					break;
				case 2:
					total = 7;
					sair = 1;
					break;
				case 3:
					total = 9;
					sair = 1;
					break;
				default: 
					printf("Opção Inválida");
					Sleep(300);
					break;
			} 
			
			system("cls");		
		
		do{
			printf("Seu total até agora é de: %.2f\n\n", total);
			printf("Temos as seguintes opções de acompanhamento: \n\n");
			printf("1. Pão de queijo\n");
			printf("	↳ R$ 1,00\n\n");
			printf("2. Coxinha de Frango\n");
			printf("	↳ R$ 3,50\n\n");
			printf("3. Esfirra de Carne\n");
			printf("	↳ R$ 4,00\n\n");
			printf("Pressione 0 para finalizar a compra\n");
			printf("Agora escolha o seu acompanhamento: ");
			scanf("%d", &escolha);
			
			switch(escolha){
				case 1:
					printf("1. Pão de queijo\n");
					printf("	↳ R$ 1,00\n\n");
					printf("Quantos Pães de Queijo gostaria: ");
					scanf("%d", &qtd);
					total = total + (qtd * 1);
					break;
				case 2:
					printf("2. Coxinha de Frango\n");
					printf("	↳ R$ 3,50\n\n");
					printf("Quantas Coxinhas gostaria: ");
					scanf("%d", &qtd);
					total = total + (qtd * 3.5);
					break;
				case 3:
					printf("3. Esfirra de Carne\n");
					printf("	↳ R$ 4,00\n\n");
					printf("Quantas esfirras gostaria: ");
					scanf("%d", &qtd);
					total = total + (qtd * 4);
					break;
				case 0:
					sair = 1;
					break;
				default:
				system("cls"); 
					printf("Opção Inválida");
					Sleep(300);
					break;				
			}
			Sleep(100);
			system("cls");
			
			
		} while (sair != 1);
		
		printf("O total da sua compra é de: %.2f\n\n", total);
		
		
		Sleep(2000);
		system("cls");
		printf("Deseja realizar nova compra? (S/N)");
		fflush(stdin);
		menu = getch();
		
		
	}while((menu != 'N') && (menu != 'n'));

    return 0;
}
