#ifndef _fila_H_
#define _fila_H_

#include <stdexcept>
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
				this->inicio++;	
				this->items[(this->inicio + this->Nitems) % this->capacidade] = item;
				this->Nitems++;
			}else{
				throw overflow_error("Overflow");
			}
		}
		
		T desenfileira(){
			if(this->Nitems > 0){
				this->Nitems--;			
				return this->items[(this->inicio + 1) % this->capacidade];
			}else {
				throw underflow_error("Underflow");
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
