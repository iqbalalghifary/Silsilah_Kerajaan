#include "tree.h"

bool IsEmpty(Tree tree){
	return tree.root == NULL;
}

void CreateEmptyTree(Tree *tree){
	(*tree).root = NULL;
}

Tnbtree* CreateNode(infotype Nama, bool gender, int usia){
	Tnbtree *newNode = (Tnbtree*)malloc(sizeof(Tnbtree));
	strcpy(data(newNode), Nama);
	firstSon(newNode) = NULL;
	nextBrother(newNode) = NULL;
	parent(newNode) = NULL;
	gender(newNode) = gender;
	status(newNode) = true;
	usia(newNode)= usia;
	return newNode;
}

void InsertNode(Tree *tree){
	Tnbtree *newNode, *temp;
	infotype data, parent;
	char jenisKelamin;
	bool gender;
	int usia,umur;
	
	

	fflush(stdin);
	printf("Data : ");
	gets(data);
	printf("\nMasukan Usia: ");
	scanf("%d",&usia);
	
	if (!IsEmpty(*tree)){
	
		do{
			fflush(stdin);
			printf("\nJenis Kelamin (L/P): ");
			jenisKelamin = toupper(getche());
		}while(jenisKelamin !='L' && jenisKelamin !='P');
		
		fflush(stdin);
		newNode = CreateNode(data, jenisKelamin == 'L', usia);
			
		do{
			fflush(stdin);
			printf("\nMasukkan Parent dari data : ");
			gets(parent);

		
		}while(Search(*tree,parent) == NULL);
		
		temp = Search(*tree,parent);
		
		if(parent != NULL){
			parent(newNode) = temp;
			if(firstSon(temp) == NULL){
				// sambung ke new node langsung //
				firstSon(temp) = newNode;
			}
			else{
				temp = firstSon(temp);
				while(nextBrother(temp) != NULL){
					temp = nextBrother(temp);
				}
				// insert new node di sini //
				nextBrother(temp) = newNode;
			}
			
		printf("Node dengan nama %s berhasil ditambahkan dengan parent %s",data,parent);	
		}
		else{
			printf("Parent berisi NULL\n");
		}
	}else {	
	newNode = CreateNode(data, true, usia);
	(*tree).root = newNode;
	
	printf("\nNode %s Menjadi Raja Karena Silsilah Kosong dengan usianya %d tahun\n ", data,usia);
	}
}

Tnbtree* Search(Tree tree, infotype nama){
	Tnbtree *node = tree.root;
	while(node != NULL){
		if(strcmp(data(node),nama)== 0){
			return node;
		}
		if(firstSon(node) != NULL){
			node = firstSon(node);
		}
		else{
			if(nextBrother(node) != NULL){
				node = nextBrother(node);
			}
			else{
				while(nextBrother(node) == NULL && node != tree.root){
					node = parent(node);
				}
				node = nextBrother(node);
			}
		}
	}
	return NULL;
}

void DeleteNode(Tree *tree, infotype data){
	Tnbtree *pSearch, *temp, *pDelete;
	pSearch = Search(*tree, data);
	
	if ((*tree).root==NULL){
		printf("\nTree Kosong\n");
	}else 
		if(data(pSearch) == (data((*tree).root)) ){
		(*tree).root = NULL;
		free(pSearch);
		printf("\nNode root telah dihapus, Tree kosong\n");
	}
	
	else{
		
		if(pSearch==NULL){
			printf("\nNode yang dicari tgiidak ada\n");
		}
		
		else
		{
			if(firstSon(pSearch) != NULL){
				temp = pSearch;
				while(firstSon(temp) != NULL){
					temp = firstSon(temp);
				}
				while(temp != pSearch){
					pDelete = temp;
					if(nextBrother(temp) != NULL){
						temp = nextBrother(temp);
						while(firstSon(temp) != NULL){
							temp = firstSon(temp);
						}
					}
					else{
						temp = parent(temp);
					}
					free(pDelete);
				}
			}
			if(firstSon(parent(pSearch)) == pSearch){
				firstSon(parent(pSearch)) = nextBrother(pSearch);
			}
			else{
				temp = firstSon(parent(pSearch));
				while(nextBrother(temp) != pSearch){
					nextBrother(temp);
				}
				nextBrother(temp) = nextBrother(pSearch);
			}
			free(pSearch);
		}
	}
}
