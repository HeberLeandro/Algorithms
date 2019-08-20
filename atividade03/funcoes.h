#ifndef _funcoes_H_
#define _funcoes_H_
#include <cstring>


namespace funcoes{
	
	template <class T>
	void trocar(T &a, T &b){
		T aux = a;
		a = b;
		b = aux;
		
	}
	
	template <class T>
	T maximo(const T a, const T b){
		
		if(a > b) return a;
		else if(a < b) return b;
		else return a; 
	}
	
	template <char * T> 
	char maximo(const char * a, const char * b){
		
		if(strcmp(a,b) > 0 ) return a;
		else if(strcmp(a,b) < 0 ) return b;
		else return a; 
	}
	
	
	template <class T>
	T minimo(const T a, const T b){
		
		if(a > b) return b;
		else if(a < b) return a;
		else return a;
	}
}
#endif
