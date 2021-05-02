#include <iostream>
#include <cstddef>
#include "grafo.h"

using namespace std;

int main() {
	int maxQtdVertices, vlrArestaNula;
	cout << "Digite a quantidade maxima de vertices:\n";
	cin >> maxQtdVertices;
	// cout << "Digite o valor para representar a ausencia de aresta:\n";
	// cin >> vlrArestaNula;
	Grafo grafo1(maxQtdVertices, NULL);
	TipoItem item1, item2;
	int opcao, valor, peso;

	do {
		cout << "Digite 0 para parar o algoritmo!\n";
		cout << "Digite 1 para inserir um vertice!\n";
		cout << "Digite 2 para inserir uma aresta!\n";
		cout << "Digite 3 para imprimir o grau de um vertice!\n";
		cout << "Digite 4 para imprimir o peso de uma aresta!\n";
		cout << "Digite 5 para imprimir a matriz de adjacencias!\n";
		cout << "Digite 6 para imprimir a lista de vertices!\n";
		cin >> opcao;

		if (opcao == 1) {
			cout << "Digite o elemento do vertice que sera inserido:\n";
			cin >> item1;
			grafo1.insereVertice(item1);
		}
		else if (opcao == 2) {
			cout << "Digite o vertice de saida:\n";
			cin >> item1;
			cout << "Digite o vertice de entrada:\n";
			cin >> item2;
			cout << "Digite o peso desta aresta:\n";
			cin >> peso;
			grafo1.insereAresta(item1, item2, peso);
		}
		else if (opcao == 3) {
			cout << "Digite o vertice que sera calculado o grau:\n";
			cin >> item1;
			valor = grafo1.getGrau(item1);
			if (valor >= 0) {
				cout << "O grau desse vertice e: " << valor << endl;
			}
			else {
				cout << "O vertice não existe: " << endl;
			}
		}
		else if (opcao == 4) {
			cout << "Digite o vertice de saida:\n";
			cin >> item1;
			cout << "Digite o vertice de entrada:\n";
			cin >> item2;
			valor = grafo1.getPeso(item1, item2);
			if (valor >= 0){
				cout << "O peso dessa aresta e: " << valor << endl;
			}
			else {
				cout << "Um dos vertices não existe: " << endl;
			}
		}
		else if (opcao == 5) {
			grafo1.imprimirMatriz();
		}
		else if (opcao == 6) {
			grafo1.imprimirVertices();
		}
	} while (opcao != 0);
	return 0;
}

// validar tratamento de função getIndice; informar usuário se retorno for nulo