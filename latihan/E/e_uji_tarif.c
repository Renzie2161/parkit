#include <stdio.h>

/* Jam sudah dibulatkan latihan sebelumnya; latihan ini fokus ke rupiah. */
int biaya_parkir(int jam, int jenis)
{
    if (jenis == 1)
        return jam * 5000; /* Mobil. */
    if (jenis == 2)
        return jam * 2000; /* Motor. */
    return -1;
}

int main(void)
{
    int jam[] = {1, 2, 2};
    int jenis[] = {1, 2, 9};
    int harapan[] = {5000, 4000, -1};
    int gagal = 0;

    for (int kasus = 0; kasus < 3; kasus++) {
        int hasil = biaya_parkir(jam[kasus], jenis[kasus]);
        printf("%d jam, jenis %d: hasil %d, harapan %d\n",
               jam[kasus], jenis[kasus], hasil, harapan[kasus]);
        if (hasil != harapan[kasus])
            gagal++;
    }
    printf("Kasus gagal: %d\n", gagal);
    return gagal != 0;
}

/* Coba: ubah tarif motor ke 3000 tanpa mengubah harapan, lalu jalankan.
   Satu kasus harus gagal. Kembalikan tarif dan cek semua lulus.
   Di parkit.c, uji hitung_tarif dengan durasi 0, 60 dan 61 menit. */
