#pragma once
#include <iostream>
#include "Aluno.h"

class ArvoreAVL
{

	struct No {
		Aluno aluno;
		No* filhoEsquerda;
		No* filhoDireita;
		int fatorB;
	};

public:
	No* raiz;
	ArvoreAVL();
	~ArvoreAVL();
	void deletarArvore(No* noAtual);
	void getRaiz(No*& noRaiz);
	//No* getRaiz(No*& noRaiz); -- tipo de dados retornado não reconhecido pelo compilador; set por referencia
	bool estaVazio();
	bool estaCheio();
	void inserir(Aluno aluno);// modificada
	void remover(Aluno aluno);// modificada
	void buscaRemocao(Aluno aluno, No*& noAtual, bool& diminuiu);//modificada
	void deletarNo(No*& noatual, bool& diminuiu); // modificada
	void getSucessor(Aluno& alunoSucessor, No* temp);
	void buscar(Aluno& aluno, bool& encontrado);
	void imprimirPreOrdem(No* noAtual);
	void imprimirEmOrdem(No* noAtual);
	void imprimirPosOrdem(No* noAtual);

	//novos métodos
	void rotacaoDireita(No*& tree);
	void rotacaoEsquerda(No*& tree);
	void rotacaoEsquerdaDireita(No*& tree);
	void rotacaoDireitaEsquerda(No*& tree);
	void realizaRotacao(No*& tree);
	void insereRecursivo(No*& noAtual, Aluno aluno, bool& cresceu);
};