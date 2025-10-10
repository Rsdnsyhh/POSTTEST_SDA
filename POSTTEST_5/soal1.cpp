#include <iostream>
using namespace std;

// mendefinisikan struktur atau blueprint untuk sebuah node dalam tree
struct Node {
    int data;       // variabel untuk menyimpan nilai dari node
    Node* left;     // pointer yang menunjuk ke node anak di sebelah kiri (nilai lebih kecil)
    Node* right;    // pointer yang menunjuk ke node anak di sebelah kanan (nilai lebih besar)

    // Constructor yang akan dieksekusi saat sebuah node baru dibuat.
    Node(int val) {
        data = val;
        // secara default, node anak kiri dan kanan diinisialisasi sebagai nullptr
        left = nullptr;
        right = nullptr;
    }
};

// fungsi untuk menambahkan node baru ke dalam tree sesuai aturan BST
Node* insert(Node* root, int val) {
    // jika tree masih kosong, node baru akan menjadi root
    if (root == nullptr) {
        return new Node(val);
    }
    // jika nilai baru lebih kecil dari data node saat ini, lanjutkan ke subtree kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    // jika nilai baru lebih besar, lanjutkan ke subtree kanan
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief Fungsi untuk menghitung jumlah total node dalam tree.
 * @param root Pointer ke node root dari tree.
 * @return Jumlah total node.
 * @logic
 * 1. Base case: Jika root adalah nullptr, tree kosong, kembalikan 0.
 * 2. Recursive step: Jumlah node adalah 1 (untuk node saat ini) +
 * jumlah node di subtree kiri + jumlah node di subtree kanan.
 */
int countNodes(Node* root) {
    // jika mencapai node nullptr (ujung tree), artinya tidak ada node untuk dihitung
    if (root == nullptr) {
        return 0;
    }
    // hitung node saat ini (1) lalu tambahkan dengan hasil rekursi dari subtree kiri dan kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    return 0;
}