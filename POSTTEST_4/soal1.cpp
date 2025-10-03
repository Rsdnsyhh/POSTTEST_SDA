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

    // push setiap karakter dari string s ke dalam stack
    for (char c : s) {
        push(stackTop, c);
    }

    // pop setiap karakter dari stack dan tambahkan ke string
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    Node* TOP = nullptr; 
    
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    
    for (char c : text) {
        push(TOP, c);
    }

    string reversedText = "";
    while (TOP != nullptr) {
        reversedText += pop(TOP);
    }

    cout << "Teks terbalik: " << reversedText << endl;
    
    return 0;
}