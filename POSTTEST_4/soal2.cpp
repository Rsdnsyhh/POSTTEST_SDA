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

    // loop setiap karakter dalam expr
    for (char c : expr) {
        // jika kurung buka, push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // jika kurung tutup
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) {
                return false;
            }
            char topChar = pop(stackTop);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    // jika stack kosong setelah loop, maka seimbang
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " => " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " => " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak seimbang") << endl;

    return 0;
}