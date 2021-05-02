
#include <iostream>
#include "Grafo.h"
#include "FilaDinamica.h"

using namespace std;

int main()
{
	int maxQtdVertices = 4, vlrArestaNula = 0;
	Grafo grafo1(maxQtdVertices, vlrArestaNula);
	TipoItem a;
	TipoItem b;
	TipoItem c;
	TipoItem d;
	
	grafo1.insereVertice(a);
	grafo1.insereVertice(b);
	grafo1.insereVertice(c);
	grafo1.insereVertice(d);
	
	grafo1.insereAresta(a, c, 1);
	grafo1.insereAresta(a, b, 1);
	grafo1.insereAresta(b, d, 1);
	grafo1.insereAresta(c, a, 1);
	grafo1.insereAresta(c, b, 1);
	grafo1.insereAresta(c, d, 1);
	grafo1.insereAresta(d, c, 1);
	float* pageRanks = new float[4];
	grafo1.getPageRanks(pageRanks);

	for (int i = 0; i < 4; i++)
	{
		cout << pageRanks[i] << " , ";
	}
	cout << endl;
	cout << "Saindo" << endl;

}
