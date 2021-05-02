#pragma once
#include <iostream>
#include <cstddef>
#include "arvoreAVL.h" //modificado
#include "Aluno.h"
using namespace std;

ArvoreAVL::ArvoreAVL() // construtor  //mudounome
{
	raiz = NULL;
}

ArvoreAVL::~ArvoreAVL() // destrutor //mudounome
{
	deletarArvore(raiz);
}

void ArvoreAVL::deletarArvore(No* noAtual)
{
	if (noAtual != NULL) {
		deletarArvore(noAtual->filhoEsquerda);
		deletarArvore(noAtual->filhoDireita);
		delete noAtual;
	}
}

void ArvoreAVL::getRaiz(No*& noRaiz) {
	noRaiz = raiz;
}


bool ArvoreAVL::estaVazio(){
	return raiz == NULL;
}

bool ArvoreAVL::estaCheio()
{
	try {
		No* temp = new No;
		delete temp;
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}
}

void ArvoreAVL::inserir(Aluno aluno) //modificada
{
	bool cresceu;
	insereRecursivo(raiz, aluno, cresceu);
}

void ArvoreAVL::insereRecursivo(No*& noAtual, Aluno aluno, bool& cresceu)
{ // novo
	if (noAtual == NULL) {
		noAtual = new No;
		noAtual->filhoDireita = NULL;
		noAtual->filhoEsquerda = NULL;
		noAtual->aluno = aluno;
		noAtual->fatorB = 0;
		cresceu = true;
		return;
	}
	if (aluno.getRa() < noAtual->aluno.getRa()) {
		insereRecursivo(noAtual->filhoEsquerda, aluno, cresceu);
		if (cresceu) {
			noAtual->fatorB -= 1;
		}
	}
	else {
		insereRecursivo(noAtual->filhoDireita, aluno, cresceu);
		if (cresceu) {
			noAtual->fatorB += 1;
		}
	}
	realizaRotacao(noAtual);

	if (cresceu && noAtual->fatorB == 0) {
		cresceu = false;
	}
}

void ArvoreAVL::remover(Aluno aluno) //modificada
{
	bool diminuiu;
	buscaRemocao(aluno, raiz, diminuiu);
}

void ArvoreAVL::buscaRemocao(Aluno aluno, No*& noAtual, bool& diminuiu)
{ //modificada
	if (aluno.getRa() < noAtual->aluno.getRa()) {
		buscaRemocao(aluno, noAtual->filhoEsquerda, diminuiu);
		if (diminuiu) {
			noAtual->fatorB += 1;
		}
	}
	else if (aluno.getRa() > noAtual->aluno.getRa()) {
		buscaRemocao(aluno, noAtual->filhoDireita, diminuiu);
		if (diminuiu) {
			noAtual->fatorB -= 1;
		}
	}
	else {
		deletarNo(noAtual, diminuiu);
	}
	if (noAtual != NULL) {
		realizaRotacao(noAtual);
		if (diminuiu && noAtual->fatorB != 0) {
			diminuiu = false;
		}
	}
}

void ArvoreAVL::deletarNo(No*& noAtual, bool& diminuiu)
{
	No* temp = noAtual;
	if (noAtual->filhoEsquerda == NULL) {
		noAtual = noAtual->filhoDireita;
		diminuiu = true;
		delete temp;
	}
	else if (noAtual->filhoDireita == NULL) {
		noAtual = noAtual->filhoEsquerda;
		diminuiu = true;
		delete temp;
	}
	else {
		Aluno AlunoSucessor;
		getSucessor(AlunoSucessor, noAtual);
		noAtual->aluno = AlunoSucessor;
		buscaRemocao(AlunoSucessor, noAtual->filhoDireita, diminuiu);
		if (diminuiu) {
			noAtual->fatorB -= 1;
		}
	}
}

void ArvoreAVL::getSucessor(Aluno& AlunoSucessor, No* temp)
{
	temp = temp->filhoDireita;
	while (temp->filhoEsquerda != NULL) {
		temp = temp->filhoEsquerda;
	}
	AlunoSucessor = temp->aluno;
}

void ArvoreAVL::buscar(Aluno& aluno, bool& busca)
{
	busca = false;
	No* noAtual = raiz;
	while (noAtual != NULL) {
		if (aluno.getRa() < noAtual->aluno.getRa()) {
			noAtual = noAtual->filhoEsquerda;
		}
		else if (aluno.getRa() > noAtual->aluno.getRa()) {
			noAtual = noAtual->filhoDireita;
		}
		else {
			busca = true;
			aluno = noAtual->aluno;
			break;
		}
	}
}

void ArvoreAVL::imprimirPreOrdem(No* noAtual)
{
	if (noAtual != NULL) {
		cout << noAtual->aluno.getNome() << ": ";
		cout << noAtual->aluno.getRa() << endl;

		imprimirPreOrdem(noAtual->filhoEsquerda);

		imprimirPreOrdem(noAtual->filhoDireita);
	}
}

void ArvoreAVL::imprimirEmOrdem(No* noAtual)
{
	if (noAtual != NULL) {
		imprimirEmOrdem(noAtual->filhoEsquerda);

		cout << noAtual->aluno.getNome() << ": ";
		cout << noAtual->aluno.getRa() << endl;

		imprimirEmOrdem(noAtual->filhoDireita);
	}
}

void ArvoreAVL::imprimirPosOrdem(No* noAtual)
{
	if (noAtual != NULL) {
		imprimirPosOrdem(noAtual->filhoEsquerda);

		imprimirPosOrdem(noAtual->filhoDireita);

		cout << noAtual->aluno.getNome() << ": ";
		cout << noAtual->aluno.getRa() << endl;
	}
}





void ArvoreAVL::rotacaoDireita(No*& pai) //novo
{
	No* novopai = pai->filhoEsquerda;
	pai->filhoEsquerda = novopai->filhoDireita;
	novopai->filhoDireita = pai;
	pai = novopai;
}

void ArvoreAVL::rotacaoEsquerda(No*& pai) //novo
{
	No* novopai = pai->filhoDireita;
	pai->filhoDireita = novopai->filhoEsquerda;
	novopai->filhoEsquerda = pai;
	pai = novopai;
}

void ArvoreAVL::rotacaoEsquerdaDireita(No*& pai)
{
	No* filho = pai->filhoEsquerda;
	rotacaoEsquerda(filho);
	pai->filhoEsquerda = filho;
	rotacaoDireita(pai);
}


void ArvoreAVL::rotacaoDireitaEsquerda(No*& pai)
{
	No* filho = pai->filhoDireita;
	rotacaoDireita(filho);
	pai->filhoDireita = filho;
	rotacaoEsquerda(pai);
}


void ArvoreAVL::realizaRotacao(No*& pai)
{
	No* filho;
	No* neto; // Caso precise da rotação dupla

	if (pai->fatorB == -2) { //rotaciona para a Direita

		filho = pai->filhoEsquerda;

		if (filho->fatorB == -1) { // Simples para a Direita
			pai->fatorB = 0;
			filho->fatorB = 0;
			rotacaoDireita(pai);
		}
		else if (filho->fatorB == 0) { // Simples para a Direita
			pai->fatorB = -1;
			filho->fatorB = 1;
			rotacaoDireita(pai);
		}
		else if (filho->fatorB == 1) { // Rotação dupla
			neto = filho->filhoDireita;
			if (neto->fatorB == -1) {
				pai->fatorB = 1;
				filho->fatorB = 0;
			}
			else if (neto->fatorB == 0) {
				pai->fatorB = 0;
				filho->fatorB = 0;
			}
			else if (neto->fatorB == 1) {
				pai->fatorB = 0;
				filho->fatorB = -1;
			}
			neto->fatorB = 0;
			rotacaoDireitaEsquerda(pai);
		}



	}
	else if (pai->fatorB == 2) { //rotaciona para a Esquerda
		filho = pai->filhoDireita;
		if (filho->fatorB == 1) { // Simples para a Esquerda
			pai->fatorB = 0;
			filho->fatorB = 0;
			rotacaoEsquerda(pai);
		}
		else if (filho->fatorB == 0) { // Simples para a Esquerda         
			pai->fatorB = 1;
			filho->fatorB = -1;
			rotacaoEsquerda(pai);
		}
		else if (filho->fatorB == -1) { // Rotacao dupla
			neto = filho->filhoEsquerda;
			if (neto->fatorB == -1) {
				pai->fatorB = 0;
				filho->fatorB = 1;
			}
			else if (neto->fatorB == 0) {
				pai->fatorB = 0;
				filho->fatorB = 0;
			}
			else if (neto->fatorB == 1) {
				pai->fatorB = -1;
				filho->fatorB = 0;
			}
			neto->fatorB = 0;
			rotacaoDireitaEsquerda(pai);
		}
	}
}