#include "linked.h"

boolean isEmpty(address p){

	if(p == NULL){
		return 1;
	}else{
		return 0;
	}

}

void Create_Node (address *p){

	*p = (address)malloc(sizeof(ElmtList));
	if(p != Nil){
		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
	}else{
		printf("Gagal Alokasi\n");
	}

}

void Isi_Node (address *p , infotype2 nilai){

	if(isEmpty(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		data(*p) = nilai;
	}

}

void Tampil_List (address p){

	if(isEmpty(p)){
		printf("List Kosong\n");
	}
	else{
		while(!isEmpty(p)){

			printf("%d", p->data);
			p = next(p);
			if(p != Nil){
				printf("->");
			}

		}
		printf("\n");
	}

}

void Ins_Awal (address *p, address PNew){

	next(PNew) = *p;
	*p = PNew;

}

void Ins_Akhir (address *p, address PNew){

	address A;
	if(isEmpty(*p)){
		*p = PNew;
	}else{
		A = *p;
		while(!isEmpty(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}

address Search (address p, infotype2 nilai){

	address A;
	boolean ketemu;

	ketemu = False;
	A = p;
	while(!ketemu && !isEmpty(A)){
		if(data(A) == nilai){
			ketemu = True;
		}else{
			A = next(A);
		}
	}
	return(A);

}

void InsertAfter (address * pBef, address PNew){

	if(*pBef != NULL){
		printf("Searching Berhasil dengan Alamat %i\n",*pBef);
		next(PNew) = next(*pBef);
		next(*pBef) = PNew;
	}else{
		printf("Tidak Ada Data yang Dicari\n");
	}

}

void Del_Awal (address * p, infotype2 * X){

	address A;

	if(isEmpty(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = data(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}

}

void Del_Akhir (address * p, infotype2 * X){

	address A,B;

	A = *p;
	if(isEmpty(*p)){
		printf("List Kosong");
	}else if(next(*p) == NULL){
		*p = NULL;
		free(A);
	}else{
		while(next(next(A)) != NULL){
			A = next(A);
		}
		B = next(A);
		next(A) = NULL;
		*X = data(B);
		free(B);
	}


}

void Del_After (address * pBef, infotype2 * X){

	address A,B;

	if(*pBef == NULL){
		printf("Tidak Ada Data yang Dicari\n");
	}else if(next(*pBef) == NULL){
		printf("Tidak Ada Data Setelah Node\n");
	}else{
		printf("Searching Berhasil\n");
		A = next(*pBef);
		B = next(A);
		next(*pBef) = B;
		next(A) = NULL;
		free(A);
	}

}

void DeAlokasi (address * p){

	*p = NULL;
	free(*p);

}

int NbElmt (address p){

	if(!isEmpty(p)){
		return 1 + NbElmt(next(p));
	}else{
		return 0;
	}

}

address BalikList (address p){

	address NodeAfter = NULL, NodeBefore = NULL;

	while(p != NULL){

		NodeAfter = next(p);
		next(p) = NodeBefore;
		NodeBefore = p;
		p = NodeAfter;

	}

	return NodeBefore;

}

