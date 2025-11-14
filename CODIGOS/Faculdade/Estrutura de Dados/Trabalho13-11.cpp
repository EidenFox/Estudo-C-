#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>


/**
*   Eu programo em casa no Linux, a função de baixo serve pra o "system(cls)"
*   funcionar com a biblioteca certa no linux ou no windows
*   mais pra baixo tem a função "limparTela" q tem um if pra usar o comando certo
**/
#ifdef _WIN32           // Se o compilador for Windows (definindo _WIN32)
    #include <windows.h>
#else                   // Caso contrário (Linux)
    #include <unistd.h>
    #include <stdlib.h>
#endif


/* Bibliotecas pra C++
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
*/


/* Constantes/Globais */
#define MAX 1000
int fila[MAX];     
int fim = 0;      
int proxima_senha = 1; 
/* Constantes/Globais */


/* Função para limpar a tela (linux/windows) */
void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear"); // Comando para limpar tela no Linux
    #endif
}

/* Função para pausar a tela (linux/windows) */
void pausar()
{
    char p;
    printf("\nPressione Enter para continuar...");
    scanf("%c", &p);    // Não achei system("pause") no linux, improvisei com "scanf"
    scanf("%c", &p);    // alternativamente poderia usar "Sleep", mas eu ja tinha pensado nisso e fiquei com preguiça de mudar
}

/* Função que checa se a fila está vazia */
bool vazia()
{
    if (fim == 0){
        printf("Nao ha senhas na fila.\n");
        pausar();
        return true;
    }
    return false;
}

/*Função que checa se a fila está cheia*/
bool cheia()
{
    if (fim == MAX){
        printf("Erro: A fila de atendimento esta cheia!\n");
        return true;
    }
    return false;
}


/**
*   Função para retirar uma nova senha 
*   (limite de 100 senhas simultâneas, configuravel na constante "MAX")
**/
void retirarSenha()
{
    if (!cheia()){
        int senha = proxima_senha;
        proxima_senha++;

        fila[fim] = senha;
        fim++;

        printf("Senha %d Gerada.\n", senha);
    }
    pausar();
}



/*Função para chamar a proxima senha e remove-la da lista*/
void chamarProximaSenha()
{
    if (!vazia()){
        int senha = fila[0];
        printf("Chamando senha --> %d\n", senha);
        for (int i = 0; i < fim - 1; i++){          // de 0 até o final da fila (-1)
            fila[i] = fila[i + 1];                  // substitui o numero da posição atual pelo da proxima
        }
        fim--;
    }
    pausar();
}

/*Função para mostrar a lista de senhas*/
void mostrarSenhas()
{
    if (!vazia()){
        limparTela();
        printf("--- Senhas na Fila (do inicio para o fim) ---\n");
        int total = 0;

        for (int i = 0; i < fim; i++){              // de 0 até o final da fila
            printf("Senha: %d\n", fila[i]);         // mostra o numero da posição atual
            total++;
        }
        printf("\nExistem %d senhas no total!", total);        
        printf("----------------------------------------------\n");
    }
    pausar();
}

/**
*   Função que remove uma senha especifica do meio da lista
**/
void removerSenhaEspecifica(){
    if (vazia()) return;

    int removerSenha;
    printf("Digite o numero da senha que deseja remover: ");
    scanf("%d", &removerSenha);

    int indice = -1;    //indice ser "-1" vai ser importante no if la em baixo

    for (int i = 0; i < fim; i++){          //Checa a lista em ordem até o fim
        if (fila[i] == removerSenha){       //se o numero atual for = ao que deve remover
            indice = i;                     //anota a posição dele
            break;                          //e para o loop (pra nn bugar se tiver numeros repetidos e nn gastar tempo/memoria atoa)
        }
    }

    if (indice != -1){  // se o indice for "-1" (igual na declaração) é pq nn achou o numero
        for (int i = indice; i < fim - 1; i++)  // Pega o indice (q anotou qual era em cima) e faz um loop até o final da fila
        {
            fila[i] = fila[i + 1];          //igual na outra função, substitui o numero da posição atual pelo da proxima até o fim
        }
        fim--;
        printf("Senha %d removida da fila com prioridade.\n", removerSenha);
    }
    else
    {
        printf("Senha %d nao foi encontrada na fila.\n", removerSenha);
    }
    pausar();
}

/* MAIN */
int main()
{
    int op = 0;

    do
    {
        limparTela();
        printf("====================================\n");
        printf("   Controle da Fila\n");
        printf("====================================\n");
        printf("1. Gerar uma senha (Cliente)\n");
        printf("2. Chamar proxima senha (Acougue)\n");
        printf("3. Remover senha especifica (Prioridade)\n");
        printf("4. Mostrar todas as senhas na fila\n");
        printf("0. SAIR\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &op);
        switch (op){
            case 1:
                retirarSenha();
                break;
            case 2:
                chamarProximaSenha();
                break;
            case 3:
                removerSenhaEspecifica();
                break;
            case 4:
                mostrarSenhas();
                break;
            case 0:
                printf("SAINDO...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar();
                break;
        }

    } while (op != 0);

    return 0;
}
/* MAIN */