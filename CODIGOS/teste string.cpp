#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    
    // Solicitar o nome do usuário
    cout << "Por favor, digite seu nome: ";
    
    // Ler a entrada do usuário
    getline(cin, nome);
    
    // Exibir o nome do usuário
    cout << "Olá, " << nome << "!" << endl;
    
    
    cin >> nome;
    cout << nome;
    
    return 0;
}