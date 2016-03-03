#include <stdio.h>
#include <string.h>



void moveRight(char **maze, int *x, int *y){
    *x += 1;
	maze[*y][*x] = ',';
    printf("RIGHT\n");
}

void moveUp(char **maze, int *x, int *y){
    *y -= 1;
    maze[*y][*x] = ',';
    printf("UP\n");
}

void moveLeft(char **maze, int *x, int *y){
    *x -= 1;
    maze[*y][*x] = ',';
    printf("LEFT\n");
}

void moveDown(char **maze, int *x, int *y){
    *y += 1;
    maze[*y][*x] = ',';
    printf("DOWN\n");
}

int atEnd(int *x, int *y, int mazeSize){
    if((*x == 0) || (*x == (mazeSize - 1)) || (*y == 0) || (*y == (mazeSize - 1))){
        return 0;
    }
	return 1;
}



int move(char **maze, int *x, int *y, int mazeSize){
    while(atEnd(x, y, mazeSize) != 0){
        if((maze[*y][*x + 1] == '@') || (maze[*y][*x + 1] == ',')){
            if((maze[*y - 1][*x] == '@') || (maze[*y - 1][*x] == ',')){
                if((maze[*y][*x - 1] == '@') || (maze[*y][*x - 1] == ',')){
                    if(maze[*y + 1][*x] != '@'){
                        moveDown(maze, x, y);
                        return 0;
                    }
                    else if(maze[*y][*x - 1] != '@'){
                        moveLeft(maze, x, y);
                        return 0;
                    }
                    else if(maze[*y][*x + 1] != '@'){
                        moveRight(maze, x, y);
                        return 0;
                    }
                }
                moveLeft(maze, x, y);
                return 0;
            }
            moveUp(maze, x, y);
            return 0;
        }
        else{
            moveRight(maze, x, y);
            return 0;
        }
    }
}

void startMaze(char **maze, int *x, int *y, int mazeSize){
    if(*x == 0){
        moveRight(maze, x, y);
    }
    if(*x == (mazeSize - 1)){
        moveLeft(maze, x, y);
    }
    if(*y == 0){
        moveDown(maze, x, y);
    }
    if(*y == (mazeSize - 1)){
        moveUp(maze, x, y);
    }
    
}
