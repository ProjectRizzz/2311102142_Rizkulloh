#include <iostream>
#include <string>

using namespace std;

// Struktur node untuk menyimpan data produk
struct ProductNode {
    string name;
    int price;
    ProductNode* prev;
    ProductNode* next;
    
    ProductNode(string n, int p) : name(n), price(p), prev(nullptr), next(nullptr) {}
};

// Kelas untuk Double Linked List
class DoubleLinkedList {
private:
    ProductNode* head;
    ProductNode* tail;
    
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ProductNode* getHead() {
    return head;
}
    
    // Method untuk menambahkan data produk di akhir list
    void addProduct(string name, int price) {
        ProductNode* newNode = new ProductNode(name, price);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // Method untuk menampilkan semua data produk
    void displayProducts() {
        ProductNode* current = head;
        cout << "Nama Produk   Harga" << endl;
        while (current) {
            cout << current->name << "   " << current->price << endl;
            current = current->next;
        }
    }
    
    // Method untuk menambahkan data produk di urutan tertentu
    void addProductAtPosition(string name, int price, string positionName) {
        ProductNode* newNode = new ProductNode(name, price);
        ProductNode* current = head;
        while (current) {
            if (current->name == positionName) {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
    
    // Method untuk menghapus data produk
    void deleteProduct(string name) {
        ProductNode* current = head;
        while (current) {
            if (current->name == name) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                break;
            }
            current = current->next;
        }
    }
    
    // Method untuk mengupdate data produk
    void updateProduct(string name, string newName, int newPrice) {
        ProductNode* current = head;
        while (current) {
            if (current->name == name) {
                current->name = newName;
                current->price = newPrice;
                break;
            }
            current = current->next;
        }
    }
    
    // Method untuk menghapus seluruh data produk
    void deleteAllProducts() {
        ProductNode* current = head;
        while (current) {
            ProductNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoubleLinkedList products;
    
    // Menambahkan data produk awal
    products.addProduct("Originote", 60000);
    products.addProduct("Somethinc", 150000);
    products.addProduct("Skintific", 100000);
    products.addProduct("Wardah", 50000);
    products.addProduct("Hanasui", 30000);
    
    // Menampilkan menu
    int choice;
    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string name;
                int price;
                cout << "Masukkan nama produk: ";
                cin >> name;
                cout << "Masukkan harga: ";
                cin >> price;
                products.addProduct(name, price);
                break;
            }
            case 2: {
                string name;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> name;
                products.deleteProduct(name);
                break;
            }
            case 3: {
                string name, newName;
                int newPrice;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> name;
                cout << "Masukkan nama baru: ";
                cin >> newName;
                cout << "Masukkan harga baru: ";
                cin >> newPrice;
                products.updateProduct(name, newName, newPrice);
                break;
            }
            case 4: {
    string name, positionName;
    int price;
    cout << "Masukkan nama produk yang ingin ditambahkan: ";
    cin >> name;
    cout << "Masukkan harga: ";
    cin >> price;
    cout << "Masukkan nama produk setelahnya: ";
    cin >> positionName;

    // Periksa apakah produk setelahnya ada dalam daftar
    ProductNode* current = products.getHead();
    bool found = false;
    while (current) {
        if (current->name == positionName) {
            found = true;
            break;
        }
        current = current->next;
    }

    // Jika produk ditemukan, tambahkan produk baru
    if (found) {
        products.addProductAtPosition(name, price, positionName);
    } else {
        cout << "Produk '" << positionName << "' tidak ditemukan dalam daftar." << endl;
    }
    break;
}
            case 5: {
                // Tidak diimplementasikan untuk kasus ini
                cout << "Fitur belum diimplementasikan." << endl;
                break;
            }
            case 6: {
                products.deleteAllProducts();
                break;
            }
            case 7: {
                products.displayProducts();
                break;
            }
            case 8: {
                cout << "Terima kasih!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    } while (choice != 8);
    
    return 0;
}
