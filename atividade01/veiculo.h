#ifndef _veiculo_H_
#define _veiculo_H_

#include <iostream>
#include <string>

using namespace std;

class Roda {

	public:

		int totalRodas;

		Roda(){
			this->totalRodas = 0;
			cout << "Roda adicionada" << endl;
		}

		~Roda(){
			cout << "Roda retirada" <<endl;
		}
};

class Veiculo {

	private:
		string nome;
		Roda *rodas;

	public:
		Veiculo(const char *string) {

			this->rodas = NULL;
			this->nome = string;


			cout << "O veiculo: "<< this->nome <<" foi criado!" << endl;
		}
		~Veiculo(){

			cout << "O veiculo: " << this->nome << ", foi destruido!" << endl;
			delete [] rodas;
		}

		//get & set
		void setNumRodas(int);
		int getNumRodas();
};

#endif

