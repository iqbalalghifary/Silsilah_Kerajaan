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
	status(newNode) = false;
	usia(newNode)= usia;
	return newNode;
}

void InsertNode(Tree *tree){
	Tnbtree *newNode, *temp;
	infotype data, parent;
	char jenisKelamin;
	bool gender;
	int usia;
	int i;
    int X = 41;
    DWORD sleepTime = 50;


	if (IsEmpty(*tree)){
	fflush(stdin);
	gotoxy(36, 8); printf("Data : \n");
	gotoxy(43, 8); gets(data);
	gotoxy(36, 10); printf("Usia raja pertama minimal 50 tahun\n");
	do{
    gotoxy(36, 11); printf("Usia : \n");
	gotoxy(43, 11); scanf("%d", &usia);
	fflush(stdin);
    }while(usia <= 49);

   	newNode = CreateNode(data, true, usia);
	(*tree).root = newNode;
    system("cls");
    raja() ;
    gotoxy(36, 8);

                const char greeting[] =  "Hello..";
                const char sentence1[] = "Perkenalkan nama saya %s";
                const char sentence2[] = "Saya adalah seorang pemuda yang baru saja diangkat";
                const char sentence3[] = "sebagai raja, salam kenal semua nya!";
                const char sentence7[] = "                                  ";
                const char sentence4[] = "sebagai ucapan terima kasih,";
                const char sentence5[] = "Anggap saja ini rumah sendiri";
                const char sentence6[] = "Dan silahkan berbuat sesuka hati anda";

                gotoxy(X, 6);
                for (i = 0; greeting[i]!=0 ; i++) {
                    Sleep(sleepTime);
                    printf("%c", greeting[i]);
                }
                Sleep(500);

                gotoxy(X, 7);

                    Sleep(sleepTime);
                    printf("Perkenalkan nama saya %s", data);

                printf(".");

                gotoxy(X, 8);
                for (i = 0; sentence2[i]!=0 ; i++) {
                    Sleep(sleepTime);
                    printf("%c", sentence2[i]);
                }

                printf(" ");
                gotoxy(X, 9);
                for (i = 0; sentence3[i]!=0 ; i++) {
                    Sleep(sleepTime);
                    printf("%c", sentence3[i]);
                }
                printf(" ");

                gotoxy(X, 10);
                for (i = 0; sentence4[i]!=0 ; i++) {
                    Sleep(sleepTime);
                    printf("%c", sentence4[i]);
                }

                gotoxy(X, 11);
                for (i = 0; sentence5[i]!=0 ; i++) {
                    Sleep(sleepTime);
                    printf("%c", sentence5[i]);
                }

                gotoxy(X, 12);
                for (i = 0; sentence6[i]!=0 ; i++) {
                    Sleep(sleepTime);
                    printf("%c", sentence6[i]);
                }
                gotoxy(X, 15);
                system("pause");
                system("cls");

            }

	else {
	fflush(stdin);
	gotoxy(36, 8);
	printf("Data : ");
	gets(data);

		do{
            gotoxy(36, 9);
			fflush(stdin);

			printf("Jenis Kelamin (L/P): ");
			jenisKelamin = toupper(getche());
		}while(jenisKelamin !='L' && jenisKelamin !='P');

		fflush(stdin);
		gotoxy(36, 10);
		printf("Masukan Usia: ");
		scanf("%d",&usia);
		fflush(stdin);
		newNode = CreateNode(data, jenisKelamin == 'L', usia);

		do{
			fflush(stdin);
			gotoxy(36, 11);
			printf("Masukkan Parent dari data : ");
			gets(parent);


		}while(Search(*tree,parent) == NULL);

		temp = Search(*tree,parent);

		if(temp->wife != NULL){


		if((temp->usia - 10 ) > newNode->usia){
			parent(newNode) = temp;
			if(firstSon(temp) == NULL){
				// sambung ke new node langsung //
				firstSon(temp) = newNode;
				gotoxy(36, 13);
				printf("Node dengan nama %s berhasil ditambahkan dengan parent %s",data,parent);
				gotoxy(36, 16);
				system("pause");
				system("cls");
			}
			else{
				if (temp->firstSon->usia >= newNode->usia){
				temp = firstSon(temp);
				while(nextBrother(temp) != NULL){
					temp = nextBrother(temp);
				}
				nextBrother(temp) = newNode;
				gotoxy(36, 12);
				printf("Node dengan nama %s berhasil ditambahkan dengan parent %s",data,parent);
				gotoxy(36, 16);
				system("pause");
			}

				else{
                    gotoxy(36, 13);
					printf("Data tidak logis");
					free(newNode);
				}
			}
		}
		else{
            gotoxy(36, 14);
			printf("Data tidak logis\n");
			free(newNode);
		}
	}

        else {
            gotoxy(36, 15);
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
	gotoxy(36, 8);
	printf("Data : \n");
	gotoxy(43, 8);
	gets(data);
	gotoxy(36, 9);
    sini:	printf("Usia : \n");
        gotoxy(43, 9);
        scanf("%d", &usia);
        jenisKelamin = 'L';
        newNode = CreateNode(data, jenisKelamin == 'P', usia);

        do{
        gotoxy(36, 10);
        printf("Seorang raja hanya boleh mempunyai 1 istri\n");
        gotoxy(36, 11);
        printf("Istri dari : ");
        gotoxy(48, 11);
        gets(suami);
        }while(Search(*tree,suami) == NULL);

        temp = Search(*tree,suami);
        if(usia(temp) != usia(newNode)){
        gotoxy(36, 12);
            printf("Usia antar pasangan haruslah sama\n");

            goto sini;
        }
        else{
        if (gender(temp) == false){
            gotoxy(36, 13);
            printf("Kerajaan ini menolak keras lesbian:)");
            free(newNode);
        }
        if (wife(temp) != NULL){
            gotoxy(36, 13);
            printf("Raja/calon raja tersebut sudah mempunyai istri, mohon jangan jadi orang ketiga");
            free(newNode);
        }
        else{
            wife(temp) = newNode;
            status(temp) = true;
            gotoxy(28, 13);
            printf("Selamat atas pernikahan %s dan %s, semoga sakinah mawadah warohmah\n\n\n", data(temp), data(newNode));
            gotoxy(31, 16);
            system("pause");
            system("cls");
            gedungnikah();
            }
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
	gotoxy(36, 8);
	printf("Data : ");
	gotoxy(43, 8);
	gets(data);
	gotoxy(36, 9);
oy:	printf("Usia : ");
    gotoxy(43, 9);
	scanf("%d", &usia);
	jenisKelamin = 'P';
	newNode = CreateNode(data, jenisKelamin == 'P', usia);

	do{
    gotoxy(36, 10);
	printf("Seorang raja hanya boleh mempunyai 1 suami\n");
	gotoxy(36, 11);
	printf("Suami dari : ");
	gets(istri);
	}while(Search(*tree,istri) == NULL);

	temp = Search(*tree,istri);
	if(usia(temp) != usia(newNode)){
        gotoxy(36, 14);
		printf("Usia pasangan harulah sama");
		system("cls");
		goto oy;
	}
	else{
	if (gender(temp) == true){
	    gotoxy(36, 15);
		printf("Kerajaan ini menolak keras homo:)");
		system("cls");
		free(newNode);
	}
	if (parent(temp) == NULL){
	    gotoxy(36, 16);
		printf("Raja/calon raja tersebut sudah mempunyai suami, mohon jangan jadi orang ketiga");
		free(newNode);
	}
	else if(parent(temp) != NULL){
		if (temp == temp->parent->firstSon){
			temp->parent->firstSon = newNode;
			newNode->parent = temp->parent;
			newNode->nextBrother = temp->nextBrother;
			temp->parent = NULL;
            gotoxy(36, 14);
            newNode->status = true;
			printf("Selamat atas pernikahan %s dan %s, semoga sakinah mawadah warohmah", data(temp), data(newNode));
			system("cls");
		}
		else{
			pCur = temp->parent->firstSon;
			while (pCur->nextBrother != temp){
				pCur=pCur->nextBrother;
			}
				pCur->nextBrother = newNode;
				newNode->parent = temp->parent;
				newNode->nextBrother = temp->nextBrother;
				temp->parent = NULL;
				gotoxy(36, 18);
				newNode->status = true;
			printf("Selamat atas pernikahan %s dan %s, semoga sakinah mawadah warohmah", data(temp), data(newNode));
			system("cls");
			gedungnikah();
		}
	}
}
}
}

void DeleteNode(Tree *tree, infotype data){
	Tnbtree *pSearch, *temp, *pDelete, *raja;
	pSearch = Search(*tree, data);
	raja = tree->root;

	if (pSearch == raja){
		if (raja->firstSon == NULL){
            gotoxy(36, 9);
			printf("Raja %s telah mati, kerajaan bubar", tree->root->data);
			tree->root = NULL;
			free(pSearch);
		}
		else{
			temp = raja->firstSon;
			if (temp->nextBrother == NULL){
					if(temp->gender == true){
					tree->root = temp;
					gotoxy(36, 8);
					printf ("Selamat %s diangkat sebagai raja baru", tree->root->data);
					free(pSearch);
				}
				else{
					tree->root = NULL;
					gotoxy(36, 9);
					printf("Tidak ada calon raja yang cocok, kerajaan hancur ketika perang");
					free(pSearch);
				}
			}
			else{
					if(temp->gender == true){
					tree->root = temp;
					temp->nextBrother = NULL;
					gotoxy(36, 9);
					printf ("Selamat %s diangkat sebagai raja baru", tree->root->data);
					free(pSearch);
				}
				else{
					while((temp->gender == false) || (temp->nextBrother != NULL)){
						temp = temp->nextBrother;
						if(temp->gender == true){
						tree->root = temp;
						temp->nextBrother = NULL;
						gotoxy(36, 9);
						printf ("Selamat %s diangkat sebagai raja baru", tree->root->data);
						free(pSearch);

				}
				else{
					tree->root = NULL;
					gotoxy(36, 9);
					printf("Tidak ada calon raja yang cocok, kerajaan hancur ketika perang");
			}
					}
			}
			}
		}
		}
		else{
			if(pSearch = raja->firstSon){
				if(pSearch->nextBrother == NULL){
					raja->firstSon = NULL;
					free(pSearch);
				}
				else{
					temp = pSearch->nextBrother;
					raja->firstSon = temp;
					free(pSearch);
				}
			}
			else{
					if(pSearch->nextBrother == NULL){
					raja = raja->firstSon;
					while(raja->nextBrother != pSearch){
						raja = raja->nextBrother;
					}
						raja->nextBrother = NULL;
						pSearch->parent = NULL;
						free(pSearch);
					}
					else{
						pSearch->parent->firstSon = temp;
						while(temp->nextBrother != pSearch){
						temp = temp->nextBrother;
					}
						temp->nextBrother = pSearch->nextBrother;
						pSearch->parent = NULL;
						pSearch->nextBrother = NULL;
						free(pSearch);
					}
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
    fflush(stdin);
	if(!IsEmpty(tree)){
	LevelOrder((tree).root);
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
        gotoxy(36, 11);
		printf("Generasi Kosong");
		}else{
		Depth((tree).root);
	}
}



//void textcolor(int color) {
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
//
void gotoxy(int X, int y) {
	COORD coord;
	coord.X = X;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void loading_screen() {
	int i;
	gotoxy(40, 10);
	printf("Loading...");
	gotoxy(40, 12);
	for (i = 0; i <= 17; i++) {
		Sleep(90);
		printf("%c", 177);
	}
	printf("\n\n");
	//system("pause");
	system("cls");
}

void introduction() {
	const char sentence[] = "Ikbal Alghifary X M. Rafli Nur Ikhsan";
	int i;
	const char sentence3[] = "Selamat datang di Polban Empire      ";

	gotoxy(40, 10);
	for (i = 0; sentence[i]!=0 ; i++) {
		Sleep(100);
		printf("%c", sentence[i]);
	}
	//system("cls");
	Sleep(100);

	gotoxy(40, 10);
	for (i = 0; sentence3[i]!=0 ; i++) {
		Sleep(100);
		printf(" ");
	}

	const char sentence2[] = "Selamat datang di Polban Empire ^_^";
	gotoxy(43, 10);
	for (i = 0; sentence2[i]!=0 ; i++) {
		Sleep(100);
		printf("%c", sentence2[i]);
	}
	Sleep(2000);

	gotoxy(43, 10);
	for (i = 0; sentence2[i]!=0 ; i++) {
		Sleep(100);
		printf(" ");
	}
    kingdom();
	system("cls");
}

void transition(){
	// sc: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	system("cls");
    int i, j;
    int x, y;

    for (x = 0; x < 115; x++) {
	    for (y = 0; y < 3; y++) {
	    	i = rand() % 30;
	    	j = rand() % 2;

			gotoxy(j+x, i);
			printf(".");

			Sleep(1);

		}
	}
	gotoxy(117, 12);
	printf(".");
    Sleep(1000);
}

void transition1(){
	// sc: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	system("cls");
    int i, j;
    int x, y;

    for (x = 0; x < 115; x++) {
	    for (y = 0; y < 3; y++) {
	    	i = rand() % 30;
	    	j = rand() % 2;

			gotoxy(j+x, i);
			printf(".");


		}
	}
	gotoxy(117, 12);
	printf(".");
}

void raja() {
	FILE *fp;
	char Text[999];

	fp = fopen("Assets//raja.txt","rt");

	if (fp == NULL) {
		printf("File tidak ditemukan\r\n");
		exit(1);
	}
	while ((fgets(Text, 1000, fp)) != NULL)
 		printf("%s\r", Text);

	fclose(fp);
}

void kingdom() {
	FILE *fp;
	char Text[999];

	langit();
	gotoxy(0, 7);
	fp = fopen("Assets//kerajaan - REV1.txt","rt");

	if (fp == NULL) {
		printf("File tidak ditemukan\r\n");
		exit(1);
	}
	while ((fgets(Text, 1000, fp)) != NULL)
 		printf("%s\r", Text);

	fclose(fp);
	Sleep(500);
	printf("\n");
	system("pause");
	system("cls");
}

void langit() {
	int i, j;
    int x;

    for (x = 0; x < 105; x++) {

    	i = rand() % 7;
    	j = rand() % 2;

		gotoxy(j+x, i);
		printf(".");

		Sleep(10);

	}
}

void gedungnikah() {
	FILE *fp;
	char Text[999];

	langit();
	gotoxy(0, 7);
	fp = fopen("Assets//kerajaan - Copy2.txt","rt");

	if (fp == NULL) {
		printf("File tidak ditemukan\r\n");
		exit(1);
	}
	while ((fgets(Text, 1000, fp)) != NULL)
 		printf("%s\r", Text);

	fclose(fp);
	Sleep(500);
	printf("\n");
	system("pause");
	system("cls");
}
