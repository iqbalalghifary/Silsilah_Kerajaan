/*	Program Utama Non-Binary Tree dengan Alokasi Dinamis
	Nama	: Gilang Liberty (191511013)
	Tanggal	: 2 Mei 2020
*/

#include"NBTreeD.h"


int main(){
	Tree tree ;
	tree.root = NULL;
//	Tnbtree cPointRoot;
	int answer, i, pil;
    CreateEmptyTree(&tree);



	for(;;){
		printf("1. Insert data\n");
		printf("2. Tambahkan istri\n");
		printf("3. Tambahkan suami\n");
		printf("4. Jumlah generasi\n");
		printf("5. Jumlah Anak\n");
		printf("Masukkan pilihan :");
		scanf("%d",&pil);
		system("cls");

		switch(pil){
			case 1 : {
				fflush(stdin);
				InsertNode(&tree);
				printf("\n\n\n");

				system("pause");
				system("cls");
				break;
			}

			case 2 : {
			fflush(stdin);
			insertwife(&tree);
			printf("\n\n\n");

			system("pause");
			system("cls");
			break;

			}

			case 3 : {
			fflush(stdin);
			insertsuami(&tree);
			printf("\n\n\n");

			system("pause");
			system("cls");
			break;

			}

			case 4 :{
				printf("============Hitung Generasi============\n");
				printf("=====================================================\n\n");
				printf("Jumlah generasi: %d\n", 1+hitungGenerasi(tree));
				printf("\n\n\n");
				system("pause");
				system("cls");

				break;
			}



			case 5: {
				fflush(stdin);
				infotype parent;
				printf("Masukkan parent yang akan dihitung jumlah anaknya:\n");
				gets(parent);
				int jumlah = hitungAnak(tree, parent);
				printf("%d", jumlah);
				printf("\n\n\n");
				system("pause");
				system("cls");
				break;
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


