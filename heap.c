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
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* nuevoHeap = (Heap*)malloc(sizeof(Heap*));
    if (nuevoHeap == NULL){
      return NULL; 
    } 

    nuevoHeap->heapArray = (heapElem*)malloc(3 * sizeof(heapElem*));
    
   if (nuevoHeap->heapArray == NULL) {
        free(nuevoHeap);
        return NULL; 
    }
    nuevoHeap->capac = 3;
    nuevoHeap->size = 0;
    return nuevoHeap;
}
