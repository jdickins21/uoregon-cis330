#ifndef _move_h
#define _move_h

void moveRight(char **maze, int *x, int *y);

void moveUp(char **maze, int *x, int *y);

void moveLeft(char **maze, int *x, int *y);

void moveDown(char **maze, int *x, int *y);

int atEnd(int *x, int *y, int mazeSize);

int move(char **maze, int *x, int *y, int mazeSize);

void startMaze(char **maze, int *x, int *y, int mazeSize);
#endif
