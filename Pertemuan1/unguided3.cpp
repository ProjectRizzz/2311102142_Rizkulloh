//Dibuat Oleh Rizkulloh Dengan NIM 2311102142
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Membuat map untuk menyimpan nomor tiket dengan nama penumpang
    map<int, string> tiketBus_142;

    // Menambahkan data ke dalam map
    tiketBus_142[1] = "Alfi";
    tiketBus_142[2] = "Bayu";
    tiketBus_142[3] = "Cindy";
    tiketBus_142[4] = "Eve";
    tiketBus_142[5] = "Eva";

    // Menampilkan nomor tiket bus beserta nama penumpang
    cout << "Nomor Tiket Bus dan Nama Penumpang:" << endl;
    for (const auto& pair : tiketBus_142) {
        cout << "Nomor Tiket: " << pair.first << ", Nama Penumpang: " << pair.second << endl;
    }
    cout << endl;
    // Mengakses nama penumpang dengan nomor tiket tertentu
    int nomorTiket = 3;
    cout << "Nama Penumpang dengan Nomor Tiket " << nomorTiket << ": " << tiketBus_142[nomorTiket] << endl;

    return 0;
}
