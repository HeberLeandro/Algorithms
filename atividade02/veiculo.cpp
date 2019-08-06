#include <string>
#include "veiculo.h"



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

Terrestre::Terrestre(const char *nome) : Veiculo(nome){
}

