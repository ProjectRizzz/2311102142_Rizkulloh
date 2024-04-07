# <h1 align="center">Laporan Praktikum MODUL V HASH TABLE</h1>

<p align="center">Rizkulloh Alpriyansah</p>

## Dasar Teori

Hash table merupakan struktur data yang digunakan untuk menyimpan dan mengorganisir data dengan cara yang efisien. Konsep dasar dari hash table adalah penggunaan fungsi hash untuk memetakan kunci (key) ke dalam indeks array. Setiap kunci memiliki nilai hash yang unik yang menentukan posisi atau indeks di mana data akan disimpan di dalam array. Ini memungkinkan akses yang cepat ke data tanpa perlu memindai seluruh array.

Ada beberapa komponen kunci dalam pemahaman hash table:

1. Fungsi Hash: Ini adalah fungsi matematis yang mengubah kunci menjadi indeks array. Tujuan dari fungsi hash adalah untuk mendistribusikan kunci secara merata di seluruh rentang indeks array dan menghindari tabrakan (collision), yaitu ketika dua kunci memiliki nilai hash yang sama. Fungsi hash yang baik menghasilkan nilai hash yang unik untuk setiap kunci.

2. Array (Tabel Hash): Ini adalah struktur data utama yang digunakan untuk menyimpan elemen-elemen data. Setiap elemen dalam array berperan sebagai slot atau bucket yang dapat menyimpan satu atau lebih item data. Ukuran array harus cukup besar untuk menampung semua data yang mungkin disimpan di dalamnya.

3. Tabrakan (Collision): Ini terjadi ketika dua atau lebih kunci menghasilkan nilai hash yang sama. Tabrakan harus ditangani dengan tepat agar tidak mengakibatkan kehilangan data. Salah satu metode yang umum digunakan untuk menangani tabrakan adalah dengan menggunakan teknik seperti chaining atau open addressing.

4. Penanganan Tabrakan: Ada beberapa pendekatan untuk menangani tabrakan. Dalam chaining, setiap slot array memiliki daftar terkait yang menyimpan semua elemen yang memiliki nilai hash yang sama. Dalam open addressing, jika terjadi tabrakan, algoritma mencari slot lain dalam array untuk menempatkan data yang bersangkutan.

Implementasi hash table dalam bahasa pemrograman C++ biasanya melibatkan pembuatan struktur data untuk elemen-elemen data (seperti struktur atau kelas), penggunaan array untuk tabel hash, dan implementasi fungsi hash yang sesuai. Operasi-operasi seperti penambahan, penghapusan, pencarian, dan penelusuran biasanya diimplementasikan dalam kelas hash table itu sendiri.

Dengan menggunakan hash table, pencarian data dapat dilakukan dalam waktu yang konstan, membuatnya menjadi struktur data yang sangat efisien untuk keperluan seperti penyimpanan data, database, dan cache. Namun, pemilihan fungsi hash yang baik dan penanganan tabrakan yang efektif sangat penting untuk kinerja dan integritas data yang optimal.

## Guided

### 1. [Guided I]

```C++
// Dibuat Oleh Rizkulloh Alpriyansah Dengan NIM 2311102142
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```

### -> Penjelasan Program

Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam
hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node
merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan
modulus untuk memetakan setiap input kunci ke nilai indeks array.

### 2. [Guided II]

```C++
// Dibuat Oleh Rizkulloh Alpriyansah Dengan NIM 2311102142
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```

### ->Penjelasan

Pada program di atas, class HashNode merepresentasikan setiap node dalam hash
table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap
digunakan untuk mengimplementasikan struktur hash table dengan menggunakan
vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan
untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi
insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi
remove digunakan untuk menghapus data dari hash table, dan fungsi
searchByName digunakan untuk mencari nomor telepon dari karyawan dengan
nama yang diberikan.

## Unguided

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :

a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).]

```C++
// Dibuat Oleh Rizkulloh Dengan NIM 2311102142
#include <iostream>
#include <string>
#include <iomanip> // Untuk setw

using namespace std;

const int UKURAN_MAKS_142 = 100; // Ukuran hash table

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa_142
{
    string nama_142;
    long long NIM_142;
    int nilai_142;
    Mahasiswa_142 *berikutnya_142; // Untuk menangani tabrakan (collision) pada hash table
};

// Class HashTable untuk menyimpan data mahasiswa menggunakan hash table
class TabelHash_142
{
private:
    static const int ukuranTabel_142 = 100;        // Ukuran hash table
    Mahasiswa_142 *tabelHash_142[ukuranTabel_142]; // Array untuk menyimpan pointer ke elemen-elemen hash table

public:
    TabelHash_142()
    {
        // Inisialisasi semua elemen hash table dengan nullptr
        for (int i = 0; i < ukuranTabel_142; ++i)
        {
            tabelHash_142[i] = nullptr;
        }
    }

    // Fungsi hash untuk menghasilkan indeks berdasarkan NIM
    int fungsiHash_142(long long NIM_142)
    {
        return NIM_142 % ukuranTabel_142;
    }

    // Fungsi untuk menambahkan data mahasiswa ke hash table
    void tambahData_142(string nama_142, long long NIM_142, int nilai_142)
    {
        int indeks_142 = fungsiHash_142(NIM_142);
        Mahasiswa_142 *baru_142 = new Mahasiswa_142;
        baru_142->nama_142 = nama_142;
        baru_142->NIM_142 = NIM_142;
        baru_142->nilai_142 = nilai_142;
        baru_142->berikutnya_142 = nullptr;

        if (tabelHash_142[indeks_142] == nullptr)
        {
            tabelHash_142[indeks_142] = baru_142;
        }
        else
        {
            Mahasiswa_142 *temp_142 = tabelHash_142[indeks_142];
            while (temp_142->berikutnya_142 != nullptr)
            {
                temp_142 = temp_142->berikutnya_142;
            }
            temp_142->berikutnya_142 = baru_142;
        }
        cout << "Data mahasiswa berhasil ditambahkan." << endl;
    }

    // Fungsi untuk menghapus data mahasiswa dari hash table berdasarkan NIM
    void hapusData_142(long long NIM_142)
    {
        int indeks_142 = fungsiHash_142(NIM_142);
        if (tabelHash_142[indeks_142] == nullptr)
        {
            cout << "Data mahasiswa dengan NIM " << NIM_142 << " tidak ditemukan." << endl;
            return;
        }

        Mahasiswa_142 *temp_142 = tabelHash_142[indeks_142];
        Mahasiswa_142 *prev_142 = nullptr;
        while (temp_142 != nullptr && temp_142->NIM_142 != NIM_142)
        {
            prev_142 = temp_142;
            temp_142 = temp_142->berikutnya_142;
        }

        if (temp_142 == nullptr)
        {
            cout << "Data mahasiswa dengan NIM " << NIM_142 << " tidak ditemukan." << endl;
            return;
        }

        if (prev_142 == nullptr)
        {
            tabelHash_142[indeks_142] = temp_142->berikutnya_142;
        }
        else
        {
            prev_142->berikutnya_142 = temp_142->berikutnya_142;
        }
        delete temp_142;
        cout << "Data mahasiswa dengan NIM " << NIM_142 << " berhasil dihapus." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariDataNIM_142(long long NIM_142)
    {
        int indeks_142 = fungsiHash_142(NIM_142);
        Mahasiswa_142 *temp_142 = tabelHash_142[indeks_142];
        while (temp_142 != nullptr)
        {
            if (temp_142->NIM_142 == NIM_142)
            {
                cout << "Data mahasiswa dengan NIM " << NIM_142 << " ditemukan. Nilainya: " << temp_142->nilai_142 << endl;
                return;
            }
            temp_142 = temp_142->berikutnya_142;
        }
        cout << "Data mahasiswa dengan NIM " << NIM_142 << " tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void cariBerdasarkanRentangNilai_142(int BatasAwalRentang_142, int BatasAkhirRentang_142)
    {
        cout << left << setw(15) << "-NAMA-" << setw(20) << "-NIM-" << right << setw(2) << "-NILAI-" << endl;
        for (int i = 0; i < ukuranTabel_142; i++)
        { // Untuk setiap indeks yang ada di tabel hash table ini, akan diiterasi satu per satu untuk mencari data yang sesuai dengan rentang yang diinginkan
            Mahasiswa_142 *current_142 = tabelHash_142[i];
            while (current_142 != nullptr)
            {
                if (current_142->nilai_142 >= BatasAwalRentang_142 && current_142->nilai_142 <= BatasAkhirRentang_142)
                {                                                                                                                                                // Jika nilai mahasiswa berada di dalam rentang yang diinginkan
                    cout << left << setw(15) << current_142->nama_142 << setw(20) << current_142->NIM_142 << right << setw(6) << current_142->nilai_142 << endl; // Maka data mahasiswa tersebut akan ditampilkan
                }
                current_142 = current_142->berikutnya_142;
            }
        }
    }

    // Fungsi untuk penelusuran seluruh data mahasiswa
    void penelusuran_142()
    {
        cout << left << setw(17) << "-NAMA-" << setw(17) << "-NIM-" << setw(12) << "-NILAI-" << endl;
        for (int i = 0; i < ukuranTabel_142; i++)
        {
            Mahasiswa_142 *current_142 = tabelHash_142[i];
            while (current_142 != nullptr)
            {
                cout << left << setw(17) << current_142->nama_142 << setw(19) << current_142->NIM_142 << setw(12) << current_142->nilai_142 << endl;
                current_142 = current_142->berikutnya_142;
            }
        }
    }
};

int main()
{
    TabelHash_142 tabelHash;
    char pilihan_142;
    string nama_142;
    long long NIM_142;
    int nilai_142;

    do
    {
        cout << "\n---Hi Rizkulloh---\n";
        cout << "\nSilahkan Pilih Menu Dibawah:\n";
        cout << "a. Tambah Data Mahasiswa\n";
        cout << "b. Hapus Data Mahasiswa\n";
        cout << "c. Cari Data Mahasiswa Berdasarkan NIM\n";
        cout << "d. Cari Data Mahasiswa Berdasarkan Rentang Nilai (80 - 90)\n";
        cout << "e. Penelusuran Seluruh Data Mahasiswa\n";
        cout << "f. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan_142;

        switch (pilihan_142)
        {
        case 'a':
        case 'A':
            cout << "\n ---Silahkan Masukan Data Mahasiswa Baru---" << endl;
            cout << "Masukkan Nama: ";
            cin >> nama_142;
            cout << "Masukkan NIM: ";
            cin >> NIM_142;
            cout << "Masukkan nilai: ";
            cin >> nilai_142;
            tabelHash.tambahData_142(nama_142, NIM_142, nilai_142);
            cout << "Anda Telah Berhasil Memasukan Data " << NIM_142;
            cout << endl;
            break;
        case 'b':
        case 'B':
            cout << "\n---Hapus Data Mahasiswa---" << endl;
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> NIM_142;
            tabelHash.hapusData_142(NIM_142);
            cout << "Anda Telah Berhasil Menghapus Data " << NIM_142;
            cout << endl;
            break;
        case 'c':
        case 'C':
            cout << "\nCari Data Mahasiswa Berdasarkan NIM" << endl;
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> NIM_142;
            tabelHash.cariDataNIM_142(NIM_142);
            cout << endl;
            break;
        case 'd':
        case 'D':
            cout << "\nData Mahasiswa Berdasarkan Rentang Nilai" << endl;
            int batasAwal_142, batasAkhir_142;
            cout << "Masukkan rentang nilai (misal: 80 90): ";
            cin >> batasAwal_142 >> batasAkhir_142;
            tabelHash.cariBerdasarkanRentangNilai_142(batasAwal_142, batasAkhir_142);
            cout << endl;
            break;
        case 'e':
        case 'E':
            cout << "\nPenelusuran Seluruh Data Mahasiswa\n";
            tabelHash.penelusuran_142();
            cout << endl;
            break;
        case 'f':
        case 'F':
            cout << "Terima kasih!";
            cout << endl;
            break;
        default:
            cout << "Pilihan tidak valid!";
            break;
        }
    } while (pilihan_142 != 'f');

    return 0;
}
```

#### Output :

#### Screenshot Bagian A

![Screenshot Output Unguided1](A.png)

#### Screenshot Bagian B

![Screenshot Output Unguided1](B.png)

#### Screenshot Bagian C

![Screenshot Output Unguided1](C.png)

#### Screenshot Bagian D

![Screenshot Output Unguided1](D.png)

## ->Penjelasan Program:

Program C++ di atas adalah implementasi sederhana dari hash table untuk menyimpan data mahasiswa.

##### Library yang Digunakan

Program menggunakan library <iostream> untuk operasi input-output.

Juga menggunakan <string> untuk bekerja dengan tipe data string.

Dan <iomanip> digunakan untuk menggunakan fungsi setw() yang mengatur lebar bidang output.

##### Struktur Data Mahasiswa

Terdapat struktur data Mahasiswa_142 yang memiliki tiga atribut: nama_142 (nama mahasiswa), NIM_142 (Nomor Induk Mahasiswa), dan nilai_142 (nilai mahasiswa).

Struktur data ini juga memiliki pointer berikutnya_142 yang digunakan untuk menangani tabrakan (collision) pada hash table.

##### Class HashTable

TabelHash_142 adalah class yang digunakan untuk menyimpan data mahasiswa menggunakan hash table.

Ukuran hash table ditentukan sebagai konstanta ukuranTabel_142 yang memiliki nilai default 100.

Hash table direpresentasikan sebagai array dari pointer ke elemen-elemen hash table.

##### Method dan Fungsi

Konstruktor TabelHash_142(): Digunakan untuk menginisialisasi semua elemen hash table dengan nullptr.

Fungsi fungsiHash_142(long long NIM_142): Menghasilkan indeks berdasarkan NIM dengan menggunakan operasi modulus.

Fungsi tambahData_142(): Digunakan untuk menambahkan data mahasiswa ke hash table. Jika terjadi collision, data ditambahkan sebagai elemen berikutnya.

Fungsi hapusData_142(): Menghapus data mahasiswa dari hash table berdasarkan NIM.

Fungsi cariDataNIM_142(): Mencari data mahasiswa berdasarkan NIM di hash table dan menampilkan nilai jika ditemukan.

Fungsi cariBerdasarkanRentangNilai_142(): Mencari data mahasiswa berdasarkan rentang nilai yang ditentukan.

Fungsi penelusuran_142(): Menampilkan seluruh data mahasiswa yang tersimpan di hash table.

##### Main Function

Terdapat loop do-while yang memungkinkan pengguna memilih berbagai operasi seperti tambah data, hapus data, cari data, dan penelusuran data.

Pengguna memasukkan pilihan menu yang diinginkan, dan sesuai dengan pilihan tersebut, program akan menjalankan fungsi yang sesuai dari class TabelHash_142.

Loop akan berlanjut hingga pengguna memilih untuk keluar dari program.

## ->Kesimpulan

Program C++ di atas adalah implementasi sederhana dari hash table untuk menyimpan data mahasiswa. Dengan menggunakan struktur data yang sesuai dan fungsi hashing, program ini memungkinkan pengguna untuk menambah, menghapus, mencari, dan menelusuri data mahasiswa berdasarkan NIM atau rentang nilai. Melalui penggunaan loop dan switch case, program memberikan antarmuka yang interaktif kepada pengguna untuk melakukan berbagai operasi terhadap data mahasiswa. Dengan demikian, program ini menyediakan solusi yang efisien dan mudah digunakan dalam manajemen data mahasiswa.

## Referensi

[1] Putri, Meidyan P., et al. ALGORITMA DAN STRUKTUR DATA. Edited by Putri, Meidyan P. CV WIDINA MEDIA UTAMA, 2022.

[2] Putra, Muhammad Taufik D., et al. BELAJAR DASAR PEMROGRAMAN DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA, 2022.

[3] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications
