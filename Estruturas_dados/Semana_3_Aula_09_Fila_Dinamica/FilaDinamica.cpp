#include "FilaDinamica.h"
#include <iostream>
#include <cstddef>

using namespace std;
FilaDinamica::FilaDinamica() {
	primeiroNo = NULL;
	ultimoNo = NULL;
}
FilaDinamica::~FilaDinamica() {
	No* noTemp;
	while (primeiroNo != NULL) {
		noTemp = primeiroNo;
		primeiroNo = primeiroNo->proximoNo;
		delete noTemp;
	}
	ultimoNo = NULL;
}
bool FilaDinamica::estaVazio() {
	return primeiroNo == NULL;
}
bool FilaDinamica::estaCheio() {
	No* noTemp;
	try
	{
		noTemp = new No;
		delete noTemp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}
void FilaDinamica::inserir(TipoItem item) {
	if (estaCheio()) {
		cout << "A fila esta cheia. Nao foi possivel inserir este elemento";
	}
	else {
		No* noNovo = new No;
		noNovo->valor = item;
		noNovo->proximoNo = NULL;
	
		if (primeiroNo == NULL) {
			primeiroNo = noNovo;
		}
		else {
			cout << "PrimeroNO" << primeiroNo->valor;
			cout << "ProximoNo" << primeiroNo->proximoNo;
			ultimoNo->proximoNo = noNovo;
		}
		ultimoNo = noNovo;
	}
}
TipoItem FilaDinamica::remover() {// pop
	if (estaVazio()) {
		cout << "A fila esta vazia\n Nao ha elemento a ser removido. ";
		return NULL;
	}
	else {
		No* noTemp = primeiroNo;
		TipoItem item = primeiroNo->valor;
		primeiroNo = primeiroNo->proximoNo;
		if (primeiroNo == NULL) {
			ultimoNo = NULL;
		}
		delete noTemp;
		return item;
	} 
} 
void FilaDinamica::imprimir() {
	No* tempNo = primeiroNo ;
	cout << "Fila= [";
	while (tempNo != NULL) {
		cout << tempNo->valor << " ";
		tempNo = tempNo->proximoNo;
	}
	cout << "]\n";
}
