#pragma once
#ifndef VERTICE_H

#include <iostream>

using namespace std;
class Vertice{
private:
	int ra;
	string nome;

public:
	Vertice(string nome) {
		this->nome = nome;
	}

	string getNome() const {
		return nome;
	}
};
#endif // !VERTICE_H

