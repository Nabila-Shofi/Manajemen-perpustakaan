#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Anggota.h"
#include "Buku.h"
using namespace std;

class Perpustakaan {
   private:
    vector<Buku> daftarBuku;
    vector<Anggota> daftarAnggota;

   public:
    void tambahBuku(const Buku& buku) {
        daftarBuku.push_back(buku);
    }

    void tambahAnggota(const Anggota& anggota) {
        daftarAnggota.push_back(anggota);
    }

    void daftarBukuTersedia() const {
        for (const auto& buku : daftarBuku) {
            if (buku.getStatus()) {
                buku.tampilkanInfoBuku();
                cout << endl;
            }
        }
    }

    void pinjamBuku(int nomorAnggota, const string& judulBuku) {
        Anggota* anggota = nullptr;
        Buku* buku = nullptr;

        for (auto& a : daftarAnggota) {
            if (a.getNomorAnggota() == nomorAnggota) {
                anggota = &a;
                break;
            }
        }

        for (auto& b : daftarBuku) {
            if (b.getJudul() == judulBuku && b.getStatus()) {
                buku = &b;
                break;
            }
        }

        if (anggota && buku) {
            anggota->pinjamBuku(*buku);
            buku->setStatus(false);
            cout << "Buku '" << judulBuku << "' berhasil dipinjam." << endl;
        } else {
            cout << "Buku sedang dipinjam." << endl;
        }
    }

    void kembalikanBuku(int nomorAnggota, const string& judulBuku) {
        Anggota* anggota = nullptr;
        Buku* buku = nullptr;

        for (auto& a : daftarAnggota) {
            if (a.getNomorAnggota() == nomorAnggota) {
                anggota = &a;
                break;
            }
        }

        for (auto& b : daftarBuku) {
            if (b.getJudul() == judulBuku && !b.getStatus()) {
                buku = &b;
                break;
            }
        }

        if (anggota && buku) {
            anggota->kembalikanBuku(judulBuku);
            buku->setStatus(true);
            cout << "Buku '" << judulBuku << "' berhasil dikembalikan." << endl;
        } else {
            cout << "Buku tidak ditemukan atau belum dipinjam." << endl;
        }
    }

    void simpanData() {
        ofstream fileBuku("buku.txt");
        ofstream fileAnggota("anggota.txt");

        for (const auto& buku : daftarBuku) {
            fileBuku << buku.getJudul() << "," << buku.getPengarang() << ","
                     << buku.getTahunTerbit() << "," << buku.getISBN() << ","
                     << buku.getStatus() << endl;
        }
        fileBuku.close();

        for (const auto& anggota : daftarAnggota) {
            fileAnggota << anggota.getNama() << "," << anggota.getNomorAnggota()
                        << "," << anggota.getAlamat() << endl;
        }
        fileAnggota.close();

        cout << "Data berhasil disimpan ke file." << endl;
    }

    void muatData() {
        ifstream fileBuku("buku.txt");
        ifstream fileAnggota("anggota.txt");

        if (fileBuku.is_open()) {
            string judul, pengarang, ISBN, statusStr;
            int tahunTerbit;
            bool status;

            while (getline(fileBuku, judul, ',')) {
                getline(fileBuku, pengarang, ',');
                fileBuku >> tahunTerbit;
                fileBuku.ignore(1, ',');
                getline(fileBuku, ISBN, ',');
                getline(fileBuku, statusStr);
                status = (statusStr == "1");

                Buku buku(judul, pengarang, tahunTerbit, ISBN);
                buku.setStatus(status);
                daftarBuku.push_back(buku);
            }
            fileBuku.close();
        }

        if (fileAnggota.is_open()) {
            string nama, alamat;
            int nomorAnggota;

            while (getline(fileAnggota, nama, ',')) {
                fileAnggota >> nomorAnggota;
                fileAnggota.ignore(1, ',');
                getline(fileAnggota, alamat);

                Anggota anggota(nama, nomorAnggota, alamat);
                daftarAnggota.push_back(anggota);
            }
            fileAnggota.close();
        }

        cout << "Data berhasil dimuat dari file." << endl;
    }

    void tampilkanInfoAnggota(int nomorAnggota) {
        for (const auto& anggota : daftarAnggota) {
            if (anggota.getNomorAnggota() == nomorAnggota) {
                anggota.tampilkanInfoAnggota();
                return;
            }
        }
        cout << "Anggota dengan nomor " << nomorAnggota << " tidak ditemukan.\n";
    }
};

#endif
