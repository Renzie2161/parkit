#include <stdio.h>
#include <string.h>

/* Cari mulai dari indeks petak; jumlah adalah banyak baris dalam daftar. */
int cari_kode(const char daftar[][3], int jumlah, const char target[], int petak)
{
    if (petak == jumlah)
        return -1;
    if (strcmp(daftar[petak], target) == 0)
        return petak;
    return cari_kode(daftar, jumlah, target, petak + 1);
}

int main(void)
{
    const char kode[][3] = {"A1", "A2", "B1", "B2"};
    int terisi[] = {0, 1, 0, 1};
    for (int petak = 0; petak < 4; petak++)
        printf("[%s %c] ", kode[petak], terisi[petak] ? 'X' : '-');
    puts("\n- kosong, X terisi");

    int hasil = cari_kode(kode, 4, "B2", 0);
    printf("Kode B2 berada di indeks %d.\n", hasil);
    if (cari_kode(kode, 4, "A1", 0) != 0 || hasil != 3 ||
        cari_kode(kode, 4, "C1", 0) != -1)
        return 1;
    return 0;
}

/* Di parkit.c, array berisi plat, bukan kode. Ubah nilai yang dibandingkan
   dan pakai JUMLAH_PETAK sebagai batas. Mulai rekursi dari indeks 0. */
