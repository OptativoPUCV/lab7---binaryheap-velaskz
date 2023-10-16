#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"
#include <stdbool.h>

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

void ampliar(Heap* pq){
    int nuevaCapacidad = pq->capac * 2 + 1;
    heapElem* nuevoArray = (heapElem*)realloc(pq->heapArray, nuevaCapacidad * sizeof(heapElem));

    if (nuevoArray != NULL) {
        pq->heapArray = nuevoArray;
        pq->capac = nuevaCapacidad;
    }
}

void heap_push(Heap* pq, void* data, int priority) {
    if (pq->size == pq->capac) {
        ampliar(pq);
    }

    bool entro = false;
    pq->heapArray[pq->size].data = data;
    pq->heapArray[pq->size].priority = priority;
    int anteriorK = pq->size;
    for (int k = pq->size;k > 0 || entro == false;k = (k-1)/2)
    {
        if (pq->heapArray[k].priority < pq->heapArray[anteriorK].priority)
        {
            int aux = pq->heapArray[k].priority;
            pq->heapArray[k].priority = pq->heapArray[anteriorK].priority;
            pq->heapArray[anteriorK].priority = aux;

            void* data = pq->heapArray[k].data;
            pq->heapArray[k].data = pq->heapArray[anteriorK].data;
            pq->heapArray[anteriorK].data = data;
        }
        anteriorK = k;
        if (k == 0) entro = true;
    }
    pq->size++;
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
