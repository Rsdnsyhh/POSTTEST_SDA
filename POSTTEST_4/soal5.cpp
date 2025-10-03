#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeFirstLast(Node*& head) {
    // kondisi jika list kosong, punya 1, atau 2 elemen tidak perlu ditukar
    if (head == nullptr || head->next == head || head->next->next == head) {
        return;
    }

    Node* tail = head->prev;
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // menukar head dan tail
    // update pointer-pointer yg berhubungan dengan head
    head->next = tail;
    head->prev = tailPrev;
    tailPrev->next = head;

    // update pointer-pointer yg berhubungan dengan tail
    tail->next = headNext;
    tail->prev = head;
    headNext->prev = tail;

    // pindahkan head ke posisi tail yg lama
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