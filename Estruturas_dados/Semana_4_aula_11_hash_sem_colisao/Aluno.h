#pragma once

#include <iostream>

using namespace std;

class Aluno
{
private:
	int ra;
	string nome;


public:
	Aluno();
	Aluno(int ra, string nome);
	int getRa();
	string getNome();
};

