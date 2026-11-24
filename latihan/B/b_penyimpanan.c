#include <stdio.h>

/* Membandingkan data sebelum dan sesudah percobaan checkout. */
int cek_checkout(int terisi, int jumlah, int harapan_terisi, int harapan_jumlah)
{
    printf("Terisi: %d (harap %d), riwayat: %d (harap %d)\n",
           terisi, harapan_terisi, jumlah, harapan_jumlah);
    return terisi == harapan_terisi && jumlah == harapan_jumlah;
}

int main(void)
{
    /* Data contoh untuk belajar memeriksa hasil, bukan menjalankan transaksi. */
    puts("Skenario 1: checkout batal");
    if (!cek_checkout(1, 0, 1, 0))
        return 1;

    puts("Skenario 2: checkout setuju");
    if (!cek_checkout(0, 1, 0, 1))
        return 1;

    puts("Cek contoh cocok.");
    return 0;
}

/* Langkah berikutnya:
 * 1. Ganti salah satu nilai aktual; pastikan pengecekan mengembalikan gagal.
 * 2. Saat parkit.c siap, coba dua skenario di atas dari menu dan catat hasilnya.
 * 3. Tambah kasus plat salah, petak penuh, dan pencarian tidak ditemukan.
 *    Simpan/muat data adalah bonus; latihan inti B tidak membuka file data.
 */
