#include <stdio.h>

int main(){
    while(1){
        int pilihan;

        puts("Selamat datang di aplikasi toko kelontong!");
        do{
            puts("Pilih menu :");
            puts("1. Staff Gudang");
            puts("2. Kasir");
            puts("3. Keluar");
            printf("Input angka : ");
            scanf("%d",&pilihan);getchar();
        }while(pilihan < 1 || pilihan > 3);

        if(pilihan == 1){
            staffGudang();
        }else if(pilihan == 2){
            kasir();
        }else{
            break;
        }
    }
    return 0;
}
