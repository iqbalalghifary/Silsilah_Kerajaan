#include <stdio.h>
#include <stdlib.h>

#include "Header/tree.h"

int main() {
	nbtree *rajaPertama;
	nb_Create(rajaPertama);
	
	setWindowCenterPos(0, -50);
	

	
	areaWindow(900, 540);
	//loading_screen();
	//introduction();
	transition(rajaPertama);
	
	setWindowCenterPos(0, -100);
	areaWindow(WIDTH, HEIGHT);
	raja();
	narasiRajaPertama(rajaPertama);
	kingdom();
	
	menu(rajaPertama);
}

