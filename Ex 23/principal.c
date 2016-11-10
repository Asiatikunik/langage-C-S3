#include <stdio.h>
#include <stdlib.h>
#include "surface.h"
#include "circonference.h"
#include "pi.h"

int main() {
	double rayon=2;
	printf("%f %f \n",circonference(rayon), surface(rayon));
	
	return 0;
}
