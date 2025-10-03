#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// menggunakan fungsi push dan pop
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. loop setiap karakter dalam `expr`.
    // kita cek satu-satu karakter di dalam string ekspresinya.
    for (char c : expr) {
        // 2. jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        // kalau ketemu kurung buka, langsung saja masukkan ke stack buat diingat.
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 3. jika karakter adalah kurung tutup ')', '}', ']'.
        // kalau nemu kurung tutup, kita harus cek pasangannya.
        else if (c == ')' || c == '}' || c == ']') {
            // a. jika stack kosong, berarti kurung tutup ini gak punya pasangan.
            // jelas tidak seimbang, langsung return false.
            if (stackTop == nullptr) {
                return false;
            }
            // b. Pop stack, lalu cek apakah cocok.
            // Kita ambil kurung buka yang terakhir dimasukin (paling atas di stack).
            char topChar = pop(stackTop);
            // kalau kurung tutupnya ')' tapi pasangannya bukan '(', atau '}' bukan '{', dst.,
            // berarti tidak cocok. tidak seimbang, return false.
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    // 4. setelah loop selesai, stack harus kosong.
    // kalau semua karakter sudah dicek dan stack-nya kosong,
    // berarti semua kurung buka punya pasangan yang pas. seimbang.
    // kalau masih ada sisa di stack, berarti ada kurung buka yang gak ditutup.
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " => " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " => " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak seimbang") << endl;

    return 0;
}