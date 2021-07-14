/*	Header Non-Binary Tree dengan Alokasi Dinamis, dengan 3 pointer of node
	Nama: Gilang Liberty (191511013)
	Tanggal: 2 Mei 2020
*/

#ifndef DNBtree_H
#define DNBtree_H

#include "queue.h"




//typedef Tnbtree *infotype2;
//typedef struct tElmtList *address;
//typedef struct tElmtList {
//infotype2 data;
//address next;
//} ElmtList;

bool IsEmpty(Tree tree);
//Mengecek apakah tree kosong atau tidak

void CreateEmptyTree(Tree *tree);
//Membuat Tree kosong

void InsertNode(Tree *tree);
//Menginsertkan node baru pada tree

void DeleteNode(Tree *tree, infotype data);
//Menghapus node yang ada pada tree

Tnbtree* CreateNode(infotype Nama, bool gender, int usia);
//Membuat Node baru

Tnbtree* Search(Tree tree, infotype nama);
//Mencari node pada tree 

int Depth(Tnbtree *root);
//Menghitung Depth tree

void PreOrder(Tnbtree *root);
//Menampilkan urutan node tree secara PreOrder

void InOrder(Tnbtree *root);
//Menampilkan urutan node tree secara InOrder

void PostOrder(Tnbtree *root);
//Menampilkan urutan node tree secara PostOrder

void LevelOrder(Tnbtree *root, int curLevel=0, int nLevel=0);
//Menampilkan urutan node tree secara LevelOrder

int CountLeaf(Tnbtree *root);
//Menghitung Daun yang ada pada tree

int Level(Tree tree, infotype data);
//Mencari level pada suatu node tertentu

int CountElement(Tnbtree *root);
//Menghitung jumlah seluruh node pada tree

void TampilanSilsilah(Tree tree);

void pewarisan(Tree *tree);

bool ValidasiWaris(Tree tree);

void insertStatusAnggota(Tree *tree);

int hitungAnak(Tree tree, infotype parent);
int hitungGenerasi(Tree tree);
void insertwife(Tree *tree);



#endif
