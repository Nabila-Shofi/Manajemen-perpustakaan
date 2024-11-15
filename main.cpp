#include <iostream>
#include <string>

#include "Anggota.h"
#include "Buku.h"
#include "Perpustakaan.h"
using namespace std;

int main() {
    Perpustakaan perpustakaan;
    perpustakaan.muatData();

    int pilihan;

    do {
        cout << "\n=====Pelayanan Perpustakaan=====\n";
        cout << "1. Menambah daftar buku\n";
        cout << "2. Daftar menjadi anggota \n";
        cout << "3. Meminjam buku\n";
        cout << "4. Mengembalikan buku\n";
        cout << "5. Daftar buku tersedia\n";
        cout << "6. Informasi anggota\n";
        cout << "7. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string judul, pengarang, ISBN;
                int tahunTerbit;

                cout << "\nJudul buku: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Nama pengarang buku: ";
                getline(cin, pengarang);
                cout << "Tahun terbit: ";
                cin >> tahunTerbit;
                cout << "No ISBN: ";
                cin >> ISBN;

                Buku buku(judul, pengarang, tahunTerbit, ISBN);
                perpustakaan.tambahBuku(buku);
                break;
            }

            case 2: {
                string nama, alamat;
                int nomorAnggota;

                cout << "\nNama Lengkap: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Nomor Anggota: ";
                cin >> nomorAnggota;
                cout << "Alamat Tinggal Saat Ini: ";
                cin.ignore();
                getline(cin, alamat);

                Anggota anggota(nama, nomorAnggota, alamat);
                perpustakaan.tambahAnggota(anggota);
                break;
            }

            case 3: {
                int nomorAnggota;
                string judulBuku;

                cout << "\nNomor anggota: ";
                cin >> nomorAnggota;
                cout << "Judul buku yang ingin dipinjam: ";
                cin.ignore();
                getline(cin, judulBuku);

                perpustakaan.pinjamBuku(nomorAnggota, judulBuku);
                break;
            }

            case 4: {
                int nomorAnggota;
                string judulBuku;

                cout << "\nNomor anggota: ";
                cin >> nomorAnggota;
                cout << "Judul buku yang dikembalikan: ";
                cin.ignore();
                getline(cin, judulBuku);

                perpustakaan.kembalikanBuku(nomorAnggota, judulBuku);
                break;
            }

            case 5: {
                perpustakaan.daftarBukuTersedia();
                break;
            }

            case 6: {
                int nomorAnggota;

                cout << "\nNomor anggota: ";
                cin >> nomorAnggota;

                perpustakaan.tampilkanInfoAnggota(nomorAnggota);
                break;
            }

            case 7: {
                perpustakaan.simpanData();
                cout << "Terimakasih telah menggunakan sistem perpustakaan\n";
                break;
            }

            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}
