# ParkIt

Proyek akhir Dasar Pemrograman C. Aplikasi inti kelompok dikerjakan di **`parkit.c`**: satu file, satu `main()`, fungsi biasa, array, dan tampilan ASCII.

## Mulai

Pasang Git dan GCC. Dari root, kompilasi starter lalu jalankan:

```powershell
gcc -Wall -Wextra -Wpedantic parkit.c -o parkit.exe
.\parkit.exe
```

Starter berisi kerangka fungsi A–E, bukan aplikasi selesai. Menu bisa dibuka dan `0` menutupnya; pilihan lain belum disambungkan. Tidak perlu Makefile. Untuk pemanasan, pilih file di `latihan/` sesuai hurufmu. Contoh untuk C:

```powershell
gcc -Wall -Wextra -Wpedantic latihan/C/c_menu.c -o latihan.exe
.\latihan.exe
```

Setelah latihan, buka `parkit.c`, cari komentar `===` sesuai hurufmu, dan mulai dari satu fungsi. Ubah badan fungsi, bukan tanda tangannya, kecuali sudah sepakat dengan pemanggil. A dan B menyambungkan fungsi ke `main()` setelah siap.

| Anggota | Urutan latihan | Lanjut di `parkit.c` |
|---|---|---|
| A | [`a_parkir.c`](latihan/A/a_parkir.c): pilih petak → [`a_struct_riwayat.c`](latihan/A/a_struct_riwayat.c): isi dan baca array struct. | Validasi plat, transaksi, isi `struct CatatanKeluar`. |
| B | [`b_penyimpanan.c`](latihan/B/b_penyimpanan.c): cek checkout batal/setuju → [`b_ekspor.c`](latihan/B/b_ekspor.c): tulis dan periksa file teks. | Integrasi, ekspor `riwayat.txt`, verifikasi hasil. |
| C | [`c_menu.c`](latihan/C/c_menu.c): baca pilihan → [`c_kolom.c`](latihan/C/c_kolom.c): ratakan kolom ASCII. | Menu dan format riwayat untuk layar dan file. |
| D | [`d_denah.c`](latihan/D/d_denah.c): denah dan rekursi → [`d_urut_plat.c`](latihan/D/d_urut_plat.c): urutkan plat lewat indeks. | Denah, pencarian rekursif, pengurutan tanpa memindahkan kendaraan. |
| E | [`e_tarif.c`](latihan/E/e_tarif.c): bulatkan durasi → [`e_uji_tarif.c`](latihan/E/e_uji_tarif.c): cek biaya mobil, motor, dan jenis salah. | Tarif rupiah sesuai jenis kendaraan. |

Kompilasi **satu file latihan sekali jalan**; tiap file punya `main()`. Jalankan contoh dulu, lalu ikuti bagian `Coba` di komentar sebelum mulai mengedit `parkit.c`. Semua latihan bisa dikerjakan tanpa menunggu anggota lain.

Kerjakan fungsi di cabang sendiri. Koordinasikan perubahan `parkit.c` dengan A dan B agar tidak menulis ulang bagian yang sama. Jangan salin solusi lokal `project_jadi/`.

**Target demo:** pilih petak sesuai jenis, cari kendaraan, urutkan plat (6), batalkan lalu konfirmasi keluar, dan ekspor riwayat (7). Ekspor membuat laporan teks, bukan save/load. Booking, denda, jam simulasi, save/load, serta ANSI/Unicode tetap bonus.

### Verifikasi di Windows

```powershell
.\test.bat C
.\test.bat all
```

Ganti `C` dengan huruf tugasmu. `all` (atau tanpa argumen) menjalankan semua latihan dan cek bahwa starter dapat membuka serta menutup menu. Runner memakai GCC dan folder sementara. `LULUS cek awal` berarti kompilasi dan eksekusi berhasil, bukan seluruh fitur aplikasi selesai. Untuk pekerjaan di `parkit.c`, tetap jalankan [skenario verifikasi](PERUBAHAN_PARKIT.md#perintah-dan-bukti-demo) dan catat hasil aktual.

**Uji fitur baru:** masukkan `Z 1234 ABC` di A1 lalu `B 1234 ABC` di A2. Pilihan 6 harus menampilkan B lebih dulu; pilihan 3 harus tetap menemukan B di A2. Batalkan checkout B: riwayat tidak bertambah. Ulangi dengan konfirmasi dan durasi 61 menit: riwayat berisi B, A2, dan Rp10.000. Pilihan 7 lalu `1` harus menulis data yang sama ke `riwayat.txt`; ulangi dengan `0` dan pastikan file tidak berubah.

## Contoh UI (tidak wajib ditiru)

Contoh setelah satu mobil masuk. C boleh mengubah bingkai, susunan, dan kata-kata. Pertahankan arti pilihan yang disepakati, tampilkan status secara jelas tanpa warna, dan beri petunjuk saat input salah atau bisa dibatalkan.

```text
+-----------------------------------------+
| PARKIT                                  |
| Kapasitas: 8   Terisi: 1   Kosong: 7      |
| 1. Masuk         2. Keluar               |
| 3. Cari          4. Denah                |
| 5. Riwayat       0. Tutup                |
+-----------------------------------------+
Pilihan: 4

Mobil  [A1 -] [A2 -] [A3 X] [A4 -]
Motor  [B1 -] [B2 -] [B3 -] [B4 -]
Indikator: - kosong, X terisi

Contoh hasil cari: B 1234 ABC | Mobil | A3
Setelah checkout:  B 1234 ABC | Mobil | A3 | 61 menit | Rp 10000
```

## Git singkat

```sh
git clone https://github.com/Renzie2161/parkit.git
cd parkit
git pull --ff-only
git switch -c feat/c-ui
```

Ganti `feat/c-ui` dengan branch tugasmu. Setelah edit dan tes, contoh untuk C:

```sh
git status
git add parkit.c
git diff --staged
git commit -m "feat(ui): lengkapi input menu"
git push -u origin feat/c-ui
```

Buka Pull Request ke branch utama. Sertakan hasil tes dan dependensi yang belum siap. Jangan push langsung ke branch utama atau ikutkan `build/`, `data/`, dan `project_jadi/`.

[Catatan revisi dan panduan penyesuaian Word](PERUBAHAN_PARKIT.md)
