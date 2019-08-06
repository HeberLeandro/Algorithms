#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM]){
	int i;
	
	//imprime o vetor
	for(i = 0; i < TAM; i++) {
		cout << vetor[i] << " - ";	
	}
}

int busca_simples(int vetor[TAM], int valorProcurado, int *posicao){
	int i;
	bool valorFoiEncontrado;	
	//percorre a lista
	for(i = 0; i < TAM; i++) {
		if(vetor[i] == valorProcurado){
			valorFoiEncontrado = true;
			*posicao = i;
		}
	}
	
	if(valorFoiEncontrado) {
	  return 1;
	}else{
		return -1;
	}
}

int busca_binaria(int vetor[TAM], int valorProcurado, int *posicao){
	int esquerda = 0;
	int direita = TAM - 1;
	int meio;
	
	while (esquerda <= direita){
	
		//meio do vetor
		meio = (esquerda + direita) / 2;
	
		if(valorProcurado == vetor[meio]) {
			*posicao = meio;
			return 1;
		}
		//ajustando limite
		if(vetor[meio] < valorProcurado){
			esquerda = meio + 1;
		}else {
			direita = meio - 1;
		}
	}
	
	return -1;
}
	

int main() {
	
	int vetor[TAM] = {1,23,44,56,63,72,84,90,98,110};
	int valorProcurado;
	int posicao;
	
	//funcao que imprime o vetor
	imprime_vetor(vetor);
	
	//ler o numero buscara
	printf("\nQual o numero deseja encontrar?");
	scanf("%d", &valorProcurado);
	
	if(busca_binaria(vetor, valorProcurado, &posicao) == 1){
		cout << "O valor foi encontrado na posicao:" << posicao;
	}else{
		cout << "Valor nao encontrado";
	}
	
	
	return 0;
}
