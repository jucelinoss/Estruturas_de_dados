#pragma once

#include "Aluno.h"

class Hash {
private:
	int funcaoHash(Aluno aluno);
	int max_qtd_itens;
	int max_posicoes;
	int qtd_itens;
	Aluno* vetorAluno;

public:
	Hash(int tam_vetor, int max);
	~Hash();
	bool estaCheio();
	int getTamanhoAtual();
	void inserir(Aluno aluno);
	void deletar(Aluno aluno);
	void buscar(Aluno& aluno, bool& busca);
	void imprimir();
};