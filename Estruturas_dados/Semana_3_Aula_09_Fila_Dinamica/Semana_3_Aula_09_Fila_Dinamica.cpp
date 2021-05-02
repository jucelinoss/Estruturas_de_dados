// Semana3_Aula08_Pilha_dinamica.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "FilaDinamica.h"

#include <iostream>
using namespace std;
int main()
{
	FilaDinamica filaDin1;
	TipoItem item;
	int opcao;
	cout << "Gerenciador de dados estruturados em fila dinamica\n";
	do {
		cout << "Digite 0 para sair do programa!\n";
		cout << "Digite 1 para inserir um elemento! \n";
		cout << "Digite 2 para remover o ultimo elemento! \n";
		cout << "Digite 3 para imprimir a pilha! \n";
		cin >> opcao;
		switch (opcao)
		{
		case 0:
			break;
		case 1:
			cout << "Digite o elemento a ser inserido!\n";
			cin >> item;
			filaDin1.inserir(item);
			break;
		case 2:
			item = filaDin1.remover();
			if (item != NULL) {
				cout << "Elemento removido: " << item << endl;
			}
			break;
		case 3:
			filaDin1.imprimir();
			break;
		default:
			cout << "Opcao incorreta. Tente novamente! ";
			break;
		}
	} while (opcao != 0);
	return 0;
}
