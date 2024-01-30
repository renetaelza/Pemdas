#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

struct tanggal
{
    int day;
    int month;
    int year;
};

typedef struct //struct admin
{
    int  kode_admin;
    char nama_admin[50];
    char username[20];
    char password[20];
} Admin;

Admin dataAdmin; //variabel global

typedef struct //struct obat
{
    char id_obat[15];
    char nama_obat[100];
    char nomor_rak[50];
    char tgl_produksi[50];
    char tgl_kadaluwarsa[50];
    int harga;
    int  stok;
} obat;

obat data_obat, storedObat; // variabel global

typedef struct //struct supplier
{
    char id_supp[50];
    char nama_supp[50];
    char kota_supp[50];
    long long hp_supp;
} supplier;

supplier dataSupplier, storedSupplier;

typedef struct //struct cust
{
    char id_cust[50];
    char nama_cust[50];
    char kota_cust[50];
    long long hp_cust;
} customer;

typedef struct //struct transaksi jual
{
    int no_transaksi;
    char nama_cust[50];
    char nama_obat[50];
    char id_obat[15];
    struct tanggal tgl_transaksi;
    int jml_obat;
    int total_byr;
} transJual;

transJual Tdata1, storedTransaksi1; // var global

typedef struct //struct transaksi beli
{
    int no_transaksi;
    char nama_supp[50];
    char nama_obat[50];
    char id_obat[15];
    struct tanggal tgltransaksi;
    int jml_obat;
    int total_byr;
} transBeli;

transBeli Tdata2, storedTransaksi2;

void daftarAdmin();
void login();
void masukMenu();
void copyNama();
int cekUsername();
int cekID();
int cekLogin();

void menuObat();
void tambahObat();
void tampilObat();
void editObat();
void cariObat();
void hapusObat();

void menuTransaksiJual();
void jual_tambah();
void jual_tampilkan();
void kurangi_stok();

void menuLaporanJual();
void laporanTanggal();
void laporanKeseluruhan();

void menuLaporanBeli();
void laporanTanggal1();
void laporanKeseluruhan1();

void tambahSupplier();
void tampilSupplier();
void cariSupplier();

void menuTransaksiBeli();
void beli_tambah();
void beli_tampilkan();
void tambah_stok();

void menuCustomer();
void tambahCust();
void tampilCust();
void cariCust();

#endif // HEADER_H_INCLUDED
