#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int maxQtdVertices, int vlrArestaNula) {
	numVertices = 0;
	this->maxQtdVertices = maxQtdVertices;
	this->arestaNula = vlrArestaNula;
	vertices = new TipoItem[maxQtdVertices];
	matrizAdjacencia = new int*[maxQtdVertices]; // a matriz é um vetor de vetores do tipo inteiro

	for (int i = 0; i < maxQtdVertices; i++) {
		matrizAdjacencia[i] = new int[maxQtdVertices];
	}
	for (int i = 0; i < maxQtdVertices; i++) {
		for (int j = 0; j < maxQtdVertices; j++) {
			matrizAdjacencia[i][j] = arestaNula;
		}
	}
}
Grafo::~Grafo() {
	delete[] vertices;
	for (int i = 0; i < maxQtdVertices; i++) {
		delete[] matrizAdjacencia[i];
	}
	delete[] matrizAdjacencia;
}
int Grafo::getIndice(TipoItem item) {
	int indice = 0;
	while (item != vertices[indice]) {
		indice++;
	}

	if (vertices[indice]== item){
		return indice;
	}
	else {
		return NULL;
	}
}
bool Grafo::estaCheio() {
	return numVertices == maxQtdVertices;
}
void Grafo::insereVertice(TipoItem item) {
	if (estaCheio()) {
		cout << "O numero maximo vertices foi alcançado";
	}
	else {
		vertices[numVertices] = item;
		numVertices++;
	}
}


void Grafo::insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso) {
	int linha = getIndice(noSaida);
	int coluna= getIndice(noEntrada);
	matrizAdjacencia[linha][coluna] = peso;
	matrizAdjacencia[coluna][linha] = peso;// grafo não direcionado; remover replicação do peso se o grafo for direcionado	
}

int Grafo::getPeso(TipoItem noSaida, TipoItem noEntrada) {
	int linha = getIndice(noSaida);
	int coluna = getIndice(noEntrada);
	return matrizAdjacencia[linha][coluna];
}

int Grafo::getGrau(TipoItem item) {
	int linha = getIndice(item);
	int grau = 0;
	for (int i = 0; i < maxQtdVertices; i++) {
		if (matrizAdjacencia[linha][i] != arestaNula)
			grau++;
	}
	return grau;
}

void Grafo::imprimirMatriz() {
	cout << "Matriz de adjacencias: \n";
	
	for (int i = 0; i < maxQtdVertices; i++) {
		cout << "[ ";
		for (int j = 0; i < maxQtdVertices; j++) {
			cout << matrizAdjacencia[i][j] << " " ;
		}
		cout << "]" << endl;
	}
}

void Grafo::imprimirVertices() {
	cout << "Lista de Vertices";
	for (int i = 0; i < numVertices; i++) {
		cout << i+1 << ": " << vertices[i] << endl;
	}
	cout << endl;
}
