#ifndef _lista_H_
#define _lista_H_

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class Lista {
	
	private:
		int capacidade, Nitems;
		T * items;
	
	public:
		Lista(int capacidade) {
		// inicilização do array, capacidade e tamanho
			this->items = new T[capacidade];
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		
		~Lista() {
		//destruição do array
			delete [] items;
		}
		
		void adiciona (const T & item) {
		// adiciona um item ao final da lista; lança “Lista cheia” caso cheia
			if(Nitems < capacidade){
				items[Nitems++] = item; 
			}else {
				throw overflow_error("Overflow");
			}
		}
		
		T pega(int idx) {
		// pega um item pelo indice (começa em 1);
		// lança “Item inválido” se posição inválida
			if(idx > 0 && idx <= Nitems){
				return items[idx-1];
			}else{
				throw underflow_error("Item invalido");
			}
		
		}
		
		void insere (int idx, const T & item) {
		// insere um item na posição indicada (a partir de 1).
		// lança “Lista cheia” caso cheia
		// lança “Item inválido” se posição inválida
		// desloca itens existentes para a direita
			if((idx > 0 && idx <= Nitems) && Nitems < capacidade){
				for(int i = Nitems-1; i >= idx; i--){
					items[i] = items[i-1];
				}
				items[idx-1] = item;
				Nitems++;
			}else{
				throw overflow_error("Overflow");
			}
		}
		
		void remove(int idx) {
		// remove item de uma posição indicada
		// lança “Item inválido” se posição inválida
		// desloca itens para a esquerda sobre o item removido
			if(idx > 0 && idx <= Nitems){
				for(int i = idx-1; i < Nitems -1; i++){
					items[i] = items[i+1];
				}
				Nitems--;
			}else{
				throw underflow_error("Item Invalido");
			}
		}
		
		void exibe() {
		// exibe os itens da saida padrão separados por espaços
			for(int i = 0; i < Nitems; i++){
				cout << items[i] << " ";
			}
			cout << endl;
		}
};

#endif
