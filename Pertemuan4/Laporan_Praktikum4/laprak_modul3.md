# <h1 align="center">Laporan Praktikum Modul 4 LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>

<p align="center">Rizkulloh Alpriyansah</p>

## Dasar Teori

Linked List adalah data structure linear yang terdiri dari koleksi node, dimana setiap node memiliki data dan referensi ke node berikutnya dalam urutan. Ada dua jenis linked list: linked list circular dan linked list non-circular.
Linked list circular adalah jenis linked list yang memiliki struktur berulang, dimana node terakhir berhubungan dengan node pertama melalui pointer next. Hal ini memungkinkan traversal dalam bentuk berulang, yang sesuai untuk beberapa aplikasi seperti queue circular dan stack circular. Dalam linked list circular, pointer next node terakhir berhubungan dengan node pertama, membentuk struktur berulang.
Sedangkan linked list non-circular adalah data structure linear yang terdiri dari node yang memiliki data dan referensi ke node berikutnya dalam urutan. Berbeda dengan linked list circular, node terakhir dalam linked list non-circular tidak berhubungan dengan node pertama, dan pointer next node terakhir diset ke NULL, yang menunjukkan akhir dari list.
Perbedaan utama antara linked list circular dan linked list non-circular adalah cara node terakhir dihubungkan. Dalam linked list circular, node terakhir terhubung dengan node pertama, membentuk struktur berulang, sedangkan dalam linked list non-circular, node terakhir tidak terhubung dengan node apa pun, dan pointer next node terakhir diset ke NULL.
Kedua jenis linked list memiliki kelebihan dan kekurangan sendiri. Linked list circular sesuai untuk implikasi data structure berulang seperti queue circular dan stack circular, sementara linked list non-circular lebih sering digunakan untuk data structure linear seperti linked list single dan linked list double.

## Guided

### 1. [Linked List Non Circular]

```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }

    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

### -> Penjelasan Program

Program ini adalah contoh implementasi Linked List Non-Circular di C++. Linked List adalah data structure linear yang terdiri dari node yang terhubung secara berurutan. Program ini mendemonstrasikan beberapa operasi yang dapat dilakukan pada Linked List, seperti menambahkan node di depan, di belakang, dan di tengah, menghapus node di depan, di belakang, dan di tengah, serta mengubah data node di depan dan di belakang. Program juga menampilkan isi Linked List dan menghapus semua node pada Linked List.

### 2. [ Linked List Circular]

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```

### ->Penjelasan

Program ini menggunakan struct Node untuk membuat node baru dengan data dan pointer ke node selanjutnya. Fungsi isEmpty() digunakan untuk mengecek apakah Linked List Non-Circular kosong atau tidak. Fungsi insertDepan(), insertBelakang(), dan insertTengah() digunakan untuk menambahkan node baru di depan, di belakang, dan di tengah Linked List Non-Circular. Fungsi hapusDepan(), hapusBelakang(), dan hapusTengah() digunakan untuk menghapus node di depan, di belakang, dan di tengah Linked List Non-Circular. Fungsi tampil() digunakan untuk menampilkan isi Linked List Non-Circular.

## Unguided

### 1. [Soal mengenai Single Linked List

Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
belakang atau tengah). Data pertama yang dimasukkan adalah
nama dan usia anda.
[Nama_anda] [Usia_anda]
John 19
Jane 20
Michael 18
Yusuke 19
Akechi 20
Hoshino 18
Karin 18
b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data]

```C++
// dibuat oleh rizkulloh NIM 2311102142
#include <iostream>
#include <string>
using namespace std;

// deklarasi struct node
struct Node_142 {
    string nama_142;
    int usia_142;
    Node_142* next_142;
};

Node_142* head_142 = nullptr;
Node_142* tail_142 = nullptr;

// inisialisasi node
void init_142() {
    head_142 = nullptr;
    tail_142 = nullptr;
}

// pengecekan apakah list kosong
bool isEmpty_142() {
    return head_142 == nullptr;
}

// hitung jumlah node
int hitungList_142() {
    int jumlah_142 = 0;
    Node_142* hitung_142 = head_142;
    while (hitung_142 != nullptr) {
        jumlah_142++;
        hitung_142 = hitung_142->next_142;
    }
    return jumlah_142;
}

// tambah node di depan
void insertDepan_142(string nama_142, int usia_142) {
    Node_142* baru_142 = new Node_142;
    baru_142->nama_142 = nama_142;
    baru_142->usia_142 = usia_142;
    baru_142->next_142 = nullptr;

    if (isEmpty_142()) {
        head_142 = tail_142 = baru_142;
    } else {
        baru_142->next_142 = head_142;
        head_142 = baru_142;
    }
}

// tambah node di belakang
void insertBelakang_142(string nama_142, int usia_142) {
    Node_142* baru_142 = new Node_142;
    baru_142->nama_142 = nama_142;
    baru_142->usia_142 = usia_142;
    baru_142->next_142 = nullptr;

    if (isEmpty_142()) {
        head_142 = tail_142 = baru_142;
    } else {
        tail_142->next_142 = baru_142;
        tail_142 = baru_142;
    }
}

// tambah node di tengah
void insertTengah_142(string nama_142, int usia_142, int posisi_142) {
    if (posisi_142 < 1) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (posisi_142 == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    if (posisi_142 > 1 && posisi_142 <= hitungList_142()) {
        Node_142* baru_142 = new Node_142;
        baru_142->nama_142 = nama_142;
        baru_142->usia_142 = usia_142;

        Node_142* bantu_142 = head_142;
        int nomor_142 = 1;

        while (nomor_142 < posisi_142 - 1) {
            bantu_142 = bantu_142->next_142;
            nomor_142++;
        }

        baru_142->next_142 = bantu_142->next_142;
        bantu_142->next_142 = baru_142;
    } else {
        cout << "Posisi diluar jangkauan" << endl;
    }
}

// hapus node di tengah
void hapusTengah_142(string nama_142) {
    if (!isEmpty_142()) {
        Node_142* hapus_142;
        Node_142* bantu_142 = head_142;

        if (head_142->nama_142 == nama_142) {
            hapus_142 = head_142;
            head_142 = head_142->next_142;
            delete hapus_142;
            return;
        }

        while (bantu_142->next_142 != nullptr && bantu_142->next_142->nama_142 != nama_142) {
            bantu_142 = bantu_142->next_142;
        }

        if (bantu_142->next_142 == nullptr) {
            cout << "Data tidak ditemukan!" << endl;
        } else {
            hapus_142 = bantu_142->next_142;
            bantu_142->next_142 = bantu_142->next_142->next_142;
            delete hapus_142;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// ubah data node
void ubahData_142(string namaCari_142, string namaBaru_142, int usiaBaru_142) {
    Node_142* bantu_142 = head_142;
    while (bantu_142 != nullptr) {
        if (bantu_142->nama_142 == namaCari_142) {
            bantu_142->nama_142 = namaBaru_142;
            bantu_142->usia_142 = usiaBaru_142;
            return;
        }
        bantu_142 = bantu_142->next_142;
    }
    cout << "Data tidak ditemukan!" << endl;
}

// tampilkan seluruh node
void tampil_142() {
    Node_142* bantu_142 = head_142;
    if (!isEmpty_142()) {
        while (bantu_142 != nullptr) {
            cout << bantu_142->nama_142 << " " << bantu_142->usia_142 << endl;
            bantu_142 = bantu_142->next_142;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init_142();

    // Masukkan data mahasiswa
    cout << "A. Masukkan data mahasiswa" << endl;
    cout << "Masukkan data mahasiswa sesuai urutan berikut:" << endl;
    cout << "[Nama] [Usia]" << endl;
    string nama_142;
    int usia_142;
    while (true) {
        cout << "Masukkan nama : ";
        cin >> nama_142;
        if (nama_142 == "stop") break; // apabila menginputkan stop, maka perulangan berhenti
        cout << "Masukkan usia : ";
        cin >> usia_142;
        insertBelakang_142(nama_142, usia_142);
    }
    tampil_142();

    cout << endl;

    // b. Hapus data
    cout << "B. Hapus data" << endl;
    cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
    cin >> nama_142;
    hapusTengah_142(nama_142);

    cout << endl;

    // C. Tambahkan data
    cout << "C. Tambahkan data" << endl;
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan: ";
    cin >> nama_142;
    cout << "Masukkan usia : ";
    cin >> usia_142;
    insertTengah_142(nama_142, usia_142, 2);

    cout << endl;

    // D. Tambahkan data di awal
    cout << "D. Tambahkan data di awal" << endl;
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan di awal: ";
    cin >> nama_142;
    cout << "Masukkan usia : ";
    cin >> usia_142;
    insertDepan_142(nama_142, usia_142);

    cout << endl;

    // E. Ubah data
    cout << "E. Ubah data" << endl;
    string cariNama_142, gantiNama_142;
    int gantiUmur_142;
    cout << "Masukkan nama mahasiswa yang ingin diubah datanya: ";
    cin >> cariNama_142;
    cout << "Masukkan nama baru: ";
    cin >> gantiNama_142;
    cout << "Masukkan usia baru: ";
    cin >> gantiUmur_142;
    ubahData_142(cariNama_142, gantiNama_142, gantiUmur_142);

    cout << endl;

    // F. Tampilkan seluruh data
    cout << "F. Tampilkan seluruh data" << endl;
    cout << "Data Mahasiswa:" << endl;
    tampil_142();

    return 0;
}
```

#### Output:

![Screenshot Output Unguided 1](Unguided1_A.png)
![Screenshot Output Unguided 1](Unguided1_B.png)
![Screenshot Output Unguided 1](Unguided1_C.png)

## ->Penjelasan Program:

Program C++ di atas adalah implementasi dari sebuah aplikasi sederhana untuk mengelola data mahasiswa menggunakan linked list. Program ini memanfaatkan konsep struktur data linked list untuk menyimpan dan mengelola data mahasiswa, termasuk operasi penambahan, penghapusan, dan pembaruan data.

Pertama, program mendeklarasikan sebuah struct Node_142 yang memiliki dua atribut, yaitu nama_142 (bertipe string) dan usia_142 (bertipe int), serta pointer next_142 yang menunjukkan ke node selanjutnya dalam linked list. Selanjutnya, program menginisialisasi linked list dengan mendeklarasikan dua pointer head_142 dan tail_142 yang menunjuk ke node pertama dan terakhir dalam linked list.

Program kemudian menyediakan beberapa fungsi, antara lain:

init_142(): untuk menginisialisasi linked list.
isEmpty_142(): untuk memeriksa apakah linked list kosong.
hitungList_142(): untuk menghitung jumlah node dalam linked list.
insertDepan_142(): untuk menambahkan node baru di depan linked list.
insertBelakang_142(): untuk menambahkan node baru di belakang linked list.
insertTengah_142(): untuk menambahkan node baru di posisi tengah linked list.
hapusTengah_142(): untuk menghapus node di posisi tengah linked list berdasarkan nama.
ubahData_142(): untuk mengubah data mahasiswa berdasarkan nama.
tampil_142(): untuk menampilkan seluruh data mahasiswa dalam linked list.
Dalam fungsi main(), program memberikan beberapa pilihan kepada pengguna untuk mengelola data mahasiswa, antara lain:

Menambahkan data mahasiswa.
Menghapus data mahasiswa.
Menambahkan data mahasiswa di awal atau di tengah.
Mengubah data mahasiswa.
Menampilkan seluruh data mahasiswa.
Dengan antarmuka yang sederhana, pengguna dapat dengan mudah mengelola data mahasiswa sesuai kebutuhan mereka. Program ini memberikan fleksibilitas dalam menambah, menghapus, dan memperbarui data mahasiswa dalam linked list.

## ->Kesimpulan

Program ini memberikan solusi yang sederhana namun efektif dalam pengelolaan data mahasiswa. Dengan antarmuka yang user-friendly dan operasi-operasi yang mudah dipahami, program ini dapat membantu pengguna dalam mengelola data mahasiswa dengan lebih efisien.

### 2. [Soal mengenai Double Linked List

Modifikasi Guided Double Linked List dilakukan dengan penambahan
operasi untuk menambah data, menghapus, dan update di tengah / di
urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya
menampilkan Nama produk dan harga.
Nama Produk Harga
Originote 60.000
Somethinc 150.000
Skintific 100.000
Wardah 50.000
Hanasui 30.000
Case:

1. Tambahkan produk Azarine dengan harga 65000 diantara
   Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini
   Toko Skincare Purwokerto
5. Tambah Data
6. Hapus Data
7. Update Data
8. Tambah Data Urutan Tertentu
9. Hapus Data Urutan Tertentu
10. Hapus Seluruh Data
11. Tampilkan Data
12. Exit
    Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
    ini :
    Nama Produk Harga
    Originote 60.000
    Somethinc 150.000
    Azarine 65.000
    Skintific 100.000
    Cleora 55.000]

```C++
// Dibuat oleh Rizkulloh Dengan NIM 2311102142
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
```

#### Output:

![Screenshot Output Unguided 2](Unguided2_a.png)
![Screenshot Output Unguided 2](Unguided2_b.png)

## ->Penjelasan Program

Program C++ di atas merupakan implementasi sederhana dari sebuah aplikasi toko skincare yang menggunakan struktur data double linked list untuk menyimpan dan mengelola data produk. Dalam program ini, terdapat struktur ProductNode yang menyimpan informasi tentang nama dan harga produk, serta pointer ke node sebelumnya dan node selanjutnya dalam linked list. Kelas DoubleLinkedList digunakan untuk mengelola linked list, dengan metode untuk menambahkan, menampilkan, menghapus, dan mengupdate produk. Program ini juga menyediakan fitur untuk menambahkan produk di urutan tertentu, meskipun belum diimplementasikan fitur untuk menghapus produk dari urutan tertentu. Dengan menggunakan menu interaktif, pengguna dapat memilih operasi yang ingin dilakukan seperti menambah, menghapus, mengupdate, atau menampilkan produk, serta menghapus semua data produk atau keluar dari program. Ini adalah contoh sederhana dari penggunaan struktur data dalam membuat aplikasi yang memungkinkan pengelolaan data produk secara efisien.

## ->Kesimpulan

Program C++ di atas adalah contoh implementasi sederhana dari aplikasi toko skincare menggunakan struktur data double linked list. Program ini memungkinkan pengguna untuk menambah, menghapus, mengupdate, dan menampilkan produk melalui menu interaktif. Meskipun beberapa fitur seperti penghapusan produk dari urutan tertentu belum diimplementasikan, program ini memberikan gambaran tentang penggunaan double linked list dalam pengelolaan data produk secara dinamis.

## Referensi

[1] Putri, Meidyan P., et al. ALGORITMA DAN STRUKTUR DATA. Edited by Putri, Meidyan P. CV WIDINA MEDIA UTAMA, 2022.

[2] Putra, Muhammad Taufik D., et al. BELAJAR DASAR PEMROGRAMAN DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA, 2022.

[3] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications
