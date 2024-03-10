# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Rizkulloh Alpriyansah</p>

## Dasar Teori

1. Tipe Data Primitif:
   Tipe data primitif merupakan tipe data dasar yang tersedia di dalam bahasa pemrograman. Tipe data ini mewakili nilai tunggal dan memiliki ukuran yang tetap.
   Contoh tipe data primitif termasuk integer (bilangan bulat), float (bilangan desimal), double (bilangan desimal dengan presisi ganda), char (karakter), dan bool (nilai kebenaran).
   Tipe data primitif digunakan untuk merepresentasikan data sederhana seperti angka, karakter, atau nilai kebenaran yang tidak memerlukan struktur yang kompleks.

2. Tipe Data Abstrak (ADT - Abstract Data Type):
   Tipe data abstrak merupakan tipe data yang didefinisikan oleh kumpulan operasi yang dapat dilakukan terhadap data tersebut, tanpa mengungkapkan bagaimana operasi tersebut diimplementasikan.
   ADT menyediakan antarmuka yang terstandarisasi untuk berinteraksi dengan data, memungkinkan pengguna untuk menggunakan operasi tersebut tanpa perlu mengetahui detail implementasinya.
   Contoh tipe data abstrak meliputi struktur data seperti stack, queue, linked list, dan tree, serta tipe data kompleks seperti bilangan kompleks atau matriks.

3. Tipe Data Koleksi:
   Tipe data koleksi digunakan untuk menyimpan sejumlah nilai atau objek dalam satu variabel. Ini memungkinkan pengelompokan data menjadi satu unit logis untuk mempermudah pengolahan data.
   Contoh tipe data koleksi termasuk array, vector (di C++), list, set, map, dan hash table.
   Tipe data koleksi memungkinkan pengguna untuk menyimpan dan mengelola data dalam jumlah yang besar dan beragam, serta memberikan akses cepat ke elemen-elemennya.

## Guided

### 1. [tipe data primitif]

```C++
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
char op;
float num1, num2;
// It allows user to enter operator i.e. +, -, *, /
cout << "Enter operator (+, -, *, /): ";
cin >> op;
// It allows user to enter the operands
cout << "Enter two operands: ";
Praktikum Struktur Data dan Algoritma 3
cin >> num1 >> num2;
// Switch statement begins
switch (op) {
// If user enters +
case '+':
cout << "Result: " << num1 + num2;
break;
// If user enters -
case '-':
cout << "Result: " << num1 - num2;
break;
// If user enters *
case '*':
cout << "Result: " << num1 * num2;
break;
// If user enters /
case '/':
if (num2 != 0) {
cout << "Result: " << fixed << setprecision(2) <<
num1 / num2;
} else {
cout << "Error! Division by zero is not allowed.";
}
break;
// If the operator is other than +, -, * or /,
// error message will display
default:
cout << "Error! Operator is not correct";
} // switch statement ends
return 0;
}
```

->Program ini meminta pengguna untuk memasukkan operator (+, -, _, /) dan dua bilangan. Kemudian, program akan melakukan operasi matematika yang sesuai dengan operator tersebut.
Jika operator yang dimasukkan oleh pengguna adalah +, -, _, atau /, maka program akan melakukan operasi tersebut dan menampilkan hasilnya. Jika operator tidak sesuai, program akan memberi tahu pengguna bahwa operator yang dimasukkan tidak benar.
Program juga mengatasi kasus pembagian dengan nol dengan memberi tahu pengguna bahwa pembagian dengan nol tidak diperbolehkan.
Setelah melakukan operasi, program akan berakhir dan keluar dengan nilai 0.

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>
//tipe data abstrak by Rizkulloh
struct Mahasiswa
{
    char name [50];
    char address [100];
    int age;

};
int main()
{
    struct Mahasiswa mhs1, mhs2;
    strcpy(mhs1.name, "Dian");
    strcpy (mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);

    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

->Program tersebut merupakan contoh penggunaan struktur (struct) dalam bahasa pemrograman untuk merepresentasikan data mahasiswa. Setiap mahasiswa memiliki nama (name), alamat (address), dan umur (age).
Dua variabel bertipe struct Mahasiswa, yaitu mhs1 dan mhs2, digunakan untuk menyimpan informasi dua mahasiswa yang berbeda.
Data untuk setiap mahasiswa diinisialisasi menggunakan fungsi strcpy() untuk menyalin string ke dalam array karakter.
Selanjutnya, program menampilkan informasi masing-masing mahasiswa dengan menggunakan printf().

### 2. [Tipe Data Abstrak]

```C++
#include <iostream>
#include <array>
//tipe data koleksi by Rizkulloh Alpriyansah
using namespace std;
int main() {
// Deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
// Mencetak array dengan tab
cout << "Isi array pertama : " << nilai[0] << endl;
cout << "Isi array kedua : " << nilai[1] << endl;
cout << "Isi array ketiga : " << nilai[2] << endl;
cout << "Isi array keempat : " << nilai[3] << endl;
cout << "Isi array kelima : " << nilai[4] << endl;
return 0;
}
```

->Program di atas merupakan contoh penggunaan array dalam bahasa C++. Array digunakan untuk menyimpan sekumpulan nilai yang memiliki tipe data yang sama.
Dalam program ini, sebuah array bernama "nilai" dengan ukuran 5 elemen dideklarasikan dan diinisialisasi dengan nilai-nilai tertentu.
Kemudian, setiap elemen dari array tersebut dicetak menggunakan perulangan cout. Pesan yang dicetak menampilkan indeks array serta nilainya.
Setelah itu, program berakhir dan mengembalikan nilai 0.

## Unguided

### 1. [Soal]

```C++
//Di buat oleh Rizkulloh Alpriyansah dengan nim 2311102142
#include <iostream>
#include <cmath>
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
```

#### Output:

![Screenshot Output Unguided 1](Screenshot_Output_Unguided-1_Rizkulloh.png)

## ->Penjelasan Program:

Program meminta pengguna untuk memilih operator aritmatika (A, B, C, atau D) dan memasukkan dua angka.
Setelah input diterima, program menggunakan struktur switch-case untuk melakukan operasi sesuai dengan operator yang dimasukkan pengguna.
Jika operator adalah pembagian dan angka kedua adalah nol, program memberikan pesan kesalahan karena tidak dapat melakukan pembagian dengan nol.
Hasil operasi aritmatika kemudian dicetak ke layar.

## Kesimpulan

Program ini menggunakan tipe data primitif seperti char untuk menyimpan operator dan float untuk menyimpan angka.
Struktur kontrol switch-case digunakan untuk mengevaluasi operator yang dimasukkan pengguna dan melakukan operasi yang sesuai.
Program ini memberikan kesempatan kepada pengguna untuk melakukan operasi matematika sederhana dengan mudah.
Penggunaan tipe data primitif dalam program ini memungkinkan penulisan kode yang sederhana dan efisien untuk operasi matematika dasar.

## Referensi

[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
