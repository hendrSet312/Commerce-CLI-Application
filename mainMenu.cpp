#include <stdio.h>
int stokGudang = 1000;
int indexBarang = 0;

struct product{
	char name[21];
	char kodeProduk[6];
	long int harga;
	int stok;
}products[1000];

struct kasir{
	char nama_kasir[21];
	struct product transactions[1000];
}arrayKasir[1000];

void staffgudang(){
	int pilihan;
	do{
		puts("Program Gudang");
		puts("Pilih menu :");
		puts("1. Menambah program");
		puts("2. Lihat Barang");
		puts("3. Update Stok");
		puts("4. Kembali ke menu utama");	
		scanf("%d",&pilihan);getchar();
	}while(pilihan < 1 || pilihan > 4);
	
	if(pilihan == 4){
		printf("\n\n\n\n\n\n");
		return;
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
