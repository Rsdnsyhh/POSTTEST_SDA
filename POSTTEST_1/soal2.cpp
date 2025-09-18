#include <iostream>
using namespace std;

int main() {
    const int ukuran = 3; // Ukuran matriks (3x3)// Ukuran matriks (3x3)
    int matriks[ukuran][ukuran];//Deklarasi array 2D sebagai matriks

    // Mengisi matriks dengan kelipatan 3
    int nilai_awal = 3;
    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            matriks[i][j] = nilai_awal;
            nilai_awal += 3;
        }
    }

    // Menampilkan isi matriks
    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    int jumlah_diagonal_utama = 0; // Penampung jumlah diagonal utama
    int jumlah_diagonal_sekunder = 0; // Penampung jumlah diagonal sekunder

    // Menghitung jumlah diagonal utama dan sekunder
    for (int i = 0; i < ukuran; i++) {
        jumlah_diagonal_utama += matriks[i][i];
        jumlah_diagonal_sekunder += matriks[i][ukuran - 1 - i];
    }

    cout << "\nJumlah diagonal utama: " << jumlah_diagonal_utama << endl;
    cout << "Jumlah diagonal sekunder: " << jumlah_diagonal_sekunder << endl;
    cout << "Total jumlah diagonal (utama + sekunder): " << jumlah_diagonal_utama + jumlah_diagonal_sekunder << endl;

    return 0;
}