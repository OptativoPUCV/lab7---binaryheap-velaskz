#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    if (pq->size == 0){
        return NULL;
    }
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    if (pq == NULL || pq->size >= pq->capac) {
        return; // El montículo es nulo o está lleno, no se puede agregar más elementos.
    }

    heapElem nuevoElemento;
    nuevoElemento.data = data;
    nuevoElemento.priority = priority;

    if (pq->size == pq->capac) {
        pq->capac *= 2;
        pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac * sizeof(heapElem));
        if (pq->heapArray == NULL) {
            // Manejar el error de realocación si es necesario
            return;
        }
    }

    int i = pq->size;
    pq->heapArray[i] = nuevoElemento;
    pq->size++;

    // Reajuste (Heapify Up)
    while (i != 0) {
        int parentIndex = (i - 1) / 2;
        if (pq->heapArray[parentIndex].priority > pq->heapArray[i].priority) {
            // Intercambiar el elemento con su padre si es necesario
            heapElem temp = pq->heapArray[i];
            pq->heapArray[i] = pq->heapArray[parentIndex];
            pq->heapArray[parentIndex] = temp;
            i = parentIndex;
        } else {
            // El elemento está en la posición correcta
            break;
        }
    }
}

// Función para calcular el índice del padre en el arreglo del montículo



void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* nuevoHeap = (Heap*)malloc(sizeof(Heap));
    if (nuevoHeap == NULL){
        return NULL; 
    }

    nuevoHeap->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
    if (nuevoHeap->heapArray == NULL){
        free(nuevoHeap);
        return NULL; 
    }

    nuevoHeap->size = 0;
    nuevoHeap->capac = 3;

    return nuevoHeap;
}
