#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>
using namespace std;

class Buku {
   private:
    string judul;
    string pengarang;
    int tahunTerbit;
    string ISBN;
    bool status;  // true = tersedia, false = dipinjam

   public:
    Buku(string judul, string pengarang, int tahunTerbit, string ISBN)
        : judul(judul), pengarang(pengarang), tahunTerbit(tahunTerbit), ISBN(ISBN), status(true) {}

    string getJudul() const { return judul; }
    string getPengarang() const { return pengarang; }
    int getTahunTerbit() const { return tahunTerbit; }
    string getISBN() const { return ISBN; }
    bool getStatus() const { return status; }

    void setStatus(bool newStatus) { status = newStatus; }

    void tampilkanInfoBuku() const {
        cout << "Judul: " << judul << endl;
        cout << "Pengarang: " << pengarang << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Status: " << (status ? "Tersedia" : "Dipinjam") << endl;
    }
};

#endif
