#include <iostream>
using namespace std;

int main() {
    int angka_142[10];
    int angkaGenap_142[10];
    int angkaGanjil_142[10];
    int jmlGenap_142 = 0;
    int jmlGanjil_142 = 0;

    cout << "Masukkan 10 angka dipisahkan oleh spasi:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> angka_142[i];
    }

    for (int i = 0; i < 10; ++i) {
        if (angka_142[i] % 2 == 0) {
            angkaGenap_142[jmlGenap_142] = angka_142[i];
            jmlGenap_142++;
        } else {
            angkaGanjil_142[jmlGanjil_142] = angka_142[i];
            jmlGanjil_142++;
        }
    }

    cout << "\nAngka Genap: ";
    for (int i = 0; i < jmlGenap_142; ++i) {
        cout << angkaGenap_142[i] << " ";
    }

    cout << "\nAngka Ganjil: ";
    for (int i = 0; i < jmlGanjil_142; ++i) {
        cout << angkaGanjil_142[i] << " ";
    }

    return 0;
}