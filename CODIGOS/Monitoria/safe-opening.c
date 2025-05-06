#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>


// Programs will be made in both Portuguese and English
// Programas serão feitos em Português e Inglês



void setPass (){
	int i;
	
	for (i = 0; i <= 2; i++){
		printf("\nEscreva o digito da senha: ");
		printf("\nType the password digit: \n");		
		scanf("%d", &pass[i]);
	}

	printf("\n\nsenha registrada: ");
	printf("\n\npassword registered: ");
	for (i = 0; i <= 2; i++){
		printf("%d", pass[i]);
	}
	
	sleep(5);
	system("cls");
	
	
}


int password();{
	printf("Digite o lado que deseja rodar: ");
	printf("\nType the side you want to turn (R/L): ");
	fflush(stdin);
	scanf("%c", &side);
	
	printf("Digite o numero que deseja inserir: ");
	printf("\nType the number you want to input: ");
	scanf("%d", &num);
	
	if ((side == 'r' || side == 'R') && (num == pass[0])){
			system("cls");
			
			printf("Digite o lado que deseja rodar: ");
			printf("\nType the side you want to turn (R/L): ");
			fflush(stdin);
			scanf("%c", &side);
			
			printf("Digite o numero que deseja inserir: ");
			printf("\nType the number you want to input: ");
			scanf("%d", &num);
			
			if ((side == 'l' || side == 'L') && (num == pass[1])){
				system("cls");
			
				printf("Digite o lado que deseja rodar: ");
				printf("\nType the side you want to turn (R/L): ");
				fflush(stdin);
				scanf("%c", &side);
				
				printf("Digite o numero que deseja inserir: ");
				printf("\nType the number you want to input: ");
				scanf("%d", &num);
				
				if ((side == 'r' || side == 'r') && (num == pass[2])){				
					system("cls");
					printf("Cofre aberto!");
					printf("Safe Open!");
					
					open = 1;
				}
			}
			
		}else{
			printf("Senha incorreta!");
			open = 0;
		}
	return open;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

	int num;
	int pass[3] = {0, 0, 0};
	char side;
	int open = 0;
	
	
	
    return 0;
}
