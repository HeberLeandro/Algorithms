#include <iostream>
#include <string>

using namespace std;

class Roda {

	public:

		int roda;

		Roda(){
			this->roda = 1;
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

