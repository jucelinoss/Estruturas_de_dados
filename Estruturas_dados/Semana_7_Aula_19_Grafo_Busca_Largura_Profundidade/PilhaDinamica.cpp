#include <iostream>
#include "PilhaDinamica.h"
#include <cstddef>

using namespace std;

PilhaDinamica::PilhaDinamica() {
	noTopo = NULL;
}

PilhaDinamica::~PilhaDinamica() {
	No* noTemp;
	//percorre a lista de Nós, fazendo bkp para matar o proximo da pilha a cada iteração, limpando toda a estrutura
	while (noTopo != NULL) {
		noTemp = noTopo;
		noTopo = noTopo->proximo;
		delete noTemp;
	}
}

bool PilhaDinamica::estaVazio() {
	return noTopo == NULL;
}

bool PilhaDinamica::estaCheio() {
	No* NoNovo;
	try {
		// tenta criar novo objeto para verificar se está cheio
		NoNovo = new No;
		delete NoNovo;
		return false;
	}// em caso de erro constata que a memória da máquina está cheia
	catch (std::bad_alloc exception) {
		return true;
	}
}

void PilhaDinamica::inserir(TipoItem item) { //push
	if (estaCheio()) {
		cout << "A pilha esta cheia\n";
		cout << "Nao foi possivel inserir este elemento";	
	}
	else {
		No* noNovo = new No;
		noNovo->valor = item;
		// aponta o novo item pilha para o ultimo que foi inserido anteriormente
		noNovo->proximo = noTopo;
		// apos apontar o novo elemento para o ultimo (colocar em cima da pilha), muda o ponteiro de topo para o item adicionado
		noTopo = noNovo;
	}
}

TipoItem PilhaDinamica::remover() {//pop
	if (estaVazio()) {
		cout << "A Pilha esta vazia!\n";
		cout << "Nao foi possivel remover nenhum elemento!\n";
		return 0;
	}
	else {
		No* noTemp;
		noTemp = noTopo;
		TipoItem item = noTopo->valor; // bkp do ultimo item da pilha para retornar ao usuário
		noTopo = noTopo->proximo; // aponta o penultimo da pilha (proximo do ultimo) como ultimo 
		delete noTemp;// remove o ultimo da pilha
		return item;
	}
}

void PilhaDinamica::imprimir() {
	// imprime o ultimo da fila e vai para o proximo, ate imprimir todos (noTopo nulo)
	No* noTemp = noTopo;
	cout << "Pilha: [ ";
	while (noTemp != NULL) {
		cout << noTemp->valor << " ";
		noTemp = noTemp->proximo;
	}
	cout << "]\n";
}