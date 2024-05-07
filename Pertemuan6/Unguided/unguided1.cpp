// Dibuat oleh Rizkulloh Alpriyansah dengan NIM 2311102142
#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Untuk menggunakan fungsi isalnum()

using namespace std;

// Fungsi untuk menghapus karakter non-alfanumerik dari sebuah string
string hapusKarakterNonAlfanumerik(const string &str_142)
{
    string hasil_142;
    for (char karakter_142 : str_142)
    {
        if (isalnum(karakter_142))
        {                                       // Menggunakan isalnum() untuk memeriksa apakah karakter adalah alfanumerik
            hasil_142 += tolower(karakter_142); // Mengubah karakter menjadi huruf kecil dan menambahkannya ke hasil
        }
    }
    return hasil_142;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau tidak
bool apakahPalindrom(const string &str_142)
{
    stack<char> tumpukanKarakter_142;
    int panjang_142 = str_142.length();

    // Menambahkan setengah karakter pertama ke dalam stack
    for (int i_142 = 0; i_142 < panjang_142 / 2; ++i_142)
    {
        tumpukanKarakter_142.push(str_142[i_142]);
    }

    // Membandingkan karakter setengah pertama dengan setengah kedua
    int i_142 = (panjang_142 + 1) / 2; // Memulai dari setengah karakter setelahnya
    while (i_142 < panjang_142)
    {
        if (tumpukanKarakter_142.top() != str_142[i_142])
        {
            return false; // Tidak merupakan palindrom jika ada perbedaan karakter
        }
        tumpukanKarakter_142.pop();
        ++i_142;
    }
    return true; // Jika tidak ada perbedaan, string adalah palindrom
}

int main()
{
    string masukan_142;
    cout << "Masukkan kalimat: ";
    getline(cin, masukan_142);

    // Menghapus karakter non-alfanumerik dan mengonversi menjadi huruf kecil
    string masukanYangDibersihkan_142 = hapusKarakterNonAlfanumerik(masukan_142);

    // Memeriksa apakah string yang sudah dibersihkan adalah palindrom atau tidak
    if (apakahPalindrom(masukanYangDibersihkan_142))
    {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    }
    else
    {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}