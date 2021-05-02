#include "Grafo.h"
#include <iostream>
#include "FilaDinamica.h"
#include "PilhaDinamica.h"

using namespace std;

Grafo::Grafo(int maxQtdVertices, int vlrArestaNula) {
	// o grafo é inicializado sem nenhum vertice ou aresta
	this->numVertices = 0;
	this->maxQtdVertices = maxQtdVertices;
	this->vlrArestaNula = vlrArestaNula;

	vetMarcador = new bool[maxQtdVertices];// vetor de marcação de ....
	vetVertices = new TipoItem[maxQtdVertices];// vetor de vertices
	matrizAdjacencia = new int* [maxQtdVertices];

	for (int i = 0; i < maxQtdVertices; i++) {
		// instancia os vetores de cada vetor (matriz quadrada)
		matrizAdjacencia[i] = new int[maxQtdVertices];
	}

	for (int i = 0; i < maxQtdVertices; i++) {
		for (int j = 0; j < maxQtdVertices; j++) {
			// define os elementos da matriz como valor de aresta nula 
			matrizAdjacencia[i][j] = vlrArestaNula;
		}
	}
}
Grafo::~Grafo() {
	delete[] vetVertices;// destroi o vetor de vertices
	// destroi os vetores de cada vetor (matriz adjacencias) para eliminar cada 
	for (int i = 0; i < maxQtdVertices; i++) {
		delete[] matrizAdjacencia[i];
	}
	// destroi a matriz de adjacencia
	delete[] matrizAdjacencia;
}
int Grafo::getIndice(TipoItem item) {
	int indice = 0;
	// varre o vetor de vertices até encontrar o item desejado
	while (item != vetVertices[indice]) {
		indice++;
	}
	return indice;
}
bool Grafo::estaCheio() {
	return (numVertices == maxQtdVertices);
}
void Grafo::insereVertice(TipoItem item) {
	if (estaCheio()) {
		cout << "O numero maximo de vertices foi alcancado!\n";
	}
	else {
		// insere o vertice na proxima posicao livre (numVertices)
		// vetor com 7 vertices -> prox posicao livre eh a 7 (0 a 6 ja esta ocuopado)
		vetVertices[numVertices] = item;
		numVertices++;
	}
}
void Grafo::insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso) {
	// a aresta sai do vertice da linha e vai para o vertice da coluna
	int linha = getIndice(noSaida);
	int coluna = getIndice(noEntrada);
	// insere o peso na correspondencia da aresta desejada
	matrizAdjacencia[linha][coluna] = peso; 
	
	//matrizAdjacencia[coluna][linha] = peso; // remover se o grafo for direcionado
}
int Grafo::getPeso(TipoItem noSaida, TipoItem noEntrada) {
	int linha = getIndice(noSaida);
	int coluna = getIndice(noEntrada);
	// retorna o peso da aresta desejada (correspondencia do nó de saida (linha) entrada pa
	return matrizAdjacencia[linha][coluna];
}
int Grafo::getGrau(TipoItem item) {
	// verifica quantas arestas de saida tem no vertice (grau não direcionado) 
	int linha = getIndice(item);
	int grau = 0;
	
	for (int i = 0; i < maxQtdVertices; i++) {
		if (matrizAdjacencia[linha][i] != vlrArestaNula) {
			grau++;
		}
	}
	return grau;
	// para grafo direcionado, precisa varrer o vetor nos dois sentidos (entrada e saida)
	//requer varredura de entrada e também de saida 

}
void Grafo::imprimirMatriz() {
	cout << "Matriz de adjacencias:\n";

	for (int i = 0; i < maxQtdVertices; i++) {
		cout << "| ";
		for (int j = 0; j< maxQtdVertices; j++) {
			cout << matrizAdjacencia[i][j] << " ";
		}
		cout << " |" << endl;
	}
}

void Grafo::imprimirVertices() {
	cout << "Lista de Vertices\n";
	for (int i = 0; i < numVertices; i++) {
		cout << i + 1 << ": " << vetVertices[i] << endl;
	}
}

// novos
void Grafo::limparMarcador() {
	for (int i = 0; i < maxQtdVertices; i++) {
		vetMarcador[i] = false;
	}
}

void Grafo::buscaEmLargura(TipoItem origem, TipoItem destino) {
	FilaDinamica filaVertices;
	bool encontrado = false;
	limparMarcador();
	//insere a origem na fila (vertice de partida da busca em largura)
	filaVertices.inserir(origem);
	do
	{
		// remove o vértice da fila para poder visitar e verificar se é o vertice de destino
		TipoItem verticeAtual = filaVertices.remover();

		if (verticeAtual == destino)
		{
			cout << "Visitando: " << verticeAtual << endl;
			cout << "Caminho encontrado\n";
			encontrado = true;
		}
		else {
			// se o verticeAtual for diferente do destino, remove o item e coloca os filhos dele na fila para verificar na proxima iteração (desde que não tenham sido enfileirados anteriormente)
			// pega o índice do vetor 
			int indice = getIndice(verticeAtual);
			cout << "Visitando: " << verticeAtual << endl;
			// percorre todos os destinos a partir da origem desejada para saber se tem caminho 
			for (int  i = 0; i < maxQtdVertices; i++)
			{
				// verifica se tem caminho para o destino da iteração (verifica toda a linha do vertice) 
				if (matrizAdjacencia[indice][i] != vlrArestaNula) {
					// verifica se não está marcado para poder colocar na fila (só pode ser enfileirado uma única vez)
					if (!vetMarcador[i]) {
						// coloca o vertice na fila somente se não tiver sido enfileirado anteriormente
						cout << "Enfileirando: " << vetVertices[i] << endl;
						filaVertices.inserir(vetVertices[i]);
						vetMarcador[i] = true;
					}
				}
			}
		}
	} while (!filaVertices.estaVazio() && !encontrado);
	if (!encontrado) {
		cout << "Caminho nao encontrado! \n";
	}
}

void Grafo::buscaEmProfundidade(TipoItem origem, TipoItem destino) {
	PilhaDinamica pilhaVertices;
	bool encontrado = false;
	limparMarcador();
	pilhaVertices.inserir(origem);
	//insere a origem na pilha (vertice de partida da busca em profundidade)
	pilhaVertices.inserir(origem);
	do
	{
		// remove o vértice da pilha para poder visitar e verificar se é o vertice de destino
		TipoItem verticeAtual = pilhaVertices.remover();

		if (verticeAtual == destino)
		{
			cout << "Visitando: " << verticeAtual << endl;
			cout << "Caminho encontrado\n";
			encontrado = true;
		}
		else {
			// se o verticeAtual for diferente do destino, remove o item e coloca os filhos dele na pilha para verificar na proxima iteração (desde que não tenham sido empilhados anteriormente)
			// pega o índice do vertice
			int indice = getIndice(verticeAtual);
			cout << "Visitando: " << verticeAtual << endl;
			// percorre todos os destinos a partir da origem desejada para saber se tem caminho 
			for (int i = 0; i < maxQtdVertices; i++)
			{
				// verifica se tem caminho para o destino da iteração (verifica toda a linha do vertice) 
				if (matrizAdjacencia[indice][i] != vlrArestaNula) {
					// verifica se não está marcado para poder colocar na fila (só pode ser enfileirado uma única vez)
					if (!vetMarcador[i]) {
						// coloca o vertice na fila somente se não tiver sido enfileirado anteriormente
						cout << "Enfileirando: " << vetVertices[i] << endl;
						pilhaVertices.inserir(vetVertices[i]);
						vetMarcador[i] = true;
					}
				}
			}
		}
	} while (!pilhaVertices.estaVazio() && !encontrado);
	if (!encontrado) {
		cout << "Caminho nao encontrado! \n";
	}
}
