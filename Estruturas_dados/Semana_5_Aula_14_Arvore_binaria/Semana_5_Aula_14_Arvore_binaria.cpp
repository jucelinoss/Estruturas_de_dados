#include <iostream>
#include "ArvoreBinaria.h"

using namespace std;

int main()
{
	ArvoreBinaria arvoreAluno;
	int opcao = 0, ra = 0, imp = 0;
	string nome;
	bool encontrado = false;
	do{
		cout << "Digite 0 para sair" << endl;
		cout << "Digite 1 para inserir um elemento" << endl;
		cout << "Digite 2 para remover um elemento" << endl;
		cout << "Digite 3 para buscar um elemento" << endl;
		cout << "Digite 4 para imprimir a Hash" << endl;
		cin >> opcao;
		if (opcao == 1) {
			cout << "Qual o RA do aluno? \n";
			cin >> ra;
			cout << "Qual o nome do aluno?\n";
			cin >> nome;
			Aluno aluno(ra, nome);
			if (arvoreAluno.estaCheio()) {
				cout << "A arvore esta cheia \n";
				cout << "Nao foi possivel inserir o elemento\n";
			}
			else {
				arvoreAluno.inserir(aluno);
			}
		}
		else if (opcao == 2)
		{
			cout << "Qual o RA do aluno a ser removido?\n";
			cin >> ra;
			Aluno aluno(ra, "");
			arvoreAluno.remover(aluno);
		}
		else if (opcao == 3) {
			cout << "Qual o RA do aluno a ser buscado?\n";
			cin >> ra;
			Aluno aluno(ra, "");
			arvoreAluno.buscar(aluno, encontrado);
			if (encontrado) {
				cout << "Aluno encontrado: \n";
				cout << "RA:" << aluno.getRa() << endl;
				cout << "Nome:" << aluno.getNome() << endl;
			}
			else {
				cout << "Aluno nao encontrado\n";
			}
		}
		else if (opcao == 4) {
			cout << "Digite 1 para imprimir em pre ordem!\n";
			cout << "Digite 2 para imprimir em ordem!\n";
			cout << "Digite 3 para imprimir em pos ordem!\n";
			cin >> imp;
			if (imp == 1) {
 				arvoreAluno.imprimirPreOrdem(arvoreAluno.getRaiz());
			}
			else if (imp == 2) {
				arvoreAluno.imprimirEmOrdem(arvoreAluno.getRaiz());
			}
			else if (imp == 3) {
				arvoreAluno.imprimirPosOrdem(arvoreAluno.getRaiz());
			}
			else {
				cout << "Opcao invalida";
			}
		}
	} while (opcao != 0);
}
