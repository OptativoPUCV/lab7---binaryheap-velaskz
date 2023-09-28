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
    heapElem newElem;
    newElem.data = data;
    newElem.priority = priority;

    // Asegurarse de que hay espacio en el montículo
    if (h->size == h->capac) {
        h->capac *= 2;
        h->heapArray = realloc(h->heapArray, h->capac * sizeof(heapElem));
    }

    // Inserción inicial
    int i = h->size;
    h->heapArray[i] = newElem;
    h->size++;

    // Reajuste (Heapify Up)
    while (i != 0 && h->heapArray[parent(i)].priority < h->heapArray[i].priority) {
        swap(&(h->heapArray[i]), &(h->heapArray[parent(i)]));
        i = parent(i);
    }
}


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
