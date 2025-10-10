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
 * @brief Fungsi untuk melakukan post-order traversal pada tree.
 * @param root Pointer ke node root dari tree.
 * @logic
 * 1. Jika node saat ini adalah nullptr, kembalikan (base case).
 * 2. Rekursif ke subtree kiri.
 * 3. Rekursif ke subtree kanan.
 * 4. Cetak data node saat ini.
 */
void postOrderTraversal(Node* root) {
    // base case untuk rekursi: jika node saat ini adalah nullptr, hentikan proses
    if (root == nullptr) {
        return;
    }
    // langkah 1: lakukan traversal secara rekursif pada subtree kiri
    postOrderTraversal(root->left);
    // langkah 2: lakukan traversal secara rekursif pada subtree kanan
    postOrderTraversal(root->right);
    // langkah 3: proses atau cetak data dari node saat ini
    cout << root->data << " ";
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}