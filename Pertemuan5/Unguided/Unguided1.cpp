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