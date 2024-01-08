/* CS3339 Spring 2022 Assignment 6
 * Original Lee Hinkle
 * Modified by Afton Schwendiman as1425
 * Some references used: https://software.intel.com/en-us/node/529735
 *                       http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
 * Timing code based off work by Dr. Martin Burtscher, Texas State University
 * Copyright 2022 Texas State University and listed authors
 * 
 * Compile with gcc -O3 -Wall MatrixOps.c -o matrixOps -std=c11
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    printf("Project 6 Array Traversal: ");
    int size = 2048;
    printf(" Array size = %ld kB\n",sizeof(size));//FIXME using size, and sizeof(int)
    int *A[size];
    int num_passes = 0;

    for (int r=0; r<size; r++){
        A[r] = (int *)malloc(size * sizeof(int));
        if (A[r] == NULL) {
            printf( "\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
            free(A);
            return 1;
        }
    }

    double runtime; // for time measurement
    struct timeval start, end;  // for time measurement
    //initialize matrix
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            A[r][c] = (int)r*c+1;
        }
    }

    gettimeofday(&start, NULL);  // start timer
    // perform matrix operation - process column first, row iterates on inner loop
    for (int c = 0; c < size; c++){
        for (int r = 0; r < size; r++){
            A[r][c] = 2*A[r][c];
            if (num_passes < 5){
                printf ("Pass %d address of A[%d][%d] is %p\n", num_passes, r, c,&A[r][c]);
                num_passes++;
            }
        }
    }
    gettimeofday(&end, NULL);  //end timer
    //compute and display results
    runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
    printf("column first compute time: %.4f seconds ", runtime);
    printf("mega_elements/sec: %.3f\n", size*size*0.000001 / runtime);

    //re-initialize matrix
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            A[r][c] = (int)r*c+1;
        }
    }
    num_passes = 0; //reset pass counter
    gettimeofday(&start, NULL);  // start timer
    // perform matrix operation - process row first, column iterates on inner loop
    // FIXME this code is still column first - change it to row first
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            A[r][c] = 2*A[r][c];
            if (num_passes < 5){
                printf ("Pass %d address of A[%d][%d] is %p\n", num_passes, r, c,&A[r][c]);
                num_passes++;
            }
        }
    }
    gettimeofday(&end, NULL);  // end timer
    //compute and display results
    runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
    printf("row first compute time: %.4f seconds ", runtime);
    printf("mega_elements/sec: %.3f\n", size*size*0.000001 / runtime);
    free(*A);
    return 0;
}
