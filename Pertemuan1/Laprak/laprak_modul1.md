# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Rizkulloh Alpriyansah</p>

## Dasar Teori

Tipe Data Primitif:

1. Tipe data primitif merupakan tipe data dasar yang tersedia di dalam bahasa pemrograman. Tipe data ini mewakili nilai tunggal dan memiliki ukuran yang tetap.
   Contoh tipe data primitif termasuk integer (bilangan bulat), float (bilangan desimal), double (bilangan desimal dengan presisi ganda), char (karakter), dan bool (nilai kebenaran).
   Tipe data primitif digunakan untuk merepresentasikan data sederhana seperti angka, karakter, atau nilai kebenaran yang tidak memerlukan struktur yang kompleks.
   Tipe Data Abstrak (ADT - Abstract Data Type):

2. Tipe data abstrak merupakan tipe data yang didefinisikan oleh kumpulan operasi yang dapat dilakukan terhadap data tersebut, tanpa mengungkapkan bagaimana operasi tersebut diimplementasikan.
   ADT menyediakan antarmuka yang terstandarisasi untuk berinteraksi dengan data, memungkinkan pengguna untuk menggunakan operasi tersebut tanpa perlu mengetahui detail implementasinya.
   Contoh tipe data abstrak meliputi struktur data seperti stack, queue, linked list, dan tree, serta tipe data kompleks seperti bilangan kompleks atau matriks.
   Tipe Data Koleksi:

3. Tipe data koleksi digunakan untuk menyimpan sejumlah nilai atau objek dalam satu variabel. Ini memungkinkan pengelompokan data menjadi satu unit logis untuk mempermudah pengolahan data.
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
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```

#### Output:

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan

Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi

[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
