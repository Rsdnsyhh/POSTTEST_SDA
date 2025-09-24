#include <iostream>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
    Item* prev;
};

Item* head = nullptr;
Item* tail = nullptr;

// tampilkan dari depan
void traversalForward() {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }
    Item* temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << no << ". Nama  : " << temp->namaItem << endl;
        cout << "   Jumlah: " << temp->jumlah << endl;
        cout << "   Tipe  : " << temp->tipe << endl;
        cout << endl;
        temp = temp->next;
        no++;
    }
}

// tampilkan dari belakang
void traversalBackward() {
    if (tail == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }
    Item* temp = tail;
    int no = 1;
    while (temp != nullptr) {
        cout << no << ". Nama  : " << temp->namaItem << endl;
        cout << "   Jumlah: " << temp->jumlah << endl;
        cout << "   Tipe  : " << temp->tipe << endl;
        cout << endl;
        temp = temp->prev;
        no++;
    }
}

// tambah item di akhir
void addLast(string nama, string tipe, int jumlah) {
    Item* newNode = new Item;
    newNode->namaItem = nama;
    newNode->tipe = tipe;
    newNode->jumlah = jumlah;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// sisipkan item di posisi tertentu
void addSpecific(string nama, string tipe, int jumlah, int posisi) {
    Item* newNode = new Item;
    newNode->namaItem = nama;
    newNode->tipe = tipe;
    newNode->jumlah = jumlah;

    if (posisi <= 1 || head == nullptr) {
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) head->prev = newNode;
        head = newNode;
        if (tail == nullptr) tail = newNode;
        return;
    }

    Item* temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) temp->next->prev = newNode;
    temp->next = newNode;
    if (newNode->next == nullptr) tail = newNode;
}

// hapus item terakhir (dengan nama item)
void deleteLast() {
    if (tail == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }
    Item* hapus = tail;
    string namaHapus = hapus->namaItem; // simpan nama item sebelum dihapus
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete hapus;
    cout << "Item " << namaHapus << " berhasil dihapus" << endl;
}

// gunakan item
void gunakanItem(string namaCari) {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }
    Item* temp = head;
    while (temp != nullptr && temp->namaItem != namaCari) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Item tidak ditemukan" << endl;
    } else {
        temp->jumlah--;
        cout << temp->namaItem << " digunakan! Sisa: " << temp->jumlah << endl;
        if (temp->jumlah <= 0) {
            if (temp == head && temp == tail) {
                head = nullptr;
                tail = nullptr;
            } else if (temp == head) {
                head = head->next;
                head->prev = nullptr;
            } else if (temp == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
    }
}

// detail item berdasarkan nama
void detailItem(string namaCari) {
    Item* temp = head;
    while (temp != nullptr) {
        if (temp->namaItem == namaCari) {
            cout << "\nDetail Item:" << endl;
            cout << "Nama  : " << temp->namaItem << endl;
            cout << "Jumlah: " << temp->jumlah << endl;
            cout << "Tipe  : " << temp->tipe << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Item tidak ditemukan" << endl;
}

// kosongkan inventory
void clearInventory() {
    Item* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
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
            cout << "NIM minimal 3 digit" << endl;
            continue;
        }

        string last3 = nim.substr(nim.size() - 3);
        int nimAkhir = stoi(last3);

        if (nimAkhir % 2 == 0) {
            cout << "NIM harus ganjil!" << endl;
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
        cout << " [2.]-----Sisipkan Item (posisi otomatis ke-" << posisiSisip << ")-----|\n";
        cout << " [3.]-------------Hapus Item Terakhir--------------|\n";
        cout << " [4.]----------------Gunakan Item------------------|\n";
        cout << " [5.]-------------Tampilkan Inventory--------------|\n";
        cout << " [6.]----Tampilkan Inventory dari Belakang---------|\n";
        cout << " [7.]-------------Lihat Detail Item----------------|\n";
        cout << " [8.]-------------Kosongkan Inventory--------------|\n";
        cout << " [0.]-------------------Keluar---------------------|\n";
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
            addLast(namaItem, tipe, defaultJumlah);
        } else if (pilihan == 2) {
            string namaItem, tipe;
            cout << "Nama Item: ";
            getline(cin, namaItem);
            cout << "Tipe Item: ";
            getline(cin, tipe);
            addSpecific(namaItem, tipe, defaultJumlah, posisiSisip);
        } else if (pilihan == 3) {
            deleteLast();
        } else if (pilihan == 4) {
            string namaItem;
            cout << "Masukkan nama item: ";
            getline(cin, namaItem);
            gunakanItem(namaItem);
        } else if (pilihan == 5) {
            traversalForward();
        } else if (pilihan == 6) {
            traversalBackward();
        } else if (pilihan == 7) {
            string namaItem;
            cout << "Masukkan nama item: ";
            getline(cin, namaItem);
            detailItem(namaItem);
        } else if (pilihan == 8) {
            clearInventory();
        }
    } while (pilihan != 0);

    cout << "Kamu telah keluar dari program..." << endl;
    return 0;
}