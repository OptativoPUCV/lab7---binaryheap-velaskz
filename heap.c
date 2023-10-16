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

    pq->heapArray[0] = pq->heapArray[pq->size - 1];
    pq->size--;

    int i = 0;
    int hijo_izquierda = 1;
    int hijo_derecha = 2;
    int masLargo = i;

    while (1) {
        if (hijo_izquierda < pq->size && pq->heapArray[hijo_izquierda].priority > pq->heapArray[masLargo].priority) {
            masLargo = hijo_izquierda;
        }
        if (hijo_derecha < pq->size && pq->heapArray[hijo_derecha].priority > pq->heapArray[masLargo].priority) {
            masLargo = hijo_derecha;
        }

        if (masLargo == i) {
            break;
        }

        heapElem temp = pq->heapArray[i];
        pq->heapArray[i] = pq->heapArray[masLargo];
        pq->heapArray[masLargo] = temp;

        i = masLargo;
        hijo_izquierda = 2 * i + 1;
        hijo_derecha = 2 * i + 2;
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
