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
        return; 
    }

    heapElem nuevoElemento;
    nuevoElemento.data = data;
    nuevoElemento.priority = priority;

    if (pq->size == pq->capac) {
        pq->capac *= 2;
        pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    }

    int i = pq->size;
    pq->heapArray[i] = nuevoElemento;
    pq->size++;

}

void heap_pop(Heap* pq) {
    if (pq->size == 0) {
        return;
    }

    // Mover el último elemento al inicio del heap
    pq->heapArray[0] = pq->heapArray[pq->size - 1];
    pq->size--;

    int i = 0;

    while (1) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int largest = i;

        // Encontrar el hijo con la mayor prioridad
        if (left_child < pq->size && pq->heapArray[left_child].priority > pq->heapArray[largest].priority) {
            largest = left_child;
        }
        if (right_child < pq->size && pq->heapArray[right_child].priority > pq->heapArray[largest].priority) {
            largest = right_child;
        }

        if (largest == i) {
            break;
        }

        // Intercambiar elementos si es necesario
        heapElem temp = pq->heapArray[i];
        pq->heapArray[i] = pq->heapArray[largest];
        pq->heapArray[largest] = temp;

        i = largest;
    }
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
