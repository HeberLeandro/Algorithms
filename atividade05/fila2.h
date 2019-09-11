#ifndef _fila2_H_
#define _fila2_H_

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T dados;
	struct Node * prox;
};

template <class T>
class Fila {
	
	private:
		int capacidade, Nitems;
		Node<T> *inicio;
		Node<T> *final;
	
	public:
		Fila(int capacidade){
			this->inicio = NULL;
			this->final = NULL;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		~Fila(){
			delete this;
		}
		
		void enfileira(const T & item){
			if(this->Nitems < this->capacidade){
				this->inicio;	
				this->items[(this->inicio + this->Nitems) % this->capacidade] = item;
				this->Nitems++;
			}else{
				cout << "Overflow!" << endl;
			}
		}
		
		T desenfileira(){
			if(this->Nitems > 0){
				this->Nitems--;			
				return this->items[(this->inicio + 1) % this->capacidade];
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
