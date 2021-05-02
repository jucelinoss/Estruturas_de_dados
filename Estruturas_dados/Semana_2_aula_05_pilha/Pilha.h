#pragma once
typedef int TipoItem;
const int max_qtd_itens = 100;
using namespace std;

class Pilha
{
private:
	int tamanho;
	TipoItem* vetor_pilha;

public:
	Pilha();
	~Pilha();
	bool estaCheia();
	bool estaVazia();
	void inserir(TipoItem item);
	TipoItem remover();
	void imprimir();
	int qualTamanho();
};

