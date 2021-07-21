
#include"NBTreeD.h"


int main(){
	Tree tree ;
	Tree rajaPertama;
	tree.root = NULL;

	int answer, i, pil;
	infotype wow;
    CreateEmptyTree(&tree);

	loading_screen();
	introduction();
	transition();


	for(;;){
      transition1();
	    gotoxy(36, 8);
        printf("<อออออออออออออออออออออออออออออออออ>\n");
        gotoxy(36, 9);
		printf(" บ                               บ\n");
        gotoxy(36, 10);
		printf(" บ   [1] Insert data             บ\n");
        gotoxy(36, 11);
		printf(" บ   [2] Tambahkan istri         บ\n");
		gotoxy(36, 12);
		printf(" บ   [3] Tambahkan suami         บ\n");
		gotoxy(36, 13);
		printf(" บ   [4] Jumlah generasi         บ\n");
		gotoxy(36, 14);
		printf(" บ   [5] Jumlah Anak             บ\n");
		gotoxy(36, 15);
		printf(" บ   [6] Bunuh Raja/calon raja   บ\n");
		gotoxy(36, 16);
		printf(" บ   [7] Tampilkan Silsilah      บ\n");
		gotoxy(36, 17);
		printf(" บ                               บ\n");
		gotoxy(36, 18);
        printf("<อออออออออออออออออออออออออออออออออ>\n");
        gotoxy(40, 20);
		printf("Masukkan pilihan:> ");
		scanf("%d",&pil);
		system("cls");

		switch(pil){
			case 1 : {
				fflush(stdin);
				TampilanSilsilah(tree);
				InsertNode(&tree);
				gotoxy(36, 8);
				printf("\n\n\n");

				system("pause");
				system("cls");
				break;
			}

			case 2 : {
                fflush(stdin);
                TampilanSilsilah(tree);
                insertwife(&tree);
                printf("\n\n\n");
                gotoxy(36, 15);
                system("pause");
                system("cls");
			break;

			}

			case 3 : {
                fflush(stdin);
                TampilanSilsilah(tree);
                insertsuami(&tree);
                printf("\n\n\n");
                gotoxy(36, 15);
                system("pause");
                system("cls");
			break;

			}

			case 4 :{
			    fflush(stdin);
			    TampilanSilsilah(tree);
			    gotoxy(36, 8); printf("============Hitung Generasi============\n");
				gotoxy(29, 9); printf("=====================================================\n\n");
				gotoxy(36, 10); printf("Jumlah generasi: %d\n", 1+hitungGenerasi(tree));
				gotoxy(36, 11); printf("\n\n\n");
				system("pause");
				system("cls");

				break;
			}



			case 5: {
				fflush(stdin);
				infotype parent;
				TampilanSilsilah(tree);
				gotoxy(36, 8);
				printf("Masukkan parent yang akan dihitung jumlah anaknya:\n");
				gotoxy(87, 8);
				gets(parent);
				int jumlah = hitungAnak(tree, parent);
				gotoxy(50, 10);
				printf(":> %s Memiliki %d anak",parent, jumlah);
				printf("\n\n\n");
				gotoxy(36, 15);
				system("pause");
				system("cls");
				break;
			}
			case 6 : {
				fflush(stdin);
				TampilanSilsilah(tree);
				gotoxy(36, 8);
				printf("Data : ");
				gets(wow);
				DeleteNode(&tree, wow);
				gotoxy(36, 8);
				printf("\n\n\n");
                gotoxy(36, 15);
				system("pause");
				system("cls");
				break;
				case 7 : {
				fflush(stdin);
				gotoxy(36, 8);
				TampilanSilsilah(tree);
				getch();
				system("pause");
				system("cls");
				break;
			}
			}
			default : {
				exit(1);
				break;
			}
		}
		TampilanSilsilah(tree);

	}
	return 0;
}


