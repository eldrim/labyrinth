/* 
 * File:   astar.c
 * Author: Eldrim
 *
 * Implementation of the A* algorithm
 * 
 * Created on 2 octobre 2015, 16:33
 */

#include "astar.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    Heap *openList;
    int *labyrinth;
    int *closedList;
    int *priority;
    int *previous;
    int *startDist;
    
    
    /* Initialization of the rng */
    srand(time(NULL));
    
    /* Initialisation of the constants and the arrays */
    Constants cst = {40,1600,35,857,0.35};
    
    
    /* Creation of the heap, the labyrinth, and the arrays */
    openList = create_Heap(cst);
    labyrinth = build_Labyrinth (cst);
    closedList = init_Array(cst);
    priority = init_Array(cst);
    previous = init_Array(cst);
    startDist = init_Array(cst);
    
    display_Labyrinth (labyrinth, cst);
    printf("------------------------------------------------------------\n");

    resolve (openList, closedList, startDist, previous, priority, labyrinth, cst);
    display_Labyrinth (labyrinth, cst);
    
    
    
    /* Free the allocated memory */
    free_Heap (openList);
    free_Labyrinth (labyrinth);
    free_Array(closedList);
    free_Array(priority);
    free_Array(previous);
    free_Array(startDist);
            
    return 0;
}

/*
 * Fonction that add the neighbors to the open list if they are not in the closed list
 */
void add_Neighbor (int c, Heap *openList, int *closedList, int *startDist, int *previous, int *priority, int *laby, Constants cst)
{
    /* Variables to get the neighbors */
    int delta[4] = {-1, 1, cst.size, -cst.size};
    int cDelta;
        
    for (int i=0 ; i<4 ; i++)
    {
        cDelta = c+delta[i];
        /* Check if the neighbors are in the labyrinth, not walls, and not in the closed list */
        /* We also need to ensure the x and y aren't different at the same time */
        if (cDelta >= 0 && cDelta < cst.total && laby[cDelta]!=WALL && \
            !(cDelta/cst.size != c/cst.size && cDelta%cst.size != c%cst.size) && !closedList[cDelta])
        {
            /* If it's already in the open list, we have to compare the distance from the start */
            if (in_Heap (cDelta,openList))
            {
                /* If the distance is lower, we change it and the previous node */
                if (startDist[c]+1 < startDist[cDelta])
                {
                    startDist[cDelta]=startDist[c]+1;
                    previous[cDelta]=c;
                }
            }
            /* Else we add it to the open list */
            else
            {
                /* We initialize it's distance from the start and his previous node */
                startDist[cDelta]=startDist[c]+1;
                previous[cDelta]=c;
                /* 
                 * We calculate his priority :
                 * distance_from_start + manhattan distance to the end
                 */
                priority[cDelta] = startDist[cDelta] + abs(c%cst.size - cst.end%cst.size) + abs(c/cst.size - cst.end/cst.size);
                push_Node (openList, priority, cDelta);
            }
        }    
    }
}

/*
 * Find the route between the start and the end
 */
int resolve (Heap *openList, int *closedList, int *startDist, int *previous, int *priority, int *laby, Constants cst)
{
    /* Current position */
    int c;
    
    /* We set the current position to the start and add it to the closed list */
    c=cst.start;
    closedList[c]=1;
    /* We add the neighbors to the open list */
    add_Neighbor (c, openList, closedList, startDist, previous, priority, laby, cst);
    
    /* while we haven't reached the end and the open list isn't empty */
    while(!(c==cst.end) && openList->size != 0)
    {
        /* We pop the best node out of the open list */
        c = pop_Node (openList, priority);
        /* We change 'laby[c]' to EXPLORED */
        laby[c] = EXPLORED;
        /* We put it in the closed list */
        closedList[c]=1;
        /* we add the neighbors to the open list */
        add_Neighbor (c, openList, closedList, startDist, previous, priority, laby, cst);
    }
    
    if (c==cst.end)
    {
        solution (cst, laby, previous);
        return 1;
    }
    else
    {
        printf("\nNo solutions found\n\n");
        return 0;
    }
}

void solution (Constants cst, int *laby, int *previous)
{
    int temp = previous[cst.end];
    
    while (temp != cst.start)
    {
        laby[temp]=SOLUTION;
        temp=previous[temp];
    }
    
}

/*
 * Initialisation of an array
 */
int* init_Array (Constants cst)
{
    int *a =  calloc(cst.total , sizeof(int));
    return a;
}

/*
 * Free the memory allocated to the array
 */
void free_Array (int *a)
{
    free(a);
}