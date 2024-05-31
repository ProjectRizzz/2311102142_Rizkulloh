// Oleh Rizkulloh Alpriyansah dengan NIM 2311102142
#include <iostream>
using namespace std;
// Definisi struktur Pohon
struct Pohon
{
    char data;
    Pohon *left;
    Pohon *right;
    Pohon *parent;
};

Pohon *root; // Pointer ke simpul root
Pohon *baru; // Pointer untuk simpul baru

// Fungsi inisialisasi untuk mengatur root menjadi null
void init()
{
    root = nullptr;
}

// Fungsi untuk memeriksa apakah pohon kosong
bool isEmpty()
{
    return root == nullptr;
}

// Fungsi untuk membuat simpul baru sebagai root
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        cout << "\nNode " << data << " successfully made root." << endl;
    }
    else
    {
        cout << "\nThe tree has been created" << endl;
    }
}

// Fungsi untuk menyisipkan simpul baru sebagai anak kiri dari simpul tertentu
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nMake a tree first!" << endl;
        return nullptr;
    }
    else
    {
        if (node->left != nullptr)
        {
            cout << "\nNode " << node->data << " there is already a left child!" << endl;
            return nullptr;
        }
        else
        {
            baru = new Pohon();
            baru->data = data;
            baru->left = nullptr;
            baru->right = nullptr;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " successfully added to left child " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk menyisipkan simpul baru sebagai anak kanan dari simpul tertentu
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nMake a tree first!" << endl;
        return nullptr;
    }
    else
    {
        if (node->right != nullptr)
        {
            cout << "\nNode " << node->data << " there's already a right child!" << endl;
            return nullptr;
        }
        else
        {
            baru = new Pohon();
            baru->data = data;
            baru->left = nullptr;
            baru->right = nullptr;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " successfully added to right child " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk memperbarui data pada simpul tertentu
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nMake a tree first!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nThe node you want to replace does not exist!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Fungsi untuk mendapatkan data dari simpul tertentu
void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\nMake a tree first!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nThe designated node does not exist!" << endl;
        }
        else
        {
            cout << "\nData node: " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (!root)
    { // Mengecek apakah pohon telah dibuat
        cout << "\nMake a tree first!" << endl;
    }
    else
    { // Mengecek apakah node yang ditunjuk tidak ada
        if (!node)
        {
            cout << "\nThe designated node does not exist!" << endl;
        }
        else
        { // Menampilkan informasi tentang node yang ditunjuk
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;

            // Menampilkan informasi tentang parent dari node yang ditunjuk
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;

            // Menampilkan informasi tentang sibling dari node yang ditunjuk
            if (node->parent != nullptr && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != nullptr && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;

            // Menampilkan informasi tentang child kiri dari node yang ditunjuk
            if (!node->left)
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;

            // Menampilkan informasi tentang child kanan dari node yang ditunjuk
            if (!node->right)
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

// Fungsi untuk melakukan traversal pre-order dari pohon
void preOrder(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != nullptr)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// Fungsi untuk melakukan traversal pre-order dari pohon
void inOrder(Pohon *node)
{
    if (!root)
    { // Mengecek apakah pohon telah dibuat
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// Fungsi untuk melakukan traversal post-order dari pohon
void postOrder(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Fungsi untuk menghapus seluruh pohon
void deleteTree(Pohon *node)
{
    if (node != nullptr)
    {
        if (node->left != nullptr)
        {
            deleteTree(node->left);
            node->left = nullptr;
        }
        if (node->right != nullptr)
        {
            deleteTree(node->right);
            node->right = nullptr;
        }
        if (node == root)
        {
            delete root;
            root = nullptr;
        }
        else
        {
            delete node;
        }
    }
}

// Fungsi untuk menghapus subtree dari suatu node
void deleteSub(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node->left != nullptr)
        {
            deleteTree(node->left);
            node->left = nullptr;
        }
        if (node->right != nullptr)
        {
            deleteTree(node->right);
            node->right = nullptr;
        }
        if (node == root)
        {
            root = nullptr;
        }
    }
}

// Fungsi untuk membersihkan seluruh pohon
void clear()
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghitung ukuran pohon
int size(Pohon *node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);
}

// Fungsi untuk menghitung tinggi pohon
int height(Pohon *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return (heightKiri >= heightKanan) ? heightKiri + 1 : heightKanan + 1;
    }
}

// Fungsi untuk menampilkan karakteristik pohon (ukuran, tinggi, rata-rata node)
void characteristic()
{
    int sz = size(root);
    int ht = height(root);
    cout << "\nSize Tree: " << sz << endl;
    cout << "Height Tree: " << ht << endl;
    cout << "Average Node of Tree: " << (ht == 0 ? 0 : sz / ht) << endl;
}

// Fungsi untuk mencari node dalam pohon berdasarkan nilai
Pohon *findNode(Pohon *node, char value)
{
    if (!node)
        return nullptr;
    if (node->data == value)
        return node;
    Pohon *foundNode = findNode(node->left, value);
    if (foundNode)
        return foundNode;
    return findNode(node->right, value);
}

// Fungsi untuk menampilkan menu interaksi pengguna
void displayMenu()
{
    cout << "\t\tMENU" << endl;
    cout << "1. Create Tree\n";
    cout << "2. Add Left Child\n";
    cout << "3. Add Right Child\n";
    cout << "4. Change Node Data\n";
    cout << "5. Show Node Data\n";
    cout << "6. Search Node\n";
    cout << "7. Preorder Traversal\n";
    cout << "8. Traversal Inorder\n";
    cout << "9. Postorder Traversal\n";
    cout << "10. Delete Subtree\n";
    cout << "11. Delete Tree\n";
    cout << "12. Display Tree Characteristics\n";
    cout << "0. Exit\n";
}

int main()
{
    init(); // Inisialisasi pohon
    int Riz_142;
    char data, parentData;
    Pohon *parentNode; // Pointer ke parent node

    do
    {
        displayMenu(); // Menampilkan menu
        cout << "Pilih opsi: ";
        cin >> Riz_142;

        switch (Riz_142)
        {
        case 1: // Menambahkan root ke pohon
            cout << "Enter the root value: ";
            cin >> data;
            buatNode(data);
            break;
        case 2: // Menambahkan child kiri ke suatu node
            cout << "Enter parent value:";
            cin >> parentData;
            parentNode = findNode(root, parentData);
            cout << "Enter a new left node value: ";
            cin >> data;
            insertLeft(data, parentNode);
            break;
        case 3: // Menambahkan child kanan ke suatu node
            cout << "Enter parent value: ";
            cin >> parentData;
            parentNode = findNode(root, parentData);
            cout << "Enter a new right node value: ";
            cin >> data;
            insertRight(data, parentNode);
            break;
        case 4: // Mengubah nilai suatu node
            cout << "Enter the node value you want to change: ";
            cin >> parentData;
            parentNode = findNode(root, parentData);
            cout << "Enter new values: ";
            cin >> data;
            update(data, parentNode);
            break;
        case 5: // Menampilkan nilai suatu node
            cout << "Enter node values:";
            cin >> data;
            parentNode = findNode(root, data);
            retrieve(parentNode);
            break;
        case 6: // Mencari node dalam pohon berdasarkan nilai
            cout << "Enter the value of the node you want to search for: ";
            cin >> data;
            parentNode = findNode(root, data);
            find(parentNode);
            break;
        case 7: // Traversal pre-order dari pohon
            cout << "\nPreorder traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 8: // Traversal in-order dari pohon
            cout << "\nInorder traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 9: // Traversal post-order dari pohon
            cout << "\nPostorder traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 10: // Menghapus subtree dari suatu node
            cout << "Enter the value of the subtree node you want to delete: ";
            cin >> data;
            parentNode = findNode(root, data);
            deleteSub(parentNode);
            break;
        case 11: // Menghapus seluruh pohon
            clear();
            break;
        case 12: // Menampilkan karakteristik pohon
            characteristic();
            break;
        }
    } while (Riz_142 != 0);

    return 0;
}