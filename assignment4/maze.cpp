#include <iostream>  // needed
#include <fstream>
#include<string>

#include "maze.hpp"
using namespace std;

    
Maze::Maze(int size){
    int i;
    //size of array
    mSize = size;
    maze = new char*[size];
    for(i = 0; i < size; ++i) {
        //mSize + 1 to account fo "\n"
        maze[i] = new char[(mSize + 1)];
    }
}

Maze::~Maze() {}
    
// Implement the following functions:
    
// read maze from file, find starting location
void Maze::readFromFile(std::ifstream &f){
    int j, k;
    string s;
    
    
    
    for(j = 0; j < mSize; j++){
        // k <= mSize because 1 more columns than rows
        for(k = 0; k <= mSize; k++){
            // put char in array
            f.get(maze[j][k]);
        }
    }
    
    //find the start point
    for(j = 0; j < mSize; j++){
        for(k = 0; k < mSize; k++){
            if(maze[j][k] == 'x'){
            startPoint = maze[j][k];
            xLoc = k;
            yLoc = j;
            }
        }
    }
}


        
          
// make a single step advancing toward the exit
int Maze::step(){
    //if can't go right
    if((maze[yLoc][xLoc + 1] == '@') || (maze[yLoc][xLoc + 1] == ',')){
        //if can't go up
        if((maze[yLoc - 1][xLoc] == '@') || (maze[yLoc - 1][xLoc] == ',')){
            //if can't go left
            if((maze[yLoc][xLoc - 1] == '@') || (maze[yLoc][xLoc - 1] == ',')){
                // if down isn't a wall
                if(maze[yLoc + 1][xLoc] != '@'){
                    //go down
                    yLoc += 1;
                    maze[yLoc][xLoc] = ',';
                    printf("DOWN\n");
                    return 0;
                }
                //if down is a wall and came from left
                else if(maze[yLoc][xLoc - 1] != '@'){
                    //go left
                    xLoc -= 1;
                    maze[yLoc][xLoc] = ',';
                    printf("LEFT\n");
                    return 0;
                }
                //if down is a wall and came from right
                else if(maze[yLoc][xLoc + 1] != '@'){
                    //go right
                    xLoc += 1;
                    maze[yLoc][xLoc] = ',';
                    printf("RIGHT\n");
                    return 0;
                }
            }
            //go left
            xLoc -= 1;
            maze[yLoc][xLoc] = ',';
            printf("LEFT\n");
            return 0;
        }
        //go up
        yLoc -= 1;
        maze[yLoc][xLoc] = ',';
        printf("UP\n");
        return 0;
    }
    //if can go left
    else{
        // go left
        xLoc += 1;
        maze[yLoc][xLoc] = ',';
        printf("RIGHT\n");
        return 0;
    }
    
}
// return true if the maze exit has been reached, false otherwise
bool Maze::atExit(){
    // check xLoc == mSize because there are 1 more columns than rows
    if((yLoc == 0) || (yLoc == (mSize - 1)) || (xLoc == 0) || (xLoc == (mSize))){
        return true;
    }
    
return false;
}
          
// set row and col to current position of 'x'
void Maze::getCurrentPosition(int &row, int &col){
    startPoint = maze[yLoc][xLoc];
}

    



