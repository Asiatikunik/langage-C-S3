#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

	double n=0;
	int s;
	double valeur=0;
	scanf("%lf", &n);
	
	
	for(s=1; s<n; s++) {
		printf("%lf \n", 1.0/s*s);
		valeur+=1.0/s*s;
	}
	
	
	printf("%lf \n", valeur);
	
	return 0;
};
