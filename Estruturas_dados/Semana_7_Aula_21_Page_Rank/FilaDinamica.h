#pragma once
#ifndef FILA_DINAMICA_H

#include "No.h"

class FilaDinamica {
public:
	FilaDinamica();
	~FilaDinamica();
	bool estaVazio()const; // const ? usado para indicar que o m?todo ? read only
	bool estaCheio()const;
	void imprimir()const;

	void inserir(TipoItem item);
	TipoItem remover();

private:
	No* primeiro;
	No* ultimo;
};

#endif // !FILA_DINAMICA_H

