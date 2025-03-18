#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <math.h>


//	definição de constantes com base no Gringo (meu cavalo)
	#define S1 14.31	//velocidade do Jade
	#define S2 0.3315	//velocidade real
	
	#define J1 4.09		//pulo do jade
	#define J2 0.859995	//pulo real??





//funcção de calculo da velocidade
double Velocidade() {
	 float speed, Tspeed;
	 
	 
 	puts(" ");
    puts("Agora digite a VELOCIDADE do cavalo:");
    scanf("%f", &speed);
    fflush(stdin);
    
    
    
    Tspeed = (speed * S2) / S1;
	
	
	
	 /*	Retorno das variaveis para checar se ta tudo ok
	 
	 printf("\nS1: %f", S1);
	 printf("\nS2: %f", S2);
	 printf("\nspeed: %f", speed);
	 printf("\nTspeed: %f", Tspeed);
	 
	 */


	return(Tspeed);
}

//funcção de calculo do pulo
double Pulo() {
	 float jump, Tjump;
	 
	 
 	puts(" ");
	puts("Agora digite a força de PULO do cavalo:");
    scanf("%f", &jump);
    fflush(stdin);
    
    
    
    Tjump = (jump * J2) / J1;
	
	
	
	/*	Retorno das variaveis para checar se ta tudo ok
	 
	 printf("\nS1: %f", J1);
	 printf("\nS2: %f", J2);
	 printf("\nspeed: %f", jump);
	 printf("\nTspeed: %f", Tjump); 
	 
	*/


	return(Tjump);
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_NUMERIC, "C");
    
  	//declaração de variaveis	    
    float Tjump, Tspeed;
	double health;
	char name[50];
	char Cjump[6], Cspeed[6];


	//	texto de inicio do pprograma :)
	puts("Bem vindo ao programa de calculo de estatisticas de cavalo");
    puts("Como sabe, os cavalos tem estatisticas que podem ser vistas atravez do mod Jade");
    puts("mas estas estatisticas não equivalem as necessarias para sumonar um cavalo novo");
	puts("Este é um programa que vai converter as estatisticas e gerar um comando para criar um cavalo com as estatisticas corretas");
    puts(" ");
    puts(" ");
    
	
    
    puts("Vamos começar, digite o nome do seu cavalo:");
   	fgets(name, sizeof(name), stdin);
   	fflush(stdin);
    
   	
   	
    //chamada das funções de calculo
    Tspeed = Velocidade();
    //Cspeed = Convert(Tspeed);
    Tjump = Pulo();
    //Cjump = Convert(Tjump);
    
    
    
    
    //get da vida maxima (nn vou fazer uma função só pra isso)
    puts(" ");
	puts("Por fim, digite a VIDA MAXIMA do cavalo:");
    scanf("%d", &health);
    puts(" ");
    puts(" ");
    
    
    
   //retorno do comando com as variaveis colocadas em sua devida posição
    puts("Aqui está seu código, é só copiar e colar em um command Block:");
    puts(" ");
	puts("---------------------------------------------- ");
	puts("\n ");
	puts("\n ");
    printf("/minecraft:summon horse ~ ~ ~ {Health:%d,Temper:100,CustomName:\'{\"text\":\"%s\"}\',Attributes:[{Name:generic.max_health,Base:%d},{Name:generic.movement_speed,Base:%.4f},{Name:horse.jump_strength,Base:%.4f}],SaddleItem:{id:\"minecraft:saddle\",Count:1b},ArmorItem:{}}", health, name, health, Tspeed, Tjump);
    puts("\n ");
    puts("\n ");
	puts("---------------------------------------------- ");
	
	
	system("pause");
    return 0;
}

