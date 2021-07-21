/*	Header Non-Binary Tree dengan Alokasi Dinamis, dengan 3 pointer of node
	Nama: Gilang Liberty (191511013)
	Tanggal: 2 Mei 2020
*/

#ifndef DNBtree_H
#define DNBtree_H

#include "header.h"


#define WIDTH 800
#define HEIGHT 700
#define GOLD 6
#define WHITE 7

#define MAX_LEN 26

void gotoxy(int, int);
//void textcolor(int);
//void areaWindow(int width, int height);
//void setWindowCenterPos(int X_delta=0, int y_delta=0);
//void transition(Tree root);
void loading_screen();
void introduction();
void transition();
void raja() ;
void kingdom();
void langit();
void gedungnikah();

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

void LevelOrder(Tnbtree *root, int curLevel=0, int nLevel=0);
//Menampilkan urutan node tree secara LevelOrder


int Level(Tree tree, infotype data);
//Mencari level pada suatu node tertentu



void TampilanSilsilah(Tree tree);


int hitungAnak(Tree tree, infotype parent);
int hitungGenerasi(Tree tree);
void insertwife(Tree *tree);
void insertsuami(Tree *tree);
void transition1();

#endif
