#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// fungsi enqueue
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (rear == nullptr) { // jika antrian kosong
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// fungsi dequeue
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        return ""; // antrian kosong
    }

    Node* temp = front;
    string doc = temp->document;
    front = front->next;

    if (front == nullptr) { // jika setelah dequeue antrian jadi kosong
        rear = nullptr;
    }

    delete temp;
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
}

int main() {
    // menggunakan nama FRONT dan REAR
    Node* FRONT = nullptr;
    Node* REAR = nullptr;

    enqueue(FRONT, REAR, "Document1.pdf");
    enqueue(FRONT, REAR, "Report.docx");
    enqueue(FRONT, REAR, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(FRONT, REAR);

    return 0;
}