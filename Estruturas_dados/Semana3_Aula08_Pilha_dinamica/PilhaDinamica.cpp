#include "PilhaDinamica.h"
#include <iostream>
#include <cstddef> //null

using namespace std;
PilhaDinamica::PilhaDinamica() {
	noTopo = NULL;
}
PilhaDinamica::~PilhaDinamica() {
	No* noTemp;
	while (noTopo != NULL) {
		noTemp = noTopo;
		noTopo = noTopo->proximoNo;
		delete noTemp;
	}
}
bool PilhaDinamica::estaVazio() {
	return noTopo == NULL;
}
bool PilhaDinamica::estaCheio()
{
	No* noNovo;
	try
	{
		noNovo = new No;
		delete noNovo;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

void PilhaDinamica::inserir(TipoItem item) {
	if (estaCheio()) {
		cout << "A pilha esta cheia\n Nao foi possivel inserir o elemento\n";
	}
	else {
		No* noNovo = new No;
		noNovo->valor = item;//insere elemento no nó
		noNovo->proximoNo = noTopo;//aponta o proximo no para o elemento do topo antigo
		noTopo = noNovo; // coloca o novo elemento no topo, 
		// que aponta para o proximo da pilha, que aponta para o proximo, até chegar no primeiro elemento da pilha
	}
}
TipoItem PilhaDinamica::remover()  // pop
{
	if (estaVazio()) {
		cout << "A pilha esta vazia\n Nao foi possivel remover nenhum elemento.";
		return NULL;
	}
	else {
		No* noTemp;
		noTemp = noTopo;
		TipoItem itemTemp = noTopo->valor;
		noTopo = noTopo->proximoNo;
		delete noTemp;
		return itemTemp;
	}
}
void PilhaDinamica::imprimir() {
	cout << "Pilha: [ ";
	No* noTemp = noTopo;
	while (noTemp != NULL) {
		cout << noTemp->valor << " ";
		noTemp = noTemp->proximoNo;
	}
	cout << "]\n";
}
