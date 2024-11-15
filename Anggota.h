#ifndef ANGGOTA_H
#define ANGGOTA_H

#include <iostream>
#include <string>
#include <vector>

#include "Buku.h"
using namespace std;

class Anggota {
   private:
    string nama;
    int nomorAnggota;
    string alamat;
    vector<Buku> daftarPinjaman;

   public:
    Anggota(string nama, int nomorAnggota, string alamat)
        : nama(nama), nomorAnggota(nomorAnggota), alamat(alamat) {}

    string getNama() const { return nama; }
    int getNomorAnggota() const { return nomorAnggota; }
    string getAlamat() const { return alamat; }

    void tampilkanInfoAnggota() const {
        cout << "Nama: " << nama << endl;
        cout << "Nomor Anggota: " << nomorAnggota << endl;
        cout << "Alamat: " << alamat << endl;

        if (daftarPinjaman.empty()) {
            cout << "Tidak ada buku yang dipinjam." << endl;
        } else {
            cout << "Buku yang dipinjam:" << endl;
            for (const auto& buku : daftarPinjaman) {
                cout << "- " << buku.getJudul() << endl;
            }
        }
    }

    void pinjamBuku(Buku& buku) {
        daftarPinjaman.push_back(buku);
    }

    void kembalikanBuku(const string& judulBuku) {
        for (auto it = daftarPinjaman.begin(); it != daftarPinjaman.end(); ++it) {
            if (it->getJudul() == judulBuku) {
                daftarPinjaman.erase(it);
                break;
            }
        }
    }
};

#endif
