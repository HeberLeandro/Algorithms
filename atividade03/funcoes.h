#ifndef _funcoes_H_
#define _funcoes_H_

void trocar(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
	
}

int maximo(const int a, const int b){
	
	if(a > b) return a;
	else if(a < b) return b;
	else return a; 
}

int minimo(const int a, const int b){
	
	if(a > b) return b;
	else if(a < b) return a;
	else return a;
}

#endif
