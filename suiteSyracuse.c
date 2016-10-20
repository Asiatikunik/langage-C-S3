#include <stdio.h>
#include <stdlib.h>

int suite(int Un) {
	
	if(Un%2==0) {
		return Un/2;
	}else{
		return (3Un+1);
	
}


int main() {

	int s;
	for(s=0; s<20; s++)
		suite(s);


	return 0;
}
