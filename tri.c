#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int n) { 

	return (rand()%(n+1));
} 

typedef struct tableau{

	int taille;
	int array[100];
	
}TABLEAU;

TABLEAU init_tab(){
	
	TABLEAU t;
	int s;
	
	t.taille=10;
	for(s=0; s<t.taille; s++) {
		t.array[s]=alea(50);
		//t.array[s]=0;
	}
	
	return t;
}

void afficher_tab(TABLEAU t) {

	int s;
	for(s=0;s<t.taille;s++) {
		printf("%d ",t.array[s]);
	}
	printf("\n");
}

void swap(int* a, int* b) {

	int c=*a;
	*a=*b;
	*b=c;
}

TABLEAU tri(TABLEAU t){

	int flag, s;
	
	do{
		flag=0;
		for(s=0;s<t.taille-1; s++) {
			if(t.array[s]>t.array[s+1]) {
				swap(&t.array[s],&t.array[s+1]);
				flag=1;
				//afficher_tab(t);
			}
		}
	}while(flag!=0);
	
	
	return t;
}

TABLEAU tri2(TABLEAU t){

	int flag, i, j, c;
	
	for(i=0;i<t.taille; i++) {
		for(j=0;j<t.taille-1; j++) {
			if(t.array[j]>t.array[j+1]) {
				swap(&t.array[j],&t.array[j+1]);
				flag=0;
			}
		}
	}

	return t;
}

void tri3_selection(TABLEAU* t){ 

	int i;
	for(i=0; i<(*t).taille /* T -> taille */; i++){
		swap(&(t->array[i]),&(t->array[mini(*t,i)]));
		// recherche de la valeur min, qu'on switch avec la valeur i (qui s'incrémente tout seul)
	}
}
	

int mini(TABLEAU t, int i){
		int min = t.array[i];
		int iMin = i;
		int j;
		
		for(j=i+1; j<t.taille; j++){
			if(t.array[j] < min){
				min = t.array[j];
				iMin = j;
			}
		}
		
		return iMin;
	}

int main() {
	

	system("clear");
	TABLEAU t;
	srand (time (NULL)); 
	t=init_tab();
	afficher_tab(t);
	t=tri(t);
	afficher_tab(t);
	
	
	TABLEAU t2;
	srand (time (NULL)); 
	t2=init_tab();
	afficher_tab(t2);
	tri3_selection(&t2);
	afficher_tab(t2);
	
	return 0;
}
