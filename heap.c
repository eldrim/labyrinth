/* 
 * File:   heap.c
 * Author: Eldrim
 *
 * Implementation of a heap to simplify the manipulation of the open list of
 * the A* algorithm
 * 
 * Created on 2 octobre 2015, 14:56
 */

/* 
 * heap[0] is unused.
 */

#include "heap.h"

/*
 * Initialization of the heap
 * 'size' is the side of the square labyrinth
 */
Heap* create_Heap(Constants cst)
{
    Heap *heap = malloc(sizeof(Heap));
    if(!heap)
    {
        return NULL;
    }
    
    heap->tab = calloc(cst.total , sizeof(int));
    if (heap->tab == NULL)
    {
        return NULL;
    }
    
    heap->size = 0;
    return heap;
}  

/*
 * Free the allocated memory
 */
void free_Heap (Heap *heap)
{
    free(heap->tab);
    free(heap);
}

/*
 * Push a value into the heap and sort it
 */
void push_Node (Heap *heap,int *priority, int value)
{
    /* The value is first put at the first free position */
    int heapSize = ++heap->size;
    heap->tab[heapSize]=value;
    /* The heap is then reorganized */
    int index = heapSize/2;
    int tmp;
    
    /* We exchange the nodes based on their priority until we reach the end */
    while(priority[heap->tab[index]] >= priority[heap->tab[heapSize]] && heapSize>1)
    {
        tmp = heap->tab[heapSize];
        heap->tab[heapSize] = heap->tab[index];
        heap->tab[index] = tmp;
        /* To access an upper branch, we just have to divide by 2 */
        index/=2;
        heapSize/=2;
    }
    
}

/*
 * Pop the top value of the heap and sort it
 */
int pop_Node (Heap *heap, int *priority)
{
    if (heap->size == 0)
        return -1;
    
    int tmp;
    int indexUp = 1;
    int indexDn = 2;
    
    /* We start by putting the last value at the first position */
    int value = heap->tab[1];
    heap->tab[1] = heap->tab[heap->size--];
    
    /* Then we exchange the nodes to sort the heap */
    while (indexDn <= heap->size)
    {
        /* We first find the lower of the 2 next branch */
        if (indexDn+1 <= heap->size && priority[heap->tab[indexDn]] > priority[heap->tab[indexDn+1]])
        {
            indexDn++;
        }
        /* If there isn't a lower branch we stop here */
        if (priority[heap->tab[indexDn]] > priority[heap->tab[indexUp]])
        {
            break;
        }
        
        tmp = heap->tab[indexDn];
        heap->tab[indexDn] = heap->tab[indexUp];
        heap->tab[indexUp] = tmp;
        
        /* We can access a lower branch by multiplying by 2 */
        indexUp = indexDn;
        indexDn *= 2;
    }
    
    return value;
}

/*
 * Find if a value 'c' is in the heap
 */
int in_Heap (int c, Heap *heap)
{
    for (int i=1 ; i<=heap->size ; i++ )
    {
        if (heap->tab[i]==c)
            return 1;
    }
    
    return 0;
}

