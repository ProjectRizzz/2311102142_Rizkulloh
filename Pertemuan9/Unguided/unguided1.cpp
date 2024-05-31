// by Rizkulloh Alpriyansah Dengan NIM 2311102142
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk menampilkan adjacency matrix
void displayMatrix(vector<vector<int>> &matriks_142, vector<string> &simpul_142)
{
    int jumlah_simpul_142 = matriks_142.size(); // Mendapatkan jumlah simpul dari ukuran matrix

    // Menampilkan label simpul di atas adjacency matrix
    cout << " ";
    for (int i = 0; i < jumlah_simpul_142; i++)
    {
        cout << simpul_142[i] << " ";
    }
    cout << endl;

    // Menampilkan adjacency matrix
    for (int i = 0; i < jumlah_simpul_142; i++)
    {
        cout << simpul_142[i] << " ";
        for (int j = 0; j < jumlah_simpul_142; j++)
        {
            cout << matriks_142[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int jumlah_simpul_142;
    cout << "Silakan masukkan jumlah simpul: "; // Meminta pengguna untuk memasukkan jumlah simpul
    cin >> jumlah_simpul_142;

    // Mendeklarasikan vektor untuk menyimpan nama-nama simpul
    vector<string> simpul_142(jumlah_simpul_142);
    // Meminta pengguna untuk memasukkan nama simpul
    cout << "Silakan masukkan nama simpul: " << endl;
    for (int i = 0; i < jumlah_simpul_142; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul_142[i];
    }

    // Mendeklarasikan adjacency matrix sebagai matriks berukuran jumlah_simpul x jumlah_simpul
    vector<vector<int>> matriks_jarak_142(jumlah_simpul_142, vector<int>(jumlah_simpul_142));
    // Meminta pengguna untuk memasukkan bobot antar simpul
    cout << "\nSilakan masukkan bobot antar simpul: " << endl;
    for (int i = 0; i < jumlah_simpul_142; i++)
    {
        for (int j = 0; j < jumlah_simpul_142; j++)
        {
            cout << simpul_142[i] << " -> " << simpul_142[j] << " = ";
            cin >> matriks_jarak_142[i][j];
        }
    }
    cout << endl;
    displayMatrix(matriks_jarak_142, simpul_142); // Memanggil fungsi untuk menampilkan adjacency matrix
    return 0;
}
