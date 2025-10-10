#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

/**
 * @brief Fungsi untuk melakukan pre-order traversal pada tree.
 * @param root Pointer ke node root dari tree.
 * @logic
 * 1. Jika node saat ini adalah nullptr, kembalikan (base case).
 * 2. Cetak data node saat ini.
 * 3. Rekursif ke subtree kiri.
 * 4. Rekursif ke subtree kanan.
 */
void preOrderTraversal(Node* root) {
    // base case: jika node saat ini nullptr, kembali dari pemanggilan fungsi
    if (root == nullptr) {
        return;
    }
    // langkah 1: proses atau cetak data dari node saat ini terlebih dahulu
    cout << root->data << " ";
    // langkah 2: lanjutkan traversal secara rekursif ke subtree kiri
    preOrderTraversal(root->left);
    // langkah 3: setelah subtree kiri selesai, lanjutkan traversal ke subtree kanan
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}