#ifndef _pilha2_H_
#define _pilha2_H_

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
struct Node {
	T dados;
	struct Node * prox;
};

template <class T>
class Pilha {
	
	private:
		int capacidade;
		int Nitems; // Quantidade de Nós na pilha.
		Node<T> *topo;
		
		
	public:
		Pilha(int capacidade){
			this->topo = NULL;
			this->capacidade = capacidade;
			this->Nitems = 0;		
		}
		
		~Pilha(){
			while(this->topo != NULL){
				Node<T> *aux = this->topo;
				this->topo = this->topo->prox;
				delete aux;
			}
			delete topo;
		}
		
		void empilha(T item) {
			if(this->Nitems < this->capacidade){
				Node<T> *novoNode = new Node<T>;
				novoNode->dados = item;
				novoNode->prox = this->topo;
				this->topo = novoNode;	
				this->Nitems++;
			}else{
				throw overflow_error("Overflow");
			}
		}
		
		T desempilha(){
			if(this->Nitems > 0){
				Node<T> *aux = this->topo;
				this->topo = this->topo->prox;
				this->Nitems--;			
				return aux->dados;
			}else {
				throw underflow_error("Underflow");
			}
		}
};


#endif
