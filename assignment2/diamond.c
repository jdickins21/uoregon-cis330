#include <stdio.h>

/* Print a diamond containing the digits 0 - 9 */
void printNumberDiamond(const int size, int **square){
	int i, j, k = 1, l, spaceNum;
	if(size % 2 == 0){ 
		// number of spaces for line on
		spaceNum = (size - 2); 
		
		// make half the diamond
		for (i = 0; i < (size / 2); i++){ 
			
			// print half the spaces for the line it is on
			for(l = 0; l <= (spaceNum / 2); ++l){ 
				printf(" ");		   
                        }
			
			// print ints for line
			for(j = 0; j < k; j++){ 
				printf("%i", square[i][j]);
			}
			k += 2; 			
	
			// print other half of spaces for line
			for(l = 0; l <= (spaceNum / 2); ++l){ 
                                printf(" ");               
                        }
			
			// decriment spaces for next line
			if(spaceNum != 0){
				spaceNum -= 2;
			}
			printf("\n");			
		}
		
		// decriment k for end of loop for first half
		k -= 2;	
		
		// second half of diamond
		for (i = 0; i < (size / 2); i++){  
			
			for(l = 0; l <= (spaceNum / 2); ++l){ 
                                printf(" ");               
                        }
                       
                        for(j = 0; j < k; j++){ // print ints for row
                                printf("%i", square[i][j]);
                        }

			if(k != 1){
				// decriment k for less int on second half
                        	k -= 2; 
			}
			
                        for(l = 0; l <= (spaceNum / 2); ++l){ 
                                printf(" ");               
                        }

			// increase spaces for second half
                        spaceNum += 2;
                        printf("\n");
		}
	}
	
	// if size is odd
	else{

		// do top half minus the middle
                spaceNum = (size - 1);

		 for (i = 0; i < ((size - 1) - 2); i++){ 

                        for(l = 0; l <= (spaceNum / 2); ++l){
                                printf(" ");               
                        }

                        for(j = 0; j < k; j++){ 
                                printf("%d", square[i][j]);
                        }
                        k += 2; 

                        for(l = 0; l <= (spaceNum / 2); ++l){ 
                                printf(" ");               
                        }

                        spaceNum -= 2;
                        printf("\n");
                }

		// bottom half plus middle
		for (i = 0; i < ((size + 1) / 2); i++){ 

                        for(l = 0; l <= (spaceNum / 2); ++l){ 
                                printf(" ");               
                        }

                        for(j = 0; j < k; j++){ 
                                printf("%d", square[i][j]);
                        }
			if(k != 1){
                        	k -= 2; 
			}

                        for(l = 0; l <= (spaceNum / 2); ++l){
                                printf(" ");               
                        }

                        spaceNum += 2;
                        printf("\n");
		}
	}
}
