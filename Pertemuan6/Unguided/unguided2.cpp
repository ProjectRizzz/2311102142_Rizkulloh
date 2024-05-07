// Dibuat oleh Rizkulloh Alpriyansah dengan NIM 2311102142
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan sebuah kalimat menggunakan stack
string balikKalimat_142(const string &kalimat_142)
{
    stack<char> tumpukan_142;
    string hasil_142;

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char karakter_142 : kalimat_142)
    {
        tumpukan_142.push(karakter_142);
    }

    // Mengambil setiap karakter dari stack untuk membentuk kalimat terbalik
    while (!tumpukan_142.empty())
    {
        hasil_142 += tumpukan_142.top();
        tumpukan_142.pop();
    }

    return hasil_142;
}

int main()
{
    string kalimat_142;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat_142);

    // Memanggil fungsi balikKalimat untuk membalikkan kalimat yang dimasukkan pengguna
    string kalimatTerbalik_142 = balikKalimat_142(kalimat_142);

    // Menampilkan hasil pembalikan kalimat
    cout << "Hasil: " << kalimatTerbalik_142 << endl;

    return 0;
}
