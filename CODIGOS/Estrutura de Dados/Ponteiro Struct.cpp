#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

typedef struct dados{
	string nome;
	int ra;
	float media;	
}dados;


int main() {
    SetConsoleOutputCP(CP_UTF8);
	dados Aluno;
	dados *pAluno;
	pAluno = &Aluno;
	
	Aluno.ra = 151926;
	Aluno.media = 6.9;
	
	cout << "\nRA: " << Aluno.ra << endl;
	cout << "Média: " << Aluno.media << endl;
	
	// usando ponteiro em struct não é necessário o "*" antes, mas vc deve colocar "->" indicando para onde ele aponta 
	// ("pAluno aponta para Aluno, para a variavel ra ou media)
	cout << "RA: " << pAluno->ra << endl;
	cout << "Méida: " << pAluno->media << endl;





    return 0;
}
