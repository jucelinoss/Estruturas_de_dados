#pragma once
#ifndef FILADINAMICA_H
#define FILADINAMICA_H
#include "No.h"

class FilaDinamica
{

private:
	No* primeiro; // front 
	No* ultimo; //rear

public:
	FilaDinamica();
	~FilaDinamica();
	bool estaVazio();
	bool estaCheio();
	void inserir(TipoItem item);// enqueue / push
	TipoItem remover(); //dequeue / pop
	void imprimir();
};

#endif