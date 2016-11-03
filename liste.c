#include <stdio.h>
#include <stdlib.h>
	
struct element {
	int val;
	struct element *suiv;
};

typedef struct element Element;
typedef int bool;
typedef Element *Liste;


int estVide(Liste l) {
	return l==NULL;
}

void afficher_liste(Liste l) {
	
	if(!estVide(l)) {
		printf("%d ", l->val);
		afficher_liste(l->suiv);
	}
	
	if(estVide(l))
		printf("\n");
}

Liste ajoutD(Liste l, int e) {

	Liste l2;
	l2=malloc(sizeof(Element));
	
	if (l2==NULL) {
		printf("Pas de mémoire");
		exit(EXIT_FAILURE);
	}
	l2->val = e;
	l2->suiv = l;
	return l2;
}

Liste creerListe() {
	return NULL;
}

void libere2(Liste l) {
	Liste l2;
	
	while(!estVide(l)) {
		l2= l->suiv;
		free(l);
		l = l2;
	}
}

void libere(Liste l) {
	if(!estVide(l)) {
		libere2(l->suiv);
		free(l);
	}
}

/*
Liste ajoutF2(Liste l, int e) {
	Liste l2, lfin;
	
	if(estVide(l));
		return ajoutD(l,e);
	lfin=l;
	
	while(!estVide(lfin->suiv))
		lfin=lfin->suiv;
	
	l2=malloc(size(struct element));
	if(l2==NULL) {
	l2->val=e;
	l2->suiv=NULL;
	lfin->suiv=l2
	}
	return l;
}
*/
 
Liste ajoutF(Liste l, int e) {
	
	if(estVide(l))
		return ajoutD(l,e);
	l->suiv=ajoutF(l->suiv,e);
	return l;
	
}

Liste estTrie(Liste l) {
	
	if(estVide(l) || estVide(l->suiv))
		return 1;
		
	if(l->val > l->suiv->val)
		return 0;
		
	return estTrie(l->suiv);
 
}

Liste ajoutT(Liste l, int e) {
	
	if(!estTrie(l)){
		printf("erreur...");
		return;
	}
	
	if(estVide(l) || e< l->val)
		return ajoutD(l,e);
		
	l->suiv=ajoutT(l->suiv,e);
	return l;
}

int main() {

	system("clear");
	int s;
	
	Liste l=creerListe();
	l=ajoutD(l,2);
	l=ajoutD(l,3);
	l=ajoutD(l,1);
	l=ajoutF(l,10);
	afficher_liste(l);
	
	estTrie(l);
	//if (s==1)
		//printf("il est trié \n");
		
	libere(l);
	
	return 0;
}


