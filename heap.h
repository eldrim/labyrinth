/* 
 * File:   heap.h
 * Author: Eldrim
 *
 * Created on 2 octobre 2015, 15:18
 */

#ifndef HEAP_H
#define	HEAP_H

#include "structures.h"

#ifdef	__cplusplus
extern "C" {
#endif

Heap* create_Heap(Constants cst);

void free_Heap (Heap *heap);

void push_Node (Heap *heap,int *priority, int value);

int pop_Node (Heap *heap, int *priority);

int in_Heap (int c, Heap *heap);

#ifdef	__cplusplus
}
#endif

#endif	/* HEAP_H */

