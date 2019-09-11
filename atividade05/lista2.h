#ifndef _lista2_H_
#define _lista2_H_

#include <iostream>
using namespace std;

template <class T>
class Lista {
	
	private:
		int capacidade, Nitems;
		T * items;
	
	public:
		Lista(int capacidade) {
		// iniciliza��o do array, capacidade e tamanho
			this->items = new T[capacidade];
			this->capacidade = capacidade;
			this->Nitems = 0;
		}
		
		
		~Lista() {
		//destrui��o do array
			delete [] items;
		}
		
		void adiciona (const T & item) {
		// adiciona um item ao final da lista; lan�a �Lista cheia� caso cheia
			if(Nitems < capacidade){
				items[Nitems] = item;
				Nitems++; 
			}else {
				cout << "Lista cheia!" << endl;
			}
		}
		
		T pega(int idx) {
		// pega um item pelo indice (come�a em 1);
		// lan�a �Item inv�lido� se posi��o inv�lida
			if(idx > 0 && idx <= Nitems){
				return items[idx-1];
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
				for(int i = capacidade-1; i >= idx; i--){
					items[i] = items[i-1];
				}
				items[idx-1] = item;
				Nitems++;
			}else{
				cout << "Lista cheia ou item inv�lido!" << endl;
			}
		}
		
		void remove(int idx) {
		// remove item de uma posi��o indicada
		// lan�a �Item inv�lido� se posi��o inv�lida
		// desloca itens para a esquerda sobre o item removido
			if(idx > 0 && idx <= Nitems){
				for(int i = idx-1; i < capacidade -1; i++){
					items[i] = items[i+1];
				}
				Nitems--;
			}else{
				cout << "item inv�lido!" << endl;
			}
		}
		
		void exibe() {
		// exibe os itens da saida padr�o separados por espa�os
			for(int i = 0; i < Nitems; i++){
				cout << items[i] << " ";
			}
			cout << endl;
		}
};

#endif
