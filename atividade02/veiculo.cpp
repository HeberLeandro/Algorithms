#include "veiculo.h"

//VEICULO
//void Veiculo::setNumRodas(int tam) {
// 
//	delete [] this->rodas;
//	this->rodas= new Roda[tam];
//	this->totalRodas = tam;
///}

//int Veiculo::getNumRodas(){

//	return this->totalRodas;
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

//Anfibio 
void Anfibio ::mover(){
	
	Terrestre::mover();
	Aquatico::mover(); 
}
