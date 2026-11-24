@echo off
setlocal
if not "%~2"=="" goto penggunaan
set "pilihan=%~1"
if not defined pilihan set "pilihan=all"
set "valid="
for %%A in (A B C D E all) do if /i "%pilihan%"=="%%A" set "valid=1"
if not defined valid goto penggunaan
where gcc >nul 2>&1
if errorlevel 1 (
    echo GCC tidak ditemukan. Pasang GCC dan periksa PATH, lalu buka terminal baru.
    goto kesalahan
)
set "kerja=%TEMP%\parkit-test-%RANDOM%-%RANDOM%"
mkdir "%kerja%" || goto kesalahan
pushd "%kerja%" || goto kesalahan
set "gagal=0"
for %%A in (A B C D E) do (
    if /i "%pilihan%"=="all" call :uji_anggota %%A
    if /i "%pilihan%"=="%%A" call :uji_anggota %%A
)
if /i "%pilihan%"=="all" (
    echo.
    echo [Starter] Kompilasi dan buka menu, lalu pilih 0.
    >masukan.txt echo 0
    call :uji_file "%~dp0parkit.c"
)
popd
rmdir /s /q "%kerja%"
echo.
if "%gagal%"=="1" (
    echo GAGAL. Lihat pesan di atas.
    call :tahan_jendela
    exit /b 1
)
echo LULUS cek awal. Untuk fitur proyek, lanjutkan skenario uji di README.md.
call :tahan_jendela
exit /b 0

:uji_anggota
>masukan.txt (
    if /i "%~1"=="C" (
        echo 4
        echo 5
    )
    echo 0
)
if not exist "%~dp0latihan\%~1\*.c" (
    echo Folder latihan %~1 kosong atau tidak ditemukan.
    set "gagal=1"
    exit /b
)
for %%F in ("%~dp0latihan\%~1\*.c") do call :uji_file "%%~fF"
exit /b

:uji_file
echo.
echo [Cek] %~nx1
gcc -Wall -Wextra -Wpedantic -Werror "%~1" -o cek.exe
if not errorlevel 1 cek.exe <masukan.txt
if errorlevel 1 (
    set "gagal=1"
    echo GAGAL: %~nx1
)
exit /b

:penggunaan
echo Penggunaan: test.bat [A^|B^|C^|D^|E^|all]
:kesalahan
call :tahan_jendela
exit /b 2

:tahan_jendela
echo.
echo Tekan tombol apa saja untuk menutup hasil cek.
pause >nul
exit /b
