#include <stdio.h>
#include <stdlib.h>

int divi(int val) {
	int i, somme=0;
	
	for( i=1; i<val; i++) {
		if(val%i==0) {
			somme+=i;
		}	
	}
		
	return somme;
}

int part1 () {
		
	int val1, val2, somme1=0, somme2=0;
	printf("Entrer la premières valeur \n");
	scanf("%d", &val1);
	printf("Entrer la deuxième valeur \n");
	scanf("%d", &val2);
	
	somme1=divi(val1);
	somme2=divi(val2);
	
	printf("la somme1 est de %d \n", somme1);
	printf("la somme2 est de %d \n", somme2);
	if(somme1==val2 && somme2==val1){
		printf("%d et %d sont amis \n", val1, val2);
	}else{
		printf("%d et %d sont ennemis \n", val1, val2);
	}
}

int amis(int val1, int val2) {
	
	int somme1=0, somme2=0;
	somme1=divi(val1);
	somme2=divi(val2);
	
	if(somme1==val2 && somme2==val1){
		return 1;
	}else{
		return 0;
	}
	
}

void part2() {
	
	int nmax, i, j;
	printf("Entrer nmax \n");
	scanf("%d",&nmax);
	
	
	for (i=0; i<nmax; i++) {
		for(j=0; j<nmax; j++) {
			if(amis(i,j)==1) 
				printf("%d et %d sont amis\n",i,j);
		}
	}		
}

int main() {
	
	int swi;
	
	printf("Entrer 1 pour comparer deux nb\n");
	printf("Entrer 2 pour trouver le nmax \n");
	scanf("%d",&swi);
	
	switch(swi) {
		case 1:
			part1();
		break;
		case 2:
			part2();
		break;
		default:
			printf("Relancer le programme");
	}	
	
	return 0;

} 
