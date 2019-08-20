#include <iostream>
#include "veiculo.h"

using namespace std;

int main() {

	//Veiculo veiculo1("veiculo");
	//{
	//	Veiculo veiculo2("veiculo");
	//	{
	//		Veiculo veiculo3("veiculo");
	//	}
	//}

	Veiculo *v1 = new Veiculo("Gol");
	v1->setNumRodas(2);
	v1->setNumRodas(2);

	cout << "O veiculo tem: " << v1->getNumRodas() << " Rodas." << endl;

	delete v1;

//	system("PAUSE");
	return 0;
}

