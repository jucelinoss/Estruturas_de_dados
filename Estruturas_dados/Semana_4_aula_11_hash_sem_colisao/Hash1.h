#pragma once
#include "Aluno.h"

class Hash
{
private:
	int funcaoHash(Aluno aluno);
	int max_qtd_itens; // fator de carga
	int max_posicoes; // tamanho do vetor
	int qtd_itens;	// qtd_itens colocados no vetor
	Aluno* vetorAluno;

public:
	Hash();
	Hash(int tam_vetor, int max);
	~Hash();
	bool estaCheio();
	bool estaVazio();
	int getTamanhoAtual();
	void inserir(Aluno aluno);
	void deletar(Aluno aluno);
	void buscar(Aluno &aluno, bool& encontrado);
	void imprimir(); 
};

