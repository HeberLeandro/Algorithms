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
			while(this->inicio != NULL){
				Node<T> *aux = this->inicio;
				this->inicio = this->inicio->prox;
				delete aux;
			}
			delete this->inicio;
		}
		
		void enfileira(const T & item){
			if(this->Nitems < this->capacidade){
				Node<T> *novoNode = new Node<T>;
				novoNode->dados = item;
				novoNode->prox = NULL;
				if(this->inicio == NULL){
					this->inicio = novoNode;
				}else{
					this->final->prox = novoNode;
				}
				this->final = novoNode;
				this->Nitems++;
			}else{
				cout << "Overflow!" << endl;
			}
		}
		
		T desenfileira(){
			if(this->Nitems > 0){
				Node<T> *aux = this->inicio;
				this->inicio = this->inicio->prox;
				if(this->inicio == NULL){
					this->final = NULL;
				}
				this->Nitems--;						
				return aux->dados;
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
