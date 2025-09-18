#include <iostream>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

Item* head = nullptr;

// tampilkan semua item
void transversal(Item* head) {
    if (head == nullptr) {
        cout << ">> Inventory kosong <<" << endl;
        return;
    }
    Item* temp = head;
    cout << "\n=== Daftar Inventory ===" << endl;
    while (temp != nullptr) {
        cout << "Nama: " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "========================\n";
}

// tambah item di akhir
void addlast(string nama, string tipe, int jumlah) {
    Item* newNode = new Item;
    newNode->namaItem = nama;
    newNode->jumlah = jumlah;
    newNode->tipe = tipe;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Item* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << ">> Item berhasil ditambah di akhir." << endl;
}

// sisipkan item di posisi tertentu
void addSpecific(string nama, string tipe, int jumlah, int posisi) {
    if (posisi <= 1 || head == nullptr) {
        Item* newNode = new Item;
        newNode->namaItem = nama;
        newNode->jumlah = jumlah;
        newNode->tipe = tipe;
        newNode->next = head;
        head = newNode;
        return;
    }

    Item* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Posisi tidak valid <<" << endl;
    } else {
        Item* newNode = new Item;
        newNode->namaItem = nama;
        newNode->jumlah = jumlah;
        newNode->tipe = tipe;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << ">> Item berhasil disisipkan di posisi -" << posisi << endl;
    }
}

// hapus item terakhir
void deleteLast() {
    if (head == nullptr) {
        cout << ">> Inventory kosong <<" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << ">> Item terakhir dihapus." << endl;
        return;
    }
    Item* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    cout << ">> Item terakhir dihapus." << endl;
}

// gunakan item maka jumlah item akan berkurang, dan kalau habis node dihapus
void gunakanItem(string namaCari) {
    if (head == nullptr) {
        cout << ">> Inventory kosong <<" << endl;
        return;
    }
    Item* temp = head;
    Item* before = nullptr;

    while (temp != nullptr && temp->namaItem != namaCari) {
        before = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << ">> Item tidak ditemukan <<" << endl;
    } else {
        temp->jumlah--;
        cout << ">> " << temp->namaItem << " digunakan! Sisa: " << temp->jumlah << endl;
        if (temp->jumlah <= 0) {
            if (before == nullptr) {
                head = temp->next;
            } else {
                before->next = temp->next;
            }
            delete temp;
            cout << ">> Item habis, otomatis dihapus dari inventory." << endl;
        }
    }
}

// kosongkan semua inventory
void clearInventory(Item*& head) {
    Item* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << ">> Inventory berhasil dikosongkan <<" << endl;
}

int main() {
    string namaUser, nim;
    cout << "Masukkan Nama: ";
    getline(cin, namaUser);

    int defaultJumlah = 0;
    int posisiSisip = 0;

    // validasi NIM harus ganjil
    while (true) {
        cout << "Masukkan NIM : ";
        getline(cin, nim);

        if (nim.size() < 3) {
            cout << ">> NIM minimal 3 digit yaa <<" << endl;
            continue;
        }

        string last3 = nim.substr(nim.size() - 3);
        int nimAkhir = stoi(last3);

        if (nimAkhir % 2 == 0) {
            cout << ">> NIM harus ganjil! Silakan coba lagi. <<" << endl;
        } else {
            defaultJumlah = nimAkhir % 100;
            if (defaultJumlah == 0) defaultJumlah = 1;
            posisiSisip = (nimAkhir % 10) + 1;
            break;
        }
    }

    int pilihan;
    do {
        cout << "\n<+=================================================+>\n";
        cout << " |            +GAME INVENTORY MANAGEMENT+          |\n";
        cout << " |  Player : " << namaUser << " | NIM : " << nim << " |\n";
        cout << "<+=================================================+>\n";
        cout << " [1.]------------Tambah Item Baru------------------|\n";
        cout << " [2.]-----Sisipkan Item (posisi otomatis ke-" << posisiSisip << ")-----|\n"; // tambahkan 3 item baru agar dapat disisipkan
        cout << " [3.]-------------Hapus Item Terakhir--------------|\n";
        cout << " [4.]----------------Gunakan Item------------------|\n";
        cout << " [5.]-------------Tampilkan Inventory--------------|\n";
        cout << " [6.]-------------Kosongkan Inventory--------------|\n";
        cout << " [0.]-------------------Keluar---------------------|\n";
        cout << "<+=================================================+>\n";
        cout << "<+=================================================+>\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string namaItem, tipe;
            cout << "Nama Item: ";
            getline(cin, namaItem);
            cout << "Tipe Item: ";
            getline(cin, tipe);
            addlast(namaItem, tipe, defaultJumlah);
        }
        else if (pilihan == 2) {
            string namaItem, tipe;
            cout << "Nama Item: ";
            getline(cin, namaItem);
            cout << "Tipe Item: ";
            getline(cin, tipe);
            addSpecific(namaItem, tipe, defaultJumlah, posisiSisip);
        }
        else if (pilihan == 3) {
            deleteLast();
        }
        else if (pilihan == 4) {
            string namaItem;
            cout << "Masukkan nama item yang ingin digunakan: ";
            getline(cin, namaItem);
            gunakanItem(namaItem);
        }
        else if (pilihan == 5) {
            transversal(head);
        }
        else if (pilihan == 6) {
            clearInventory(head);
        }
        else if (pilihan == 0) {
            cout << "Kamu telah keluar dari program..." << endl;
        }
        else {
            cout << ">> Pilihan tidak valid <<" << endl;
        }

    } while (pilihan != 0);

    return 0;
}