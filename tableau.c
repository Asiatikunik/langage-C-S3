#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random (int _iMin, int _iMax) { 

	srand (time (NULL)); 
	return (_iMin + (rand () % (_iMax-_iMin+1))); 
} 

void initArray(int taille, int tab[]) {

	int i;

	for(i=0;i<taille;i++){
		tab[i]=1;
	}
}


void afficherArray(int taille, int tab[]) {

	int i;

	for(i=0;i<taille;i++){
		printf("%d ",tab[i] );
	}
	printf("\n");
}


int main() {

	int taille=10;
	int array[taille];
	initArray(taille,array);
	aleaArray(taille, array);
	afficherArray(taille, array);
	

	return 0;
}
