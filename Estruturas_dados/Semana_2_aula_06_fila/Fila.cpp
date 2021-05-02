#include "Fila.h"
#include <iostream>
#include <cstddef>

using namespace std;

Fila::Fila() {
	primeiro = 0;
	ultimo = 0;
	vetor_fila = new TipoItem[max_qtd_itens];
}
Fila::~Fila() {
	delete[] vetor_fila;
}
bool Fila::estaVazio() {
	return primeiro == ultimo;
}
bool Fila::estaCheio() {
	return ultimo - primeiro == max_qtd_itens;
}
void Fila::inserir(TipoItem item){
	if (estaCheio()) {
		cout << "A fila esta cheia\n";
		cout << "Nenhum elemento pode ser inserido.\n";
	}
	else {
		vetor_fila[ultimo % max_qtd_itens] = item;
		ultimo++; // inclui o ultimo elemento da fila
	}
}
TipoItem Fila::remover() {
	if (estaVazio()) {	
		cout << "A fila está vazia\n";
		cout << "Nenhum elemento foi removido.\n";
		return NULL;
	}
	else {
		TipoItem aux = vetor_fila[primeiro % max_qtd_itens];
		primeiro++; // avança para o próximo da fila
		return aux;
	}
}

void Fila::imprimir() {
	cout << "Fila:  [ ";
	for (int i = primeiro; i < ultimo; i++) {
		cout << vetor_fila[i % max_qtd_itens] << " ";
	}
	cout << "]\n";
}
