/*
 * graph.cpp

 *
 *  Created on: 10 de nov de 2017
 *      Author: ramide
 */
#include "graph.h"

Graph::Graph(int numVertices) {
	this->numVertices = numVertices;

	used = new int[numVertices];
	group = new int[numVertices];
	matrix = new int*[numVertices];

	for (int i = 0; i < numVertices; i++) {
		used[i] = 0;
		matrix[i] = new int[numVertices];
		for (int n = 0; n < numVertices; n++)
			matrix[i][n] = 0;
	}
}

Graph::~Graph() {
	for (int i = 0; i < numVertices; i++)
		delete [] matrix[i];

	delete [] matrix;
	delete [] used;
	delete [] group;
}


void Graph::edge(int v1, int v2) {
	matrix[v1][v2] = 1;
	used[v1] = 1;
	used[v2] = 1;
}


// Indica se existe caminho entre v1 e v2,
// isto é, se eles fazem parte do mesmo grupo
int Graph::_find(int v1, int v2) {
	return (group[v1] == group[v2]);
}

// Faça a união dos grupos de v1 e v2
// Ao final, group[v1] == group[v2],
// e todos os nós que faziam parte do grupo de v1
// agora fazem o parte do grupo de v2 (e vice-versa)
void Graph::_union(int v1, int v2) {
	if (group[v1] == group[v2]) return;

	for (int k = 0; k < numVertices; k++) {
		if (group[k] == group[v2])
			group[k] = group[v1];
	}
}

// Ver descrição na prática
int Graph::connected() {
	// TODO
	
	// Inicializar grupos
	for(int i = 0; i < numVertices; i++){
		if(used[i] == 1){
			group[i] = i;
		}
		for (int n = 0; n < numVertices; n++){
			if(matrix[i][n] == 1){
				_union(i, n);
			}
		}
	}
	
	for(int i = 1; i < numVertices-1; i++){
		if(used[i] == 1 && used[i+1] == 1){
			if( !(_find(i, i+1)) ) return 1;
		}
	}	
	
	// Para todos as arestas, faça a união dos dois vértices
	// (isto é, agora eles são parte do mesmo grupo)

	// Para todos os nós (usados), verifique se estão no mesmo grupo
	// (isto é, grafo o grafo é conexo)

	return 0;
}

int Graph::degree(int v) {
	int total = 0;
	
	for(int i = 0; i < numVertices; i++){
		total += matrix[v][i];
	}
	
	return total;
}



