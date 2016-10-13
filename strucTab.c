#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


typedef struct tableau{
	int taille;
	int tab[100];

} TABLEAU;

int alea(int n) {

	return (rand()%(n+1));
}

TABLEAU initTab() {
	
	TABLEAU t;
	int s;
	
	t.taille=10;
	for(s=0; s<t.taille; s++) {
		t.tab[s]=alea(20);
		//t.tab[s]=0;
	}
	
	return t;
}

void afficherTab(TABLEAU t) {

	int s;
	for(s=0; s<t.taille; s++) {
		printf("%d ",t.tab[s]);
	}
	printf("\n");
	
}

int somme(TABLEAU t) {
	
	int result=0, s=0;
	
	for(s=0; s<t.taille; s++) {
		result+=t.tab[s];
	}
	
	return result;
}

int minimum(TABLEAU t) {
	
	int min=t.tab[0];
	int s;
	
	for(s=0; s<t.taille-1; s++) {
		printf("%d %d \n", t.tab[s], t.tab[s+1]);
		if(t.tab[s]<=min){
			min=t.tab[s];
			printf("est plus petit %d \n", t.tab[s+1]);
		}	
	}
	
	return min;
}

int main() {
	
	system("clear");
	TABLEAU t;
	srand(time(NULL));
	//printf("%d \n", sizeof(TABLEAU)); //la taille est de 404
	int result;int mini;
	
	
	t=initTab();
	afficherTab(t);
	result=somme(t);
	printf("somme du tab: %d \n", result);
	mini=minimum(t);
	printf("le minimum est: %d \n", mini);
	
	
	
	return 0;
}
