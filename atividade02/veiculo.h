#ifndef _veiculo_H_
#define _veiculo_H_

#include <iostream>
#include <string>

using namespace std;

class Roda {

	public:
		
		Roda(){
			cout << "Roda adicionada" << endl;
		}

		~Roda(){
			cout << "Roda retirada" <<endl;
		}
};

class Veiculo {

	protected:
		string nome;
		Roda *rodas;
		int totalRodas;

	public:
		Veiculo(const char *string) {

			this->rodas = NULL;
			this->nome = string;


			cout << "O veiculo: "<< this->nome <<" foi criado!" << endl;
		}

		virtual	~Veiculo(){

			cout << "O veiculo: " << this->nome << ", foi destruido!" << endl;
			delete [] rodas;
		}
		
		virtual void mover() = 0;
		
		//get & set
		void setNumRodas(int);
		int getNumRodas();
};



class Terrestre : virtual public Veiculo {
	
	private:
		int cap_pass;
		
	protected:
		Terrestre() : Veiculo("Terr") {
		}
		
		
	public:
		Terrestre(const char * nome) : Veiculo(nome) {
			this->cap_pass = 5;
			cout << "O veiculo Terrestre: "<< this->nome << " foi criado!" << endl;
		}
		public:	
		virtual ~Terrestre(){
			cout << "O veiculo Terrestre: "<< this->nome <<" foi Destruido!" << endl;
		}
		
		void setCap_pass(int);
		int getCap_pass();
		void mover();
	
};



class Aquatico : virtual public Veiculo {
	
	private:
		float carga_max;
		
	protected:
		Aquatico() : Veiculo("Aqua") {
		}
				
	public:			
		Aquatico(const char * nome) : Veiculo(nome) {//: Veiculo(const char*nome){
			this->carga_max = 10;
			cout << "O veiculo Aquatico: " << this->nome << " foi criado!" << endl;
		}
	
		virtual ~Aquatico(){
			cout << "O veiculo Aquatico: "<< this->nome <<" foi Destruido!" << endl;
		}

		void setCarga_max(float);
		int getCarga_max();
		void mover();
			
};

class Aereo : public Veiculo {
	
	private: 
		float vel_max;
	
	public:
		Aereo(const char * nome) : Veiculo(nome) { //(const char *nome) : Veiculo(nome){
			this->vel_max = 100;
			cout << "O veiculo Aereo: "<< this->nome <<" foi criado!" << endl;
		}
		
		virtual ~Aereo(){
			cout << "O veiculo Aereo: "<< this->nome <<" foi Destruido!" << endl;
		}
		
		void setVel_max(float);
		int getVel_max();
		void mover();
		
};

class Anfibio : public Terrestre, public Aquatico {
	
	public:
		Anfibio (const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {
			cout << "O veiculo Anfibio: "<< this->nome <<" foi criado!" << endl;
		}
		virtual ~Anfibio(){
			cout << "O veiculo Anfibio: "<< this->nome <<" foi Destruido!" << endl;
		}

		virtual void mover();
	
};

#endif

