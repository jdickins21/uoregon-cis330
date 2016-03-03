#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "square1.h"
#include "square2.h"
#include "diamond.h"

int main(int aegc, const char * argv[]){

	int **square;
	int size;
	
	print10Square();

	printf("Please enter the size of the square [2-10]: ");
	scanf("%i", &size);
	if(2 > size && size < 11){
		printf("Please enter the size of the square [2-10]: ");
		scanf("%i", &size);	
	}
	else{
        	allocateNumberSquare((const int)size, &square);
		initializeNumberSquare((const int)size, &*square);
		printNumberSquare((const int)size, &*square);
                printNumberDiamond((const int)size, &*square);
		deallocateNumberSquare((const int)size, &*square);
	}
}
