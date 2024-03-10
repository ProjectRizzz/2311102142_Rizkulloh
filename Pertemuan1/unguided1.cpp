#include <iostream>
#include <cmath>
//Dibuat oleh Rizkulloh dengan NIM 2311102142
using namespace std;

int main() {
    char pil_142;
    float ang1_142, ang2_142;

    cout << "Operator logika yang kami sediakan :" << endl;
    cout << "A. Tambah (+)" << endl;
    cout << "B. Kurang (-)" << endl;
    cout << "C. Kali (*)" << endl;
    cout << "D. Bagi (/)" << endl;
    cout << "Silahkan masukkan operator (A, B, C, D): ";
    cin >> pil_142;

    cout << "Masukkan angka pertama : ";
    cin >> ang1_142;
    cout << "Masukkan angka kedua : ";
    cin >>ang2_142;

    switch (pil_142) {
        case 'A':
            cout << "Hasil Tambah: " << ang1_142 + ang2_142 << endl;
            break;
        case 'B':
            cout << "Hasil Kurang: " << ang1_142 - ang2_142 << endl;
            break;
        case 'C':
            cout << "Hasil Kali: " << ang1_142 * ang2_142 << endl;
            break;
        case 'D':
            if (ang2_142 != 0)
                cout << "Hasil Bagi: " << ang1_142 / ang2_142 << endl;
            else
                cout << "Tidak bisa melakukan pembagian dengan nol." << endl;
            break;
        default:
            cout << "Operator tidak valid!" << endl;
            break;
    }

    return 0;
}
