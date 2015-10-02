/* 
 * File:   laby.c
 * Author: Eldrim
 *
 * Creation and display of the labyrinth
 * 
 * Created on 2 octobre 2015, 13:52
 */

/*
 * The labyrinth is a simple square one, with a side defined by a constant.
 * It's implemented as a simple array, the (0,0) position at the bottom left angle
 * To access the position of C, X = c%side and Y = c/side
 */

#include "laby.h"

/*
 * Plain method for the creation of the labyrinth
 * start and end are the position of the exits
 * walls is a number between 0 and 1, a high number means more walls
 */
int* build_Labyrinth (Constants cst)
{
    int x, y, c;
    
    /* Allocation for the array and test */
    int *labyrinth = calloc(cst.total,sizeof(int));
    if (!labyrinth)
    {
        return NULL;
    }
    
    /* Filling the array with random generated walls */
    for (x = 0; x < cst.size; x++)
    {
        for (y = 0; y < cst.size; y++)
        {
            c = y * cst.size + x;
            if (rand() / (RAND_MAX+1.0) < cst.walls)
                labyrinth[c] = WALL;
            else
                labyrinth[c] = EMPTY;
        }
    }
    
    /* We ensure the exits aren't on a wall */
    labyrinth[cst.start] = EMPTY;
    labyrinth[cst.end] = EMPTY;

    return labyrinth;
}

/*
 * Free the memory allocated for the labyrinth
 */
void free_Labyrinth (int *laby)
{
    free(laby);
}

/*
 * Function to display the labyrinth
 */
void display_Labyrinth(int *laby, Constants cst)
{
    int x, y, c;

    for (y = cst.size-1; y >= 0; y--)
    {
        for (x = 0; x < cst.size; x++)
        {
            c= y * cst.size + x;
            
            if (c == cst.start)
                printf("S ");
            else if (c == cst.end)
                printf("E ");
            else if (laby[c] == EMPTY)
                printf("  ");
            else if (laby[c] == EXPLORED)
                printf(". ");
            else if (laby[c] == SOLUTION)
                printf("o ");
            else
                printf("# ");
        }
        printf("\n");
    }
    printf("\n");
}




