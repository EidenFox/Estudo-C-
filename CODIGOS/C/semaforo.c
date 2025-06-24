#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/

//Definindo o termo "COLOR_<cor>" como uma cor para usar em printf
//Defined the term "COLOR_<color>" as a color to use in printf
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"


int main() {
    SetConsoleOutputCP(CP_UTF8);

	while(1){
		
		
		printf("+---+\n");
		printf("|[ ]|\n");
		printf("|[ ]|======++\n");
		printf("|[");
		
//		Usando o Termo COLOR_<cor> para mudar a cor da luz
//		Using the term COLOR_<color>" to change the color of the light
		printf(COLOR_GREEN "*" COLOR_RESET);;
		printf("]|      ||\n");
		printf("+---+      ||\n");
		printf("           ||\n");
		printf("           ||\n");
		printf("           ||\n");
		sleep(2);
		system("cls");
		
		printf("+---+\n");
		printf("|[ ]|\n");
		printf("|[");
		
//		Usando o Termo COLOR_<cor> para mudar a cor da luz
//		Using the term COLOR_<color>" to change the color of the light
		printf(COLOR_YELLOW "*" COLOR_RESET);
		printf("]|======++\n");
		printf("|[ ]|      ||\n");
		printf("+---+      ||\n");
		printf("           ||\n");
		printf("           ||\n");
		printf("           ||\n");
		sleep(2);
		system("cls");
		
		printf("+---+\n");
		printf("|[");
		
//		Usando o Termo COLOR_<cor> para mudar a cor da luz
//		Using the term COLOR_<color>" to change the color of the light
		printf(COLOR_RED "*" COLOR_RESET);
		printf("]|\n");
		printf("|[ ]|======++\n");
		printf("|[ ]|      ||\n");
		printf("+---+      ||\n");
		printf("           ||\n");
		printf("           ||\n");
		printf("           ||\n");
		sleep(2);
		system("cls");
	}




    return 0;
}
