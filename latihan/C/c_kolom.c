#include <stdio.h>

/* %-10s meratakan teks ke kiri dalam kolom minimal 10 karakter. */
void cetak_baris(const char plat[], int menit)
{
    printf("| %-10s | %5d |\n", plat, menit);
}

int main(void)
{
    puts("+------------+-------+");
    puts("| Plat       | Menit |");
    puts("+------------+-------+");
    cetak_baris("B 1234 ABC", 0);
    cetak_baris("D 5678 XYZ", 61);
    puts("+------------+-------+");
    return 0;
}

/* Coba: tambah kolom biaya dan satu baris berisi 1440 menit.
   Hasil: garis | tetap sejajar dengan judul. Bentuk tabel boleh diubah.
   Di parkit.c, pakai data riwayat dari array, bukan contoh tetap. */
