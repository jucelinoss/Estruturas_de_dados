#include "Grafo.h"
#include <iostream>
#include "FilaDinamica.h"


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
		for (int j = 0; j < maxQtdVertices; j++) {
			cout << matrizAdjacencia[i][j] << " ";
		}
		cout << "|" << endl;
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

void Grafo::getAdjacencia(TipoItem item, FilaDinamica& fila) {
	int indiceOrigem;
	int indiceDestino;
	indiceOrigem = getIndice(item);
	for (indiceDestino = 0; indiceDestino < numVertices; indiceDestino++) {
		if (matrizAdjacencia[indiceOrigem][indiceDestino] != vlrArestaNula) {
			// Uma cópia do elemento é adicionada no array.
			fila.inserir(vetVertices[indiceDestino]);
		}
	}
}

void Grafo::marcarVertice(TipoItem item){
  int indice = getIndice(item);
  vetMarcador[indice] = true;
}
bool Grafo::estaMarcado(TipoItem item){
  int indice= getIndice(item);
  return vetMarcador[indice];
}

void Grafo::getPageRanks(float* pageRanks){
  // Computando graus de saída
  int* vetQtdGrauSaida = new int[numVertices];
  for (int i = 0; i < numVertices; i++) {
	  vetQtdGrauSaida[i] = 0;
	for (int j = 0; j < numVertices; j++) {
	  if (matrizAdjacencia[i][j] != vlrArestaNula) {
		  vetQtdGrauSaida[i] += 1;
	  }
	}
  }

  // Computando pageRanks.
  float* vetPgRankAnterior = new float[numVertices];
  float* vetPgRank         = new float[numVertices];

  // Inicializando pgRrank = 1/ qtd_vertices
  for (int i = 0; i < numVertices; i++) {
	  vetPgRankAnterior[i] = 1.0/numVertices;
  }

  float d = .85; // taxa de amortecimento
  // calcula o page rank 100 vezes. Estudos indicam que 50 iterações já são suficientes
  // com isso a o valor do pagerank de cada vertice é mantido
  // outra forma seria validar cada valor antigo e novo e calcular novo Pgrank, até q o pgrank de cada um seja igual ao seu anterior
  for (int numIter = 0; numIter < 100; numIter++){
	// Passo Iterativo
	for (int i = 0; i< numVertices; i++){
		vetPgRank[i] = 0;
	  for (int j = 0; j < numVertices; j++){
		  // verifica os predecessores (percorre a coluna e não a linha)
		if (matrizAdjacencia[j][i] != vlrArestaNula){
			//calcula o page rank (voto de suporte) de cada nó. O voto de cada nó é dividido para os vertices de saida (qtd
			vetPgRank[i] += vetPgRankAnterior[j]/ vetQtdGrauSaida[j];
		}
	  }
	  // pageRank = 0,15 / qtdVertices + pageRank * 0.85
	  vetPgRank[i] = (1-d)/numVertices + d*vetPgRank[i];
	}
	// coloca o page rank no vetor anterior para se preparar para a proxima iteração
	for (int i = 0; i< numVertices; i++){
		vetPgRankAnterior[i] = vetPgRank[i];
	}
  }
  //joga os dados do pagerank no parametro de referencia (para retornar os dados)
  for (int i = 0; i< numVertices; i++){
	pageRanks[i] = vetPgRank[i];
  }

  delete [] vetPgRankAnterior;
  delete [] vetPgRank;
  delete [] vetQtdGrauSaida;

}

