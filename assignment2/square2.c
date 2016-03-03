#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allocate a square of size "size" (a 2-D array of ints) */
void allocateNumberSquare(const int size, int ***square){	
	int i;

	*square = (int **)malloc(size * sizeof(int *));
	for (i=0; i<size; i++)
		(*square)[i] = (int *)malloc(size * sizeof(int));
}

/* Initialize the 2-D square array */
void initializeNumberSquare(const int size, int **square){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){	
			square[j][i] = i;
		}
	}
}

/* Print a formatted square */
void printNumberSquare(const int size, int **square){
	int y,  z;
	for(y = 0; y < size; ++y){
		for(z = 0; z < size; ++z){
			printf("%i ", square[y][z]);
		}
		printf("\n");
	}
}

/* Free the memory for the 2-D square array */
void deallocateNumberSquare(const int size, int **square){

	int i;

	for (i = 0; i < size; ++i){ 
		free((square)[i]);
	}
}
