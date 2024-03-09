# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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
