#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "BODY.c"
#include "HEADER.h"

int main()
{
    int pilihan;

    do
    {
        system("cls");
        printf("\n\n\t\t==========================================\n");
        printf("\t\tSELAMAT DATANG DI DATABASE APOTEK\n");
        printf("\t\t==========================================\n");
        printf("\t\tMenu: \n");
        printf("\t\t1. Registrasi\n");
        printf("\t\t2. Login\n");
        printf("\t\t3. Exit\n");
        printf("\t\tPilih menu (1-3):");
        scanf("%d",&pilihan);

        switch(pilihan)
        {
        case 1:
            daftarAdmin();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("\n\t\tTerimakasih telah menggunakan database apotek!\n");
            exit(0);
        default:
            printf("\n\n\t\tPilihan tidak valid. Silahkan coba lagi\n");
            system("pause");
            break;
        }
        printf("\n");
    }
    while(pilihan!=3);

    return 0;
}
