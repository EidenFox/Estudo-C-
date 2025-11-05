#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include<conio.h>


typedef struct impressoras{
	int id;
	char marca[20];
	int impressoes;
}impressoras;



void contaImpressoras(impressoras impressora[], int n){
	int maior = 0;
	int id = 0;
	for (int i=0; i<n; i++){
		if(impressora[i].impressoes > maior){
			maior = impressora[i].impressoes;
			id = i;
		} 
	}
	puts("\n---------------\n");
	puts("Impressora com maior numero de impressões");
	printf("\nId da impressora: %d", impressora[id].id);
	printf("\nMarca da impressora: %s", impressora[id].marca);
	printf("\nNumero de impressões: %d", impressora[id].impressoes);
	puts("\n---------------\n\n");
	Sleep(10000);
	
}


void listImpressoras(impressoras impressora[], int n){
	system("cls");
	for (int i=0; i<n; i++){	
		printf("\n\nId da impressora: %d", impressora[i].id);
		printf("\nMarca da impressora: %s", impressora[i].marca);
		printf("\nNumero de impressões: %d\n\n", impressora[i].impressoes);
		}
	system("pause");
}



void cadImpressoras(impressoras impressora[], int n){
	
	for (int i=0; i<n; i++){
		printf("Digite o id da impressora numero %d: ", i+1);
		scanf("%d", &impressora[i].id);
		fflush(stdin);
		printf("Digite o modelo da impressora: ");		
		gets(impressora[i].marca);
		fflush(stdin);
		printf("Digite a quantidade de impressões da impressora: ");
		scanf("%d", &impressora[i].impressoes);
		puts("--------------\n\n");
	}
	
	puts("Cadastro Concluido!");
	Sleep(3000);
	
}





int main() {
	
    setlocale (LC_ALL, "portuguese");

	bool sair = false;
	int op, n;
	
	puts("Quantas impressoras gostaria de cadastra?");
	scanf("%d", &n);
	impressoras impressora[n];
	
	do{
	
		system("cls");
		puts("--------------------");
		puts("-------MENU---------");
		puts("--------------------");
		puts("[1] Cadastrar impressoras.");
		puts("[2] Listar impressoras cadastradas.");
		puts("[3] Verificar impressora de maior uso");
		puts("[0] SAIR!");
		printf("Opção desejada: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				cadImpressoras(impressora,n);
				break;
			case 2:{
				listImpressoras(impressora,n);			
				break;}
			case 3:
				contaImpressoras(impressora,n);
				break;
			default:
				puts("Opção Inválida, tente novamente\n");
				Sleep(3000);
				break;
			case 0:
				system("cls");
				printf("Saindo");
				for (int i=0; i<3; i++){
					Sleep(1000);
					printf(".");
				}
				sair = true;
				break;
		}
		
	}while(!sair);




    return 0;
}
