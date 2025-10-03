#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) {
        return '\0'; // mengembalikan karakter null jika stack kosong
    }
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. push setiap karakter dari string s ke dalam stack.
    // kita looping setiap karakter di string 's'.
    // kerus, kita 'push' atau masukkan satu per satu ke dalam stack.
    // karakter pertama masuk paling bawah, terakhir masuk paling atas (LIFO).
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    // selama stack-nya belum kosong, kita 'pop' atau keluarkan karakternya.
    // karena yang keluar duluan itu yang terakhir masuk,
    // urutannya jadi kebalik. hasil pop langsung kita gabungin ke string 'reversed'.
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    Node* TOP = nullptr; 
    
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    
    // proses push, sama seperti di fungsi reverseString
    for (char c : text) {
        push(TOP, c);
    }

    string reversedText = "";
    // proses pop, juga sama logikanya
    while (TOP != nullptr) {
        reversedText += pop(TOP);
    }

    cout << "Teks terbalik: " << reversedText << endl;
    
    return 0;
}