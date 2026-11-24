#include <stdio.h>

int main(void)
{
    /* Mode w menulis ulang file. Nama latihan terpisah dari riwayat ParkIt. */
    FILE *berkas = fopen("latihan_riwayat.txt", "w");
    if (berkas == NULL) {
        puts("Gagal membuka file latihan.");
        return 1;
    }

    int hasil_tulis = fprintf(berkas, "B 1234 ABC | 61 menit | Rp 10000\n");
    int hasil_tutup = fclose(berkas); /* Penulisan masih bisa gagal saat ditutup. */
    if (hasil_tulis < 0 || hasil_tutup == EOF) {
        puts("Gagal menyimpan laporan lengkap.");
        return 1;
    }
    puts("Buka latihan_riwayat.txt untuk memeriksa hasil.");
    return 0;
}

/* Coba dari folder latihan kosong: buka hasil di Notepad, cocokkan satu baris.
   Lalu ubah nama tujuan ke folder yang belum ada. Harus gagal, bukan sukses.
   Di parkit.c, minta konfirmasi sebelum fopen dan cetak data dari array. */
