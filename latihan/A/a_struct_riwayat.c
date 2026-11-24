#include <stdio.h>

/* Satu Catatan menyimpan data satu kendaraan yang sudah keluar. */
typedef struct {
    char plat[11];
    int menit;
    int biaya;
} Catatan;

int main(void)
{
    Catatan riwayat[3] = {{"B 1234 ABC", 61, 10000}, {"D 5678 XYZ", 20, 2000}};
    int jumlah = 2; /* Satu tempat masih tersedia. */

    for (int baris = 0; baris < jumlah; baris++)
        printf("%s | %d menit | Rp %d\n", riwayat[baris].plat,
               riwayat[baris].menit, riwayat[baris].biaya);
    return 0;
}

/* Coba: isi catatan ketiga sebelum loop, lalu naikkan jumlah menjadi 3.
   Hasil: plat baru muncul di baris terakhir. Tambahkan field int petak
   dan cetak nilainya. Di parkit.c, isi catatan hanya setelah checkout disetujui. */
