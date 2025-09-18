#include <iostream>
using namespace std;

// Fungsi untuk membalik urutan elemen dalam array (pakai pointer)
void balikArray(int* arr, int ukuran) {
    int* kiri = arr;
    int* kanan = arr + ukuran - 1;
    while (kiri < kanan) {
        int temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;
        kiri++;
        kanan--;
    }
}

// Fungsi untuk menampilkan isi array
void tampilkanArray(int* arr, int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    const int ukuran = 7;
    int data[ukuran];

    // Isi array dengan kelipatan 3
    for (int i = 0; i < ukuran; i++) {
        data[i] = (i + 1) * 3;
    }
    cout << "Array sebelum dibalik: ";
    tampilkanArray(data, ukuran);
    balikArray(data, ukuran);
    cout << "Array sesudah dibalik: ";
    tampilkanArray(data, ukuran);

    return 0;
}