#pragma once
#include <iostream>
#include <cstddef>

using namespace std;
typedef string TipoItem;

//grafo simples não direcionado ponderado
class Grafo
{
private:
	int arestaNula = -1;
	int maxQtdVertices;
	int numVertices; 
	TipoItem* vertices;
	int** matrizAdjacencia;// vetor de vetores do tipo inteiro

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
};

