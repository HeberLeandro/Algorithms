#include "veiculo.h"


void Veiculo::setNumRodas(int qtdRodas) {
	
	delete [] this->rodas;

 	this->rodas = new Roda[qtdRodas];
	this->totalRodas = qtdRodas;
}

int Veiculo::getNumRodas(){
	return this->totalRodas;
}

