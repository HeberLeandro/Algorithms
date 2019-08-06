#include <iostream>
#include <stdio.h>
#include "veiculo.h"


using namespace std;

int main() {
	
	//Terrestre t1("t1");
	//cout << t1.getCap_pass() << endl;
	
	//Veiculo * terr, * aqua, * aereo;
	
	//terr = new Terrestre("VT1");
	//((Terrestre *) terr)->setCap_pass(45);
	//terr->mover();
	
	//Veiculo *aqua = new Aquatico("VQ1");
	//dynamic_cast<Aquatico*>(aqua)->mover();
	//((Aquatico *) aqua)->setCarga_max(12.5);
	
	
	//aereo = new Aereo("VA1");
	//((Aereo *) aereo)->setVel_max(1040.5);
	//aereo->mover();
	
	//delete terr;
	//delete aqua;
	//delete aereo;
	
	
	Veiculo *anfi  = new Anfibio("anfi");
	
	anfi->mover();
	
	delete anfi;
	
	

	return 0;
}

