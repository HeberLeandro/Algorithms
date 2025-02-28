/*
 * lista.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>
#include "lista.h"
using namespace std;

int main() {
	Lista<char> lista(10);

	lista.adiciona('a');	// a
	lista.adiciona('b');	// a b
	lista.adiciona('c');	// a b c
	lista.adiciona('d');	// a b c d
	lista.adiciona('e');	// a b c d e
	lista.exibe(); 			// a b c d e (sa�da)

	lista.remove(3); 		// a b d e
	lista.exibe(); 			// a b d e (sa�da)

	cout << lista.pega(4) << endl; 			// e
	lista.insere(2, 'f'); 	// a f b d e
	lista.exibe(); 			// a f b d e (sa�da)

	lista.adiciona('g'); 	// a f b d e g
	lista.insere(4, 'h'); 	// a f b h d e g
	cout << lista.pega(2) << endl; 			// f
	lista.exibe(); 			// a f b h d e g (sa�da)
	
	return 0;
}


