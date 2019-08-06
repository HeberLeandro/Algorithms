#ifndef _veiculo_H_
#define _veiculo_H_

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

	protected:
		string nome;
		Roda *rodas;

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



class Terrestre : public virtual Veiculo {
	
	private:
		int cap_pass = 5;
		
	protected:
		Terrestre(const char *nome) : Veiculo(nome){
			cout << "O veiculo Terrestre: foi criado!" << endl;
		
		public:	
		virtual ~Terrestre(){
			cout << "O veiculo Terrestre: "<< this->nome <<" foi Destruido!" << endl;
		}
		
		void setCap_pass(int);
		int getCap_pass();
		void mover();
	
};



class Aquatico : public virtual Veiculo {
	
	private:
		float carga_max = 10;
		
	protected:
		
		Aquatico(const char *nome) : Veiculo(nome){
			cout << "O veiculo Aquatico: foi criado!" << endl;
		}
		
	public:	
		
		virtual ~Aquatico(){
			cout << "O veiculo Aquatico: "<< this->nome <<" foi Destruido!" << endl;
		}

		void setCarga_max(float);
		int getCarga_max();
		void mover();
			
};

class Aereo : public Veiculo {
	
	private: 
		float vel_max = 100;
	
	public:
		Aereo(const char *nome) : Veiculo(nome){
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
		Anfibio (const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {}
	
};

#endif

