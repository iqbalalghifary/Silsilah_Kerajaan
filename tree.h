#ifndef tree_H
#define tree_h
#include "header.h"



bool IsEmpty(Tree tree);
//Mengecek apakah tree kosong atau tidak

void CreateEmptyTree(Tree *tree);
//Membuat Tree kosong

void InsertNode(Tree *tree);
//Menginsertkan node baru pada tree

Tnbtree* Search(Tree tree, infotype nama);
//Mencari node pada tree 

void DeleteNode(Tree *tree, infotype data);

#endif
