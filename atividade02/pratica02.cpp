#include <iostream>
#include <stdio.h>
#ifndef VEICULO_CPP // if
#include "veiculo.cpp"
#endif // END IF

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
	v1->setNumRodas(4);
	cout << "O veiculo tem: " << v1->getNumRodas() << " Rodas." << endl;

	delete v1;

	system("PAUSE");
	return 0;
}

