#pragma once
#include "PilhaDinamica.h"
#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include "No.h"
class PilhaDinamica {
private: 
	No* noTopo;

public:
	PilhaDinamica();
	~PilhaDinamica();
	bool estaVazio();
	bool estaCheio(); 
	void inserir(TipoItem item); //push
	TipoItem remover();//pop
	void imprimir();
};













#endif // !PILHADINAMICA_H

