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

    pq->heapArray[0].data = pq->heapArray[pq->size - 1].data;
    pq->heapArray[0].priority = pq->heapArray[pq->size - 1].priority;
    pq->size--;

    size_t k = 0;
    size_t anteriorK = k;

    int izquierda = 2 * k + 1;
    int derecha = 2 * k + 2;

    while (izquierda < pq->size || derecha < pq->size) {
        anteriorK = k;

        if (izquierda < pq->size && derecha < pq->size) {
            if (pq->heapArray[izquierda].priority < pq->heapArray[derecha].priority) {
                k = derecha;
            } else {
                k = izquierda;
            }
        } else if (izquierda < pq->size) {
            k = izquierda;
        } else if (derecha < pq->size) {
            k = derecha;
        }

        int aux = pq->heapArray[k].priority;
        pq->heapArray[k].priority = pq->heapArray[anteriorK].priority;
        pq->heapArray[anteriorK].priority = aux;

        void* data = pq->heapArray[k].data;
        pq->heapArray[k].data = pq->heapArray[anteriorK].data;
        pq->heapArray[anteriorK].data = data;

        izquierda = 2 * k + 1;
        derecha = 2 * k + 2;
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
