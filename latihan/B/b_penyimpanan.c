#include <stdio.h>
#include <string.h>

/* Cocokkan identitas kendaraan, bukan hanya jumlah kendaraan. */
int cek_checkout(const char plat_petak[], const char plat_riwayat[],
                 const char harapan_petak[], const char harapan_riwayat[])
{
    printf("Petak: \"%s\" (harap \"%s\")\n", plat_petak, harapan_petak);
    printf("Riwayat: \"%s\" (harap \"%s\")\n", plat_riwayat, harapan_riwayat);
    return strcmp(plat_petak, harapan_petak) == 0 &&
           strcmp(plat_riwayat, harapan_riwayat) == 0;
}

int main(void)
{
    /* Bayangkan B 1234 ABC terparkir di A1 dan riwayat semula kosong.
       Dua argumen awal adalah contoh hasil pengamatan, bukan hasil ParkIt.
       Dua argumen terakhir adalah harapan. "" berarti kosong. */
    puts("Skenario 1: checkout dibatalkan");
    if (!cek_checkout("B 1234 ABC", "", "B 1234 ABC", ""))
        return 1;

    puts("Skenario 2: checkout dikonfirmasi");
    if (!cek_checkout("", "B 1234 ABC", "", "B 1234 ABC"))
        return 1;

    puts("Cek contoh cocok.");
    return 0;
}

/* Coba ganti argumen kedua skenario 2 menjadi "D 5678 XYZ".
   Jumlah catatan tetap satu, tetapi pengecekan harus gagal: platnya salah.
   Setelah parkit.c siap, ulangi lewat menu untuk mengecek petak dan riwayat.
   Nama file ini diwariskan; latihan ini tidak menyimpan atau membuka file. */
