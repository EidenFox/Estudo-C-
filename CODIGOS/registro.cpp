#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct products{
	string name;
	string details;
	double price;
	int stock;	
	int code;
};


void addProduct(vector<products>& productList) {
	products newProduct;
	newProduct.code = productList.size();
	
	cout << "Escreva o nome: ";
	cin.ignore();
	getline(cin, newProduct.name);
	
	cout << "Escreva os Detalhes do produto: ";
	cin.ignore();
	getline(cin, newProduct.details);
	
	cout << "Escreva o Preço do produto: ";
	cin >> newProduct.price;
	
	cout << "Escreva a quantidade de Estoque do produto: ";
	cin >> newProduct.stock;
	
	cin.ignore();
	productList.push_back(newProduct);
	
}
void view(vector<products>& productList) {
	int i;
    /*for (const auto &product : products) {
        cout << "Nome: " << product.name << endl;
        cout << "Detalhes: " << product.details << endl;
        cout << "Preço: " << product.price << endl;
        cout << "Estoque: " << product.stock << endl;
        cout << "Código: " << product.code << endl;
        cout << "----------------------" << endl;
    }*/
    
    cout << "Fora do for: " << productList.size() << endl;
    
    for (i = 0; i <= productList.size(); i++){
    cout << "Dentro do For: " << i << endl;
	}	
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    
	vector<products> productList;
    
	int menu, op, i, j, end;
	
	do{
		system("cls");
		
		menu = 0;
		
		cout << "Quantidade de registros: " << productList.size() << "\n\n" << endl;
		cout << "Escolha a opção desejada" << endl; cout << "1. Cadastrar contato" << endl; cout << "2. Ver lista" << endl; cout << "3. Editar" << endl;
		cout << "4. Excluir" << endl; cout << "5. Sair" << endl; cout << endl; 
		cin >> op;
		
		switch (op){
			case 1:
				addProduct(productList);
				break;                                           							
			case 2:
				 view(productList);
				break;
			/*case 3: 
				//edit();
				break;
			case 4:
				//erase();
				break;
				*/
			case 5:
				cout << "Saindo..." << endl;
				menu = 1;
				break;
			default:
				cout << "Opção Invalida" << endl;
				break;			
		}
		
system("pause");
}while (menu != 1);
    
    
    
    




	return 0;
}