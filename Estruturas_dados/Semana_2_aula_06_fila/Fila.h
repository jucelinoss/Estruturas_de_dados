#pragma once
typedef int TipoItem;

const int max_qtd_itens = 5;

class Fila
{
private: 
	int primeiro, ultimo;
	TipoItem* vetor_fila;
public:
	Fila();
	~Fila();
	bool estaVazio();
	bool estaCheio();
	void inserir(TipoItem item);
	TipoItem remover();
	void imprimir();
};

