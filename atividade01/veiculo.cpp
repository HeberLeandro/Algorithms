#include <string>
#include "veiculo.h"



void Veiculo::setNumRodas(int tam) {
	
	if(this->rodas != NULL){
		delete [] this->rodas;
	}
	
	Roda * Vrodas = new Roda[tam];
	Vrodas[0].totalRodas = tam;
	this->rodas = Vrodas;
}

int Veiculo::getNumRodas(){
	
	return this->rodas->totalRodas;
}

