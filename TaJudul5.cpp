#include <iostream>
using namespace std;

struct Node {
    int nomor;
    Node* left;
    Node* right;
};


Node* buatNode(int nomor) {
    Node* baru = new Node();
    baru->nomor = nomor;
    baru->left = baru->right = nullptr;
    return baru;
}


Node* insertNode(Node* root, int nomor) {
    if (root == nullptr)
        return buatNode(nomor);
    if (nomor < root->nomor)
        root->left = insertNode(root->left, nomor);
    else if (nomor > root->nomor)
        root->right = insertNode(root->right, nomor);
    return root;
}


bool searchNode(Node* root, int nomor) {
    if (root == nullptr)
        return false;
    if (root->nomor == nomor)
        return true;
    else if (nomor < root->nomor)
        return searchNode(root->left, nomor);
    else
        return searchNode(root->right, nomor);
}


void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->nomor << " ";
        inorder(root->right);
    }
}


int findMin(Node* root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr)
        root = root->left;
    return root->nomor;
}


int findMax(Node* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr)
        root = root->right;
    return root->nomor;
}

int main() {
    Node* root = nullptr;
    int pilih, x;

    do {
        cout << "\n=== SISTEM NOMOR ANTREAN (BST) ===\n";
        cout << "1. Tambah nomor antrean (insert)\n";
        cout << "2. Cari nomor antrean (search)\n";
        cout << "3. Tampilkan semua antrean (Inorder)\n";
        cout << "4. Lihat nomor antrean pertama (Min)\n";
        cout << "5. Lihat nomor antrean terakhir (Max)\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nomor antrean (insert): "; cin >> x;
            root = insertNode(root, x);
            cout << "Nomor antrean " << x << " berhasil ditambahkan.\n";

        } else if (pilih == 2) {
            cout << "Masukkan nomor yang ingin dicari: "; cin >> x;
            cout << (searchNode(root, x) ? "Nomor ditemukan!\n" : "Nomor tidak ditemukan!\n");

        } else if (pilih == 3) {
            cout << "\n=== Daftar Nomor Antrean (BST) ===\n";
            inorder(root);
            cout << endl;

        } else if (pilih == 4) {
            cout << "Nomor antrean pertama (Min): " << findMin(root) << endl;

        } else if (pilih == 5) {
            cout << "Nomor antrean terakhir (Max): " << findMax(root) << endl;

        } else if (pilih == 6) {
            cout << "Keluar dari program.\n";

        } else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 6);

    return 0;
}
