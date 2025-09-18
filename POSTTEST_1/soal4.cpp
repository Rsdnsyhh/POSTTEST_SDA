#include <iostream>
using namespace std;

// Fungsi untuk menukar nilai variabel lewat pointer ke pointer
void tukarNilai(int** a, int** b) {
    int temp = **a; 

    **a = **b; 
    **b = temp; 
}

int main() {
    int nilai1, nilai2;

    cout << "Masukkan nilai pertama: ";
    cin >> nilai1;
    cout << "Masukkan nilai kedua: ";
    cin >> nilai2;

    // Pointer menunjuk ke variabel nilai1 dan nilai2
    int* ptr1 = &nilai1;
    int* ptr2 = &nilai2;

    cout << "\nSebelum pertukaran:" << endl;
    cout << "Nilai 1 = " << nilai1 << endl;
    cout << "Nilai 2 = " << nilai2 << endl;

 // Pemanggilan fungsi tukarNilai dikirim alamat pointer)
    tukarNilai(&ptr1, &ptr2);

    cout << "\nSetelah pertukaran:" << endl;
    cout << "Nilai 1 = " << nilai1 << endl;
    cout << "Nilai 2 = " << nilai2 << endl;

    return 0;
}