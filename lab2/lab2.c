
#define ROW 3
#define COL 4

#include <stdbool.h>
#include <stdio.h>

bool arrayEqual(int a[ROW][COL], int b[ROW][COL], int m, int n){
	
	int x, y;
	
	for (x = 0; x < ROW; ++x){
		for (y = 0; y < COL; ++y){
			if (a[x][y] != b[x][y]){
				printf("not a match");
				return false;
			}
		}
	}
	
	printf("match");
	return true;
}

int main(int argc, const char * argv[]){
	
	int a[ROW][COL] = {
		{0, 1, 2, 3} ,
		{4, 5, 6, 7} ,
		{8, 9, 10, 11} ,
	};

	int b[ROW][COL] = {
                {0, 1, 2, 3} ,
                {4, 5, 6, 7} ,
                {8, 9, 10, 11} ,
        };

	arrayEqual(a, b, ROW, COL);

	return 0;
}
