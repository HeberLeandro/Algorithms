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
			this->inicio =  0;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		~Fila(){
			delete [] items;
		}
		
		void enfileira(const T & item){
			if(this->Nitems < this->capacidade){
				this->items[(this->inicio + this->Nitems) % this->capacidade] = item;
				this->Nitems++;
			}else{
				throw overflow_error("Overflow");
			}
		}
		
		T desenfileira(){
			if(this->Nitems > 0){
				this->Nitems--;
				int aux = this->inicio;	
				this->inicio = (this->inicio + 1) % this->capacidade;
				return this->items[aux];
			}else {
				throw underflow_error("Underflow");
			}
		}
		
		int cheia(){
			 return (this->Nitems == this->capacidade);
		}
		
		int vazia(){
			 return (this->Nitems == 0);
		}
		
		int tamanho(){
			return this->Nitems;
		}
};



#endif
