#include <string>
#ifndef VEICULO_H // if
#include "veiculo.h"
#endif // END IF


void Veiculo::setNumRodas(int tam) {
	Roda * Vrodas = new Roda[tam];
	this->rodas = &Vrodas[0];
}

int Veiculo::getNumRodas(){
	int i = 0;
	Roda *aux = this->rodas;

	while(aux->roda == 1){
		i += aux->roda;
		++aux;
	}
	return i;
}

