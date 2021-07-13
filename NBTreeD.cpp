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



	fflush(stdin);
	printf("Data : ");
	gets(data);

	if (!IsEmpty(*tree)){

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
	newNode = CreateNode(data, true, 50);
	(*tree).root = newNode;

	printf("\nNode %s Menjadi Raja Karena Silsilah Kosong dengan asumsi usianya 50 tahun\n ", data);
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

void PreOrder(Tnbtree *root){
	if(root != NULL){
		printf("%s ", data(root));
		PreOrder(firstSon(root));
		PreOrder(nextBrother(root));
		if(parent(root) == 0) printf("\n");
	}
}

void PostOrder(Tnbtree *root){
	Tnbtree *temp;
	if(root != NULL){
		PostOrder(firstSon(root));
		if(firstSon(root) != NULL){
			temp = firstSon(root);
			while(temp != NULL){
				PostOrder(nextBrother(temp));
				temp = nextBrother(temp);
			}
		}
		printf("%s ", data(root));
		if(parent(root) == NULL) printf("\n");
	}
}

void InOrder(Tnbtree *root){
	Tnbtree *temp;
	if(root != NULL){
		InOrder(firstSon(root));
		printf("%s ", data(root));
		if(root->firstSon != NULL){
			temp = firstSon(root);
			while(temp != NULL){
				InOrder(nextBrother(temp));
				temp = nextBrother(temp);
			}
		}
		if(parent(root) == NULL) printf("\n");
	}
}

int CountElement(Tnbtree *root){
	int sum = 0;
	if(root != NULL){
		sum =sum + CountElement(firstSon(root));
		sum = sum + CountElement(nextBrother(root));
		return sum + 1;
	}
	else{
		return 0;
	}
}

int CountLeaf(Tnbtree *root){
	int sumLeaf = 0;
	if(root != NULL){
		if(firstSon(root) == NULL){
			sumLeaf = 1;
		}
		sumLeaf = sumLeaf + CountLeaf(firstSon(root));
		sumLeaf = sumLeaf + CountLeaf(nextBrother(root));
	}
	return sumLeaf;
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


bool ValidasiWaris(Tree tree){
	Queue queue;
	CreateEmpty(&queue);
	Tnbtree *root;
	root = firstSon((tree).root);

	while(root!= NULL && Level(tree,data(root)) < 3 ){

		if(gender(root) && status(root)==true) return true;	//laki2 dan hidup

		if(firstSon(root) != NULL){
			Enqueue(&queue,firstSon(root));
		}
		if(nextBrother(root) != NULL){
			root = nextBrother(root);
		}else{
			if(IsEmpty(queue)){
				printf("root = NULL\n");
				root = NULL;
				printf("root = NULL\n");
			}else{
				Dequeue(&queue,&root);
			}
		}
	}
	return false;
}

void pewarisan(Tree *tree){

	Queue queue;
	Tnbtree *child;
	Tnbtree *delParent;
	Tnbtree	*calon;
	Tnbtree *cpoint, *temp, *temp2, *rajaSebelumnya;

	CreateEmpty(&queue);
	rajaSebelumnya = (*tree).root;
	child = calon = firstSon((*tree).root);
	printf("child = calon = firstSon root yaitu %s\n\n",data(calon));

	printf("PROSES PERGANTIAN TAHTA\n");




		while((!gender(calon)  && Level(*tree, data(calon))<3 && status(calon)!=true) || 	//perempuan mati
		 		(gender(calon)  && Level(*tree, data(calon))<3 && status(calon)!=true) || 	//laki2 mati
				(!gender(calon)  && Level(*tree, data(calon))<3 && status(calon)==true)){	//perempuan hidup
			printf("(looping)karena JK %s perempuan\n", data(calon));

				if(firstSon(calon) != NULL){
					printf("\n	jika (Fs(%s) != Null\n		Enqueue firstSon calon yaitu %s\n",data(calon), data(firstSon(calon)));
					Enqueue(&queue,firstSon(calon));


				}


				if(nextBrother(calon) != NULL){
					printf("\n	jika nextBrother(%s) != Null\n		calon diisi nbnya yaitu %s \n", data(calon), data(nextBrother(calon)));
					calon = nextBrother(calon);
				}else{
					printf("\n		(Else)jika nextBrother(calon)==null\n");
					if(IsEmpty(queue)){
						printf("\n			Dan jika queue kosong-->break\n");
						break;
					}else{
						printf("\n			jika queue adaan\n				dequeue calon yaitu %s\n",data(calon));
						Dequeue(&queue,&calon);	//berfungsi supaya si anak menggantikan parent dalam queue



					}
			}
		}

		printf("Karena calon yaitu %s laki-laki maka pewarisan berhasil\n\n",data(calon));
		if(usia(calon)<20){
			printf("Penobatan akan dilakukan ketika %s berusia 20 tahun\n\n",data(calon));
			printf("%s akan menggantikan %s sebagai Raja",data(calon),data(rajaSebelumnya));
		}else{
			printf("%s akan menggantikan %s sebagai Raja",data(calon),data(rajaSebelumnya));
		}

		if(calon == child && nextBrother(calon) != NULL && firstSon(calon) == NULL){
			printf("\nKondisi 1-a");
	//		parent(calon) = NULL;
			cpoint = nextBrother(calon);
			firstSon(calon) = cpoint;
			while(nextBrother(cpoint) != NULL){
				cpoint = nextBrother(cpoint);
				parent(cpoint) = calon;
			}
			parent(cpoint) = calon;
			nextBrother(calon) = NULL;
		}else if(calon == child && nextBrother(calon) != NULL && firstSon(calon) != NULL){
			printf("\nKondisi 1-b");
			cpoint = nextBrother(calon);
			temp = firstSon(calon);
			while(nextBrother(temp) != NULL){
				temp = nextBrother(temp);
			}
			nextBrother(temp) = cpoint;
			parent(cpoint) = calon;
			while(nextBrother(cpoint) != NULL){
				cpoint = nextBrother(cpoint);
				parent(cpoint) = calon;
			}
			nextBrother(calon) = NULL;
		}

		if(calon != child && (Level(*tree, data(calon)) == 1) && firstSon(calon) == NULL){
			printf("\nKondisi 2-a");
			cpoint = child;
			parent(cpoint) = calon;
			firstSon(calon) = cpoint;
			while(nextBrother(cpoint) != calon){
				cpoint = nextBrother(cpoint);
				parent(cpoint) = calon;
			}
			nextBrother(cpoint) = NULL;
			if(nextBrother(calon) != NULL){
				nextBrother(cpoint) = nextBrother(calon);
				cpoint = nextBrother(cpoint);
				parent(cpoint) = calon;
				while(nextBrother(cpoint) != NULL){
					cpoint = nextBrother(cpoint);
					parent(cpoint) = calon;
				}
			}
		}else if(calon != child  && (Level(*tree, data(calon)) == 1)&& firstSon(calon) != NULL){
			printf("\nKondisi 2-b");
			cpoint = child;
			parent(cpoint) = calon;
			temp = firstSon(calon);
			while(nextBrother(temp) != NULL){
				temp = nextBrother(temp);
			}
			nextBrother(temp) = cpoint;
			while(nextBrother(cpoint) != calon){
				cpoint = nextBrother(cpoint);
				parent(cpoint) = calon;
			}
			nextBrother(cpoint) = NULL;
			if(nextBrother(calon) != NULL){
				nextBrother(cpoint) = nextBrother(calon);
				cpoint = nextBrother(cpoint);
				parent(cpoint) = calon;
				while(nextBrother(cpoint) != NULL){
					cpoint = nextBrother(cpoint);
					parent(cpoint) = calon;
				}
			}
		}

		if(calon == firstSon(parent(calon)) && Level(*tree, data(calon)) == 2 && firstSon(calon) == NULL && nextBrother(calon) != NULL){
		printf("\n3-a");
		cpoint = nextBrother(calon);
		firstSon(calon) = cpoint;
		while(nextBrother(cpoint) != NULL){
			cpoint = nextBrother(cpoint);
			parent(cpoint) = calon;
		}
		nextBrother(calon) = NULL;
	}else if(calon == firstSon(parent(calon)) && Level(*tree, data(calon)) == 2 && firstSon(calon) != NULL && nextBrother(calon) != NULL){
		printf("\n3-b");
		cpoint = nextBrother(calon);
		temp = firstSon(calon);
		while(nextBrother(temp) != NULL){
			temp = nextBrother(temp);
		}
		nextBrother(temp) = cpoint;
		while(nextBrother(cpoint) != NULL){
			cpoint = nextBrother(cpoint);
			parent(cpoint) = calon;
		}
		nextBrother(calon) = NULL;
	}

			if(parent(calon) == child && nextBrother(child) != NULL ){
			printf("\n4");
			if(firstSon(calon) == NULL){
				printf("\n4-a");
				cpoint = child;
				while(nextBrother(cpoint) != NULL){
					cpoint = nextBrother(cpoint);
					if(firstSon(cpoint) != NULL){
						temp = firstSon(cpoint);
						if(firstSon(calon) == NULL){
							firstSon(calon) = temp;
							parent(temp) = calon;
							while(nextBrother(temp) != NULL){
								temp = nextBrother(temp);
								parent(temp) = calon;
							}
						}else{
							temp2 = firstSon(calon);
							while(nextBrother(temp2) != NULL){
								temp2 = nextBrother(temp2);
							}
							nextBrother(temp2) = temp;
							parent(temp) = calon;
							while(nextBrother(temp) != NULL){
								temp = nextBrother(temp);
								parent(temp) = calon;
							}
						}
					}
				}
			}else{
				printf("\n4-b");
				cpoint = child;
				while(nextBrother(cpoint) != NULL){
					cpoint = nextBrother(cpoint);
					if(firstSon(cpoint) != NULL){
						temp = firstSon(cpoint);
						temp2 = firstSon(calon);
						while(nextBrother(temp2) != NULL){
							temp2 = nextBrother(temp2);
						}
						nextBrother(temp2) = temp;
						parent(temp) = calon;
						while(nextBrother(temp) != NULL){
							temp = nextBrother(temp);
							parent(temp) = calon;
						}
					}
				}
			}
		}
//

//		delParent = parent(calon);
		parent(calon) = NULL;
//		free (delParent);
		(*tree).root= calon;
	}


void insertStatusAnggota(Tree *tree){
	infotype anggota;

	Tnbtree *pSearch;
	if(!IsEmpty(*tree)){
		TampilanSilsilah(*tree);
		fflush(stdin);
		do{
		printf("\n\nPilih anggota yang akan diubah statusnya menjadi meninggal:\n");
		gets(anggota);

		}while (Search(*tree,anggota) == NULL);
		pSearch = Search(*tree,anggota);
//		printf("Node dengan nama % statusnya awalnya yaitu %d\n",data(pSearch), status(pSearch));
		status(pSearch) = false;

		printf("Node dengan nama % berubah statusnya menjadi meninggal\n",data(pSearch));
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

int NbAnakLakiLaki(*Tnbtree tree){
	int jum;
	boolean visit;
	visit = true;
	jum = 0;
	if(firstSon(tr) == NULL)
		return jum;
	else{
		while(parent(tr) != NULL || visit){
			if(firstSon(tr) != NULL && visit){
				tr = firstSon(tr);
				if(gender(tr))
					jum++;
			}else{
				if(nb(tr) != NULL){
					tr = nb(tr);
					if(gender(tr))
						jum++;
					visit = true;
				}else{
					tr = parent(tr);
					visit = false;
				}
			}
		}
	}
	return jum;
}


