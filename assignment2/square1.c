#include <stdio.h>

void print10Square(){
	
	int x;
	
	int squ[10][10] = { 
		{0,0,0,0,0,0,0,0,0,0} ,
		{1,1,1,1,1,1,1,1,1,1} ,
		{2,2,2,2,2,2,2,2,2,2} ,
		{3,3,3,3,3,3,3,3,3,3} ,
		{4,4,4,4,4,4,4,4,4,4} ,
		{5,5,5,5,5,5,5,5,5,5} ,
		{6,6,6,6,6,6,6,6,6,6} ,
		{7,7,7,7,7,7,7,7,7,7} ,
		{8,8,8,8,8,8,8,8,8,8} ,
		{9,9,9,9,9,9,9,9,9,9} ,
	};

	for (x = 0; x < 10; ++x){
		printf("%i %i %i %i %i %i %i %i %i %i\n",squ[x][0], squ[x][1], squ[x][2], squ[x][3], squ[x][4], squ[x][5], squ[x][6], squ[x][7], squ[x][8], squ[x][9]);
	}
}