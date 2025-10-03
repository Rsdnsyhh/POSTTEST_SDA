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

    if (data <= head->data) {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }

    while (current->next != head && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
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