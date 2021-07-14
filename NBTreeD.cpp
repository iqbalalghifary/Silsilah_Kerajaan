/*	Isi dari prototype Non-Binary Tree dengan Alokasi Dinamis
	Nama`	: Gilang Liberty (191511013)
	Tanggal	: 2 Mei 2020
*/

#include"NBTreeD.h"

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
	wife(newNode) = NULL;
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
	int usia;


	if (IsEmpty(*tree)){
	fflush(stdin);
	printf("Data : \n");
	gets(data);	
	printf("Usia raja pertama minimal 50 tahun\n");
	do{
	printf("Usia : \n");
	scanf("%d", &usia);
    }while(usia <= 49);
    
   	newNode = CreateNode(data, true, usia);
	(*tree).root = newNode;

	printf("\nNode %s Menjadi Raja Karena Silsilah Kosong dengan asumsi usianya %d tahun\n ", data, usia);

	}


	else {
	fflush(stdin);
	printf("Data : \n");
	gets(data);

		do{
			fflush(stdin);
			printf("\nJenis Kelamin (L/P): ");
			jenisKelamin = toupper(getche());
		}while(jenisKelamin !='L' && jenisKelamin !='P');

		fflush(stdin);
		printf("\nMasukan Usia: ");
		scanf("%d",&usia);
		newNode = CreateNode(data, jenisKelamin == 'L', usia);

		do{
			fflush(stdin);
			printf("\nMasukkan Parent dari data : ");
			gets(parent);


		}while(Search(*tree,parent) == NULL);

		temp = Search(*tree,parent);
		
		if(temp->wife != NULL){
		
		
		if((temp->usia - 10 ) > newNode->usia){
			parent(newNode) = temp;
			if(firstSon(temp) == NULL){
				// sambung ke new node langsung //
				firstSon(temp) = newNode;
				printf("Node dengan nama %s berhasil ditambahkan dengan parent %s",data,parent);
			}
			else{
				if (temp->firstSon->usia >= newNode->usia){
				temp = firstSon(temp);
				while(nextBrother(temp) != NULL){
					temp = nextBrother(temp);
				}
				nextBrother(temp) = newNode;
				printf("Node dengan nama %s berhasil ditambahkan dengan parent %s",data,parent);		
			}

				else{
					printf("Data tidak logis");
					free(newNode);
				}
				
				// insert new node di sini //
				
			}


		}
		else{
			printf("Data tidak logis\n");
			free(newNode);
		}
	}
	
else {
	printf("Raja ini masih jomblo, gimana caranya punya anak?:(");
}
}

}

void insertwife(Tree *tree){
	Tnbtree *newNode, *temp;
	infotype data, suami;
	char jenisKelamin;
	bool gender;
	int usia;

	if (!IsEmpty(*tree)){
	fflush(stdin);
	printf("Data : \n");
	gets(data);
	printf("Usia : \n");
	scanf("%d", &usia);
	jenisKelamin = 'L';
	newNode = CreateNode(data, jenisKelamin == 'P', usia);

	do{
	printf("Seorang raja hanya boleh mempunyai 1 istri\n");
	printf("Istri dari : ");
	gets(suami);
	}while(Search(*tree,suami) == NULL);

	temp = Search(*tree,suami);

	if (gender(temp) == false){
		printf("Kerajaan ini menolak keras lesbian:)");
		free(newNode);
	}
	if (wife(temp) != NULL){
		printf("Raja/calon raja tersebut sudah mempunyai istri, mohon jangan jadi orang ketiga");
		free(newNode);
	}
	else{
		wife(temp) = newNode;
	}
}
}

void insertsuami(Tree *tree){
	Tnbtree *newNode, *temp, *pCur;
	infotype data, istri;
	char jenisKelamin;
	bool gender;
	int usia;

	if (!IsEmpty(*tree)){
	fflush(stdin);
	printf("Data : \n");
	gets(data);
	printf("Usia : \n");
	scanf("%d", &usia);
	jenisKelamin = 'P';
	newNode = CreateNode(data, jenisKelamin == 'P', usia);

	do{
	printf("Seorang raja hanya boleh mempunyai 1 suami\n");
	printf("Suami dari : ");
	gets(istri);
	}while(Search(*tree,istri) == NULL);

	temp = Search(*tree,istri);

	if (gender(temp) == true){
		printf("Kerajaan ini menolak keras homo:)");
		free(newNode);
	}
	if (parent(temp) == NULL){
		printf("Raja/calon raja tersebut sudah mempunyai suami, mohon jangan jadi orang ketiga");
		free(newNode);
	}
	else{
		if (temp = temp->parent->firstSon){
			temp->parent->firstSon = newNode;
			newNode->nextBrother = temp->nextBrother;
		}
		if (temp != temp->parent->firstSon){
			pCur = temp->parent->firstSon;
			while (pCur->nextBrother != temp){
				pCur=pCur->nextBrother;
			}
				pCur->nextBrother = newNode;
				newNode->parent = temp->parent;
				newNode->nextBrother = temp->nextBrother;
		}
	}
}	
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



int Depth(Tnbtree *root){
	int maxLevel = -1;
	if(root != NULL){
		if(maxLevel <= Depth(firstSon(root)))maxLevel = Depth(firstSon(root));
		maxLevel = maxLevel + 1;
		if(maxLevel <= Depth(nextBrother(root)))maxLevel = Depth(nextBrother(root));
	}
	return maxLevel;
}

int Level(Tree tree, infotype data){
	int level;
	Tnbtree *pSearch = Search(tree, data);
	if(pSearch != NULL){
		level = 0;
		while(pSearch != tree.root){
			level = level + 1;
			pSearch = parent(pSearch);
		}
		return level;
	}
	return -1; // data pada tree kosong
}

void LevelOrder(Tnbtree *root, int curLevel, int nLevel){
	if(root != NULL){
		if(curLevel == nLevel){
			printf("%s(%d)(%d)(%d)	", data(root),status(root),gender(root),usia(root));
		}
		else{

			LevelOrder(firstSon(root), curLevel + 1, nLevel);
		}

		LevelOrder(nextBrother(root), curLevel, nLevel);

		if(parent(root) == NULL && nLevel <= Depth(root)){
			printf("\n");
			LevelOrder(root, curLevel, nLevel+1);

		}
		if(nLevel == 0){
			printf("\n");
		}
	}
}

void TampilanSilsilah(Tree tree){
	if(!IsEmpty(tree)){
	LevelOrder((tree).root);
	}else{
		printf("\nSilsilah kosong\n");
	}
}



int hitungAnak(Tree tree, infotype parent){
 Tnbtree *temp;

 int jumlah = 0;


 if(!IsEmpty(tree)){
	  temp = Search(tree, parent);
  	if (firstSon(temp) != NULL){
   		jumlah =jumlah +1;
   		temp = firstSon(temp);
  		}else{
   			return 0;
  		}
  		while (nextBrother(temp) != NULL){
   			temp = nextBrother(temp);
   			jumlah =jumlah +1;
  		}
  	return jumlah;

 }
  return 0;
}


int hitungGenerasi(Tree tree){
	if(IsEmpty(tree)){
		printf("\nGenerasi Kosong");
		}else{
		Depth((tree).root);
	}
}






