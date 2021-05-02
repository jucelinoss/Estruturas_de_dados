#include <iostream>
#include "pilha.h"

using namespace std;

Pilha::Pilha()
{
	tamanho = 0;
	vetor_pilha = new TipoItem[max_qtd_itens];
}

Pilha::~Pilha() {
	delete[] vetor_pilha;
}

bool Pilha::estaCheia() {
	return tamanho == max_qtd_itens;
}
bool Pilha::estaVazia() {
	return tamanho == 0;
}

void Pilha::inserir(TipoItem item) {
	if (estaCheia()) {
		cout << "A pilha está cheia! Não é possível inserir este elemento\n";
	}
	else {
		vetor_pilha[tamanho] = item; // insere o elemento na próxima posição vazia (tamanho, o último elemento encontra-se na posição tamanho-1)
		tamanho++; // indica que um novo elemento foi adicionado, aumentando a qtd de itens da lista
	}
}

TipoItem Pilha::remover()
{
	if (estaVazia()) {
		cout << "A pilha está vazia! \n Nao ha elementos a remover";
		return 0;
	}
	else {
		TipoItem aux = vetor_pilha[tamanho-1]; // salva o elemento removido antes de excluir logicamente do vetor
		tamanho--; // ignora o ultimo elemento indicando que existe um elemento a menos
		return aux;
	}
}


void Pilha::imprimir() {
	cout << "Pilha: [ ";
	for (int i = 0; i < tamanho; i++) {
		cout << vetor_pilha[i] << " ";
	}
	cout << "]\n";
}

int Pilha::qualTamanho() {
	return tamanho;
}



