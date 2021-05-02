// Semana_2_aula_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
	ItemType character;
	Stack stack;
	ItemType stackItem;

	cout << "Adicione uma String." << endl;
	cin.get(character);
	while (character != '\n')
	{
		stack.push(character);
		cin.get(character);
	}

	while (!stack.isEmpty())
	{
		stackItem = stack.pop();
		cout << stackItem;
	}

	cout << endl;
}
