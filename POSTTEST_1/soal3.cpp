#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    Mahasiswa daftarMahasiswa[5]; // Array berisi 5 data mahasiswa

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan data mahasiswa ke " << i + 1 << endl;
        cout << "Nama: ";
        getline(cin >> ws, daftarMahasiswa[i].nama);
        cout << "NIM: ";
        getline(cin, daftarMahasiswa[i].nim);
        cout << "IPK: ";
        cin >> daftarMahasiswa[i].ipk;
        cout << endl;
    }

    // Inisialisasi pencarian IPK tertinggi
    int indeksIPKTertinggi = 0;
    double ipkTertinggi = daftarMahasiswa[0].ipk;

    // Cari mahasiswa dengan IPK tertinggi
    for (int i = 1; i < 5; i++) {
        if (daftarMahasiswa[i].ipk > ipkTertinggi) {
            ipkTertinggi = daftarMahasiswa[i].ipk;
            indeksIPKTertinggi = i;
        }
    }

    cout << "IPK mahasiswa yang tertinggi:" << endl;
    cout << "Nama: " << daftarMahasiswa[indeksIPKTertinggi].nama << endl;
    cout << "NIM: " << daftarMahasiswa[indeksIPKTertinggi].nim << endl;
    cout << "IPK: " << daftarMahasiswa[indeksIPKTertinggi].ipk << endl;

    return 0;
}