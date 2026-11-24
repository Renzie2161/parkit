#include <stdio.h>
#include <string.h>

/* Cari plat dari indeks petak saat ini. String kosong menandai petak kosong. */
int cari_plat(const char daftar[][11], int jumlah, const char target[], int petak)
{
    if (petak >= jumlah)
        return -1;
    if (daftar[petak][0] != '\0' && strcmp(daftar[petak], target) == 0)
        return petak;
    return cari_plat(daftar, jumlah, target, petak + 1);
}

int main(void)
{
    const char kode[][3] = {"A1", "A2", "B1", "B2"};
    const char daftar[][11] = {"B 1234 ABC", "", "", "D 5678 XYZ"};
    for (int petak = 0; petak < 4; petak++)
        printf("[%s %c] ", kode[petak], daftar[petak][0] == '\0' ? '-' : 'X');
    puts("\n- kosong, X terisi");

    int hasil = cari_plat(daftar, 4, "D 5678 XYZ", 0);
    if (cari_plat(daftar, 4, "B 1234 ABC", 0) != 0 || hasil != 3 ||
        cari_plat(daftar, 4, "Z 1111 AAA", 0) != -1 ||
        cari_plat(daftar, 4, "", 0) != -1)
        return 1;
    printf("D 5678 XYZ terparkir di %s (indeks %d).\n", kode[hasil], hasil);
    return 0;
}

/* Coba pindahkan D 5678 XYZ dari B2 ke B1: kosongkan B2 dan ubah
   harapan indeks dari 3 ke 2. Denah dan hasil cari harus ikut berubah.
   ParkIt punya 8 petak; gunakan JUMLAH_PETAK, bukan angka 4 dari contoh. */
