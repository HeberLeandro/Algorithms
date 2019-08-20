#ifndef _arranjo_H_
#define _arranjo_H_

#include <iostream>

using namespace std;

template <class T>
class Arranjo {
	
	private:
		int tamanho; // tamanho do arranjo
		T * items; //items do arranjo
		
	public:
		
		Arranjo(int tam) {
			this->tamanho = tam;
			this->items = new T[tam];
			cout << "Arranjo com o tamanho: " << this->tamanho << ", foi criado." << endl;
		}
		
		virtual ~Arranjo() {
			cout << "Arranjo destruido" << endl;
			delete [] items;
		}
		
		virtual T get(int idx) {
		// retornar um item do array a partir do indice;
			return this->items[idx];
		}
		
		virtual void set(int idx, const T &item) {
		// set o item do array apontado pelo indice usando =
			this->items[idx] = item;
		}
		
		virtual void exibir();
};
		
template<class T>
void Arranjo<T>::exibir() {
// exibir cada item numa linha da forma "<idx>: <item>"
	for(int i = 0; i < this->tamanho; i++){
		cout << "index > " << i << " : item > " << this->get(i) << endl;
	}
}
#endif
