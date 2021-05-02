// Semana_4_aula_11_hash_sem_colisao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Hash.h"
using namespace std;


int main()
{
	int tamVet, max_elems;
	cout << "Programa gerador de Hash!\n";
	cout << "Digite o tamanho da hash\n";
	cin >> tamVet;
	cout << "Digite o numero maxido de elementos\n";
	cin >> max_elems;
	cout << "Fator de carga: " << (float)max_elems / float(tamVet) << endl;
	Hash alunoHash(tamVet, max_elems);
	int opcao; 
	int ra;
	string nome;
	bool encontrado;
	Aluno aluno;
	do {
		cout << "Digite 0 para sair"<< endl;
		cout << "Digite 1 para inserir um elemento"<< endl;
		cout << "Digite 2 para remover um elemento"<< endl;
		cout << "Digite 3 para buscar um elemento"<< endl;
		cout << "Digite 4 para imprimir a Hash"<< endl;
		cin >> opcao;
		if (opcao == 1) {
			cout << "Qual o RA do aluno? \n";
			cin >> ra;
			cout << "Qual o nome do aluno?\n";
			cin >> nome;
			Aluno aluno(ra, nome);
			alunoHash.inserir(aluno);	
		}
		else if (opcao == 2)
		{
			cout << "Qual o RA do aluno a ser removido?\n";
			cin >> ra;
			Aluno aluno(ra, "");
			alunoHash.deletar(aluno);
		}
		else if (opcao == 3) {
			cout << "Qual o RA do aluno a ser buscado?\n";
			cin >> ra;
			Aluno aluno(ra, "");
			alunoHash.buscar(aluno, encontrado);
			if (encontrado) {
				cout << "Aluno encontrado: \n";
				cout << "RA:" << aluno.getRa()<< endl;
				cout << "Nome:" << aluno.getNome()<< endl;
			}
			else {
				cout << "Aluno nao encontrado\n";
			}
		}
		else if (opcao == 4){
			alunoHash.imprimir();
		}
	} while (opcao != 0);
	return 0;
}