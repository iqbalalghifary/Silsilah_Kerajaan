
#include <malloc.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include <conio.h>
#include "boolean.h"


#define data(P) (P)->data
#define firstSon(P)(P)->firstSon
#define nextBrother(P)(P)->nextBrother
#define parent(P)(P)->parent
#define gender(P)(P)->gender
#define status(P)(P)->status
#define usia(P)(P)->usia

/*Definisi akses component type */
#define data(P)	(P)->data
#define next(p)	(p)->next
#define Nil NULL

typedef char infotype[20];
typedef struct Tnbtree{
	infotype data;
	int usia;
	bool status;
	bool gender;
	Tnbtree *firstSon, *nextBrother, *parent;
} nbtree;

typedef struct{
	Tnbtree *root;
}Tree;



/* Element list* linier */
typedef Tnbtree* infotype2;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
infotype2 data;
address next;
} ElmtList;
