/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int validate(int * data, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (data[i] > data[i + 1]) return 0;
	}
	return 1;
}

void print(int * data, int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int * clone(int * array, int size) {
	int * copy = new int[size];
	for (int i = 0; i < size; i++) { copy[i] = array[i]; }
	return copy;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void noopsort(int * array, int size) {
	// no-op
}


void bubblesort(int * array, int size) {
	//TO DO
	bool troca;
	do{
		troca = false;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]){
				swap(array[i], array[i + 1]);
				troca = true;
			}
		}
	}while(troca);
}


void selectionsort(int * array, int size) {
	//TO DO
	int min;
	for (int i = 0; i < size; i++) {
		min = i;
		for(int j = i+1; j < size; j++){
			if(array[min] > array[j]){
				min = j;
			}
		}
		swap(array[min],array[i]);
	}
}


void insertionsort(int * array, int size) {
	//TO DO
}

void merge(int * target, int * buffer, int start, int mid, int finish) {
	//TO DO
	int inicio = start, meio = mid;
	for(int i = start;i <= finish; i++){
		if(inicio <= mid-1 && meio <= finish){
			if(buffer[inicio] <= buffer[meio]){
				target[i] = buffer[inicio++];
			}else {
				target[i] = buffer[meio++];
			}
		}
		else if(inicio <= mid-1){
			target[i] = buffer[inicio++];
		}
		else if(meio <= finish){
			target[i] = buffer[meio++];
		}
	}
}

void mergesort(int * target, int * buffer, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(buffer, target, start, mid);
	mergesort(buffer, target, mid + 1, finish);

	merge(target, buffer, start, mid + 1, finish);
}

void mergesort(int * array, int size) {
	int * copy = clone(array, size);
	mergesort(array, copy, 0, size - 1);
	delete [] copy;
}

int partition(int * array, int start, int finish) {
	//TO DO
	int pivo = array[finish];
	int P = start-1;
	for(int i = start; i <= finish; i++){
		if(array[i] <= pivo){
			P++;
			swap(array[i], array[P]);
		}	
	}
	return P;
}

void quicksort(int * array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

void quicksort(int * array, int size) {
	quicksort(array, 0, size - 1);
}



void show(int * array, int size, const char * name, void function(int *, int), int printFlag) {
	int * copy = clone(array, size);
	auto start = std::chrono::high_resolution_clock::now();

	function(copy, size);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy, size);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") "; //<< endl;

	if (printFlag) print(copy, size);
	delete [] copy;
}

int main() {
	int size = 15;
	int print = 1;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	
	show(array, size, "NoOpSort     ", noopsort, print);
	show(array, size, "BubbleSort   ", bubblesort, print);
	show(array, size, "SelectionSort", selectionsort, print);
	//show(array, size, "InsertionSort", insertionsort, print);
	show(array, size, "MergeSort    ", mergesort, print);
	show(array, size, "QuickSort    ", quicksort, print);
	delete [] array;
}






