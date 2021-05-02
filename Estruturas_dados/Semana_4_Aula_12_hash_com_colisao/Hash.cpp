#include "Hash.h"
#include <iostream>

using namespace std;

Hash::Hash(int tam_vetor, int max) {
	qtd_itens = 0;
	max_qtd_itens = max;
	max_posicoes = tam_vetor;
	vetorAluno = new Aluno[tam_vetor];
}

int Hash::funcaoHash(Aluno aluno) {
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
	if (estaCheio()) {
		cout << "A tabela hash esta cheia\n O elemento nao pode ser inserido";
	}
	int local = funcaoHash(aluno);
	while(vetorAluno[local].getRa() > 0 )
	{
		local = (local + 1) % max_posicoes; 
	}
	vetorAluno[local] = aluno;
	qtd_itens++;
}
void Hash::deletar(Aluno aluno) {
	int local = funcaoHash(aluno);
	bool blnEncontrado = false;
	while (vetorAluno[local].getRa() != -1) {
		if (vetorAluno[local].getRa() == aluno.getRa()) {
			cout << "Elemento removido\n";
			vetorAluno[local] = Aluno(-2, ""); // -2 : disponível 
			qtd_itens--;
			blnEncontrado = true;
			break;
		}
		local = (local + 1) % max_posicoes;
	}
	if (!blnEncontrado) {
		cout << "Elemento nao encontrado\nNenhum elemento foi removido. ";
	}

}

void Hash::buscar(Aluno& aluno, bool& encontrado) {
	int local = funcaoHash(aluno);
	encontrado = false;
	while (vetorAluno[local].getRa() != -1)
	{
		if (vetorAluno[local].getRa() == aluno.getRa())
		{
			encontrado = true;
			aluno = vetorAluno[local];
			break;
		}
		local = (local + 1) % max_posicoes;
	}
}

void Hash::imprimir() {
	cout << "Tabela Hash:\n";
	for (int i = 0; i < max_posicoes; i++)
	{
		if (vetorAluno[i].getRa() > 0 ) {
			cout << i << ":" << vetorAluno[i].getRa() << " ";
			cout << vetorAluno[i].getNome() << endl;
		}
	}
}