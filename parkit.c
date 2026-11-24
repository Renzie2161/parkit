#include <stdio.h>

/* DATA BERSAMA — A dan B koordinasikan perubahan ukuran atau arti array. */
#define JUMLAH_PETAK 8
#define UKURAN_PLAT 11
#define MAKS_RIWAYAT 20

/* Satu struct = satu checkout; jenis dan kode diturunkan dari indeks petak. */
typedef struct {
    char plat[UKURAN_PLAT];
    int petak;
    int menit;
    int biaya;
} CatatanKeluar;

/* Tiap daftar[petak] menyimpan satu plat; teks kosong berarti petak kosong.
   Indeks 0–3 = A1–A4 (mobil), 4–7 = B1–B4 (motor).
   Riwayat adalah array CatatanKeluar; akses contoh: riwayat[0].biaya.
   (void)parameter hanya menandai parameter yang belum dipakai. Hapus baris
   tersebut saat mulai memakai parameternya. Pesan belum diimplementasikan
   berarti fitur belum siap diuji. */

/* === E: TARIF ========================================================== */

/* Contoh hitung_tarif(61, 5000) menghasilkan 10000. */
int hitung_tarif(int menit, int tarif_per_jam)
{
    /* TODO E: Tolak durasi di luar 0–1440 dan tarif selain 2000/5000
       dengan hasil -1. Hitung jam dari pembagian 60 dan sisa pembagian.
       Tambah satu jam jika ada sisa; tagih minimal satu jam.
       Cek 0, 60, dan 61 menit sebelum menyambungkan ke fungsi keluar. */
    (void)menit;
    (void)tarif_per_jam;
    return -1;
}

/* === D: DENAH DAN PENCARIAN ============================================ */

/* Mulai dengan petak = 0. Kembalikan indeks hasil, atau -1 jika tidak ada. */
int cari_plat(char daftar[][UKURAN_PLAT], const char plat[], int petak)
{
    /* TODO D: Jika petak sudah mencapai JUMLAH_PETAK, berhenti dengan -1.
       Bandingkan isi daftar[petak] dengan plat memakai strcmp.
       Jika cocok, kembalikan petak. Jika tidak, panggil fungsi ini lagi
       dari petak + 1 dan kembalikan hasilnya. Jangan urutkan array petak.
       Coba target pada indeks 0, indeks 7, dan target yang tidak ada. */
    (void)daftar;
    (void)plat;
    (void)petak;
    return -1;
}

void tampilkan_denah(char daftar[][UKURAN_PLAT])
{
    /* TODO D: Cetak satu baris mobil dan satu baris motor. Pakai for untuk
       membaca empat petak di tiap baris. Tampilkan kode dan statusnya,
       misalnya [A1 X] dan [A2 -]. Jangan ubah isi daftar. */
    (void)daftar;
    puts("Denah belum diimplementasikan.");
}

void tampilkan_daftar_urut(char daftar[][UKURAN_PLAT])
{
    /* TODO D: Buat array indeks petak aktif dan urutkan berdasarkan plat.
       Contoh: Z di A1 dan B di A2 menghasilkan urutan A2, A1.
       Geser indeks, bukan isi daftar, agar lokasi kendaraan tidak berubah. */
    (void)daftar;
    puts("Pengurutan belum diimplementasikan.");
}

/* === C: MENU DAN TAMPILAN ============================================== */

void tampilkan_menu(char daftar[][UKURAN_PLAT])
{
    /* TODO C: Hitung petak yang teksnya kosong (daftar[petak][0] == '\0').
       Cetak ringkasan terisi/kosong dan menu. Susunan teks bebas;
       pertahankan nomor pilihan agar cocok dengan main(). */
    (void)daftar;
    puts("\n1. Masuk  2. Keluar  3. Cari  4. Denah  5. Riwayat");
    puts("6. Urut plat  7. Ekspor riwayat  0. Tutup");
}

/* Kembalikan 0 pada EOF; -1 pada input yang bukan satu pilihan sah. */
int baca_pilihan(void)
{
    /* TODO C: Gunakan fgets. Terima hanya satu angka 0–7 dalam satu baris.
       Jika baris terlalu panjang, buang sisanya sampai newline atau EOF.
       Coba huruf, baris kosong, 12, dan EOF. Untuk saat ini starter hanya
       menjamin tombol 0; jangan menyatakan pembaca sudah selesai. */
    char masukan[16];
    printf("Pilihan: ");
    if (fgets(masukan, sizeof masukan, stdin) == NULL)
        return 0;
    if (masukan[0] == '0' && (masukan[1] == '\n' || masukan[1] == '\0'))
        return 0;
    return -1;
}

void tampilkan_hasil_cari(const char plat[], int petak)
{
    /* TODO C: Jika petak == -1, tampilkan tidak ditemukan. Jika ditemukan,
       tampilkan plat, jenis (indeks < 4 berarti mobil), dan kode petak.
       Contoh: plat B 1234 ABC pada indeks 2 berarti Mobil, A3. */
    (void)plat;
    (void)petak;
    puts("Tampilan hasil cari belum diimplementasikan.");
}

void cetak_riwayat(FILE *tujuan, const CatatanKeluar riwayat[], int jumlah)
{
    /* TODO C: Jika jumlah == 0, tampilkan pesan riwayat kosong. Jika tidak,
       baca plat, petak, menit dan biaya dari tiap CatatanKeluar.
       Pakai fprintf(tujuan, ...) agar layar dan ekspor berbagi format. */
    (void)tujuan;
    (void)riwayat;
    (void)jumlah;
    fprintf(tujuan, "Tampilan riwayat belum diimplementasikan.\n");
}

/* === A: PLAT DAN TRANSAKSI ============================================== */

/* Isi buffer plat pada sukses (1); kembalikan 0 pada batal atau input salah. */
int baca_plat(char plat[])
{
    /* TODO A: Baca satu baris ke buffer sementara. Buang newline, bukan
       spasi pemisah. Format tepat 10 karakter: huruf di posisi 0 dan 7–9,
       spasi di 1 dan 6, angka di 2–5. Ubah huruf kecil jadi kapital.
       Contoh b 1234 abc -> B 1234 ABC. Isi plat hanya jika seluruhnya sah.
       Tolak input terlalu panjang dan buang sisa baris sebelum kembali. */
    (void)plat;
    puts("Pembaca plat belum diimplementasikan.");
    return 0;
}

void kendaraan_masuk(char daftar[][UKURAN_PLAT])
{
    /* TODO A:
       1. Baca plat; bila gagal atau hasil cari_plat(..., 0) bukan -1, berhenti.
       2. Minta jenis, tampilkan denah D, lalu minta kode petak atau 0 (batal).
       3. Ubah kode yang sah ke indeks: A3 -> 2, B2 -> 5. Tolak jenis yang
          tidak cocok dan petak terisi; minta pilih lagi tanpa mengubah data.
       4. Salin plat ke daftar[petak] hanya setelah semua cek lulus. */
    (void)daftar;
    puts("Kendaraan masuk belum diimplementasikan.");
}

/* Kembalikan jumlah catatan baru, atau jumlah lama ketika batal/gagal. */
int kendaraan_keluar(char daftar[][UKURAN_PLAT],
                     CatatanKeluar riwayat[], int jumlah)
{
    /* TODO A:
       1. Baca plat dan cari indeksnya. Berhenti bila tidak ditemukan.
       2. Baca durasi dalam menit. Panggil hitung_tarif milik E (mobil
          Rp5000/jam, motor Rp2000/jam); tampilkan biaya sebelum konfirmasi.
       3. Jika disetujui, isi tiap field pada satu CatatanKeluar.
          Saat penuh, geser catatan ke kiri supaya catatan terlama keluar.
       4. Setelah mencatat, kosongkan plat dengan daftar[petak][0] = '\0'.
          Jika batal, jangan ubah daftar maupun riwayat. */
    (void)daftar;
    (void)riwayat;
    puts("Kendaraan keluar belum diimplementasikan.");
    return jumlah;
}

/* === B + A: INTEGRASI DAN VERIFIKASI ==================================== */

void ekspor_riwayat(const CatatanKeluar riwayat[], int jumlah)
{
    /* TODO B: Minta konfirmasi sebelum menimpa riwayat.txt. Buka file
       dengan fopen mode w, periksa NULL, lalu panggil cetak_riwayat.
       Periksa ferror dan fclose sebelum mengumumkan sukses.
       Uji batal tanpa mengubah file, isi laporan, dan gagal membuka file. */
    (void)riwayat;
    (void)jumlah;
    puts("Ekspor riwayat belum diimplementasikan.");
}

int main(void)
{
    char daftar[JUMLAH_PETAK][UKURAN_PLAT] = {0};
    CatatanKeluar riwayat[MAKS_RIWAYAT];
    int jumlah_riwayat = 0;

    /* TODO B + A: Setelah fungsi anggota siap, uji satu alur pada satu waktu:
       masuk -> cari -> keluar batal -> keluar setuju -> lihat riwayat.
       Jangan menambah main() kedua. Jaga urutan dan parameter tiap panggilan. */
    puts("ParkIt | Starter kelompok");
    while (1) {
        tampilkan_menu(daftar);
        int pilihan = baca_pilihan();
        if (pilihan == 0 || feof(stdin) || ferror(stdin))
            break;

        /* TODO B + A: Sambungkan pilihan 1 ke kendaraan_masuk, 2 ke
           kendaraan_keluar (simpan jumlah kembaliannya), 3 ke baca_plat,
           cari_plat dan tampilkan_hasil_cari, 4 ke tampilkan_denah, dan
           5 ke cetak_riwayat(stdout, ...), 6 ke tampilkan_daftar_urut,
           dan 7 ke ekspor_riwayat. Aktifkan tiap pilihan saat fungsi siap. */
        puts("Pilihan belum tersedia. Ketik 0 untuk keluar.");
    }
    /* Dua nilai di bawah mulai dipakai saat checkout dan riwayat terhubung. */
    (void)riwayat;
    (void)jumlah_riwayat;
    return 0;
}
