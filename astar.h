/* 
 * File:   astar.h
 * Author: Eldrim
 *
 * Created on 2 octobre 2015, 16:37
 */

#ifndef ASTAR_H
#define	ASTAR_H

#include <math.h>
#include <time.h>
#include "heap.h"
#include "laby.h"

#ifdef	__cplusplus
extern "C" {
#endif

void add_Neighbor (int c, Heap *openList, int *closedList, int *startDist, int *previous, int *priority, int *laby, Constants cst);

int resolve (Heap *openList, int *closedList, int *startDist, int *previous, int *priority, int *laby, Constants cst);

void solution (Constants cst, int *laby, int *previous);

int* init_Array (Constants cst);

void free_Array (int *a);

#ifdef	__cplusplus
}
#endif

#endif	/* ASTAR_H */

