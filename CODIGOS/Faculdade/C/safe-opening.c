#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>


// Programs will be made in both Portuguese and English
// Programas serão feitos em Português e Inglês



int setPass (int pass[], int open){
	int i;
	int error = 0;
	char dir;
	
	system("cls");
	for (i = 0; i <= 2; i++){
		printf("\nEscreva o %dº digito da senha: ", i+1);
		printf("\nType the %dº password digit: \n", i+1);		
		scanf("%d", &pass[i]);
	}
	
	system("cls");
	if(pass[0] == 0 && pass[1] == 0 && pass[2] == 0){
		printf("Senha invalida, cofre permanecerá aberto!");
		printf("Invalid Password, safe will remain open!");
		open = 1;
	}else{
		printf("\n\nsenha registrada: ");
		printf("\npassword registered: \n");
		for (i = 0; i <= 2; i++){
			if (i != 1){
				dir = 'R';
			}else{
				dir = 'L';
			}
			printf("%c%d ", dir, pass[i]);
		}
		open = 0;
	}
	sleep(5);
	system("cls");
	return open;
}


int password(const int pass[], int open){
	char side;
	int num;
	
	system("cls");
	printf("Digite o lado que deseja rodar (R/L): ");
	printf("\nType the side you want to turn (R/L):\n");
	fflush(stdin);
	scanf("%c", &side);
	
	printf("Digite o numero que deseja inserir: ");
	printf("\nType the number you want to input:\n");
	scanf("%d", &num);
	
	if ((side == 'r' || side == 'R') && (num == pass[0])){
			
			system("cls");
			printf("Digite o lado que deseja rodar (R/L): ");
			printf("\nType the side you want to turn (R/L):\n");
			fflush(stdin);
			scanf("%c", &side);
			
			printf("Digite o numero que deseja inserir: ");
			printf("\nType the number you want to input:\n");
			scanf("%d", &num);
			
			if ((side == 'l' || side == 'L') && (num == pass[1])){
				
				system("cls");
				printf("Digite o lado que deseja rodar (R/L): ");
				printf("\nType the side you want to turn (R/L):\n");
				fflush(stdin);
				scanf("%c", &side);
				
				printf("Digite o numero que deseja inserir: ");
				printf("\nType the number you want to input:\n");
				scanf("%d", &num);
				
				if ((side == 'r' || side == 'R') && (num == pass[2])){				
					system("cls");
					printf("Cofre aberto!");
					printf("Safe Open!");
					
					open = 1;
				}else{
				printf("Senha incorreta!");
				open = 0;
				sleep(3);
				}
			}else{
				printf("Senha incorreta!");
				open = 0;
				sleep(3);
			}
			
		}else{
			printf("Senha incorreta!");
			open = 0;
			sleep(3);
		}
		system("cls");
	return open;
}

data(){
	system("cls");
	printf("\n\nSe voce esta lendo esta mensagem o cofre foi aberto com sucesso!");
	printf("\nIf you are reading this message the safe was successfully opened!\n\n");
	sleep(5);
}


int main() {
	
	//ao invez de "setlocale (LC_ALL "Portugues")" 
	//eu uso este comando por usar uma versão diferente do DevC++
    SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_ALL, "Portuguese");

	int menu;
	int pass[3] = {0, 0, 0};
	int open = 1;
	int exit = 0;
	
	do{
		system("cls");
		printf("\n\nBem vindo ao programa de Senha de Cofre. \nSelecione uma opção:");
		printf("\n1. Escolher/Mudar senha");
		printf("\n2. Abrir cofre ");
		printf("\n3. Trancar Cofre");
		printf("\n4. Acessar Arquivos");
		printf("\n0. Sair");
		if(open == 1){
			printf("\n\nEstado do Cofre: ABERTO");
		}else{
			printf("\n\nEstado do Cofre: FECHADO");
		}
		printf("\n-----------------------------\n\n");
		printf("Wellcome to the Safe Password Program. Select an option: ");
		printf("\n1. Set/Change Password");
		printf("\n2. Open Safe");
		printf("\n3. Lock Safe");
		printf("\n4. Acess Files");
		printf("\n0. Exit");
		if(open == 1){
			printf("\n\nSafe State: OPEN");
		}else{
			printf("\n\nSafe State: CLOSED");
		}
		printf("\n-----------------------------\n\n");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:
				system("cls");
				if (open == 0){
					open = password(pass, open);
					
					if (open != 0){
					open = setPass(pass, open);
					}
				}else{
					open = setPass(pass, open);
				}
				break;
			
			case 2:
				system("cls");
				if(open == 1){
					printf("\n\nCofre Já aberto!");
					printf("\nSafe Already Open!");
					sleep(2);
				}else{
					open = password(pass, open);
				}
				break;
			
			case 3:
				system("cls");
				if(pass[0] == 0 && pass[1] == 0 && pass[2] == 0){
					printf("\n\nNenhuma senha cadastrada, cofre permanecerá aberto!");
					printf("\nNo password registered, safe will remain open!\n");
					open = 1;
				}else{
				printf("\nCofre Trancado!");
				printf("\nSafe Locked!");
				open = 0;
				}
				sleep(2);
				break;
			
			case 4:
				system("cls");
				if (open == 0){
					open = password(pass, open);
					
					if (open != 0){
					printf("Acesso Concedido!\n\n");
					printf("Acess Granted");
					data();
					}
				}else{
					printf("Acesso Concedido!\n\n");
					printf("Acess Granted");
					data();
				}
				break;
			
			case 0:
				system("cls");
				printf("\nObrigado por testar meu programa!");
				printf("\nThank you for testing my program!\n\n");
				sleep(5);
				exit = 1;
				break;
			
			default:
				printf("Opção não reconhecida, Tente Novamente!");
				printf("Option not recognized, Try Again!");
				break;
		}
	}while (exit != 1);
	
    return 0;
}
