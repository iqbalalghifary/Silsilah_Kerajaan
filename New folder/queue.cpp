#include"queue.h"

void CreateEmpty(Queue *Q){
	
	*Q = NULL;
	
}

boolean IsEmpty(Queue Q){
	
	return(isEmpty(Q));
	
}

void Enqueue(Queue *Q,infotype2 X){
	
	address a = NULL;
	
	Create_Node(&a);
	Isi_Node(&a, X);
	Ins_Akhir(&(*Q),a);
	
}

void Dequeue(Queue *Q,infotype2 *X){
	
	Del_Awal(&(*Q),&(*X));
	
}

int SearchList(Queue Q,infotype2 x){
	
	int count = 1;

	while(!IsEmpty(Q)){
		
		if(data(Q) == x){
			
			return count;
			
		}else{
			
			Q = next(Q);
			count++;
		}
		
	}
	
	return 0;
	
}
