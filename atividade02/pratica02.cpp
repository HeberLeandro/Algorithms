#include <iostream>
#include "veiculo.h"


using namespace std;

int main() {
	//Terrestre t1("t1");
	//cout << t1.getCap_pass() << endl;
	
	Veiculo * terr, * aqua, * aereo;
	
	terr = new Terrestre("VT1");
	dynamic_cast<Terrestre*>(terr)->setCap_pass(45);
	//((Terrestre *) terr)->setCap_pass(45);
	terr->mover();
	
	aqua = new Aquatico("VQ1");
	dynamic_cast<Aquatico*>(aqua)->setCarga_max(12.5);
	aqua->mover();
	//((Aquatico *) aqua)->setCarga_max(12.5);
	
	aereo = new Aereo("VA1");
	dynamic_cast<Aereo*>(aereo)->setVel_max(1040.5);
	aereo->mover();
	

	Veiculo *anfi  = new Anfibio("anfi");
	anfi->mover();
	
	cout << endl;
	
	delete terr;
	delete aqua;
	delete aereo;
	
	delete anfi;
	
	return 0;
}

