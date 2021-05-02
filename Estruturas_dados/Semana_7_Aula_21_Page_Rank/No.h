#pragma once
#ifndef NO_H

#include <iostream>
#include "Vertice.h"

using namespace std;

typedef string TipoItem;

struct No {
	TipoItem valor;
	No* proximo;
};

#endif // !NO_H
