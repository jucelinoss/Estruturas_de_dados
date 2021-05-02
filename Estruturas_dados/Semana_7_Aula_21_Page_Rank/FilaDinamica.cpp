#include "FilaDinamica.h"	// para NULL
#include <new>				// para bad_alloc
#include <cstddef>
#include <iostream>
#pragma once
using namespace std;

FilaDinamica::FilaDinamica() {
	primeiro	=	NULL; 
	ultimo	=	NULL;
}

FilaDinamica::~FilaDinamica()  {
	No* temp;
	//percorre os itens da fila para apagar um a um (através do ponteiro temp)
	while (primeiro != NULL) {
		temp = primeiro;
		primeiro = primeiro->proximo;
		delete temp;
	}
	ultimo = NULL;
}
bool FilaDinamica::estaVazio() const{
	// se não houver proximo da fila, é porque está vazia
	return primeiro == NULL;
}

bool FilaDinamica::estaCheio() const{
	No* temp;
	try
	{
		// tenta criar novo objeto na memória
		temp = new No;
		delete temp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

void FilaDinamica::imprimir() const{
	No* temp = primeiro;
	// percorre cada nó para imprimir um por vez
	while (temp != NULL) {
		cout << temp->proximo->valor;
		temp = temp->proximo;
	}
	cout << endl;
}

void FilaDinamica::inserir(TipoItem item) {
	if (estaCheio()) {
		cout << "A Fila esta cheia! \n";
		cout << "Nao foi possivel inserir este elemento";
	}
	else {
		No* noNovo = new No;
		noNovo->valor = item;
		noNovo->proximo = NULL;
		if (primeiro == NULL) {
			// primeiro elemento da fila
			primeiro = noNovo;
		}
		else {
			// se tiver algum elemento na lista, faz o ultimo da fila apontar para o novo elemento adicionado
			ultimo->proximo = noNovo;
		}
		// o indicador do ultimo elemento passa a apontar para o item adicionado
		ultimo = noNovo;
	}
}

TipoItem  FilaDinamica::remover() {
	if (!estaVazio()) {
		No* temp;
		temp = new No;
		TipoItem item = primeiro->valor;
		primeiro= primeiro->proximo;
		if (ultimo == NULL)
			ultimo = NULL;
		delete temp;
		return item;
	}
	else {
		cout << "A fila ja esta cheia";
	}
}
