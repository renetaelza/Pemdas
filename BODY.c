#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "HEADER.h"

int cekusername(const char* username)
{
    FILE *filepointer = fopen("admin.txt", "r");
    if (filepointer == NULL)
    {
        printf("File tidak ditemukan \n");
        return 0;
    }

    Admin storedAdmin;
    while (fscanf(filepointer, "%d %s %s %s", &storedAdmin.kode_admin, storedAdmin.nama_admin, storedAdmin.username, storedAdmin.password) == 4)
    {
        if (strcmp(username, storedAdmin.username) == 0)
        {
            fclose(filepointer);
            return 1; // Username sudah ada
        }
    }

    fclose(filepointer);

    return 0; // Username belum ada
}

int cekid(int id)
{
    FILE *filepointer = fopen("admin.txt", "r");
    if (filepointer == NULL)
    {
        printf("File tidak ditemukan\n");
        return 0;
    }

    Admin storedAdmin;
    while (fscanf(filepointer, "%d %s %s %s", &storedAdmin.kode_admin, storedAdmin.nama_admin, storedAdmin.username, storedAdmin.password) == 4)
    {
        if (dataAdmin.kode_admin == storedAdmin.kode_admin)
        {
            fclose(filepointer);
            return 1; // Username sudah ada
        }
    }

    fclose(filepointer);

    return 0;//ID belum ada
}

void daftarAdmin()
{
    FILE *filepointer = fopen("admin.txt", "a");
    if (filepointer == NULL)
    {
        printf("File tidak ditemukan.\n");
        return;
    }

    system("cls");
    printf("\n\n\t\t==========================================\n");
    printf("\t\t         REGISTRASI ADMIN\n");
    printf("\t\t==========================================\n");
    printf("\n");

    int idd;
    do
    {
        printf("\t\tID Admin: ");
        scanf("%d", &dataAdmin.kode_admin);
        idd = cekid(dataAdmin.kode_admin);
        if (idd == 1)
        {
            printf("t\tID yang dimasukkan sudah ada. Masukkan ID lain\n\n");
        }
    }
    while (idd == 1);

    printf("\t\tNama: ");
    scanf(" %s", dataAdmin.nama_admin);

    int usn;
    do
    {
        printf("\t\tUsername: ");
        scanf("%s", dataAdmin.username);
        usn = cekusername(dataAdmin.username);
        if (usn == 1)
        {
            printf("\t\tUsername yang dimasukkan sudah ada. Masukkan username lain\n\n");
        }
    }
    while (usn == 1);

    printf("\t\tPassword: ");
    scanf("%s", dataAdmin.password);

    fprintf(filepointer, "%d %s %s %s\n", dataAdmin.kode_admin, dataAdmin.nama_admin, dataAdmin.username, dataAdmin.password);

    fclose(filepointer);

    printf("\n\t\tRegistration Successful!\n");
    printf("\n\t\tConfirming details...\n\t\tWelcome, %s!\n\n\t\tPlease continue to login section by press any key\n", dataAdmin.nama_admin);
    getch();
}

int ceklogin(const char* username, const char* password)
{
    FILE *filepointer = fopen("admin.txt", "r");
    if (filepointer == NULL)
    {
        printf("File tidak ditemukan\n");
        return 0;
    }

    Admin storedAdmin;
    while (fscanf(filepointer, "%d %s %s %s", &storedAdmin.kode_admin, storedAdmin.nama_admin, storedAdmin.username, storedAdmin.password) == 4)
    {
        if (strcmp(username, storedAdmin.username) == 0)
        {
            if(strcmp(password,storedAdmin.password)==0)
            {
                fclose(filepointer);
                return 1; // Login berhasil
            }
            else
            {
                fclose(filepointer);
                return -1; //Password salah
            }
        }
    }
    fclose(filepointer); //Username tidak ditemukan
    return 0;
}

void copynama(const char* username, char* nama_admin)
{
    FILE *filepointer = fopen("admin.txt", "r");
    if (filepointer == NULL)
    {
        printf("File tidak ditemukan\n");
        return 0;
    }

    Admin storedAdmin;
    while (fscanf(filepointer, "%d %s %s %s", &storedAdmin.kode_admin, storedAdmin.nama_admin, storedAdmin.username, storedAdmin.password) == 4)
    {
        if (strcmp(username, storedAdmin.username) == 0)
        {
            strcpy(nama_admin, storedAdmin.nama_admin); // Menyalin nama ke variabel storedNama
            fclose(filepointer);
            return;
        }
    }
    fclose(filepointer);
}

void login()
{
    FILE* filepointer = fopen("admin.txt","r");

    system("cls");
    char username[100];
    char password[100];
    char nama_admin[100];

    printf("\n\n\t\t==========================================\n");
    printf("\t\t         LOGIN ADMIN\n");
    printf("\t\t==========================================\n");
    printf("\t\tUsername: ");
    scanf("%s", username);
    printf("\t\tPassword: ");
    scanf("%s", password);

    int hasil = ceklogin(username, password);
    if(hasil==1)
    {
        copynama(username, nama_admin);
        fclose(filepointer);
        masukmenu(nama_admin);
    }
    else if(hasil==-1)
    {
        printf("\t\tPassword yang dimasukkan salah. Coba lagi\n");
        system("pause");
        login();
    }
    else
    {
        printf("\t\tUsername tidak ditemukan.\n");
        system("pause");
        login();
    }

    getch();
}

void masukmenu(const char* nama_admin)
{
    int pilihan;
    do
    {
        system("cls");
        printf("\n\n\t\tLogin berhasil. Selamat datang, %s!\n", nama_admin);
        printf("\t\t==========================================\n");
        printf("\t\t       MENU PILIHAN DATABASE APOTEK\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. DATA OBAT\n");
        printf("\t\t2. DATA SUPPLIER\n");
        printf("\t\t3. DATA CUSTOMER\n");
        printf("\t\t4. Logout\n");
        printf("\t\tPilih menu (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            menuObat();
            break;
        case 2:
            menusuplier();
            break;
        case 3:
            menuCustomer();
            break;
        case 4:
            printf("\n\t\tAnda berhasil logout!\n");
            break;
        default:
            printf("\n\n\t\tPilihan tidak valid. Silahkan coba lagi\n");
            system("pause");
            break;
        }
        printf("\n");
    }
    while (pilihan != 4);
}

void menuObat()
{
    int pilihan;
    do
    {
        system("cls");
        printf("\t\t==========================================\n");
        printf("\t\tMENU PILIHAN PENGELOLAAN DATA OBAT\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Tambah Data Obat\n");
        printf("\t\t2. Tampilkan Data Obat\n");
        printf("\t\t3. Edit Data Obat\n");
        printf("\t\t4. Cari Obat\n");
        printf("\t\t5. Transaksi penjualan obat\n");
        printf("\t\t6. Laporan Penjualan Obat\n");
        printf("\t\t7. Laporan Pembelian Obat\n");
        printf("\t\t8. Hapus Obat\n");
        printf("\t\t9. Kembali\n");
        printf("\t\tPilih menu (1-9): ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahObat();
            break;
        case 2:
            tampilObat();
            break;
        case 3:
            editObat();
            break;
        case 4:
            cariObat();
            break;
        case 5:
            menuTransaksiJual();
            break;
        case 6:
            menuLaporanJual();
            break;
        case 7:
            menuLaporanBeli();
            break;
        case 8:
            hapusObat();
            break;
        case 9:
            break;
        default:
            printf("\n\nPilihan tidak valid. Silahkan coba lagi\n");
            system("pause");
            break;
        }
        printf("\n");
    }
    while (pilihan != 9);
}

void tambahObat()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("dataObat.txt", "a+");

    obat data_obat;
    obat storedObat;

    printf("\n\n\t\t==========================================\n");
    printf("\t\t         TAMBAH OBAT\n");
    printf("\t\t==========================================\n");

    printf("\t\tMasukan ID Obat                 = ");
    fflush(stdin);
    scanf(" %[^\n]", data_obat.id_obat);

    while(fscanf(filePointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", storedObat.id_obat, storedObat.nama_obat, storedObat.tgl_produksi, storedObat.tgl_kadaluwarsa,
            storedObat.nomor_rak, &storedObat.harga, &storedObat.stok) == 7)
    {
        if(strcmp(data_obat.id_obat, storedObat.id_obat) == 0)
        {
            printf("\t\tID Obat %s sudah digunakan!\n", data_obat.id_obat);
            getch();
            fclose(filePointer);
            return;
        }
    }

    printf("\t\tMasukan Nama Obat               = ");
    fflush(stdin);
    scanf(" %[^\n]", data_obat.nama_obat);

    printf("\t\tMasukan Tanggal Produksi        = ");
    fflush(stdin);
    scanf(" %[^\n]", data_obat.tgl_produksi);

    printf("\t\tMasukan Tanggal Kadaluwarsa     = ");
    fflush(stdin);
    scanf(" %[^\n]", data_obat.tgl_kadaluwarsa);

    printf("\t\tMasukan Nomor Rak               = ");
    fflush(stdin);
    scanf(" %[^\n]", data_obat.nomor_rak);

    printf("\t\tMasukan Harga obat              = ");
    scanf("%d", &data_obat.harga);

    printf("\t\tMasukan Stok obat               = ");
    scanf("%d", &data_obat.stok);

    fprintf(filePointer, "%s;%s;%s;%s;%s;%d;%d\n", data_obat.id_obat, data_obat.nama_obat, data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa,
            data_obat.nomor_rak, data_obat.harga, data_obat.stok);

    fclose(filePointer);

    printf("\t\tObat berhasil ditambahkan.\n");

    getch();
}

void tampilObat()
{
    system("cls");
    FILE *filePointer;
    int totalObat = 0;
    filePointer = fopen("dataObat.txt", "r"); // Membaca file

    obat data_obat;

    printf("\n\n\t\t\t\t\t==========================================\n");
    printf("\t\t\t\t\t\t         DAFTAR OBAT\n");
    printf("\t\t\t\t\t==========================================\n");

    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID OBAT    | NAMA OBAT            | TANGGAL PRODUKSI     | TANGGAL KADALUWARSA  | NOMOR RAK       | HARGA   | STOK  |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n",
                  data_obat.id_obat, data_obat.nama_obat, data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa,
                  data_obat.nomor_rak, &data_obat.harga, &data_obat.stok) == 7) {
        printf("| %-10s | %-20s | %-20s | %-20s | %-15s | %-7d | %-5d |\n", data_obat.id_obat, data_obat.nama_obat, data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa,
               data_obat.nomor_rak, data_obat.harga, data_obat.stok);

        totalObat++; // Menghitung jumlah data_obat yang ada
    }

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\nJumlah total obat: %d\n", totalObat);
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    // Menutup file
    fclose(filePointer);
    system("pause");
}

void menuTransaksiJual()
{
    int pilihan;
    do
    {
        system("cls");
        printf("\t\t==========================================\n");
        printf("\t\tTRANSAKSI PENJUALAN OBAT\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Tambah Transaksi\n");
        printf("\t\t2. Tampilkan Transaksi\n");
        printf("\t\t3. Kembali\n");
        printf("\t\tPilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            jual_tambah();
            break;
        case 2:
            jual_tampilkan();
            break;
        case 3:
            break;
        default:
            printf("\t\tPilihan tidak valid. Silakan coba lagi.\n");
            system("pause");
            menuTransaksiJual();
            break;
        }
    }
    while(pilihan!=3);
}

void jual_tambah()
{
    system("cls");
    FILE *filePointer;

    obat data_obat;
    transJual Tdata1;
    transJual storedTransaksi1;

    filePointer = fopen("dataTransaksi.txt", "a+");

    printf("\n");
    printf("\n\n\t\t==========================================\n");
    printf("\t\t            TAMBAH TRANSAKSI\n");
    printf("\t\t==========================================\n");
    printf("\t\tMasukan Nomor Transaksi     = ");
    fflush(stdin);
    scanf("%d", &Tdata1.no_transaksi);

    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &storedTransaksi1.no_transaksi, storedTransaksi1.nama_cust,
                storedTransaksi1.nama_obat, storedTransaksi1.id_obat, &storedTransaksi1.tgl_transaksi.day, &storedTransaksi1.tgl_transaksi.month,
                &storedTransaksi1.tgl_transaksi.year, &storedTransaksi1.jml_obat, &storedTransaksi1.total_byr) != EOF)
    {
        if (storedTransaksi1.no_transaksi == Tdata1.no_transaksi)
        {
            printf("\t\tID Transaksi sudah ada. Masukkan ID Transaksi yang lain.\n");
            printf("\t\tMasukan Nomor Transaksi     = ");
            scanf("%d", &Tdata1.no_transaksi);
        }
    }

    printf("\t\tMasukan Nama Customer       = ");
    fflush(stdin);
    scanf(" %[^\n]", Tdata1.nama_cust);

    printf("\t\tMasukan ID Obat             = ");
    fflush(stdin);
    scanf(" %[^\n]", Tdata1.id_obat);

    printf("\t\tMasukan Nama Obat           = ");
    fflush(stdin);
    scanf(" %[^\n]", Tdata1.nama_obat);

    printf("\t\tMasukan Tanggal Transaksi (dd-mm-yyyy)     = ");
    scanf("%d-%d-%d", &Tdata1.tgl_transaksi.day, &Tdata1.tgl_transaksi.month, &Tdata1.tgl_transaksi.year);

    printf("\t\tMasukan Jumlah Obat         = ");
    scanf("%d", &Tdata1.jml_obat);

    // Cari harga obat berdasarkan ID obat di file dataObat.txt
    FILE *fileObat;
    fileObat = fopen("dataObat.txt", "r");
    int found = 0;

    while (fscanf(fileObat, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", data_obat.id_obat, data_obat.nama_obat,
                data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, &data_obat.harga, &data_obat.stok) != EOF)
    {
        if (strcmp(Tdata1.id_obat, data_obat.id_obat) == 0)
        {
            found = 1;
            Tdata1.total_byr = data_obat.harga * Tdata1.jml_obat;
            break;
        }
    }

    fclose(fileObat);

    if (found)
    {
        fprintf(filePointer, "%d %s %s %s %02d-%02d-%04d %d %d\n", Tdata1.no_transaksi, Tdata1.nama_cust,
                Tdata1.nama_obat, Tdata1.id_obat, Tdata1.tgl_transaksi.day, Tdata1.tgl_transaksi.month, Tdata1.tgl_transaksi.year, Tdata1.jml_obat, Tdata1.total_byr);

        printf("\n\t\tTransaksi berhasil ditambahkan.\n");

        // Kurangi stok obat
        kurangi_stok(Tdata1.id_obat, Tdata1.jml_obat);
    }
    else
    {
        printf("\n\t\tObat dengan ID %s tidak ditemukan.\n", Tdata1.id_obat);
    }

    fclose(filePointer);
    getch();
}

void jual_tampilkan()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("dataTransaksi.txt", "r");

    printf("\n\n\t\t\t\t\t==========================================\n");
    printf("\t\t\t\t\t\t  DAFTAR TRANSAKSI PENJUALAN\n");
    printf("\t\t\t\t\t==========================================\n");
    printf("\n");printf("\n");

    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-20s | %-15s | %-15s | %-10s | %-10s |\n",
           "ID TRANSAKSI", "NAMA CUSTOMER", "NAMA OBAT", "ID OBAT", "TANGGAL TRANSAKSI", "JUMLAH OBAT", "TOTAL HARGA");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");

    transJual Tdata1;
    while (fscanf(filePointer, "%d %s %s %s %02d-%02d-%04d %d %d", &Tdata1.no_transaksi, Tdata1.nama_cust,
                Tdata1.nama_obat, Tdata1.id_obat, &Tdata1.tgl_transaksi.day, &Tdata1.tgl_transaksi.month, &Tdata1.tgl_transaksi.year, &Tdata1.jml_obat, &Tdata1.total_byr) != EOF)
{
    printf("| %-15d | %-20s | %-20s | %-15s | %02d-%02d-%04d        | %-10d  | %-10d  |\n", Tdata1.no_transaksi, Tdata1.nama_cust,
            Tdata1.nama_obat, Tdata1.id_obat, Tdata1.tgl_transaksi.day, Tdata1.tgl_transaksi.month, Tdata1.tgl_transaksi.year, Tdata1.jml_obat, Tdata1.total_byr);
}


    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(filePointer);
    system("pause");
}

void kurangi_stok(char id_obat[], int jumlah_obat)
{
    FILE *filepointer, *temp;
    int found = 0;

    filepointer = fopen("dataObat.txt", "r");
    temp = fopen("temp.txt", "w");

    obat data_obat;

    while (fscanf(filepointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", data_obat.id_obat, data_obat.nama_obat,
                data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, &data_obat.harga, &data_obat.stok) != EOF)
    {
        if (strcmp(id_obat, data_obat.id_obat) == 0)
        {
            found = 1;
            if (data_obat.stok < jumlah_obat) {
                printf("Maaf, stok obat tidak cukup\n");
            } else {
                data_obat.stok -= jumlah_obat;
            }
        }
        fprintf(temp, "%s;%s;%s;%s;%s;%d;%d\n", data_obat.id_obat, data_obat.nama_obat, data_obat.tgl_produksi,
                data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, data_obat.harga, data_obat.stok);
    }

    fclose(filepointer);
    fclose(temp);

    if (found)
    {
        remove("dataObat.txt");
        rename("temp.txt", "dataObat.txt");
        printf("\t\tStok obat telah diperbarui.\n");
    } else
    {
        remove("temp.txt");
        printf("Produk dengan kode %s tidak ditemukan.\n", id_obat);
    }
}

void menuLaporanJual()
{
    int pilihan;
    do
    {
        system("cls");
        printf("\t\t==========================================\n");
        printf("\t\tTRANSAKSI LAPORAN PENJUALAN\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Filter Laporan Berdasarkan Tanggal\n");
        printf("\t\t2. Laporan Penjualan Secara Keseluruhn\n");
        printf("\t\t3. Kembali\n");
        printf("\t\tPilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            laporanTanggal();
            break;
        case 2:
            laporanKeseluruhan();
            break;
        case 3:
            break;
        default:
            printf("\t\tPilihan tidak valid. Silakan coba lagi.\n");
            system("pause");
            menuTransaksiJual();
            break;
        }
    }
    while(pilihan!=3);
}

void laporanTanggal()
{
    system("cls");

    FILE *filePointer;
    transJual storedTransaksi;

    filePointer = fopen("dataTransaksi.txt", "r");

    printf("\n");
    printf("\n\n\t\t================================================================\n");
    printf("\t\t                          LAPORAN PENJUALAN\n");
    printf("\t\t================================================================\n");
    printf("\t\tMasukan Tanggal Transaksi (dd-mm-yyyy)     = ");
    struct tanggal tgl;
    scanf("%d-%d-%d", &tgl.day, &tgl.month, &tgl.year);

    int found = 0;

    printf("\n\n\t\t================================================================\n");
    printf("\t\t       DATA TRANSAKSI PADA TANGGAL %02d-%02d-%04d\n", tgl.day, tgl.month, tgl.year);
    printf("\t\t================================================================\n");

    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &storedTransaksi.no_transaksi, storedTransaksi.nama_cust,
                storedTransaksi.nama_obat, storedTransaksi.id_obat, &storedTransaksi.tgl_transaksi.day, &storedTransaksi.tgl_transaksi.month,
                &storedTransaksi.tgl_transaksi.year, &storedTransaksi.jml_obat, &storedTransaksi.total_byr) != EOF)
    {
        if (storedTransaksi.tgl_transaksi.day == tgl.day && storedTransaksi.tgl_transaksi.month == tgl.month && storedTransaksi.tgl_transaksi.year == tgl.year)
        {
            printf("\n");
            printf("\t\tNomor Transaksi   : %d\n", storedTransaksi.no_transaksi);
            printf("\t\tNama Customer     : %s\n", storedTransaksi.nama_cust);
            printf("\t\tNama Obat         : %s\n", storedTransaksi.nama_obat);
            printf("\t\tID Obat           : %s\n", storedTransaksi.id_obat);
            printf("\t\tTanggal Transaksi : %02d-%02d-%04d\n", storedTransaksi.tgl_transaksi.day, storedTransaksi.tgl_transaksi.month, storedTransaksi.tgl_transaksi.year);
            printf("\t\tJumlah Obat       : %d\n", storedTransaksi.jml_obat);
            printf("\t\tTotal Bayar       : %d\n", storedTransaksi.total_byr);

            found = 1;
        }
    }

    if (!found)
    {
        printf("\n\t\tTidak ada transaksi pada tanggal tersebut.\n");
    }

    fclose(filePointer);
    getch();
}

void laporanKeseluruhan()
{
    system("cls");

    FILE *filePointer;
    transJual dataTransaksi[1000];
    int count = 0;

    filePointer = fopen("dataTransaksi.txt", "r");

    printf("\n");
    printf("\n\n\t\t==================================================================================================================\n");
    printf("\t\t                                     LAPORAN PENJUALAN URUT BERDASARKAN TANGGAL\n");
    printf("\t\t==================================================================================================================\n");

    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &dataTransaksi[count].no_transaksi, dataTransaksi[count].nama_cust,
                dataTransaksi[count].nama_obat, dataTransaksi[count].id_obat, &dataTransaksi[count].tgl_transaksi.day, &dataTransaksi[count].tgl_transaksi.month,
                &dataTransaksi[count].tgl_transaksi.year, &dataTransaksi[count].jml_obat, &dataTransaksi[count].total_byr) != EOF)
    {
        count++;
    }

    // Urutkan data transaksi berdasarkan tanggal menggunakan Bubble Sort
    int i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (dataTransaksi[j].tgl_transaksi.year > dataTransaksi[j + 1].tgl_transaksi.year ||
                (dataTransaksi[j].tgl_transaksi.year == dataTransaksi[j + 1].tgl_transaksi.year &&
                 dataTransaksi[j].tgl_transaksi.month > dataTransaksi[j + 1].tgl_transaksi.month) ||
                (dataTransaksi[j].tgl_transaksi.year == dataTransaksi[j + 1].tgl_transaksi.year &&
                 dataTransaksi[j].tgl_transaksi.month == dataTransaksi[j + 1].tgl_transaksi.month &&
                 dataTransaksi[j].tgl_transaksi.day > dataTransaksi[j + 1].tgl_transaksi.day))
            {
                // Tukar posisi
                transJual temp = dataTransaksi[j];
                dataTransaksi[j] = dataTransaksi[j + 1];
                dataTransaksi[j + 1] = temp;
            }
        }
    }

    printf("\n\n\t\t===================================================================================================================\n");
    printf("\t\t| No. | No. Transaksi |   Nama Customer   |    Nama Obat     |   ID Obat   |   Tanggal   | Jml Obat | Total Bayar |\n");
    printf("\t\t===================================================================================================================\n");

    for (i = 0; i < count; i++)
    {
        printf("\t\t| %3d |   %10d  | %-18s| %-16s | %-12s| %02d-%02d-%04d  | %8d | %11d |\n", i + 1, dataTransaksi[i].no_transaksi,
               dataTransaksi[i].nama_cust, dataTransaksi[i].nama_obat, dataTransaksi[i].id_obat,
               dataTransaksi[i].tgl_transaksi.day, dataTransaksi[i].tgl_transaksi.month, dataTransaksi[i].tgl_transaksi.year,
               dataTransaksi[i].jml_obat, dataTransaksi[i].total_byr);
    }

    printf("\t\t===================================================================================================================\n");

    fclose(filePointer);
    getch();
}

void menuLaporanBeli()
{
     int pilihan;
    do
    {
        system("cls");
        printf("\t\t==========================================\n");
        printf("\t\tTRANSAKSI LAPORAN PEMBELIAN\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Filter Laporan Berdasarkan Tanggal\n");
        printf("\t\t2. Laporan Penjualan Secara Keseluruhn\n");
        printf("\t\t3. Kembali\n");
        printf("\t\tPilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            laporanTanggal1();
            break;
        case 2:
            laporanKeseluruhan1();
            break;
        case 3:
            break;
        default:
            printf("\t\tPilihan tidak valid. Silakan coba lagi.\n");
            system("pause");
            menuTransaksiJual();
            break;
        }
    }
    while(pilihan!=3);
}

void laporanTanggal1()
{
    system("cls");

    FILE *filePointer;
    transBeli storedTransaksi;

    filePointer = fopen("dataTransaksiBeli.txt", "r");

    printf("\n");
    printf("\n\n\t\t================================================================\n");
    printf("\t\t                          LAPORAN PEMBELIAN\n");
    printf("\t\t================================================================\n");
    printf("\t\tMasukan Tanggal Transaksi (dd-mm-yyyy)     = ");
    struct tanggal tgl;
    scanf("%d-%d-%d", &tgl.day, &tgl.month, &tgl.year);

    int found = 0;

    printf("\n\n\t\t================================================================\n");
    printf("\t\t       DATA TRANSAKSI PADA TANGGAL %02d-%02d-%04d\n", tgl.day, tgl.month, tgl.year);
    printf("\t\t================================================================\n");

    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &storedTransaksi.no_transaksi, storedTransaksi.nama_supp,
                storedTransaksi.nama_obat, storedTransaksi.id_obat, &storedTransaksi.tgltransaksi.day, &storedTransaksi.tgltransaksi.month,
                &storedTransaksi.tgltransaksi.year, &storedTransaksi.jml_obat, &storedTransaksi.total_byr) != EOF)
    {
        if (storedTransaksi.tgltransaksi.day == tgl.day && storedTransaksi.tgltransaksi.month == tgl.month && storedTransaksi.tgltransaksi.year == tgl.year)
        {
            printf("\n");
            printf("\t\tNomor Transaksi   : %d\n", storedTransaksi.no_transaksi);
            printf("\t\tNama Customer     : %s\n", storedTransaksi.nama_supp);
            printf("\t\tNama Obat         : %s\n", storedTransaksi.nama_obat);
            printf("\t\tID Obat           : %s\n", storedTransaksi.id_obat);
            printf("\t\tTanggal Transaksi : %02d-%02d-%04d\n", storedTransaksi.tgltransaksi.day, storedTransaksi.tgltransaksi.month, storedTransaksi.tgltransaksi.year);
            printf("\t\tJumlah Obat       : %d\n", storedTransaksi.jml_obat);
            printf("\t\tTotal Bayar       : %d\n", storedTransaksi.total_byr);

            found = 1;
        }
    }

    if (!found)
    {
        printf("\n\t\tTidak ada transaksi pada tanggal tersebut.\n");
    }

    fclose(filePointer);
    getch();
}

void laporanKeseluruhan1()
{
    system("cls");

    FILE *filePointer;
    transBeli dataTransaksi[1000];
    int count = 0;

    filePointer = fopen("dataTransaksiBeli.txt", "r");

    printf("\n");
    printf("\n\n\t\t==================================================================================================================\n");
    printf("\t\t                                     LAPORAN PENJUALAN URUT BERDASARKAN TANGGAL\n");
    printf("\t\t==================================================================================================================\n");

    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &dataTransaksi[count].no_transaksi, dataTransaksi[count].nama_supp,
                dataTransaksi[count].nama_obat, dataTransaksi[count].id_obat, &dataTransaksi[count].tgltransaksi.day, &dataTransaksi[count].tgltransaksi.month,
                &dataTransaksi[count].tgltransaksi.year, &dataTransaksi[count].jml_obat, &dataTransaksi[count].total_byr) != EOF)
    {
        count++;
    }

    // Urutkan data transaksi berdasarkan tanggal menggunakan Bubble Sort
    int i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (dataTransaksi[j].tgltransaksi.year > dataTransaksi[j + 1].tgltransaksi.year ||
                (dataTransaksi[j].tgltransaksi.year == dataTransaksi[j + 1].tgltransaksi.year &&
                 dataTransaksi[j].tgltransaksi.month > dataTransaksi[j + 1].tgltransaksi.month) ||
                (dataTransaksi[j].tgltransaksi.year == dataTransaksi[j + 1].tgltransaksi.year &&
                 dataTransaksi[j].tgltransaksi.month == dataTransaksi[j + 1].tgltransaksi.month &&
                 dataTransaksi[j].tgltransaksi.day > dataTransaksi[j + 1].tgltransaksi.day))
            {
                // Tukar posisi
                transBeli temp = dataTransaksi[j];
                dataTransaksi[j] = dataTransaksi[j + 1];
                dataTransaksi[j + 1] = temp;
            }
        }
    }

    printf("\n\n\t\t===================================================================================================================\n");
    printf("\t\t| No. | No. Transaksi |   Nama Customer   |    Nama Obat     |   ID Obat   |   Tanggal   | Jml Obat | Total Bayar |\n");
    printf("\t\t===================================================================================================================\n");

    for (i = 0; i < count; i++)
    {
        printf("\t\t| %3d |   %10d  | %-18s| %-16s | %-12s| %02d-%02d-%04d  | %8d | %11d |\n", i + 1, dataTransaksi[i].no_transaksi,
               dataTransaksi[i].nama_supp, dataTransaksi[i].nama_obat, dataTransaksi[i].id_obat,
               dataTransaksi[i].tgltransaksi.day, dataTransaksi[i].tgltransaksi.month, dataTransaksi[i].tgltransaksi.year,
               dataTransaksi[i].jml_obat, dataTransaksi[i].total_byr);
    }

    printf("\t\t===================================================================================================================\n");

    fclose(filePointer);
    getch();
}

void cariObat()
{
    system("cls");
    FILE *filePointer;
    char idObat[20];

    obat storedObat;

    filePointer = fopen("dataObat.txt", "r");
    if (filePointer == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\n\n\t\t==========================================\n");
    printf("\t\t            PENCARIAN OBAT\n");
    printf("\t\t==========================================\n");
    printf("\t\tMasukkan ID Obat yang ingin dicari : ");

    //Masukkan ID
    scanf("%s", idObat);

    printf("\n\t\tHasil Pencarian: \n");

    int found = 0;
    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", storedObat.id_obat, storedObat.nama_obat, storedObat.tgl_produksi,
            storedObat.tgl_kadaluwarsa, storedObat.nomor_rak, &storedObat.harga, &storedObat.stok) !=EOF) {
        if (strcmp(idObat, storedObat.id_obat) == 0) {
            printf("\t\tID Obat                 : %s\n", storedObat.id_obat);
            printf("\t\tNama Obat               : %s\n", storedObat.nama_obat);
            printf("\t\tTanggal Produksi Obat   : %s\n", storedObat.tgl_produksi);
            printf("\t\tTanggal Kadaluwarsa     : %s\n", storedObat.tgl_kadaluwarsa);
            printf("\t\tNomor Rak Obat          : %s\n", storedObat.nomor_rak);
            printf("\t\tHarga                   : %d\n", storedObat.harga);
            printf("\t\tStok                    : %d\n", storedObat.stok);
            found = 1;
        }
    }

    if (!found) {
        printf("\t\tObat dengan ID tersebut tidak ditemukan.\n");
    }

    fclose(filePointer);
    printf("\n\t\tPress any key to continue . . .");
    getch();
}

void editObat()
{
    system("cls");
    FILE* filePointer, * fnew;
    //Membuka file asli untuk dibaca
    filePointer = fopen("dataObat.txt", "r");
    if (filePointer == NULL)
    {
        printf("File tidak ditemukan.\n");
        getch();
        return;
    }
    //Membaca file sementara untuk ditulis
    fnew = fopen("dataObat_new.txt", "w");

    printf("\n\n\t\t==========================================\n");
    printf("\t\t              EDIT DATA OBAT\n");
    printf("\t\t==========================================\n");

    char idObat[20];
    //Meminta input ID Obat yang ingin diedit datanya
    printf("\t\tMasukkan ID Obat yang ingin diedit: ");
    scanf("%19s", idObat);

    int found = 0; //Menandakan apakah data dengan target ID Obat ditemukan

    obat data_obat;
    obat storedObat;

    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", storedObat.id_obat, storedObat.nama_obat,
                  storedObat.tgl_produksi, storedObat.tgl_kadaluwarsa, storedObat.nomor_rak, &storedObat.harga,
                  &storedObat.stok) == 7)
    {
        if (strcmp(idObat, storedObat.id_obat) == 0) {
            found = 1;

            printf("\n\t\tData Obat Ditemukan\n");
            printf("\t\t===============================\n");
            printf("\t\tID Obat                 : %s\n", storedObat.id_obat);
            printf("\t\tNama Obat               : %s\n", storedObat.nama_obat);
            printf("\t\tTanggal Produksi Obat   : %s\n", storedObat.tgl_produksi);
            printf("\t\tTanggal Kadaluwarsa     : %s\n", storedObat.tgl_kadaluwarsa);
            printf("\t\tNomor Rak Obat          : %s\n", storedObat.nomor_rak);
            printf("\t\tHarga                   : %d\n", storedObat.harga);
            printf("\t\tStok                    : %d\n", storedObat.stok);

            printf("\n\t\tMasukkan data baru untuk obat ini:\n");
            printf("\t\tMasukan Nama Obat               = ");
            fflush(stdin);
            scanf(" %[^\n]", data_obat.nama_obat);

            printf("\t\tMasukan Tanggal Produksi        = ");
            fflush(stdin);
            scanf(" %[^\n]", data_obat.tgl_produksi);

            printf("\t\tMasukan Tanggal Kadaluwarsa     = ");
            fflush(stdin);
            scanf(" %[^\n]", data_obat.tgl_kadaluwarsa);

            printf("\t\tMasukan Nomor Rak               = ");
            fflush(stdin);
            scanf(" %[^\n]", data_obat.nomor_rak);

            printf("\t\tMasukan Harga obat              = ");
            scanf("%d", &data_obat.harga);

            printf("\t\tMasukan Stok obat               = ");
            scanf("%d", &data_obat.stok);

            fprintf(fnew, "%s;%s;%s;%s;%s;%d;%d\n", storedObat.id_obat, data_obat.nama_obat,
                    data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, data_obat.harga,
                    data_obat.stok);

            printf("\n\t\tData obat berhasil diedit.\n");
        }
        else
        {
            fprintf(fnew, "%s;%s;%s;%s;%s;%d;%d\n", storedObat.id_obat, storedObat.nama_obat,
                    storedObat.tgl_produksi, storedObat.tgl_kadaluwarsa, storedObat.nomor_rak, storedObat.harga,
                    storedObat.stok);
        }
    }

    if (found == 0)
    {
        printf("\nObat dengan ID %s tidak ditemukan.\n", idObat);
    }

    // Menutup file
    fclose(filePointer);
    fclose(fnew);
    // Menghapus file asli
    remove("dataObat.txt");
    // Mengganti file sementara dengan file asli
    rename("dataObat_new.txt", "dataObat.txt");
    getch();
}

void hapusObat()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("dataObat.txt", "r+");

    if (filePointer == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    obat storedObat;
    char idObat[20];
    int found = 0;

    printf("\n\n\t\t==========================================\n");
    printf("\t\t           HAPUS DATA OBAT\n");
    printf("\t\t==========================================\n");

    printf("\t\tMasukkan ID Obat yang ingin dihapus: ");
    fflush(stdin);
    scanf("%19s", idObat);

    FILE *tempFilePointer;
    tempFilePointer = fopen("tempDataObat.txt", "w");

    if (tempFilePointer == NULL) {
        printf("\t\tGagal membuka file.\n");
        fclose(filePointer);
        return;
    }

    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", storedObat.id_obat, storedObat.nama_obat,
                  storedObat.tgl_produksi, storedObat.tgl_kadaluwarsa, storedObat.nomor_rak, &storedObat.harga,
                  &storedObat.stok) == 7) {
        if (strcmp(idObat, storedObat.id_obat) == 0) {
            found = 1;
            printf("\n\t\tData Obat Ditemukan\n");
            printf("\t\t===============================\n");
            printf("\t\tID Obat                 : %s\n", storedObat.id_obat);
            printf("\t\tNama Obat               : %s\n", storedObat.nama_obat);
            printf("\t\tTanggal Produksi Obat   : %s\n", storedObat.tgl_produksi);
            printf("\t\tTanggal Kadaluwarsa     : %s\n", storedObat.tgl_kadaluwarsa);
            printf("\t\tNomor Rak Obat          : %s\n", storedObat.nomor_rak);
            printf("\t\tHarga                   : %d\n", storedObat.harga);
            printf("\t\tStok                    : %d\n", storedObat.stok);
            printf("\n\t\tData obat berhasil dihapus.\n");
        } else {
            fprintf(tempFilePointer, "%s;%s;%s;%s;%s;%d;%d\n", storedObat.id_obat, storedObat.nama_obat,
                    storedObat.tgl_produksi, storedObat.tgl_kadaluwarsa, storedObat.nomor_rak, storedObat.harga,
                    storedObat.stok);
        }
    }

    fclose(filePointer);
    fclose(tempFilePointer);

    if (found) {
        remove("dataObat.txt");
        rename("tempDataObat.txt", "dataObat.txt");
    } else {
        remove("tempDataObat.txt");
        printf("\t\tObat dengan ID tersebut tidak ditemukan.\n");
    }

    printf("\n\t\tPress any key to continue . . .");
    getch();
}

void laporan_jual()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("dataTransaksi.txt", "r");

    printf("\n\n\t\t==========================================\n");
    printf("\t\t                  LAPORAN PENJUALAN\n");
    printf("\t\t==========================================\n");

    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-20s | %-15s | %-15s | %-10s | %-10s |\n",
           "ID TRANSAKSI", "NAMA CUSTOMER", "NAMA OBAT", "ID OBAT", "TANGGAL TRANSAKSI", "JUMLAH OBAT", "TOTAL HARGA");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    transJual Tdata;
    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &Tdata.no_transaksi, Tdata.nama_cust,
                  Tdata.nama_obat, Tdata.id_obat, &Tdata.tgl_transaksi.day, &Tdata.tgl_transaksi.month, &Tdata.tgl_transaksi.year, &Tdata.jml_obat, &Tdata.total_byr) == 9)
    {
        printf("| %-15d | %-20s | %-20s | %-15s | %02d-%02d-%04d        | %-10d  | %-10d |\n", Tdata.no_transaksi, Tdata.nama_cust,
               Tdata.nama_obat, Tdata.id_obat, Tdata.tgl_transaksi.day, Tdata.tgl_transaksi.month, Tdata.tgl_transaksi.year, Tdata.jml_obat, Tdata.total_byr);
    }

    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(filePointer);
    system("pause");
}

void menusuplier()
{
    int pilihan;

    do {
        system("cls");
        printf("\t\t==========================================\n");
        printf("\t\tMENU PILIHAN PENGELOLAAN DATA SUPPLIER\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Tambah Data Supplier\n");
        printf("\t\t2. Tampilkan Data Supplier\n");
        printf("\t\t3. Cari Supplier\n");
        printf("\t\t4. Transaksi Pembelian Obat\n");
        printf("\t\t5. Kembali\n");
        printf("\t\tPilih menu (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
                tambahSupplier();
                break;
            case 2:
                tampilSupplier();
                break;
            case 3:
                cariSupplier();
                break;
            case 4:
                menuTransaksiBeli();
            case 5:
                break;
            default:
                printf("Pilihan menu tidak valid.\n");
                break;
        }
    } while (pilihan != 5);
}

void tambahSupplier()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("dataSupplier.txt", "a+");

    supplier dataSupplier;
    supplier storedSupplier;

    printf("\n\n\t\t==========================================\n");
    printf("\t\t                  TAMBAH DATA\n");
    printf("\t\t==========================================\n");

    printf("\t\tMasukan ID Supplier     = ");
    fflush(stdin);
    scanf(" %[^\n]", dataSupplier.id_supp);

    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%lld\n", storedSupplier.id_supp, storedSupplier.nama_supp, storedSupplier.kota_supp, &storedSupplier.hp_supp) == 4)
    {
        if (strcmp(dataSupplier.id_supp, storedSupplier.id_supp) == 0)
        {
            printf("ID Supplier %s sudah digunakan!\n", dataSupplier.id_supp);
            getch();
            fclose(filePointer);
            return;
        }
    }

    printf("\t\tMasukan Nama Supplier   = ");
    fflush(stdin);
    scanf(" %[^\n]", dataSupplier.nama_supp);

    printf("\t\tMasukan Kota Supplier   = ");
    fflush(stdin);
    scanf(" %[^\n]", dataSupplier.kota_supp);

    printf("\t\tMasukan Nomor HP        = ");
    scanf("%lld", &dataSupplier.hp_supp);

    fprintf(filePointer, "%s;%s;%s;%lld\n", dataSupplier.id_supp, dataSupplier.nama_supp, dataSupplier.kota_supp, dataSupplier.hp_supp);

    fclose(filePointer);

    printf("\t\tSupplier berhasil ditambahkan.\n");

    getch();
}

void tampilSupplier()
{
    system("cls");
    FILE *filePointer;
    int totalSupplier = 0;
    int hp=0;
    filePointer = fopen("dataSupplier.txt", "r"); // Membaca file

    supplier dataSupplier;

    printf("\n");printf("\n");
    printf("==============================================================================================\n");
    printf("                                      DAFTAR SUPPLIER\n");
    printf("==============================================================================================\n");

    printf("\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| ID SUPPLIER        | NAMA SUPPLIER         | NAMA KOTA            | NOMOR HANDPHONE       |\n");
    printf("----------------------------------------------------------------------------------------------\n");

    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%lld\n", dataSupplier.id_supp, dataSupplier.nama_supp, dataSupplier.kota_supp, &dataSupplier.hp_supp) == 4) {
        printf("| %-18s | %-21s | %-20s | %d%-20lld |\n", dataSupplier.id_supp, dataSupplier.nama_supp, dataSupplier.kota_supp, hp, dataSupplier.hp_supp);
        totalSupplier++; // Menghitung jumlah data_suppomer yang ada
    }

    printf("----------------------------------------------------------------------------------------------\n");
    printf("Jumlah total supplier: %d\n", totalSupplier);
    printf("----------------------------------------------------------------------------------------------\n");

    // Menutup file
    fclose(filePointer);
    system("pause");
}

void cariSupplier()
{
    system("cls");
    FILE *filePointer;
    char idSupplier[20];

    supplier storedSupplier;

    filePointer = fopen("dataSupplier.txt", "r");
    if (filePointer == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\n\n\t\t==========================================\n");
    printf("\t\t            PENCARIAN SUPPLIER\n");
    printf("\t\t==========================================\n");

    printf("\t\tMasukkan ID Supplier yang ingin dicari : ");

    // Masukkan ID
    fflush(stdin);
    scanf(" %[^\n]", idSupplier);

    printf("\n\n\t\tHasil Pencarian: ");
    printf("\n");

    int found = 0;
    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%lld\n", storedSupplier.id_supp, storedSupplier.nama_supp, storedSupplier.kota_supp, &storedSupplier.hp_supp) == 4)
    {
        if (strcmp(idSupplier, storedSupplier.id_supp) == 0) {
            printf("\t\tID Supplier     : %s\n", storedSupplier.id_supp);
            printf("\t\tNama Supplier   : %s\n", storedSupplier.nama_supp);
            printf("\t\tKota            : %s\n", storedSupplier.kota_supp);
            printf("\t\tNomor HP        : 0%lld\n", storedSupplier.hp_supp);
            found = 1;
            break;  // Keluar dari perulangan setelah supplier ditemukan
        }
    }

    if (!found) {
        printf("\t\tSupplier dengan ID tersebut tidak ditemukan.\n");
    }

    fclose(filePointer);
    printf("\t\tPress any key to continue . . .");
    getch();
}

void menuTransaksiBeli()
{
    int pilihan;
    do
    {
        system("cls");
        printf("\t\t==========================================\n");
        printf("\t\t         TRANSAKSI PEMBELIAN OBAT\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Tambah Transaksi\n");
        printf("\t\t2. Tampilkan Transaksi\n");
        printf("\t\t3. Kembali\n");
        printf("\t\tPilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            beli_tambah();
            break;
        case 2:
            beli_tampilkan();
            break;
        case 3:
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
            system("pause");
            menuTransaksiJual();
            break;
        }
    }
    while(pilihan!=3);
}

void beli_tambah()
{
    system("cls");
    FILE *filePointer;

    obat data_obat;
    transBeli Tdata2, storedTransaksi2;

    filePointer = fopen("dataTransaksiBeli.txt", "a+");

    printf("\n");
    printf("\t\t==========================================\n");
    printf("\t\t         TAMBAH TRANSAKSI\n");
    printf("\t\t==========================================\n");

    printf("\t\tMasukan Nomor Transaksi      = ");
    fflush(stdin);
    scanf("%d", &Tdata2.no_transaksi);

    while (fscanf(filePointer, "%d %s %s %s %d-%d-%d %d %d", &storedTransaksi2.no_transaksi, storedTransaksi2.nama_supp,
                storedTransaksi2.nama_obat, storedTransaksi2.id_obat, &storedTransaksi2.tgltransaksi.day, &storedTransaksi2.tgltransaksi.month,
                &storedTransaksi2.tgltransaksi.year, &storedTransaksi2.jml_obat, &storedTransaksi2.total_byr) != EOF)
    {
        if (storedTransaksi2.no_transaksi == Tdata2.no_transaksi)
        {
            printf("ID Transaksi sudah ada. Masukkan ID Transaksi yang lain.\n");
            printf("Masukan Nomor Transaksi     = ");
            scanf("%d", &Tdata2.no_transaksi);
        }
    }

    printf("\t\tMasukan Nama Supplier        = ");
    fflush(stdin);
    scanf(" %[^\n]", Tdata2.nama_supp);

    printf("\t\tMasukan ID Obat              = ");
    fflush(stdin);
    scanf(" %[^\n]", Tdata2.id_obat);

    printf("\t\tMasukan Nama Obat            = ");
    fflush(stdin);
    scanf(" %[^\n]", Tdata2.nama_obat);

    printf("\t\tMasukan Tanggal Transaksi (dd-mm-yyyy)     = ");
    scanf("%d-%d-%d", &Tdata2.tgltransaksi.day, &Tdata2.tgltransaksi.month, &Tdata2.tgltransaksi.year);

    printf("\t\tMasukan Jumlah Obat          = ");
    scanf("%d", &Tdata2.jml_obat);

    // Cari harga obat berdasarkan ID obat di file dataObat.txt
    FILE *fileObat;
    fileObat = fopen("dataObat.txt", "r");
    int found = 0;

    while (fscanf(fileObat, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", data_obat.id_obat, data_obat.nama_obat,
                data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, &data_obat.harga, &data_obat.stok) != EOF)
    {
        if (strcmp(Tdata2.id_obat, data_obat.id_obat) == 0)
        {
            found = 1;
            Tdata2.total_byr = data_obat.harga * Tdata2.jml_obat;
            break;
        }
    }

    fclose(fileObat);

    if (found)
    {
        fprintf(filePointer, "%d %s %s %s %02d-%02d-%04d %d %d\n", Tdata2.no_transaksi, Tdata2.nama_supp,
                Tdata2.nama_obat, Tdata2.id_obat, Tdata2.tgltransaksi.day, Tdata2.tgltransaksi.month, Tdata2.tgltransaksi.year, Tdata2.jml_obat, Tdata2.total_byr);

        printf("\t\tTransaksi berhasil ditambahkan.\n");

        // Kurangi stok obat
        tambah_stok(Tdata2.id_obat, Tdata2.jml_obat);
    }
    else
    {
        printf("\t\tObat dengan ID %s tidak ditemukan.\n", Tdata2.id_obat);
    }

    fclose(filePointer);
    getch();
}

void beli_tampilkan()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("dataTransaksiBeli.txt", "r");

    printf("\n\n\t\t\t\t\t==========================================\n");
    printf("\t\t\t\t\t\t  DAFTAR TRANSAKSI PEMBELIAN\n");
    printf("\t\t\t\t\t==========================================\n");
    printf("\n");printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-20s | %-15s | %-15s | %-10s | %-10s |\n",
           "ID TRANSAKSI", "NAMA SUPPLIER", "NAMA OBAT", "ID OBAT", "TANGGAL TRANSAKSI", "JUMLAH OBAT", "TOTAL HARGA");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");

    transBeli Tdata2;
    while (fscanf(filePointer, "%d %s %s %s %02d-%02d-%04d %d %d", &Tdata2.no_transaksi, Tdata2.nama_supp,
                Tdata2.nama_obat, Tdata2.id_obat, &Tdata2.tgltransaksi.day, &Tdata2.tgltransaksi.month, &Tdata2.tgltransaksi.year, &Tdata2.jml_obat, &Tdata2.total_byr) != EOF)
    {
    printf("| %-15d | %-20s | %-20s | %-15s | %02d-%02d-%04d        | %-10d  | %-10d |\n", Tdata2.no_transaksi, Tdata2.nama_supp,
            Tdata2.nama_obat, Tdata2.id_obat, Tdata2.tgltransaksi.day, Tdata2.tgltransaksi.month, Tdata2.tgltransaksi.year, Tdata2.jml_obat, Tdata2.total_byr);
    }


    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(filePointer);
    system("pause");
}

void tambah_stok(char id_obat[], int jumlah_obat)
{
    FILE *filepointer, *temp;
    int found = 0;

    filepointer = fopen("dataObat.txt", "r");
    temp = fopen("temp.txt", "w");

    obat data_obat;

    while (fscanf(filepointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d\n", data_obat.id_obat, data_obat.nama_obat,
                data_obat.tgl_produksi, data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, &data_obat.harga, &data_obat.stok) != EOF)
    {
        if (strcmp(id_obat, data_obat.id_obat) == 0)
        {
            found = 1;
            data_obat.stok += jumlah_obat;
        }
        fprintf(temp, "%s;%s;%s;%s;%s;%d;%d\n", data_obat.id_obat, data_obat.nama_obat, data_obat.tgl_produksi,
                data_obat.tgl_kadaluwarsa, data_obat.nomor_rak, data_obat.harga, data_obat.stok);
    }

    fclose(filepointer);
    fclose(temp);

    if (found)
    {
        remove("dataObat.txt");
        rename("temp.txt", "dataObat.txt");
        printf("\t\tStok obat telah diperbarui.\n");
    }
    else
    {
        remove("temp.txt");
        printf("\t\tProduk dengan kode %s tidak ditemukan.\n", id_obat);
    }
}

void menuCustomer()
{
    int pilihan;

    do {
        system("cls");
        printf("\n\n\t\t==========================================\n");
        printf("\t\t      MENU PENGELOLAAN DATA CUSTOMER\n");
        printf("\t\t==========================================\n");
        printf("\t\t1. Tambah Customer\n");
        printf("\t\t2. Tampilkan Customer\n");
        printf("\t\t3. Cari Customer\n");
        printf("\t\t4. Kembali\n");
        printf("\t\tPilih menu (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahCust();
                break;
            case 2:
                tampilCust();
                break;
            case 3:
                cariCust();
                break;
            case 4:
                break;
            default:
                printf("Pilihan menu tidak valid.\n");
                break;
        }
    } while (pilihan != 4);
}

void tambahCust()
{
    system("cls");
    FILE *filePointer;
    filePointer = fopen("datacustomer.txt", "a+");

    customer dataCustomer;
    customer data_Customer;
    int hp=0;

    printf("\n\n\t\t==========================================\n");
    printf("\t\t      TAMBAH DATA CUSTOMER\n");
    printf("\t\t==========================================\n");

    printf("\t\tMasukan ID Customer     = ");
    fflush(stdin);
    scanf(" %[^\n]", data_Customer.id_cust);

    while(fscanf(filePointer, "%[^;];%[^;];%[^;];%lld\n", dataCustomer.id_cust, dataCustomer.nama_cust, dataCustomer.kota_cust, &dataCustomer.hp_cust) !=EOF)
    {
        if(strcmp(data_Customer.id_cust, dataCustomer.id_cust) == 0)
        {
            printf("\t\tID Customer %s sudah digunakan!\n", data_Customer.id_cust);
            getch();
            fclose(filePointer);
            return;
        }
    }

    printf("\t\tMasukan Nama Customer   = ");
    fflush(stdin);
    scanf(" %[^\n]", data_Customer.nama_cust);

    printf("\t\tMasukan Nama Kota       = ");
    fflush(stdin);
    scanf(" %[^\n]", data_Customer.kota_cust);

    printf("\t\tMasukan Nomor HP        = ");
    fflush(stdin);
    scanf(" %lld", &data_Customer.hp_cust);

    fprintf(filePointer, "%s;%s;%s;%d%lld\n", data_Customer.id_cust, data_Customer.nama_cust, data_Customer.kota_cust, hp , data_Customer.hp_cust);

    fclose(filePointer);

    printf("\t\tCustomer berhasil ditambahkan.\n");

    getch();
}

void tampilCust()
{
    system("cls");
    FILE *filePointer;
    int totalCustomer = 0;
    int hp=0;
    filePointer = fopen("datacustomer.txt", "r"); // Membaca file

    if (filePointer == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    customer dataCustomer;

    printf("\n");printf("\n");
    printf("==============================================================================================\n");
    printf("                                      DAFTAR CUSTOMER\n");
    printf("==============================================================================================\n");

    printf("\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| ID SUPPLIER        | NAMA CUSTOMER         | NAMA KOTA            | NOMOR HANDPHONE       |\n");
    printf("----------------------------------------------------------------------------------------------\n");

    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%lld\n", dataCustomer.id_cust, dataCustomer.nama_cust, dataCustomer.kota_cust, &dataCustomer.hp_cust) == 4) {
        printf("| %-18s | %-21s | %-20s | %d%-20lld |\n", dataCustomer.id_cust, dataCustomer.nama_cust, dataCustomer.kota_cust, hp, dataCustomer.hp_cust);
        totalCustomer++; // Menghitung jumlah data_customer yang ada
    }

    printf("----------------------------------------------------------------------------------------------\n");
    printf("Jumlah total customer: %d\n", totalCustomer);
    printf("----------------------------------------------------------------------------------------------\n");

    // Menutup file
    fclose(filePointer);
    system("pause");
}

void cariCust()
{
    system("cls");
    FILE *filePointer;
    char idCustomer[20];

    customer dataCustomer;

    filePointer = fopen("datacustomer.txt", "r");
    if (filePointer == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\n\n\t\t==========================================\n");
    printf("\t\t      PENCARIAN DATA CUSTOMER\n");
    printf("\t\t==========================================\n");
    printf("\t\tMasukkan ID Customer yang ingin dicari : ");

    //Masukkan ID
    scanf("%s", idCustomer);

    printf("\n\t\tHasil Pencarian: \n\n");

    int found = 0;
    while (fscanf(filePointer, "%[^;];%[^;];%[^;];%lld\n", dataCustomer.id_cust, dataCustomer.nama_cust, dataCustomer.kota_cust, &dataCustomer.hp_cust) == 4) {
        if (strcmp(idCustomer, dataCustomer.id_cust) == 0) {
            printf("\t\tID Customer     : %s\n", dataCustomer.id_cust);
            printf("\t\tNama Customer   : %s\n", dataCustomer.nama_cust);
            printf("\t\tKota            : %s\n", dataCustomer.kota_cust);
            printf("\t\tNomor HP        : 0%lld\n", dataCustomer.hp_cust);
            found = 1;
        }
    }

    if (!found) {
        printf("\t\tCustomer dengan ID tersebut tidak ditemukan.\n");
    }

    fclose(filePointer);
    printf("\n\t\tPress any key to continue . . .");
    getch();
}


