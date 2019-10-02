#ifndef _fila2_H_
#define _fila2_H_

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class FilaGenerica{
	public:
		int capacidade, Nitems;
		
		FilaGenerica(int cap){
			this->capacidade = cap;
		}
		
		virtual ~FilaGenerica(){}
		
	 	virtual void enfileira(const T & item) = 0;
	 	virtual T desenfileira() = 0;
	 	virtual int cheia() = 0;
	 	virtual int vazia() = 0;
	 	virtual int tamanho() = 0;
};


template <class T>
class FilaEncadeada : public FilaGenerica<T>{
	
	private:
		struct Node {
			T dados;
			struct Node * prox;
		};
		Node *inicio;
		Node *final;
	
	public:
		FilaEncadeada(int capacidade) : FilaGenerica<T>(capacidade){
			this->inicio = NULL;
			this->final = NULL;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		~FilaEncadeada(){
			while(this->Nitems > 0){
				desenfileira();
			}
		}
		
		void enfileira(const T & item){
			if(this->Nitems < this->capacidade){
				Node *novoNode = new Node;
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
				throw overflow_error("Overflow");
			}
		}
		
		T desenfileira(){
			if(this->Nitems > 0){
				Node *aux = this->inicio;
				this->inicio = this->inicio->prox;
				if(this->inicio == NULL){
					this->final = NULL;
				}
				T dados = aux->dados;
				delete aux;
				this->Nitems--;						
				return dados;
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



template <class T>
class FilaArray : public FilaGenerica<T> {
	
	private:
		int inicio;
		T * items;
	
	public:
		FilaArray(int capacidade) : FilaGenerica<T>(capacidade){
			this->items = new T[capacidade];
			this->inicio =  0;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		~FilaArray(){
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
