#pragma once
// Grafo simples direcionado ponderado
#include "FilaDinamica.h"

using namespace std;

class Grafo
{
private:
	int vlrArestaNula;
	int maxQtdVertices;
	int numVertices;
	TipoItem* vetVertices;
	int** matrizAdjacencia; // vetor de vetores de inteiro
	bool* vetMarcador; // vetor de marcação de vértices visitados

public:
	Grafo(int maxQtdVertices, int vlrArestaNula);
	~Grafo();
	int getIndice(TipoItem item);
	bool estaCheio();
	bool estaMarcado(TipoItem item);
	void insereVertice(TipoItem item);
	void insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso);
	int getPeso(TipoItem noSaida, TipoItem noEntrada);
	int getGrau(TipoItem item);
	void imprimirMatriz();
	void imprimirVertices();
	void limparMarcador();
	void getPageRanks(float* pageRanks);
	void marcarVertice(TipoItem item);
	void getAdjacencia(TipoItem item, FilaDinamica& fila);
};

