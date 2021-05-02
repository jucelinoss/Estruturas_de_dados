#pragma once
// Grafo simples direcionado ponderado
#include <iostream>
#include "PilhaDinamica.h"
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
	void insereVertice(TipoItem item);
	void insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso);
	int getPeso(TipoItem noSaida, TipoItem noEntrada);
	int getGrau(TipoItem item);
	void imprimirMatriz();
	void imprimirVertices();

	// novos
	void limparMarcador();
	void buscaEmLargura(TipoItem origem, TipoItem destino);
	void buscaEmProfundidade(TipoItem origem, TipoItem destino);
};

