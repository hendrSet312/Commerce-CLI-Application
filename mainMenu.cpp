#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>

int stokGudang = 1000;
int indexBarang = 0;
int indexTransaksi = 0;

struct product{
	char name[21];
	
	int kodeProdukInt;
	char codeProduct[10];
	
	long long int harga;
	long long int stok;
}products[1000];

struct kasir{
	char nama_kasir[21];
	int codeTransc;
	long long int totalHarga;
	
	int lenTrans;
	struct product transactions[1000];
}arrayKasir[1000];

int checkInt(char harga[]){
	for(int i = 0; i<strlen(harga); i++){
		if(!isdigit(harga[i])){
			return 0;
		}
	}
	return 1; 
}

void baris(int n){
	for(int i=0; i<=n; i++){
		printf(i<n? "-":"-\n");
	}
}


void printTabel(int choice){
	if(choice == 1){
		baris(80);
		printf("No\t|Kode Produk\t|Nama Produk\t\t|Harga\t\t|Stok\t\t|\n");
		for(int i=0; i<indexBarang; i++){
			baris(80);
			printf("%-4d\t|%-12s\t|%-21s\t|%-10lld\t|%-4lld\t|\n", i+1,products[i].codeProduct, products[i].name,products[i].harga, products[i].stok);
		}
		baris(80);
	}else{
		baris(100);
		printf("No%-2\t|Kode transaksi\t%-2|Nama kasir%-12\t|total%-5\t|Detail pembelian\t\t\t|\n");
		for(int i=0; i<indexBarang; i++){
			baris(100);
			printf("%-4d\t|TIX%-4d\t|%-21s\t|%-10lld\t|", i+1,arrayKasir[i].codeTransc, arrayKasir[i].nama_kasir,arrayKasir[i].totalHarga);
			for(int j = 0 ; j<arrayKasir[i].lenTrans; j++){
				if(j<1){
					printf("\t|\t|\t|\t|%s - %s - %lld pcs - Rp.%lld\t|\n",arrayKasir[i].transactions[j].codeProduct,arrayKasir[i].transactions[j].name,arrayKasir[i].transactions[j].stok,arrayKasir[i].transactions[j].harga);
				}else{
					printf("|%s - %s - %lld pcs - Rp.%lld\t|\n",arrayKasir[i].transactions[j].codeProduct,arrayKasir[i].transactions[j].name,arrayKasir[i].transactions[j].stok,arrayKasir[i].transactions[j].harga);
				}
				
			}
		}
		baris(100);
		
	}
	printf("\n\n\n\n\n\n");
	
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
			printf("Input angka : ");
			scanf("%d",&pilihan);getchar();
		}while(pilihan < 1 || pilihan > 4);
		
		if(pilihan == 1){
			printf("\n\n\n\n\n\n");
			
			do{
				printf("Masukkan nama produk : ");
				scanf("%[^\n]", products[indexBarang].name);
				getchar();
				if(strlen(products[indexBarang].name ) < 5 || strlen(products[indexBarang].name) > 20){
					printf("Masukkan nama lebih dari 5 karakter atau tidak lebih dari 20 karakter\n");
				}
			}while(strlen(products[indexBarang].name) < 5 || strlen(products[indexBarang].name) > 20);
			
			char harga[7];
			int pass1;
			do{
				pass1 = 1;
				printf("Masukkan harga barang : ");
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
			
			int pass2;
			char stock[4];
			
			do{
				pass2 = 1;
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
			
			products[indexBarang].kodeProdukInt = indexBarang+1;
			sprintf(products[indexBarang].codeProduct,"BIC%d",products[indexBarang].kodeProdukInt);
			
			printf("Barang berhasil diinput dengan kode produk %s\n", products[indexBarang].codeProduct);
			indexBarang = indexBarang + 1;
			printf("\n\n\n\n\n\n");
		}
		
		if(pilihan == 2){
			printf("\n\n\n\n\n\n");
			if(indexBarang == 0){
				printf("Data barang kosong\n\n");
			}else{
				printTabel(1);
			}
		}
		
		if(pilihan == 3){
			printf("\n\n\n\n\n\n");
			if(indexBarang == 0){
				printf("Data barang kosong\n\n");
				continue;
			}else{
				printTabel(1);
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
			printf("\n\n\n\n\n");
		}
	
		if(pilihan == 4){
			printf("\n\n\n\n\n\n");
			return;
		}
	
	}
}

int validate(int code){
	//IF kodeProduk di Staff Gudang == kodeProduk di Kasir
	for(int i = 0; i<indexBarang ; i++){
	
		if(products[i].kodeProdukInt == code){
			return i;
		}
	}
	return -1;
}

int validateCode(char trCode[]){
	char num[6];
	int idx = 0;
	
	if(trCode[0] == 'B' && trCode[1] == 'I' && trCode[2] == 'C' && strlen(trCode) > 3){
		for(int i = 3 ; i<strlen(trCode) ; i++){
			if(!isdigit(trCode[i])){
				return -1;
			}else{
				num[idx++] = trCode[i];
			}
		}
	}else{
		return -1;
	}
	
	return validate(atoi(num));
}


void kasir(){
	int pilihan;
	int index = 0;
	char namaKasir[20];
	
	while(1){
		do{
		puts("Program Kasir");
		puts("Pilih menu :");
		puts("1. Menambah transaksi");
		puts("2. Lihat list transaksi");
		puts("3. Kembali ke menu utama");
		scanf("%d", &pilihan);getchar();
		}while(pilihan<1 || pilihan>3);
		printf("\n\n\n\n\n\n");
	
	if(pilihan==1){
		arrayKasir[indexTransaksi].totalHarga = 0;
		
		do{
			printf("Nama Kasir: ");
			scanf("%[^\n]", arrayKasir[indexTransaksi].nama_kasir);getchar();
		}while(strlen(arrayKasir[indexTransaksi].nama_kasir)<5 || strlen(arrayKasir[indexTransaksi].nama_kasir)>20);
		
		while(1){
				int foundProductIndex;
				
				do{
					
					printf("Kode Produk: ");
					scanf("%s", arrayKasir[indexTransaksi].transactions[index].codeProduct);getchar();
					foundProductIndex = validateCode(arrayKasir[indexTransaksi].transactions[index].codeProduct);
				}while(foundProductIndex < 0);
			
				arrayKasir[indexTransaksi].transactions[index] = products[foundProductIndex];
				
				do{
					printf("Jumlah Pembelian: ");
					scanf("%lld", &arrayKasir[indexTransaksi].transactions[index].stok);getchar();
				}while(arrayKasir[indexTransaksi].transactions[index].stok > products[foundProductIndex].stok);
				
				products[foundProductIndex].stok-= arrayKasir[indexTransaksi].transactions[index].stok;
				arrayKasir[indexTransaksi].totalHarga = arrayKasir[indexTransaksi].totalHarga + (products[foundProductIndex].harga * arrayKasir[indexTransaksi].transactions[index].stok);
				index++;
				
				char option;
				
				do{
					printf("apakah ingin menambahkan produk pada transaksi? (Y/N): ");
					scanf("%c",&option);getchar();				
				}while(option != 'N' && option != 'Y');
			
				if(option == 'N'){
					arrayKasir[indexTransaksi].lenTrans = index;
					arrayKasir[indexTransaksi].codeTransc = indexTransaksi+1;
					printf("Total Transaksi TK%d adalah Rp%lld\n",indexTransaksi+1,arrayKasir[indexTransaksi].totalHarga);
					printf("\n\n\n\n\n");
					indexTransaksi++;
					break;
				}
			}
			
		}else if(pilihan==2){
			if(indexTransaksi == 0){
				printf("Data barang kosong\n");
			}else if(index>0){
				printTabel(2);
			}
			printf("\n\n\n\n\n");
		}else{
			return;
		}	
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