#include "FilaDinamica.h"
#include <cstddef>
//#include <new>

using namespace std;

FilaDinamica::FilaDinamica() {

	primeiro = NULL;
	ultimo = NULL;
}

FilaDinamica::~FilaDinamica() {
	No* temp;
	//percorre a lista de Nós, fazendo bkp para matar o proximo da fila a cada iteração, limpando toda a estrutura
	while (primeiro != NULL) { 
		temp = primeiro;
		primeiro = primeiro->proximo;
		delete temp;
	}
}

bool FilaDinamica::estaVazio() {
	return primeiro == NULL;
}


bool FilaDinamica::estaCheio() {
	No* temp;
	try{
		// tenta criar novo objeto para verificar se está cheio
		temp = new No;
		delete temp;
		return false;
	}// em caso de erro constata que a memória da máquina está cheia
	catch (std::bad_alloc exception) {
		return true;
	}
}

void FilaDinamica::inserir(TipoItem item) {// enqueue / push
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


TipoItem FilaDinamica::remover() { //dequeue / pop
	if (estaVazio()) {
		cout << "A fila esta vazia! \n";
		cout << "Nao ha elemento a ser removido!\n";
		return NULL;
	}
	else {
		// remove o primeiro da fila
		No* temp = primeiro;
		TipoItem item = primeiro->valor;
		primeiro = primeiro->proximo;// marca o ponteiro de primeiro para pegar o proximo da fila
		// se o proximo elemento da lista estiver vazio (saiu do ultimo para NULL), então marca o ultimo como vazio  para indicar que a lista está vazia
		if (primeiro == NULL) {
			ultimo = NULL;
		}
		// remove o valor da fila e retorna para o usuário
		delete temp;
		return item;
	}
}


void FilaDinamica::imprimir() {
	// imprime o primeiro da fila e vai para o proximo, ate imprimir todos (proximo nulo)
	No* temp = primeiro;
	cout << "Fila= [";
	while (temp != NULL) {
		cout << temp->valor << " ";
		temp = temp->proximo;
	}
	cout << "]\n";
}
