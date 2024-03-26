// dibuat oleh rizkulloh NIM 2311102142
#include <iostream>
#include <string>
using namespace std;

// deklarasi struct node
struct Node_142 {
    string nama_142;
    int usia_142;
    Node_142* next_142;
};

Node_142* head_142 = nullptr;
Node_142* tail_142 = nullptr;

// inisialisasi node
void init_142() {
    head_142 = nullptr;
    tail_142 = nullptr;
}

// pengecekan apakah list kosong
bool isEmpty_142() {
    return head_142 == nullptr;
}

// hitung jumlah node
int hitungList_142() {
    int jumlah_142 = 0;
    Node_142* hitung_142 = head_142;
    while (hitung_142 != nullptr) {
        jumlah_142++;
        hitung_142 = hitung_142->next_142;
    }
    return jumlah_142;
}

// tambah node di depan
void insertDepan_142(string nama_142, int usia_142) {
    Node_142* baru_142 = new Node_142;
    baru_142->nama_142 = nama_142;
    baru_142->usia_142 = usia_142;
    baru_142->next_142 = nullptr;

    if (isEmpty_142()) {
        head_142 = tail_142 = baru_142;
    } else {
        baru_142->next_142 = head_142;
        head_142 = baru_142;
    }
}

// tambah node di belakang
void insertBelakang_142(string nama_142, int usia_142) {
    Node_142* baru_142 = new Node_142;
    baru_142->nama_142 = nama_142;
    baru_142->usia_142 = usia_142;
    baru_142->next_142 = nullptr;

    if (isEmpty_142()) {
        head_142 = tail_142 = baru_142;
    } else {
        tail_142->next_142 = baru_142;
        tail_142 = baru_142;
    }
}

// tambah node di tengah
void insertTengah_142(string nama_142, int usia_142, int posisi_142) {
    if (posisi_142 < 1) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (posisi_142 == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    if (posisi_142 > 1 && posisi_142 <= hitungList_142()) {
        Node_142* baru_142 = new Node_142;
        baru_142->nama_142 = nama_142;
        baru_142->usia_142 = usia_142;

        Node_142* bantu_142 = head_142;
        int nomor_142 = 1;

        while (nomor_142 < posisi_142 - 1) {
            bantu_142 = bantu_142->next_142;
            nomor_142++;
        }

        baru_142->next_142 = bantu_142->next_142;
        bantu_142->next_142 = baru_142;
    } else {
        cout << "Posisi diluar jangkauan" << endl;
    }
}

// hapus node di tengah
void hapusTengah_142(string nama_142) {
    if (!isEmpty_142()) {
        Node_142* hapus_142;
        Node_142* bantu_142 = head_142;

        if (head_142->nama_142 == nama_142) {
            hapus_142 = head_142;
            head_142 = head_142->next_142;
            delete hapus_142;
            return;
        }

        while (bantu_142->next_142 != nullptr && bantu_142->next_142->nama_142 != nama_142) {
            bantu_142 = bantu_142->next_142;
        }

        if (bantu_142->next_142 == nullptr) {
            cout << "Data tidak ditemukan!" << endl;
        } else {
            hapus_142 = bantu_142->next_142;
            bantu_142->next_142 = bantu_142->next_142->next_142;
            delete hapus_142;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// ubah data node
void ubahData_142(string namaCari_142, string namaBaru_142, int usiaBaru_142) {
    Node_142* bantu_142 = head_142;
    while (bantu_142 != nullptr) {
        if (bantu_142->nama_142 == namaCari_142) {
            bantu_142->nama_142 = namaBaru_142;
            bantu_142->usia_142 = usiaBaru_142;
            return;
        }
        bantu_142 = bantu_142->next_142;
    }
    cout << "Data tidak ditemukan!" << endl;
}

// tampilkan seluruh node
void tampil_142() {
    Node_142* bantu_142 = head_142;
    if (!isEmpty_142()) {
        while (bantu_142 != nullptr) {
            cout << bantu_142->nama_142 << " " << bantu_142->usia_142 << endl;
            bantu_142 = bantu_142->next_142;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init_142();

    // Masukkan data mahasiswa
    cout << "A. Masukkan data mahasiswa" << endl;
    cout << "Masukkan data mahasiswa sesuai urutan berikut:" << endl;
    cout << "[Nama] [Usia]" << endl;
    string nama_142;
    int usia_142;
    while (true) {
        cout << "Masukkan nama : ";
        cin >> nama_142;
        if (nama_142 == "stop") break; // apabila menginputkan stop, maka perulangan berhenti
        cout << "Masukkan usia : ";
        cin >> usia_142;
        insertBelakang_142(nama_142, usia_142);
    }
    tampil_142();

    cout << endl;

    // b. Hapus data
    cout << "B. Hapus data" << endl;
    cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
    cin >> nama_142;
    hapusTengah_142(nama_142);

    cout << endl;

    // C. Tambahkan data
    cout << "C. Tambahkan data" << endl;
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan: ";
    cin >> nama_142;
    cout << "Masukkan usia : ";
    cin >> usia_142;
    insertTengah_142(nama_142, usia_142, 2);

    cout << endl;

    // D. Tambahkan data di awal
    cout << "D. Tambahkan data di awal" << endl;
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan di awal: ";
    cin >> nama_142;
    cout << "Masukkan usia : ";
    cin >> usia_142;
    insertDepan_142(nama_142, usia_142);

    cout << endl;

    // E. Ubah data
    cout << "E. Ubah data" << endl;
    string cariNama_142, gantiNama_142;
    int gantiUmur_142;
    cout << "Masukkan nama mahasiswa yang ingin diubah datanya: ";
    cin >> cariNama_142;
    cout << "Masukkan nama baru: ";
    cin >> gantiNama_142;
    cout << "Masukkan usia baru: ";
    cin >> gantiUmur_142;
    ubahData_142(cariNama_142, gantiNama_142, gantiUmur_142);

    cout << endl;

    // F. Tampilkan seluruh data
    cout << "F. Tampilkan seluruh data" << endl;
    cout << "Data Mahasiswa:" << endl;
    tampil_142();

    return 0;
}