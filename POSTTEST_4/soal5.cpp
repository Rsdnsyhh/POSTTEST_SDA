#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeFirstLast(Node*& head) {
    // kondisi jika list kosong, punya 1, atau 2 elemen tidak perlu ditukar
    // jika 2 elemen, ditukar juga hasilnya sama aja posisinya (saling nunjuk).
    if (head == nullptr || head->next == head || head->next->next == head) {
        return;
    }

    // simpan dulu semua node penting biar gak ilang jejak.
    Node* tail = head->prev;       // ekor lama (node sebelum head)
    Node* headNext = head->next;   // tetangga kanan head lama
    Node* tailPrev = tail->prev;   // tetangga kiri tail lama

    // logikanya adalah menyambungkan kembali tetangga-tetangga
    // ke head dan tail yang sudah bertukar posisi.

    // 1. sambungkan Ekor (tail) yang baru (yaitu head lama)
    // tetangga kiri ekor lama (tailPrev) sekarang harus nyambung ke head lama.
    head->prev = tailPrev;
    tailPrev->next = head;

    // 2. sambungkan Kepala (head) yang baru (yaitu tail lama)
    // tetangga kanan head lama (headNext) sekarang harus nyambung ke tail lama.
    tail->next = headNext;
    headNext->prev = tail;
    
    // 3. sambungkan kepala baru dan ekor baru secara langsung
    // ini untuk menjaga sifat circular-nya.
    // ekor baru (head lama) next-nya adalah kepala baru (tail lama)
    head->next = tail;
    // kepala baru (tail lama) prev-nya adalah ekor baru (head lama)
    tail->prev = head;

    // 4. terakhir, update pointer utama `head` di program kita
    // biar nunjuk ke kepala yang baru.
    head = tail;
}

void printList(Node *head) {
    if (head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void insertEnd(Node*& head, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node *tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node* HEAD = nullptr;

    insertEnd(HEAD, 1);
    insertEnd(HEAD, 2);
    insertEnd(HEAD, 3);
    insertEnd(HEAD, 4);
    insertEnd(HEAD, 5);

    cout << "List sebelum exchange: ";
    printList(HEAD);

    exchangeFirstLast(HEAD);

    cout << "List setelah exchange: ";
    printList(HEAD);

    return 0;
}