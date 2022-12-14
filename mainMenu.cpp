#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>

int indexBarang = 0;
int indexKasir = 0;
int indexTransaksi = 0;


struct product{
	char name[21];
	int kodeProduk;
	long int harga;
	int stok;
}products[1000];

struct kasir{
	char nama_kasir[21];
	struct product transactions[1000];
	int codeTrans;
	long long int totalTranc;
}arrayKasir[1000];

int checkInt(char harga[]){
	for(int i = 0; i<strlen(harga); i++){
		if(!isdigit(harga[i])){
			return 0;
		}
	}
	return 1; 
}

void printTabel(){
	printf("No\tKode Produk\t Nama Produk\t Harga\t Stok\n");
	for(int i=0; i<indexBarang; i++){
		printf("%-3d BC%-4d %-20s %-10ld %-4d\n", i+1,products[i].kodeProduk, products[i].name,products[i].harga, products[i].stok);
	}
}

void staffgudang(){
	while(true){
		int pilihan;
		do{
			puts("Program Gudang");
			puts("Pilih menu :");
			puts("1. Menambah barang");
			puts("2. Lihat Barang");
			puts("3. Update Stok");
			puts("4. Kembali ke menu utama");	
			scanf("%d",&pilihan);getchar();
		}while(pilihan < 1 || pilihan > 4);
		
		if(pilihan == 1){
			
			do{
				printf("Masukkan nama produk\n");
				scanf("%[^\n]", products[indexBarang].name);
				getchar();
				if(strlen(products[indexBarang].name ) < 5 || strlen(products[indexBarang].name) > 20){
					printf("Masukkan nama lebih dari 5 karakter atau tidak lebih dari 20 karakter\n");
				}
			}while(strlen(products[indexBarang].name) < 5 || strlen(products[indexBarang].name) > 20);
			
			char harga[7];
			int pass1 = 1;
			do{
				printf("Masukkan harga barang\n");
				scanf("%s", harga);
				getchar();
				if(checkInt(harga) == 0){
					pass1^=1;
					printf("Harga harus berupa angka\n");
				}else{
					products[indexBarang].harga = atoi(harga);
					if(products[indexBarang].harga < 1000 || products[indexBarang].harga > 1000000){
						printf("Harga harus diantara 1000 dan 1000000\n");
						pass1^=1;
					}
				}
				
			}while(pass1 < 1);
			
			int pass2 = 1;
			char stock[4];
			do{
				printf("Masukkan stok barang: ");
				scanf("%s",stock);
				getchar();
				if(checkInt(stock) == 0){
					pass2^=1;
					printf("Stok harus berupa angka\n");
				}else{
					products[indexBarang].stok = atoi(stock);
				}
			}while(pass2 == 0);
			products[indexBarang].kodeProduk = indexBarang+1;
			printf("Barang berhasil diinput dengan kode produk BIC%d\n", products[indexBarang].kodeProduk);
			indexBarang = indexBarang + 1;
		}
		
		if(pilihan == 2){
			if(indexBarang == 0){
				printf("Data barang kosong");
			}else{
				printTabel();
			}
		}
		
		if(pilihan == 3){
			if(indexBarang == 0){
				printf("Data barang kosong");
			}else{
				printTabel();
			}
			
			char nomer[4];
			int pass1 = 1;
			
			do{
				printf("Masukkan nomer barang yang ingin ditambahkan: ");
				scanf("%s", nomer);
				getchar();
				if(checkInt(nomer) == 0){
					pass1^=1;
					printf("Input harus berupa angka\n");
				}
			}while(pass1 < 1);
			
			int updateStok;
			printf("Masukkan jumlah yang akan ditambahkan= ");
			scanf("%d", &updateStok);
			getchar();
			
			int idxTable = atoi(nomer)-1;
			
			products[idxTable].stok = products[idxTable].stok + updateStok;
			printf("Stok Barang %s Berhasil di Update\n", products[idxTable].name);
		}
	
		if(pilihan == 4){
			printf("\n\n\n\n\n\n");
			return;
		}
	
	}
	}

void kasir(){
	int pilihan;
	do{
		puts("Program Gudang");
		puts("Pilih menu :");
		puts("1. Menambah transaksi");
		puts("2. Lihat list transaksi");
		puts("3. Kembali ke menu utama");
		scanf("%d",&pilihan);getchar();
	}while(pilihan < 1 || pilihan > 2);

	if(pilihan == 2){
		printf("\n\n\n\n\n");
		return;
	}
}
int main(){

    while(1){
        int pilihan;
        puts("Selamat datang di aplikasi toko Indocommerce!");
        do{
            puts("Pilih menu :");
            puts("1. Staff Gudang");
            puts("2. Kasir");
            puts("3. Keluar");
            printf("Input angka : ");
            scanf("%d",&pilihan);getchar();
        }while(pilihan < 1 || pilihan > 3);

        if(pilihan == 1){
        	printf("\n\n\n\n\n");
            staffgudang();
        }else if(pilihan == 2){
        	printf("\n\n\n\n\n");
            kasir();
        }else{
            break;
        }
    }


    return 0;
}
