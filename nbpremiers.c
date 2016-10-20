#include <stdlib.h>
#include <stdio.h>

int main() {
	
	int valeur=0, flag=0, i;
	scanf("%d", &valeur);
	
	for(i=1;i<9;i++) {
		if( i==valeur && valeur%i == 0){
			flag=1;
		}
	}
	
	if(flag==1) {
		printf("%d est premier \n",valeur);
	}else{
		printf("%d n'est pas premier \n",valeur);
	}
	
}
