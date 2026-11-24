#include <stdio.h>

/* Cari indeks kosong pertama hanya di blok kendaraan yang sesuai. */
int cari_petak_kosong(int terisi[], int jenis)
{
    if (jenis != 1 && jenis != 2)
        return -1;

    int awal = (jenis - 1) * 4;
    for (int petak = awal; petak < awal + 4; petak++) {
        if (terisi[petak] == 0)
            return petak;
    }
    return -1;
}

int main(void)
{
    int terisi[8] = {1, 0, 1, 1, 0, 1, 1, 1};
    int petak = cari_petak_kosong(terisi, 1);
    if (petak != 1 || cari_petak_kosong(terisi, 2) != 4)
        return 1;

    printf("Petak mobil kosong: A%d (indeks %d)\n", petak + 1, petak);
    terisi[petak] = 1;
    if (cari_petak_kosong(terisi, 1) != -1)
        return 1;
    puts("Blok mobil sekarang penuh.");
    return 0;
}

/* Langkah berikutnya:
 * 1. Ubah satu nilai array dan tebak indeks hasilnya.
 * 2. Fungsi ini hanya mendeteksi apakah blok masih punya tempat kosong.
 *    Di ParkIt, indeks hasil bukan pilihan akhir: operator memilih kode petak.
 * 3. Coba A2 untuk motor: tolak karena bloknya salah, meskipun A2 kosong.
 *    Di kendaraan_masuk, cek juga petak terisi dan plat ganda sebelum mencatat.
 */
