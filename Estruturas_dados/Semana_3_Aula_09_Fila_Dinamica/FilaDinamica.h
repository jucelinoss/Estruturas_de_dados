typedef int TipoItem;

using namespace std;

struct No
{
	TipoItem valor;
	No* proximoNo;
};

class FilaDinamica
{
private:
	No* primeiroNo; //front 
	No* ultimoNo; // rear
public:
	FilaDinamica();
	~FilaDinamica();
	bool estaVazio();
	bool estaCheio();
	void inserir(TipoItem item);
	TipoItem remover(); // pop
	void imprimir();
};

