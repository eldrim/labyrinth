/* 
 * File:   structures.h
 * Author: Eldrim
 *
 * Created on 2 octobre 2015, 21:48
 */

#ifndef STRUCTURES_H
#define	STRUCTURES_H

#include <stdlib.h>
#include <stdio.h>

/* 
 * Constants will be grouped in this struct for now,
 * waiting for more control over them during the execution
 */
typedef struct
{
    const int size;
    const int total;
    const int start;
    const int end;
    const float walls;
} Constants;

/*
 * Structure of the heap
 * size is the size of the current heap
 */
typedef struct
{
    int size;
    int *tab;
} Heap;

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STRUCTURES_H */

