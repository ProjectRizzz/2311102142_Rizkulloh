# <h1 align="center">Laporan Praktikum Modul ARRAY</h1>

<p align="center">Rizkulloh Alpriyansah</p>

## Dasar Teori

Array merupakan kumpulan variabel yang terstruktur, digunakan untuk menyimpan data dengan tipe yang serupa atau data-data yang disusun secara berurutan. Di dalamnya, setiap elemen memiliki tipe data yang serupa. Indeks digunakan untuk mengakses setiap elemen yang disimpan dalam array, sedangkan panjang atau length menyatakan jumlah total elemen yang tersimpan di dalamnya. Secara umum, terdapat tiga jenis tipe data array yang sering dikenal:

Array Satu Dimensi:
Array satu dimensi adalah kumpulan elemen yang disusun secara linear. Elemen-elemen ini dapat diakses menggunakan satu indeks. Keunggulan dari array satu dimensi adalah kemudahan penggunaan dan pembacaan. Contohnya, kita dapat menggunakan array Nilai[5] untuk menyimpan 5 nilai integer atau Nama[10] untuk menyimpan 10 nama string.

Array Dua Dimensi:
Array dua dimensi adalah struktur data yang memiliki dua dimensi, sering kali dijelaskan sebagai tabel dengan baris dan kolom. Elemen-elemen dalam array ini diakses menggunakan dua indeks yang mewakili posisi baris dan kolomnya. Array ini berguna untuk menyimpan data yang memerlukan pengaturan dua dimensi, seperti matriks. Sebagai contoh, kita dapat menggunakan array NilaiUjian[3][5] untuk menyimpan nilai ujian 3 siswa untuk 5 mata pelajaran yang berbeda.

Array Multidimensi:
Array multidimensi adalah struktur data yang memiliki lebih dari dua dimensi. Ini memungkinkan representasi data dengan lebih banyak tingkat hierarki dan kompleksitas. Array ini digunakan untuk menyimpan data yang memerlukan struktur yang lebih kompleks, seperti data spasial atau temporal. Contohnya, Warna[3][3][3] dapat digunakan untuk menyimpan data warna RGB untuk 3 objek, di mana setiap objek memiliki 3 bagian dan setiap bagian memiliki 3 warna yang berbeda.

## Guided

### 1. [Latihan Single Linked List]

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

//Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void insertDepan(int nilai) {
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int nilai) {
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List
int hitungList() {
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi) {
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }
            if (nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data) {
    if (isEmpty() == false) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi) {
    Node *bantu;
    if (isEmpty() == false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data) {
    if (isEmpty() == false) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil() {
    Node *bantu;
    bantu = head;
    if (isEmpty() == false) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
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

Program C++ di atas adalah implementasi dari Single Linked List non-circular yang memungkinkan operasi dasar seperti penambahan, penghapusan, dan pengubahan elemen, serta menampilkan isi dari linked list. Dalam program ini, struktur data Node digunakan untuk merepresentasikan setiap elemen dalam linked list, yang terdiri dari dua bagian: data (bertipe int) dan pointer ke simpul berikutnya (next). Fungsi-fungsi seperti init() untuk menginisialisasi linked list, isEmpty() untuk memeriksa apakah linked list kosong, insertDepan() dan insertBelakang() untuk menambahkan elemen di depan dan di belakang, serta hapusDepan() dan hapusBelakang() untuk menghapus elemen pertama dan terakhir. Fungsi insertTengah() dan hapusTengah() digunakan untuk menambahkan dan menghapus elemen pada posisi tertentu. Untuk mengubah nilai data dari elemen, terdapat fungsi seperti ubahDepan(), ubahBelakang(), dan ubahTengah(). Fungsi hitungList() digunakan untuk menghitung jumlah elemen dalam linked list, sementara clearList() untuk menghapus seluruh isi linked list. Program ini kemudian diuji dengan memanggil fungsi-fungsi tersebut dan menampilkan isi linked list setelah setiap operasi dilakukan.

### 2. [Latihan Double Linked List]

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2: {
            list.pop();
            break;
        }
        case 3: {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated) {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4: {
            list.deleteAll();
            break;
        }
        case 5: {
            list.display();
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```

### ->Penjelasan

Program C++ di atas merupakan implementasi dari Doubly Linked List menggunakan kelas DoublyLinkedList dan kelas Node. Doubly Linked List adalah struktur data linear di mana setiap elemen (node) memiliki dua pointer, yaitu pointer ke node sebelumnya (prev) dan pointer ke node selanjutnya (next).

Kelas DoublyLinkedList memiliki anggota data head dan tail, yang merupakan pointer ke node pertama dan terakhir dalam linked list. Metode push() digunakan untuk menambahkan elemen baru di depan linked list. Metode pop() menghapus elemen pertama dari linked list. Metode update() digunakan untuk mengubah nilai data dari suatu elemen berdasarkan nilai data lama yang diberikan. Metode deleteAll() menghapus seluruh isi linked list. Metode display() digunakan untuk menampilkan isi dari linked list.

Dalam fungsi main(), pengguna dapat memilih berbagai operasi yang ingin dilakukan pada linked list melalui menu pilihan. Pilihan termasuk menambahkan data baru, menghapus data, mengubah data, menghapus seluruh isi linked list, dan menampilkan isi linked list. Program akan terus berjalan hingga pengguna memilih untuk keluar.

Program ini memberikan fleksibilitas bagi pengguna untuk mengelola Doubly Linked List dengan mudah melalui antarmuka yang sederhana dan intuitif.

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

![Screenshot Output Unguided 1](Output_Unguided1_Rizkulloh.png)

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

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user]

```C++
// Dibuat oleh Rizkulloh Dengan NIM 2311102142
#include <iostream>

using namespace std;

int main() {
    int x_142, y_142, z_142;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan jumlah elemen untuk dimensi pertama: ";
    cin >> x_142;
    cout << "Masukkan jumlah elemen untuk dimensi kedua: ";
    cin >> y_142;
    cout << "Masukkan jumlah elemen untuk dimensi ketiga: ";
    cin >> z_142;

    // Deklarasi array tiga dimensi sesuai dengan ukuran yang dimasukkan pengguna
    int array3D[x_142][y_142][z_142];

    // Memasukkan nilai ke dalam array
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < x_142; ++i) {
        for (int j = 0; j < y_142; ++j) {
            for (int k = 0; k < z_142; ++k) {
                cout << "Masukkan nilai untuk elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan isi array
    cout << "Isi array:" << endl;
    for (int i = 0; i < x_142; ++i) {
        for (int j = 0; j < y_142; ++j) {
            for (int k = 0; k < z_142; ++k) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

```

#### Output:

![Screenshot Output Unguided 2](Output_unguided2_pt1.png)
![Screenshot Output Unguided 2](Output_unguided2_pt2.png)

## ->Penjelasan Program:

Program C++ di atas merupakan contoh penggunaan array tiga dimensi. Program meminta pengguna untuk memasukkan jumlah elemen untuk setiap dimensi array, kemudian membuat array tiga dimensi sesuai dengan ukuran yang dimasukkan. Setelah itu, program meminta pengguna untuk memasukkan nilai-nilai untuk setiap elemen array dan menampilkannya ke layar.

Penjelasan langkah demi langkah:

Pertama, program meminta pengguna untuk memasukkan jumlah elemen untuk masing-masing dimensi array.
Array tiga dimensi array3D dideklarasikan dengan ukuran yang dimasukkan pengguna.
Pengguna diminta untuk memasukkan nilai untuk setiap elemen array menggunakan tiga loop bersarang, masing-masing untuk dimensi pertama, kedua, dan ketiga.
Setelah semua nilai dimasukkan, program menampilkan isi array ke layar menggunakan loop bersarang.

## -> Kesimpulan

Program ini memperlihatkan cara menggunakan array tiga dimensi dalam bahasa pemrograman C++. Array tiga dimensi digunakan untuk menyimpan data dalam bentuk tiga dimensi, seperti dalam kasus ini, di mana data disusun dalam baris, kolom, dan lapisan. Program memungkinkan pengguna untuk memasukkan data ke dalam array dan menampilkan isi array tersebut.

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
//Dibuat Oleh Rizkulloh Dengan NIM 2311102142
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int size;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> size;

    // Membuat array sesuai dengan ukuran yang dimasukkan pengguna
    int arr[size];

    // Meminta pengguna untuk memasukkan nilai-nilai array
    cout << "Masukkan nilai-nilai array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Nilai elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    char repeat;

    do {
        // Menampilkan menu
        cout << "Pilih operasi yang ingin dilakukan:" << endl;
        cout << "1. Cari nilai maksimum" << endl;
        cout << "2. Cari nilai minimum" << endl;
        cout << "3. Cari nilai rata-rata" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        // Proses sesuai dengan pilihan pengguna
        switch (choice) {
            case 1: {
                // Mencari nilai maksimum
                int maxVal = INT_MIN;
                for (int i = 0; i < size; ++i) {
                    if (arr[i] > maxVal) {
                        maxVal = arr[i];
                    }
                }
                cout << "Nilai maksimum dalam array: " << maxVal << endl;
                break;
            }
            case 2: {
                // Mencari nilai minimum
                int minVal = INT_MAX;
                for (int i = 0; i < size; ++i) {
                    if (arr[i] < minVal) {
                        minVal = arr[i];
                    }
                }
                cout << "Nilai minimum dalam array: " << minVal << endl;
                break;
            }
            case 3: {
                // Menghitung nilai rata-rata
                int sum = 0;
                for (int i = 0; i < size; ++i) {
                    sum += arr[i];
                }
                double average = static_cast<double>(sum) / size;
                cout << "Nilai rata-rata dari array: " << average << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        cout << "Mau melakukan operasi lain? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
```

#### Output:

![Screenshot Output Unguided 3](Output_unguided3_Rizkulloh.png)

## ->Penjelasan Program

Program C++ di atas merupakan program sederhana yang meminta pengguna untuk memasukkan ukuran array dan nilai-nilai dalam array tersebut. Kemudian, program memberikan pilihan kepada pengguna untuk melakukan operasi tertentu seperti mencari nilai maksimum, nilai minimum, atau nilai rata-rata dari elemen-elemen array.

Penjelasan langkah demi langkah:

1. Program meminta pengguna untuk memasukkan ukuran array.
2. Array arr dibuat dengan ukuran yang dimasukkan oleh pengguna.
3. Pengguna diminta untuk memasukkan nilai-nilai array.
4. Program memberikan pilihan kepada pengguna untuk memilih operasi yang ingin dilakukan.
5. Bergantung pada pilihan pengguna, program menjalankan proses yang sesuai menggunakan switch-case:
   Jika pengguna memilih 1, program mencari nilai maksimum dalam array.
   Jika pengguna memilih 2, program mencari nilai minimum dalam array.
   Jika pengguna memilih 3, program menghitung nilai rata-rata dari array.
   Jika pilihan tidak valid, program memberikan pesan kesalahan.
6. Setelah operasi selesai dilakukan, program meminta pengguna apakah ingin melakukan operasi lain atau tidak.
7. Jika pengguna memilih untuk melanjutkan, program akan kembali ke langkah 4. Jika tidak, program selesai.

## ->Kesimpulan

Program ini memungkinkan pengguna untuk memasukkan nilai-nilai ke dalam array dan melakukan operasi seperti mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array. Pengguna dapat melakukan operasi berulang sesuai dengan keinginan mereka.

## Referensi

[1] Putri, Meidyan P., et al. ALGORITMA DAN STRUKTUR DATA. Edited by Putri, Meidyan P. CV WIDINA MEDIA UTAMA, 2022.

[2] Putra, Muhammad Taufik D., et al. BELAJAR DASAR PEMROGRAMAN DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA, 2022.
