#include <stdio.h>

double power(double a, double b){
	
	double i, answer;	
	answer = a;

	for(i = 0; i < b; i++){
		answer = answer * a;
	}
	
	printf("%f", answer); 
	
	return answer;
}
