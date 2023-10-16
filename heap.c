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




void heap_pop(Heap* pq){
    if (pq->size == 0) {
        return;
    }

    // Mover el último elemento al inicio del heap
    pq->heapArray[0].data = pq->heapArray[pq->size - 1].data;
    pq->heapArray[0].priority = pq->heapArray[pq->size - 1].priority;
    pq->size--;

    // Reordenar el heap después de quitar el elemento superior
    int i = 0;
    while (1) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int smallest = i;

        if (left_child < pq->size && pq->heapArray[left_child].priority < pq->heapArray[smallest].priority) {
            smallest = left_child;
        }

        if (right_child < pq->size && pq->heapArray[right_child].priority < pq->heapArray[smallest].priority) {
            smallest = right_child;
        }

        if (smallest != i) {
            // Intercambiar elementos si la prioridad del hijo es menor que la del padre
            heapElem temp = pq->heapArray[i];
            pq->heapArray[i] = pq->heapArray[smallest];
            pq->heapArray[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
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
