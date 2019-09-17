#include <iostream>

using namespace std;

class ListaOrdenada {
private:
	int * items;
	int tamanho, capacidade;
public:
	ListaOrdenada(int cap) {
		this->capacidade = cap;
		this->tamanho = 0;
		items = new int[cap];
	}

	~ListaOrdenada() {
		delete [] items;
	}

	void insere(int key) {
		int posicao = -1;
		if(tamanho < capacidade){
			for(int i = 0; i < tamanho; i++){
				if(items[i] > key){
					posicao = i;
				}
			}
			if(posicao >= 0){
				for(int i = tamanho-1; i >= posicao; i--){
					items[i+1] = items[i];
				}
				items[posicao] = key;
				tamanho++;
			}else {
				items[tamanho] = key;
				tamanho++;
			}
		}
	}

	int buscaSequencial(int key) {
		// implementar
	}

	int buscaBinaria(int item) {
		return buscaBinaria(0, tamanho - 1, item);
	}

	int valida() {
		for (int i = 0; i < tamanho - 1; i++) {
			if (items[i] > items[i + 1]) return 0;
		}
		return 1;
	}

	void exibe() {
		for (int i = 0; i < tamanho; i++) {
			cout << i << ": " << items[i] << "; ";
		}
		cout << endl;
	}

private:

	int buscaBinaria(int inicio, int final, int item) {
		// implementar
	}

};


int main() {

	ListaOrdenada lista(10);

	int elementos [] = {10, 5, 25, 1, 5, 13, 50, 99, 33, 12};

	for (int i = 0; i < 10; i++) {
		lista.insere(elementos[i]);
	}

	cout << "Lista válida: " << (lista.valida()?"sim":"não") << endl;
	lista.exibe();

//	int teste [] = {5, 7, 16, 99, 45, 12, 33, 1, 60, 6};
//
//	for (int i = 0; i < 10; i++) {
//		cout << "Buscando " << teste[i] << ": sequencial = " << lista.buscaSequencial(teste[i]) << " binaria = " << lista.buscaBinaria(teste[i]) << endl;
//
//	}
	return 0;
} 


