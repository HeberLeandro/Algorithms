#ifndef _fila_H_
#define _fila_H_

#include <iostream>
using namespace std;

template <class T>
class Fila {
	
	private:
		int capacidade, Nitems, inicio;
		T * items;
	
	public:
		Fila(int capacidade){
			this->items = new T[capacidade];
			this->inicio =  -1;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		~Fila(){
			delete [] items;
		}
		
		void enfileira(const T & item){
			if(this->Nitems < this->capacidade){
				this->inicio += 1;	
				this->items[(this->inicio + this->Nitems) % this->capacidade] = item;
				this->Nitems += 1;
			}else{
				cout << "Overflow!" << endl;
			}
		}
		
		T desenfileira(){
			if(this->Nitems > 0){
				int aux = this->inicio;
				this->inicio = (this->inicio + 1) % this->capacidade;
				this->Nitems -= 1;			
				return this->items[aux];
			}else {
				cout << "Underflow!" << endl;
			}
		}
		
		int cheia(){
			if (this->Nitems == this->capacidade) return 1;
			else return 0;
		}
		
		int vazia(){
			if(this->Nitems == 0) return 1;
			else return 0;
		}
		
		int tamanho(){
			return this->Nitems;
		}
};



#endif
