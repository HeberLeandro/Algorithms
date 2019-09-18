#ifndef _pilha_H_
#define _pilha_H_

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class Pilha {
	
	private:
		int capacidade, Nitems, topo;
		T * items;
		
	public:
		Pilha(int capacidade){
			this->items = new T[capacidade];
			this->topo =  -1;
			this->capacidade = capacidade;
			this->Nitems = 0;		
		}
		
		~Pilha(){
			delete [] items;
		}
		
		void empilha(T item) {
			if(this->Nitems < this->capacidade){
				this->topo += 1;	
				this->items[this->topo] = item;
				this->Nitems += 1;
			
			}else{
				throw overflow_error("Overflow");
			}
		}
		
		T desempilha(){
			if(this->Nitems > 0){
				int aux = this->topo;
				this->topo -= 1;
				this->Nitems -= 1;			
				return this->items[aux];
			}else {
				throw underflow_error("Underflow");
			}
		}
};


#endif
