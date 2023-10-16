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



void heap_push(Heap* pq, void* data, int priority) {

}




void heap_pop(Heap* pq) {
    if (pq->size == 0) {
        return;
    }

    pq->heapArray[0] = pq->heapArray[pq->size - 1];
    pq->size--;

    int i = 0;

    while (1) {
        int hijoIzquierda = 2 * i + 1;
        int hijoDerecha = 2 * i + 2;
        int masLargo = i;

        // Encontrar el hijo con la mayor prioridad
        if (hijoIzquierda < pq->size && pq->heapArray[hijoIzquierda].priority > pq->heapArray[masLargo].priority) {
            masLargo = hijoIzquierda;
        }
        if (hijoDerecha < pq->size && pq->heapArray[hijoDerecha].priority > pq->heapArray[masLargo].priority) {
            masLargo = hijoDerecha;
        }

        if (masLargo == i) {
            break;
        }

        // Intercambiar elementos si es necesario
        heapElem temp = pq->heapArray[i];
        pq->heapArray[i] = pq->heapArray[masLargo];
        pq->heapArray[masLargo] = temp;

        i = masLargo;
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
