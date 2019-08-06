#include <string>
#include "veiculo.h"

//VEICULO
//void Veiculo::setNumRodas(int tam) {
//	Roda * Vrodas = new Roda[tam];
//	this->rodas = &Vrodas[0];
///}

//int Veiculo::getNumRodas(){
//	int i = 0;
//	Roda *aux = this->rodas;

//	while(aux->roda == 1){
//		i += aux->roda;
//		++aux;
//	}
//	return i;
//}


//TERRESTRE
void Terrestre::setCap_pass(int cap){
	this->cap_pass = cap;
}

int Terrestre::getCap_pass(){
	return this->cap_pass;
}

void Terrestre::mover(){
	cout << "Veiculo Terrestre " << this->nome << " moveu" << endl;
}


//AQUATICO
void Aquatico::setCarga_max(float carga_max){
	this->carga_max = carga_max;
}

int Aquatico::getCarga_max(){
	return this->carga_max;
}

void Aquatico::mover(){
	cout << "Veiculo Aquatico " << this->nome << " moveu" << endl;
}

//AEREO
void Aereo::setVel_max(float vel_max){
	this->vel_max = vel_max;	
}

int Aereo::getVel_max(){
	return this->vel_max;
}

void Aereo::mover(){
	cout << "Veiculo Aereo " << this->nome << " moveu" << endl;
}

