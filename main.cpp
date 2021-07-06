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
	
	//areaWindow(900, 540);
	loading_screen();
	introduction();
	
		CreateEmptyTree(&tree);
		printf("abimasur\n");
		printf("   /\n");
		printf("  /\n");
		printf(" /\n");
		printf("rizki\n\n");
		printf("Menu :\n");
	for(;;){
		printf("1. Insert data\n2. Jumlah generasi\n3. Tampilkan silsilah\n4. pewaris takhta\n5. Status Kematian\n6. Jumlah Anak\n");
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
			
			case 2 :{
				printf("============Hitung Generasi============\n");
				printf("=====================================================\n\n");
//				printf("Jumlah Elemen: %d\n", CountElement(tree.root));
//				printf("\nJumlah Daun: %d\n", CountLeaf(tree.root));
				printf("Jumlah generasi: %d\n", 1+hitungGenerasi(tree));
				
				printf("\n\n\n");
				system("pause");
				system("cls");

				break;
			}
			
			case 3 : {
				printf("================Tampil silsilah===============\n");
				printf("===============================================\n");
				printf("Silsilah Kerajaan : \n");
				TampilanSilsilah(tree);
				
				printf("\n\n\n");
				system("pause");
				system("cls");
				break;
			}
			
			case 4 : {
				printf("=============Pewarisan Takhta========================\n");
				printf("======================================================\n");
				printf("1. Ketentuan\n");
				printf("2. Calon raja\n");
				do{
				printf("Masukkan pilihan : ");
				scanf("%d", &pil);
				}while(pil != 1 && pil !=2);
				
				switch(pil){
					case 1 : {
						printf("======================Ketentuan===================\n");
						printf("1. Calon raja ditentukan oleh peraturan kerajaan yang sudah ditetapkan secara turun temurun\n");
						printf("2. Seseorang yang akan menjadi1 calon raja haruslah keturunan dari raja yang sedang menjabat saat itu\n");
						printf("3. Seseorang yang akan menjadi raja haruslah anak laki - laki\n");
						printf("4. Jika seorang raja tidak mempunyai keturunan laki - laki maka pewarisan tidak dapat di lakukan");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}
					case 2 : {
						fflush(stdin);
						if(!IsEmpty(tree)){
							if (ValidasiWaris(tree)){
									pewarisan(&tree);
							}else{
								printf("Pewarisan tidak dapat dilakukan");
							}
						}else{
							printf("Silsilah Kosong\n");
						}
						
						printf("\n\n\n");
						system("pause");
						system("cls");
						break;
					}
				}
				break;
			}
			
			case 5: {
				fflush(stdin);
				insertStatusAnggota(&tree);
				
				printf("\n\n\n");

				system("pause");
				system("cls");
				break;
			}
			
			case 6: {
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
	

