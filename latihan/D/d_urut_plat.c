#include <stdio.h>
#include <string.h>

/* Tukar indeks, bukan data plat: kode petak tetap mengikuti plat aslinya. */
void urutkan_petak(char plat[][11], int urutan[], int jumlah)
{
    for (int putaran = 0; putaran < jumlah - 1; putaran++) {
        for (int posisi = 0; posisi < jumlah - 1 - putaran; posisi++) {
            int kiri = urutan[posisi];
            int kanan = urutan[posisi + 1];
            if (strcmp(plat[kiri], plat[kanan]) > 0) {
                urutan[posisi] = kanan;
                urutan[posisi + 1] = kiri;
            }
        }
    }
}

int main(void)
{
    char plat[3][11] = {"Z 1234 ABC", "B 5678 XYZ", "D 1111 AAA"};
    int urutan[3] = {0, 1, 2};
    urutkan_petak(plat, urutan, 3);
    for (int posisi = 0; posisi < 3; posisi++) {
        int petak = urutan[posisi];
        printf("%s | A%d\n", plat[petak], petak + 1);
    }
    return 0;
}

/* Hasil awal: B di A2, D di A3, Z di A1. Coba kosongkan plat A2.
   Jangan masukkan indeks petak kosong ke urutan. Hasil baru: D lalu Z.
   Di parkit.c, boleh memakai bubble sort ini atau algoritma urut lain. */
