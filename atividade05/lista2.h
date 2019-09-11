#ifndef _lista2_H_
#define _lista2_H_

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T dados;
	struct Node * prox;
};

template <class T>
class Lista {
	
	private:
		int capacidade, Nitems;
		Node<T> *inicio;
		Node<T> *final;
	
	public:
		Lista(int capacidade) {
		// inicilização do array, capacidade e tamanho
			this->inicio = NULL;
			this->final = NULL;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		
		~Lista() {
		//destruição do array
			while(this->inicio != NULL){
				Node<T> *aux = this->inicio;
				this->inicio = this->inicio->prox;
				delete aux;
			}
			delete this->inicio;
		}
		
		void adiciona (const T & item) {
		// adiciona um item ao final da lista; lança “Lista cheia” caso cheia
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
			}else {
				cout << "Lista cheia!" << endl;
			}
		}
		
		T pega(int idx) {
		// pega um item pelo indice (começa em 1);
		// lança “Item inválido” se posição inválida
			if(idx > 0 && idx <= Nitems){
				Node<T> *aux = this->inicio;
				idx -= 1;
				while(idx > 0){
					aux = aux->prox;
					idx--;
				}
				return aux->dados;
				
			}else{
				cout << "Item inválido!" << endl;
			}
		
		}
		
		void insere (int idx, const T & item) {
		// insere um item na posição indicada (a partir de 1).
		// lança “Lista cheia” caso cheia
		// lança “Item inválido” se posição inválida
		// desloca itens existentes para a direita
			if((idx > 0 && idx <= Nitems) && Nitems < capacidade){
				Node<T> *novoNode = new Node<T>;
				novoNode->dados = item;
				novoNode->prox = NULL;
				if(idx == 1){
					novoNode->prox = this->inicio;
					this->inicio = novoNode;
				}else {
					Node<T> *aux = this->inicio;
					idx -= 2;
					while(idx > 0) {
						aux = aux->prox;
						idx--;
					}
					novoNode->prox = aux->prox;
					aux->prox = novoNode;
				}
				this->Nitems++;
			}else{
				cout << "Lista cheia ou item inválido!" << endl;
			}
		}
		
		void remove(int idx) {
		// remove item de uma posição indicada
		// lança “Item inválido” se posição inválida
		// desloca itens para a esquerda sobre o item removido
			if(idx > 0 && idx <= Nitems){
				Node<T> *aux;
				if(idx == 1){
					aux = this->inicio;
					this->inicio = this->inicio->prox;
					if(aux == this->final){
						this->final = NULL;
					}
				}else {
					aux = this->inicio;//aux = anterior
					Node<T> *tmp;
					idx -= 2;
					while(idx > 0) {
						aux = aux->prox;
						idx--;
					}
					tmp = aux->prox;
					aux->prox = tmp->prox;
					if(this->final == tmp){
						this->final = aux;
					}	
				}
				this->Nitems--;
			}else{
				cout << "item inválido!" << endl;
			}
		}
		
		void exibe() {
		// exibe os itens da saida padrão separados por espaços
			Node<T> *aux = this->inicio;
			int i = this->Nitems;
			while(i > 0){
				cout << aux->dados << " ";
				aux = aux->prox;
				i--;
			}
			cout << endl;
		}	
};

#endif
