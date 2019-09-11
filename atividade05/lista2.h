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
		// iniciliza��o do array, capacidade e tamanho
			this->inicio = NULL;
			this->final = NULL;
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		
		~Lista() {
		//destrui��o do array
			while(this->inicio != NULL){
				Node<T> *aux = this->inicio;
				this->inicio = this->inicio->prox;
				delete aux;
			}
			delete this->inicio;
		}
		
		void adiciona (const T & item) {
		// adiciona um item ao final da lista; lan�a �Lista cheia� caso cheia
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
		// pega um item pelo indice (come�a em 1);
		// lan�a �Item inv�lido� se posi��o inv�lida
			if(idx > 0 && idx <= Nitems){
				Node<T> *aux = this->inicio;
				idx -= 1;
				while(idx > 0){
					aux = aux->prox;
					idx--;
				}
				return aux->dados;
				
			}else{
				cout << "Item inv�lido!" << endl;
			}
		
		}
		
		void insere (int idx, const T & item) {
		// insere um item na posi��o indicada (a partir de 1).
		// lan�a �Lista cheia� caso cheia
		// lan�a �Item inv�lido� se posi��o inv�lida
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
				cout << "Lista cheia ou item inv�lido!" << endl;
			}
		}
		
		void remove(int idx) {
		// remove item de uma posi��o indicada
		// lan�a �Item inv�lido� se posi��o inv�lida
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
				cout << "item inv�lido!" << endl;
			}
		}
		
		void exibe() {
		// exibe os itens da saida padr�o separados por espa�os
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
