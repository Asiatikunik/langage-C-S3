#include <stdio.h>
#include <stdlib.h>

void f2(int *a, int *b) {
	
	int c;
	c=*a;
	*a=*b;
	*b=c;
	
	
}

void reinitPointeur(int *p) {
	p= NULL;
}

int main() {
	/*
	int a=5; int b=3;
	printf("%d %d \n", a, b);
	f2(&a,&b);
	printf("%d %d \n", a, b);
	*/
	int a=1;
	printf("%d \n", a);
	int *p= &a;
	printf("%d \n", a);
	reinitPointeur(p);
	printf("%d \n", a);
	
return 0;	
	
}
