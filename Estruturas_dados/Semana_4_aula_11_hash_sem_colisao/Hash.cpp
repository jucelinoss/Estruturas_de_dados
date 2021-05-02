#include "Hash.h"
#include <iostream>

using namespace std;

Hash::Hash(int tam_vetor, int max) {
	qtd_itens = 0;
	max_qtd_itens = max;
	max_posicoes = tam_vetor;
	vetorAluno = new Aluno[tam_vetor];
}

int Hash::funcaoHash( Aluno aluno) {
	return aluno.getRa() % max_posicoes;
}
Hash::~Hash() {
	delete[] vetorAluno;
}
bool Hash::estaCheio() {
	return qtd_itens == max_qtd_itens;
}

int Hash::getTamanhoAtual() {
	return qtd_itens;
}
void Hash::inserir(Aluno aluno) {
	int local = funcaoHash(aluno);
	vetorAluno[local] = aluno;
	qtd_itens++;
}
void Hash::deletar(Aluno aluno) {
	int local = funcaoHash(aluno);
	if (vetorAluno[local].getRa()) {
		vetorAluno[local] = Aluno(-1, "");
		qtd_itens--;
	}

}
void Hash::buscar(Aluno& aluno, bool& encontrado) {
	int local = funcaoHash(aluno);
	Aluno aux = vetorAluno[local];
	if (aux.getRa() != aluno.getRa()){
		encontrado = false;
	}
	else {
		encontrado = true;
		aluno = aux;
	}
}
void Hash::imprimir() {
	cout << "Tabela Hash:\n";
		for (int i =0; i < max_posicoes; i++)
		{
			if (vetorAluno[i].getRa() != -1) {
				cout << "indice -> "<< i << ":" << vetorAluno[i].getRa() <<" " ;
				cout << vetorAluno[i].getNome() << endl;
			}
		}
}