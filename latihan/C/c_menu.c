#include <stdio.h>

/* -1: salah, 0: tutup/EOF, 4 dan 5: pilihan demo. */
int baca_pilihan(void)
{
    char baris[16] = {0};
    if (fgets(baris, sizeof baris, stdin) == NULL)
        return 0;
    if (baris[1] != '\n' && baris[1] != '\0') {
        int posisi = 0;
        while (baris[posisi] != '\0' && baris[posisi] != '\n')
            posisi++;
        if (baris[posisi] == '\0') {
            int karakter;
            do {
                karakter = getchar();
            } while (karakter != '\n' && karakter != EOF);
        }
        return -1;
    }
    if (baris[0] == '0' || baris[0] == '4' || baris[0] == '5')
        return baris[0] - '0';
    return -1;
}

int main(void)
{
    puts("ParkIt | Contoh menu");
    while (1) {
        puts("4. Denah  5. Riwayat  0. Tutup");
        printf("Pilihan: ");
        int pilihan = baca_pilihan();
        if (pilihan == 0)
            break;
        if (pilihan == 4)
            puts("Contoh denah: [A1 -] [A2 X]");
        else if (pilihan == 5)
            puts("Belum ada catatan keluar.");
        else
            puts("Pilih 4, 5, atau 0.");
    }
    return 0;
}

/* Coba 45, teks panjang, 4, 5, lalu 0. Angka 45 bukan pilihan 4.
   Di parkit.c, lengkapi 0–5. Tampilan contoh boleh didesain ulang. */
