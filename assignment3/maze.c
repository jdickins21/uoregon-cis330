#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "move.h"

enum Direction { DOWN, RIGHT, UP, LEFT }; //might be useful

//void mazeSolve( char[][MAX_MAZE_SIZE], const int, const int, int, int, int );

int main( int argc, const char* argv[] ){
    
    char **maze, start[] = "x";
    int size, i, j, x = 5, y = 5;
    
    if( argc != 2 ) {
        //checks for the input file name
        printf( "error; no input file name\n" );
        return 1;
    }

    FILE *filePointer;
    filePointer = fopen( argv[1], "r" );

    int numberOfTestCases = 0;
    fscanf( filePointer, "%d\n", &numberOfTestCases );

    for( int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++ ){

        fscanf( filePointer, "%d\n", &size);
        
        //malloc array space
        maze = (char **)malloc(size * sizeof(char *));
        for (i=0; i<size; i++)
            (maze)[i] = (char *)malloc(size * sizeof(char));

        printf( "ENTER\n" );
        // get maze
        for(i = 0; i < size; i++){
            fscanf(filePointer, "%s\n", maze[i]);
        }
        //TRYING to find the x
        for(i = 0; i < size; i++){
            for(j = 0; j < size; ++j){
                if(maze[i][j] == 'x'){
                    y = i;
                    x = j;
                }
            }
        }
        //go through the maze
        startMaze(maze, &x, &y, size);
        while(move(maze, &x, &y, size) == 0){
            move(maze, &x, &y, size);
        }
        
        printf( "EXIT\n***\n" );
        // trying to free, but it says it wasnt allocated
        for (i = 0; i < size; i++){
            free((maze)[i]);
        }
    }

    fclose( filePointer );
    return 0;
}
