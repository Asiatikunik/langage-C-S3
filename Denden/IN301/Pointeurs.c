#include <stdio.h>

void echange(int *a, int *b){
	int c;
	
	c = *a;
	*a = *b;
	*b = c;
	
	printf("a vaut %d et b vaut %d \n", *a,*b);
}

void reinitPointeur(int **p){
	*p = NULL;
	printf("%p \n", p);
}

int main(){
	/* taille mémoire
	int a;
	a = sizeof(char);
	printf("%d \n", a);
	*/
	
	/* echange
	int a,b;
	a=5; b=6;
	
	echange(&a,&b);
	*/
	
	int a = 1;
	int *p = &a; //valeur de p = adresse de a
	printf("%p \n", p); // qiand on essaye de print, c'est l'adresse de a qui s'affiche !
	reinitPointeur(&p);
	printf("travaille sale chintok! \n");
		
	return 0;
}
