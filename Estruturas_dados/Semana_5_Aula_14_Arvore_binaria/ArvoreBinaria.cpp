#include <cstddef>
#include <iostream>
#include "ArvoreBinaria.h"
#include "Aluno.h"

ArvoreBinaria::ArvoreBinaria() {
	raiz = NULL;
}
ArvoreBinaria::~ArvoreBinaria() {
	deletarArvore(raiz);
}

void ArvoreBinaria::deletarArvore(No* noAtual) {
	if (noAtual != NULL) {
		deletarArvore(noAtual->filhoEsquerda);
		deletarArvore(noAtual->filhoDireita);
		delete noAtual;
	}
}

No* ArvoreBinaria::getRaiz() {
	return raiz;
}

bool ArvoreBinaria::estaVazio() {
	return raiz == NULL;
}

bool ArvoreBinaria::estaCheio() {
	try
	{
		No* temp = new No;
		delete temp;
		return false;
	}
	catch (bad_alloc exception )
	{
		return true;
	}
}

void ArvoreBinaria::inserir(Aluno aluno) {
	if (estaCheio()) {
		cout << "A arvore esta cheia\n nao foi possivel inserir este elemento";
	} else{
		No* noNovo = new No;
		noNovo->aluno = aluno;
		noNovo->filhoEsquerda = NULL;
		noNovo->filhoDireita = NULL;
		if (estaVazio())
		{
			raiz = noNovo;
		}
		else {
			No* temp = raiz;
			while (temp != NULL) {
				if (aluno.getRa() < temp->aluno.getRa()) {
					if (temp->filhoEsquerda == NULL) {
						temp->filhoEsquerda = noNovo;
						break;
					}
					else {
						temp = temp->filhoEsquerda;
					}
				}
				else {
					if (temp->filhoDireita == NULL) {
						temp->filhoDireita = noNovo;
						break;
					}
					else {
						temp = temp->filhoDireita;
					}
				}
			}
		}
			
	}
}

void ArvoreBinaria::remover(Aluno aluno) {
	buscaRemocao(aluno, raiz);
}

void ArvoreBinaria::buscaRemocao(Aluno aluno, No*& noAtual) {
	if (aluno.getRa() < noAtual->aluno.getRa()) {
		buscaRemocao(aluno, noAtual->filhoEsquerda);
	}
	else if (aluno.getRa() > noAtual->aluno.getRa()) {
		buscaRemocao(aluno, noAtual->filhoDireita);
	}
	else {
		deletarNo(noAtual);
	}
}

void ArvoreBinaria::deletarNo(No*& noAtual) {
	No* temp = noAtual;
	if (noAtual->filhoEsquerda == NULL) {
		noAtual = noAtual->filhoDireita;
		delete temp;
	}
	else if (noAtual->filhoDireita == NULL) {
		noAtual = noAtual->filhoEsquerda;
		delete temp;
	}
	else {
		Aluno alunoSucessor;
		getSucessor(alunoSucessor, noAtual);
		noAtual->aluno = alunoSucessor;
		buscaRemocao(alunoSucessor, noAtual->filhoDireita);
	}
}

void ArvoreBinaria::getSucessor(Aluno& alunoSucessor, No* temp) {
	temp = temp->filhoDireita;
	while (temp->filhoEsquerda != NULL) {
		temp = temp->filhoEsquerda;
	}
	alunoSucessor = temp->aluno;
}

void ArvoreBinaria::buscar(Aluno& aluno, bool& encontrado) {
	encontrado = false;
	No* noAtual = raiz;
	while (noAtual != NULL) {
		if (aluno.getRa() < noAtual->aluno.getRa()) {
			noAtual = noAtual->filhoEsquerda;
		}
		else if (aluno.getRa() > noAtual->aluno.getRa()) {
			noAtual = noAtual->filhoDireita;
		}
		else {
			encontrado = true;
			aluno = noAtual->aluno;
			break;
		}
	}
}

void ArvoreBinaria::imprimirPreOrdem(No* noAtual) {
	if (noAtual != NULL) {
		cout << noAtual->aluno.getRa() << ": ";
		cout << noAtual->aluno.getNome() << endl;
		imprimirPreOrdem(noAtual->filhoEsquerda);
		imprimirPreOrdem(noAtual->filhoDireita);
	}
}

void ArvoreBinaria::imprimirEmOrdem(No* noAtual) {
	if (noAtual != NULL) {
		imprimirEmOrdem(noAtual->filhoEsquerda);
		cout << noAtual->aluno.getRa() << ": ";
		cout << noAtual->aluno.getNome() << endl;
		imprimirEmOrdem(noAtual->filhoDireita);
	}
}

void ArvoreBinaria::imprimirPosOrdem(No* noAtual) {
	if (noAtual != NULL) {
		imprimirPosOrdem(noAtual->filhoEsquerda);
		imprimirPosOrdem(noAtual->filhoDireita);
		cout << noAtual->aluno.getRa() << ": ";
		cout << noAtual->aluno.getNome() << endl;
	}
}
