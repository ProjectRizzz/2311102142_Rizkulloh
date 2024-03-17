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
    
    // Menampilkan menu
    cout << "Pilih operasi yang ingin dilakukan:" << endl;
    cout << "1. Cari nilai maksimum" << endl;
    cout << "2. Cari nilai minimum" << endl;
    cout << "3. Cari nilai rata-rata" << endl;
    cout << "Pilihan: ";
    
    int choice;
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
    
    return 0;
}