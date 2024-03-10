// Dibuat oleh Rizkulloh Dengan NIM 2311102142
#include <iostream>
#include <string>

using namespace std;

// Struct untuk menyimpan nama dan nomor favorit
struct Biodata {
    string nama_142;
    int nomorFavorit_142;
};

// Class untuk merepresentasikan sebuah kendaraan
class Kendaraan {
private:
    string jenis_142;
    string merek_142;
    string model_142;
    int tahun_142;

public:
    // Constructor untuk menginisialisasi objek Kendaraan
    Kendaraan(string jns, string m, string mdl, int thn) : jenis_142(jns), merek_142(m), model_142(mdl), tahun_142(thn) {}

    // Metode untuk menampilkan informasi kendaraan
    void display() {
        cout << "Jenis Kendaraan: " << jenis_142 << endl;
        cout << "Merek: " << merek_142 << ", Model: " << model_142 << ", Tahun: " << tahun_142 << endl;
    }
};

int main() {
    // Membuat objek Biodata
    Biodata biodata_142;
    biodata_142.nama_142 = "Rizkulloh";
    biodata_142.nomorFavorit_142 = 7;

    // Menampilkan informasi biodata
    cout << "Biodata:" << endl;
    cout << "Nama: " << biodata_142.nama_142 << endl;
    cout << "Nomor Favorit: " << biodata_142.nomorFavorit_142 << endl;

    // Membuat objek Kendaraan
    Kendaraan mobil_142("Mobil", "Toyota", "Avanza", 2020);

    // Menampilkan informasi kendaraan
    cout << "\nInformasi Kendaraan:" << endl;
    mobil_142.display();

    return 0;
}