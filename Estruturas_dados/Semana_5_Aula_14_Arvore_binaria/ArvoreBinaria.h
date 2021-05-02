#pragma once
#include <iostream>
#include "Aluno.h"


struct No {
	Aluno aluno;
	No* filhoEsquerda;
	No* filhoDireita;
};

class ArvoreBinaria// BST - Binary Search Tree
{
private:
	No* raiz;


public:
	ArvoreBinaria();
	~ArvoreBinaria();
	void deletarArvore(No* noAtual);
	No* getRaiz();
	bool estaVazio();
	bool estaCheio();
	void inserir(Aluno aluno);
	void remover(Aluno aluno);
	void buscaRemocao(Aluno aluno, No*& noAtual);
	void deletarNo(No*& noAtual);
	void getSucessor(Aluno& alunoSucessor, No* temp);
	void buscar(Aluno& aluno, bool& encontrado);
	void imprimirPreOrdem(No* noAtual);
	void imprimirEmOrdem( No* noAtual);
	void imprimirPosOrdem(No* noAtual);
};
