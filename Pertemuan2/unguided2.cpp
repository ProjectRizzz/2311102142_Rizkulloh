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
