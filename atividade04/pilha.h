#ifndef _pilha_H_
#define _pilha_H_

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class Pilha{
	
	private:
		int capacidade, topo;
		T * items;
		
	public:
		Pilha(int capacidade){
			this->items = new T[capacidade];
			this->topo = -1;
			this->capacidade = capacidade;		
		}
		
		~Pilha(){
			delete [] items;
		}
		
		void empilha(T item) {
			if(this->topo < this->capacidade-1){
				this->topo += 1;	
				this->items[this->topo] = item;
			
			}else{
				throw overflow_error("Overflow");
			}
		}
		
		T desempilha(){
			if(this->topo >= 0){
				int aux = this->topo;
				this->topo -= 1;			
				return this->items[aux];
			}else {
				throw underflow_error("Underflow");
			}
		}
};


#endif
