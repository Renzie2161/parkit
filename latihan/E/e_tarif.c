#include <stdio.h>

/* Contoh pembulatan durasi tanpa uang atau jam sistem. */
int jam_tagihan(int menit)
{
    if (menit < 0 || menit > 1440)
        return -1;
    if (menit == 0)
        return 1;
    return (menit + 59) / 60;
}

int main(void)
{
    int durasi[] = {0, 60, 61};
    int harapan[] = {1, 1, 2};
    for (int contoh = 0; contoh < 3; contoh++) {
        int jam = jam_tagihan(durasi[contoh]);
        printf("%d menit -> %d jam (harap %d)\n",
               durasi[contoh], jam, harapan[contoh]);
        if (jam != harapan[contoh])
            return 1;
    }
    if (jam_tagihan(-1) != -1 || jam_tagihan(1441) != -1)
        return 1;
    return 0;
}

/* Di hitung_tarif pada parkit.c, kalikan jam dengan Rp2000 atau Rp5000
   sesuai jenis. Contoh: mobil 61 menit -> 2 x 5000 = Rp10000. */
