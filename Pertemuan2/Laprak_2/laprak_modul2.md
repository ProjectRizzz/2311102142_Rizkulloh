# <h1 align="center">Laporan Praktikum Modul ARRAY</h1>

<p align="center">Rizkulloh Alpriyansah</p>

## Dasar Teori

Dasar Teori tentang Array dalam C++
Array adalah struktur data dalam bahasa pemrograman C++ yang dapat menyimpan sejumlah elemen data dari tipe yang sama dalam urutan yang terdefinisi.
Setiap elemen dalam array diakses menggunakan indeks yang menunjukkan posisi relatifnya dalam array.

Deklarasi Array:
Untuk mendeklarasikan array dalam C++, kita perlu menentukan tipe data yang akan disimpan dalam array serta jumlah elemen yang akan ditampung.

Inisialisasi Array:
Array bisa diinisialisasi saat mendeklarasikannya atau setelahnya.

Mengakses Elemen Array:
Elemen-elemen dalam array diakses menggunakan indeksnya.

Operasi pada Array:
Berbagai operasi dapat dilakukan pada array, seperti pengisian nilai, pencarian nilai maksimum/minimum, atau pengurutan elemen-elemennya.

Keterbatasan Array:

Ukuran array harus ditentukan pada saat kompilasi, yang berarti kita perlu mengetahui berapa banyak elemen yang akan disimpan dalam array sebelum program dijalankan.
Array tidak dapat diperbesar atau diperkecil secara dinamis saat program berjalan.
Penanganan Array yang Fleksibel:

Untuk menangani keterbatasan array, C++ menyediakan mekanisme lain seperti std::vector yang dapat memperbesar atau memperkecil ukurannya sesuai kebutuhan.

## Guided

### 1. [Program Input Array Tiga Dimensi]

```C++
#include <iostream>

using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI By Rizkulloh dengan NIM 2311102142
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

### -> Penjelasan Program

Program tersebut adalah contoh implementasi array 3 dimensi dalam C++. Array tersebut berukuran 2x3x3. Program meminta pengguna untuk memasukkan nilai untuk setiap elemen array dan kemudian mencetak kembali nilai-nilai tersebut dengan label indeks dan tanpa label indeks. Ini dilakukan menggunakan nested loop untuk mengakses setiap elemen array.

### 2. [Program Mencari Nilai Maksimal pada Array]

```C++
#include <stdio.h>
#include <iostream>
// By Rizkulloh Dengan NIM 2311102142
using namespace std;

int main(){
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
        {
            cout << "Array ke-" << (i) << ": ";
            cin >> array[i];
        }
    maks = array[0];
    for (i = 0; i < a; i++)
        {
        if (array[i] > maks)
            {
                maks = array[i];
                lokasi = i;
            }
        }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```

->

## Unguided

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user]

```C++
//Di buat oleh Rizkulloh Alpriyansah dengan nim 2311102142
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
```

#### Output:

![Screenshot Output Unguided 1](Output_Unguided1_Rizkulloh.png)

## ->Penjelasan Program:

## ->Kesimpulan

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user]

```C++
// Dibuat oleh Rizkulloh Dengan NIM 2311102142
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

```

#### Output:

![Screenshot Output Unguided 2]()

## ->Penjelasan Program:

## Penjelasan class dan struct

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map]

```C++
//Dibuat Oleh Rizkulloh Dengan NIM 2311102142
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

    int choice;
    char repeat;

    do {
        // Menampilkan menu
        cout << "Pilih operasi yang ingin dilakukan:" << endl;
        cout << "1. Cari nilai maksimum" << endl;
        cout << "2. Cari nilai minimum" << endl;
        cout << "3. Cari nilai rata-rata" << endl;
        cout << "Pilihan: ";
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

        cout << "Mau melakukan operasi lain? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
```

#### Output:

![Screenshot Output Unguided 3]()

## ->Penjelasan Program:

## ->Kesimpulan

## Referensi

[1] Putri, Meidyan P., et al. ALGORITMA DAN STRUKTUR DATA. Edited by Putri, Meidyan P. CV WIDINA MEDIA UTAMA, 2022.

[2] Putra, Muhammad Taufik D., et al. BELAJAR DASAR PEMROGRAMAN DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA, 2022.
