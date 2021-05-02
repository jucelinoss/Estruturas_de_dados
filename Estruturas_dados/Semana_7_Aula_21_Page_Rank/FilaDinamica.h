#pragma once
#ifndef FILA_DINAMICA_H

#include "No.h"

class FilaDinamica {
public:
	FilaDinamica();
	~FilaDinamica();
	bool estaVazio()const; // const é usado para indicar que o método é read only
	bool estaCheio()const;
	void imprimir()const;

	void inserir(TipoItem item);
	TipoItem remover();

private:
	No* primeiro;
	No* ultimo;
};

#endif // !FILA_DINAMICA_H

