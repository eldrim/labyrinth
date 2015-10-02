/* 
 * File:   laby.h
 * Author: Eldrim
 *
 * Created on 2 octobre 2015, 18:27
 */

#ifndef LABY_H
#define	LABY_H

#include "structures.h"

#define EMPTY 0
#define WALL 1
#define EXPLORED 2
#define SOLUTION 3

#ifdef	__cplusplus
extern "C" {
#endif

int* build_Labyrinth (Constants cst);

void free_Labyrinth (int *laby);

void display_Labyrinth(int *laby, Constants cst);


#ifdef	__cplusplus
}
#endif

#endif	/* LABY_H */

