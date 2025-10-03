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

    // 1. jika queue kosong (rear == nullptr), maka front dan rear jadi node baru ini.
    // cek terlebih dahulu, antriannya kosong atau tidak. jika kosong,
    // si node baru ini jadi yang pertama (front) sekaligus yang terakhir (rear).
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
    // 2. jika tidak kosong, sambungkan node terakhir (rear->next) ke node baru,
    // lalu update si rear jadi node baru ini.
    // jadi, orang terakhir di antrian (rear) nunjuk ke orang baru (newNode),
    // kemudian status 'orang terakhir' pindah ke si newNode.
        rear->next = newNode;
        rear = newNode;
    }
}

// fungsi dequeue
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        return ""; // antrian kosong
    }

    // 1. simpan data dan node dari front.
    // kita amankan dulu node paling depan (temp) sama datanya (doc).
    Node* temp = front;
    string doc = temp->document;

    // 2. geser front ke orang berikutnya di antrian (front->next).
    // panggilan selanjutnya dimulai dari orang kedua.
    front = front->next;

    // 3. jika setelah digeser front jadi kosong, berarti antrian habis.
    // rear juga harus di-set jadi kosong.
    if (front == nullptr) {
        rear = nullptr;
    }

    // 4. hapus node paling depan yang tadi, lalu kembalikan datanya.
    delete temp;
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    // loop sampai antrian (queue) kosong.
    // selama masih ada dokumen di antrian (front tidak null),
    // kita panggil dequeue buat ngambil dokumen paling depan, kemudian kita cetak.
    // seperti itu saja terus sampai habis.
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