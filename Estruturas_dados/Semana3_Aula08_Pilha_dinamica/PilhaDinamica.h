#pragma once
// pilha dinamica = dynamic stack

typedef int TipoItem;

struct No // Node
{
	TipoItem valor;
	No* proximoNo;
};

class PilhaDinamica
{
private:
	No* noTopo;

public:
	PilhaDinamica();
	~PilhaDinamica();
	bool estaVazio();
	bool estaCheio();
	void inserir(TipoItem item);
	TipoItem remover(); // pop
	void imprimir();
};
