#include <iostream>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

using namespace std;
using namespace funcoes;

int main() {
	
//	int x = 5, y = 10, z = 30;
//	float x = 5.5s, y = 10.15, z = 30.7;
//	char * a = "a"; 
//	char * b = "b";
//	swap(x, y);
//	cout << "Minimo entre " << a << " e " << b << " eh " << minimo(a, b) << endl;
//	cout << "Maximo entre " << a << " e " << b << " eh " << maximo(a, b) << endl;
	
//	Arranjo<int> arr(10);
//	arr.set(4, 5);
//	arr.set(7, 15);
//	arr.set(8, 22);
//	arr.exibir();

	// Arranjo<float> arr(5);
	// arr.set(0, 0.5);
	// arr.set(2, 9.5);
	// arr.set(3, 5.34);
	// arr.exibir();

	Arranjo<Aluno> turma(3);
	turma.set(0, Aluno("Joao","1234"));
	turma.set(1, Aluno("Maria","5235"));
	turma.set(2, Aluno("Jose","2412"));
	turma.exibir();

	return 0;
}
