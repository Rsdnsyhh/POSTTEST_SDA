#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* current = head;

    // data baru lebih kecil atau sama dengan data di head.
    // berarti node baru harus jadi head yang baru.
    // kita sisipkan sebelum head lama.
    if (data <= head->data) {
        Node* tail = head->prev; // cari buntutnya dulu (elemen terakhir)
        newNode->next = head;    // node baru nunjuk ke head lama
        newNode->prev = tail;    // node baru nunjuk balik ke buntut
        tail->next = newNode;    // buntut nunjuk ke node baru
        head->prev = newNode;    // head lama nunjuk balik ke node baru
        head = newNode;          // terakhir, update head jadi si node baru
        return;
    }

    // cari posisi yang tepat di tengah atau akhir.
    // kita jalankan 'current' selama 'next'-nya bukan head
    // data 'next'-nya masih lebih kecil dari data baru.
    // cari posisi dimana 'current' pas sebelum tempat si node baru.
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }

    // setelah ketemu, sisipkan node baru di antara 'current' dan 'current->next'.
    // proses menghubungkan 4 pointer:
    newNode->next = current->next;      // 1. next dari node baru nunjuk ke next-nya current
    newNode->prev = current;            // 2. prev dari node baru nunjuk ke current
    current->next->prev = newNode;      // 3. prev dari tetangga kanan nunjuk ke node baru
    current->next = newNode;            // 4. next dari current nunjuk ke node baru
}

void printList(Node* head) {
    if (!head) {
        cout << "List kosong" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* HEAD = nullptr;
    sortedInsert(HEAD, 3);
    sortedInsert(HEAD, 2);
    sortedInsert(HEAD, 5);
    sortedInsert(HEAD, 1);
    sortedInsert(HEAD, 4);

    cout << "List terurut: ";
    printList(HEAD);

    return 0;
}