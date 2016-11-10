#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "couleur.h"

int main(){
	init_graphics(400,400);
	POINT BG, HD;
	BG.x = 10; BG.y = 10;
	HD.x = 50; HD.y = 50;
	COULEUR coul;
	coul = bleu;
	
	draw_fill_rectangle(BG, HD, coul);
	draw_line(BG, HD, jaune);
	
	
	wait_escape();
	return 0;
}
