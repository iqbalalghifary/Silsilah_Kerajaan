#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main() {
	Tree tree;
	tree.root = NULL;
	CreateEmptyTree(&tree);
	
	InsertNode(&tree);
}

