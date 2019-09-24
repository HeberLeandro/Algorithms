#include <iostream>
#include <stdexcept>

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
		bool ehMenor = false;
		if(this->tamanho < this->capacidade){
			if(this->tamanho == 0){
				this->items[0] = key;
				tamanho++;
			}else{
				for(int i = 0; i < this->capacidade; i++){
					if(key <= items[i]){
						for(int j = this->capacidade - 1; j >= i; j--){
							items[j+1] = items[j];
						}
						ehMenor = true;
						items[i] = key;	
						this->tamanho++;
						break;					
					}
				}
				if(!ehMenor){
					items[this->tamanho] = key;
					this->tamanho++;
				}
			}
		}else {
			throw overflow_error("Overflow");
		}
	}

	int buscaSequencial(int key) {
		int i, idx;
		bool valorEncontrado;	
		//percorre a lista
		for(i = 0; i < tamanho; i++) {
			if(items[i] == key){
				valorEncontrado = true;
				idx = i;
				break;
			}
		}
		
		if(valorEncontrado) {
		  return idx;
		}else{
			return -1;
		}
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
	
	void remove(int idx) {
		// remove item de uma posição indicada
		// lança “Item inválido” se posição inválida
		// desloca itens para a esquerda sobre o item removido
		if(idx > 0 && idx <= this->tamanho){
			for(int i = idx-1; i < this->tamanho -1; i++){
				items[i] = items[i+1];
			}
			this->tamanho--;
		}else{
			throw underflow_error("Item Invalido");
		}
	}

private:

	int buscaBinaria(int inicio, int final, int item) {
		int meio;
		while(inicio <= final){
			meio = (inicio + final) / 2;
			
			if(item == items[meio]) return meio;
			
			if(items[meio] < item) inicio = meio + 1;
		
			else final = meio - 1;
		}
		return -1;
	}

};


int main() {

	ListaOrdenada lista(10);

	int elementos [] = {10, 5, 25, 1, 5, 13, 50, 99, 33, 12};

	for (int i = 0; i < 10; i++) {
		lista.insere(elementos[i]);
	}
//	lista.remove(2);
//	lista.remove(2);
	
	cout << "Lista válida: " << (lista.valida()?"sim":"não") << endl;
	lista.exibe();

	int teste [] = {5, 7, 16, 99, 45, 12, 33, 1, 60, 6};

	for (int i = 0; i < 10; i++) {
		cout << "Buscando " << teste[i] << ": sequencial = " << lista.buscaSequencial(teste[i]) << " binaria = " << lista.buscaBinaria(teste[i]) << endl;
	}
	return 0;
} 


