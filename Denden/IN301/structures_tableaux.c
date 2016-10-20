#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//structures
	typedef struct tableau{
		int taille;
		int tab[100];
	} TABLEAU;

//fonction alea int
	int alea(int n){
		return (rand()%(n));
	}

// initialisation
	TABLEAU initialise_tableau(){
		TABLEAU T;
		int i;
		
		T.taille = 10;
		
		for(i=0; i<10; i++){
			T.tab[i] = alea(20);
		}
		
		return T;
	}
	
// affichage
	void affiche_tableau(TABLEAU T){
		int i;
	
		printf("Valeurs actuelles dans le tableau T : \n");
		
		for(i=0; i<T.taille; i++){
			printf("%d \n", T.tab[i]);
		}
	}
	
// produit des éléments du tableau
	int produit(TABLEAU T){
		int i,res;
		res = 1;
		
		for(i=0; i<T.taille; i++){
			res *= T.tab[i];
		}
		
		return res;
	}

	// valeur minimale tableau
	int val_min(TABLEAU T){
		int i,min;
		min = T.tab[0];
		
		for(i=1; i<T.taille; i++){
			if(T.tab[i] < min){
				min = T.tab[i];
			}
		}
		
		return min;
	}
	
// décalage de 1 case à droite de tous les éléments du tab

	// 1ere possibilité en renvoyant un tableau
	TABLEAU decale_tab(TABLEAU T){
		/* TABLEAU tmp;
		int i;
		
		// copie dans tmp = tableau temporaire
		tmp = T;
		
		T.taille ++;
		
		// décalage
		for(i=1; i<T.taille; i++){
			T.tab[i] = tmp.tab[i-1];
		}
		
		T.tab[0] = 0;
		
		return T;
		*/
		
		// correction
		int i;
		T.taille ++;
		for(i=T.taille-1; i>0; i--){
			T.tab[i] = T.tab[i-1];
		}
		T.tab[0] = 0;
		return T;
	}
	
	//2e possibilité avec des adresses et des pointeurs
	void decale(TABLEAU *T){
		int i;
		(*T).taille ++; // T -> taille
		for(i=(*T).taille-1; i>0; i--){
			(*T).tab[i] = (*T).tab[i-1];
		}
		(*T).tab[0] = 0;
	}
	
// trie des éléments du tableau
	// tab trié ?
	int siTrie(TABLEAU T){
		int i;
		
		for(i=0; i<T.taille-1; i++){
			if(T.tab[i] > T.tab[i+1]){ return 1; }
		}
		
		return 0;
	}
	
	// permute pour utilisation dans les tris juste apres
	void permute(int *a, int *b){
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	
	// mini pour tri selection
	int mini(TABLEAU T, int i){
		int min = T.tab[i];
		int iMin = i;
		int j;
		
		for(j=i+1; j<T.taille; j++){
			if(T.tab[j] < min){
				min = T.tab[j];
				iMin = j;
			}
		}
		
		return iMin;
	}
	
	// tri tab (correction)
	
		// tri bulle
		TABLEAU tri_bulle(TABLEAU T){
			int i,j; // boucle
			
			for(i=0; i<T.taille; i++){
				for(j=T.taille-1; j>i; j--){
					if(T.tab[j] < T.tab[j-1]){
						permute(&(T.tab[j]),&(T.tab[j-1])); 
						// permute les valeurs de la fin vers le début t.taille fois, jusqu'a ce que le tab soit entierement trié
					}
				}
			}
			
			return T;
		}
		
		// tri avec effet de bord
		void selection(TABLEAU *T){
			int i;
			
			for(i=0; i<(*T).taille /* T -> taille */; i++){
				permute(&(T->tab[i]),&(T->tab[mini(*T,i)]));
				// recherche de la valeur min, qu'on switch avec la valeur i (qui s'incrémente tout seul)
			}
		}
	
	/*
	TABLEAU trie_tableau(TABLEAU T){
		int position = val_min(T);
		int est_trie = siTrie(T);
		int pivot = 0;
		int tmp = 0;
		
		while(est_trie){
			tmp = T.tab[pivot];
			T.tab[pivot] = T.tab[position];
			T.tab[position] = tmp;
			pivot += 1;
			
			affiche_tableau(T);
			est_trie = siTrie(T);
		}
				
		return T;
	}
	*/
	
// main

int main(){
	srand(time(NULL));
	
	/* taille de la structure tableau
	int a;
	a = sizeof(TABLEAU);
	printf("%d \n", a);
	*/
	
	// initialisation - affichage
	TABLEAU T;
	T = initialise_tableau();
	affiche_tableau(T);
	
	// produit
	int res_produit = produit(T);
	printf("Le produit des éléments du tableau T vaut : %d \n", res_produit);
	
	// min
	int min = val_min(T);
	printf("La valeur minimale du tableau T est : %d \n", min);
	
	// décalage vers la droite
	printf("Après décalage : \n");
	T = decale_tab(T);
	affiche_tableau(T);
	
	// trie tableau
	printf("Après trie : \n");
	//T = tri_bulle(T);
	selection(&T);
	affiche_tableau(T);
	
	return 0;
}
