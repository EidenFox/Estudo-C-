#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <Windows.h>

/*Bibliotecas pra C++*/
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);


	int val;
	
	val = 13;
	
	int *anya = &val;
	cout << "VAL:" << val << endl;
	cout << "Anya:" << *anya << endl;
	
	cout << "-------------------------" << endl;
	
	val = 24;
	cout << "VAL:" << val << endl;
	cout << "Anya:" << *anya << endl;
	
	int res1 = 0;
	int res2 = 0;
	
	
	res1 = 10 + val;
	res2 = 10 + *anya;
	cout << "RES: " << res1 << endl;
	cout << "RES: " << res2 << endl;
	
	val = 13;
	
	res1 = 10 + val;
	res2 = 10 + *anya;
	
	cout << "RES: " << res1 << endl;
	cout << "RES: " << res2 << endl;
	
	
	
}
