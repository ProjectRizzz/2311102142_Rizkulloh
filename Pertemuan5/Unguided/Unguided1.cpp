// Dibuat Oleh Rizkulloh Alpriyansah Dengan NIM 2311102142

#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa
{
    string NIM;
    int nilai;
    Mahasiswa *next; // Untuk menangani tabrakan (collision) pada hash table
};

// Class HashTable untuk menyimpan data mahasiswa menggunakan hash table
class HashTable
{
private:
    static const int tableSize = 100; // Ukuran hash table
    Mahasiswa *hashTable[tableSize];  // Array untuk menyimpan pointer ke elemen-elemen hash table

public:
    HashTable()
    {
        // Inisialisasi semua elemen hash table dengan nullptr
        for (int i = 0; i < tableSize; ++i)
        {
            hashTable[i] = nullptr;
        }
    }

    // Fungsi hash untuk menghasilkan indeks berdasarkan NIM
    int hashFunction(string NIM)
    {
        int sum = 0;
        for (char c : NIM)
        {
            sum += c;
        }
        return sum % tableSize;
    }

    // Fungsi untuk menambahkan data mahasiswa ke hash table
    void tambahData(string NIM, int nilai)
    {
        int index = hashFunction(NIM);
        Mahasiswa *baru = new Mahasiswa;
        baru->NIM = NIM;
        baru->nilai = nilai;
        baru->next = nullptr;

        if (hashTable[index] == nullptr)
        {
            hashTable[index] = baru;
        }
        else
        {
            Mahasiswa *temp = hashTable[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = baru;
        }
        cout << "Data mahasiswa berhasil ditambahkan." << endl;
    }

    // Fungsi untuk menghapus data mahasiswa dari hash table berdasarkan NIM
    void hapusData(string NIM)
    {
        int index = hashFunction(NIM);
        if (hashTable[index] == nullptr)
        {
            cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
            return;
        }

        Mahasiswa *temp = hashTable[index];
        Mahasiswa *prev = nullptr;
        while (temp != nullptr && temp->NIM != NIM)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
            return;
        }

        if (prev == nullptr)
        {
            hashTable[index] = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Data mahasiswa dengan NIM " << NIM << " berhasil dihapus." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariDataNIM(string NIM)
    {
        int index = hashFunction(NIM);
        Mahasiswa *temp = hashTable[index];
        while (temp != nullptr)
        {
            if (temp->NIM == NIM)
            {
                cout << "Data mahasiswa dengan NIM " << NIM << " ditemukan. Nilainya: " << temp->nilai << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    void cariDataRentangNilai()
    {
        cout << "Data mahasiswa dengan nilai antara 80 dan 90:" << endl;
        for (int i = 0; i < tableSize; ++i)
        {
            Mahasiswa *temp = hashTable[i];
            while (temp != nullptr)
            {
                if (temp->nilai >= 80 && temp->nilai <= 90)
                {
                    cout << "NIM: " << temp->NIM << ", Nilai: " << temp->nilai << endl;
                }
                temp = temp->next;
            }
        }
    }
};

int main()
{
    HashTable hashTable;
    char pilihan;
    string NIM;
    int nilai;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa Berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa Berdasarkan Rentang Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cout << "Masukkan nilai: ";
            cin >> nilai;
            hashTable.tambahData(NIM, nilai);
            break;
        case '2':
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> NIM;
            hashTable.hapusData(NIM);
            break;
        case '3':
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> NIM;
            hashTable.cariDataNIM(NIM);
            break;
        case '4':
            hashTable.cariDataRentangNilai();
            break;
        case '5':
            cout << "Terima kasih!";
            break;
        default:
            cout << "Pilihan tidak valid!";
            break;
        }
    } while (pilihan != '5');

    return 0;
}