// Dibuat Oleh Rizkulloh Dengan NIM 2311102142
#include <iostream>
#include <string>

using namespace std;

struct Node_142
{
    string nama_142;
    string nim_142;
    Node_142 *next_142;
};

void tambahDepan_142(Node_142 **head_142, string nama_142, string nim_142)
{
    Node_142 *newNode_142 = new Node_142;
    newNode_142->nama_142 = nama_142;
    newNode_142->nim_142 = nim_142;
    newNode_142->next_142 = *head_142;
    *head_142 = newNode_142;
}

void tambahBelakang_142(Node_142 **head_142, string nama_142, string nim_142)
{
    Node_142 *newNode_142 = new Node_142;
    newNode_142->nama_142 = nama_142;
    newNode_142->nim_142 = nim_142;
    newNode_142->next_142 = NULL;

    if (*head_142 == NULL)
    {
        *head_142 = newNode_142;
    }
    else
    {
        Node_142 *current_142 = *head_142;
        while (current_142->next_142 != NULL)
        {
            current_142 = current_142->next_142;
        }
        current_142->next_142 = newNode_142;
    }
}

void tambahTengah_142(Node_142 **head_142, string nama_142, string nim_142, int posisi_142)
{
    Node_142 *newNode_142 = new Node_142;
    newNode_142->nama_142 = nama_142;
    newNode_142->nim_142 = nim_142;

    if (posisi_142 == 1)
    {
        tambahDepan_142(head_142, nama_142, nim_142);
    }
    else
    {
        Node_142 *current_142 = *head_142;
        for (int i = 1; i < posisi_142 - 1 && current_142 != NULL; i++)
        {
            current_142 = current_142->next_142;
        }
        if (current_142 == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode_142->next_142 = current_142->next_142;
        current_142->next_142 = newNode_142;
    }
}

void ubahDepan_142(Node_142 **head_142, string nama_142_lama, string nim_142_lama, string nama_142_baru, string nim_142_baru)
{
    Node_142 *current_142 = *head_142;
    while (current_142 != NULL && (current_142->nama_142 != nama_142_lama || current_142->nim_142 != nim_142_lama))
    {
        current_142 = current_142->next_142;
    }

    if (current_142 == NULL)
    {
        cout << "Data tidak ditemukan" << endl;
    }
    else
    {
        current_142->nama_142 = nama_142_baru;
        current_142->nim_142 = nim_142_baru;
        cout << "Data (" << nama_142_lama << " " << nim_142_lama << ") telah diganti dengan data (" << nama_142_baru << " " << nim_142_baru << ")" << endl;
    }
}

void ubahBelakang_142(Node_142 **head_142, string nama_142_lama, string nim_142_lama, string nama_142_baru, string nim_142_baru)
{
    if (*head_142 == NULL)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node_142 *current_142 = *head_142;
    Node_142 *prev_142 = NULL;

    // Mencari node terakhir
    while (current_142->next_142 != NULL)
    {
        prev_142 = current_142;
        current_142 = current_142->next_142;
    }

    // Memeriksa apakah nilai node terakhir sesuai dengan nilai yang ingin diubah
    if (current_142->nama_142 == nama_142_lama && current_142->nim_142 == nim_142_lama)
    {
        // Mengubah nilai node terakhir
        current_142->nama_142 = nama_142_baru;
        current_142->nim_142 = nim_142_baru;
        cout << "Data (" << nama_142_lama << " " << nim_142_lama << ") telah diganti dengan data (" << nama_142_baru << " " << nim_142_baru << ")" << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}

void ubahTengah_142(Node_142 **head_142, string nama_142_lama, string nim_142_lama, string nama_142_baru, string nim_142_baru, int posisi_142)
{
    Node_142 *current_142 = *head_142;
    for (int i = 1; i < posisi_142 && current_142 != NULL; i++)
    {
        current_142 = current_142->next_142;
    }

    if (current_142 == NULL || current_142->next_142 == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    if (current_142->next_142->nama_142 == nama_142_lama && current_142->next_142->nim_142 == nim_142_lama)
    {
        current_142->next_142->nama_142 = nama_142_baru;
        current_142->next_142->nim_142 = nim_142_baru;
        cout << "Data (" << current_142->next_142->nama_142 << " " << current_142->next_142->nim_142 << ") telah diganti dengan data (" << nama_142_baru << " " << nim_142_baru << ")" << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}

void hapusDepan_142(Node_142 **head_142)
{
    if (*head_142 == NULL)
    {
        cout << "List sudah kosong" << endl;
        return;
    }
    Node_142 *current_142 = *head_142;
    *head_142 = current_142->next_142;
    delete current_142;
}

void hapusBelakang_142(Node_142 **head_142)
{
    if (*head_142 == NULL)
    {
        cout << "List sudah kosong" << endl;
        return;
    }
    Node_142 *current_142 = *head_142;
    Node_142 *prev_142 = NULL;
    while (current_142->next_142 != NULL)
    {
        prev_142 = current_142;
        current_142 = current_142->next_142;
    }
    if (prev_142 != NULL)
    {
        prev_142->next_142 = NULL;
    }
    else
    {
        *head_142 = NULL;
    }
    delete current_142;
}

void hapusTengah_142(Node_142 **head_142, int posisi_142)
{
    if (*head_142 == NULL)
    {
        cout << "List sudah kosong" << endl;
        return;
    }
    Node_142 *current_142 = *head_142;
    Node_142 *prev_142 = NULL;
    for (int i = 1; current_142 != NULL && i < posisi_142; i++)
    {
        prev_142 = current_142;
        current_142 = current_142->next_142;
    }
    if (current_142 == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }
    if (prev_142 != NULL)
    {
        prev_142->next_142 = current_142->next_142;
    }
    else
    {
        *head_142 = current_142->next_142;
    }
    delete current_142;
}

void hapusList_142(Node_142 **head_142)
{
    Node_142 *current_142 = *head_142;
    while (current_142 != NULL)
    {
        Node_142 *temp_142 = current_142;
        current_142 = current_142->next_142;
        delete temp_142;
    }
    *head_142 = NULL;
}

void tampilData_142(Node_142 *head_142)
{
    Node_142 *current_142 = head_142;
    while (current_142 != NULL)
    {
        cout << "NAMA : " << current_142->nama_142 << " NIM : " << current_142->nim_142 << endl;
        current_142 = current_142->next_142;
    }
}

int main()
{
    Node_142 *head_142 = NULL;

    int pilihan_142;
    string nama_142, nim_142, nama_142_baru, nim_142_baru;
    int posisi_142;

    do
    {
        cout << "---Silahkan Pilih Menu DI Bawah!---" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan_142;

        switch (pilihan_142)
        {
        case 1:
            cout << "Tambah Depan" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_142;
            cout << "Masukkan NIM : ";
            cin >> nim_142;
            tambahDepan_142(&head_142, nama_142, nim_142);
            cout << "Data " << nama_142 << " Berhasil Ditambahkan!";
            cout << endl;
            break;
        case 2:
            cout << "Tambah Belakang" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_142;
            cout << "Masukkan NIM : ";
            cin >> nim_142;
            tambahBelakang_142(&head_142, nama_142, nim_142);
            cout << "Data " << nama_142 << " Berhasil Ditambahkan!";
            cout << endl;
            break;
        case 3:
            cout << "Tambah Tengah" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_142;
            cout << "Masukkan NIM : ";
            cin >> nim_142;
            cout << "Masukkan Posisi : ";
            cin >> posisi_142;
            tambahTengah_142(&head_142, nama_142, nim_142, posisi_142);
            cout << "Data " << nama_142 << " Berhasil Ditambahkan Pada Posisi " << posisi_142;
            cout << endl;
            break;
        case 4:
            cout << "Ubah Depan" << endl;
            cout << "Masukkan Nama Lama : ";
            cin >> nama_142;
            cout << "Masukkan NIM Lama : ";
            cin >> nim_142;
            cout << "Masukkan Nama Baru : ";
            cin >> nama_142_baru;
            cout << "Masukkan NIM Baru : ";
            cin >> nim_142_baru;
            ubahDepan_142(&head_142, nama_142, nim_142, nama_142_baru, nim_142_baru);
            cout << "Data " << nama_142 << " Telah Di Ganti Dengan Data " << nama_142_baru;
            cout << endl;
            break;
        case 5:
            cout << "Ubah Belakang" << endl;
            cout << "Ubah Depan" << endl;
            cout << "Masukkan Nama Lama : ";
            cin >> nama_142;
            cout << "Masukkan NIM Lama : ";
            cin >> nim_142;
            cout << "Masukkan Nama Baru : ";
            cin >> nama_142_baru;
            cout << "Masukkan NIM Baru : ";
            cin >> nim_142_baru;
            ubahBelakang_142(&head_142, nama_142, nim_142, nama_142_baru, nim_142_baru);
            cout << "Data " << nama_142 << " Telah Di Ganti Dengan Data " << nama_142_baru;
            cout << endl;
            break;

        case 6:
            cout << "Ubah Tengah" << endl;
            cout << "Masukkan Nama Lama : ";
            cin >> nama_142;
            cout << "Masukkan NIM Lama : ";
            cin >> nim_142;
            cout << "Masukkan Nama Baru : ";
            cin >> nama_142_baru;
            cout << "Masukkan NIM Baru : ";
            cin >> nim_142_baru;
            cout << "Masukkan Posisi : ";
            cin >> posisi_142;
            ubahTengah_142(&head_142, nama_142, nim_142, nama_142_baru, nim_142_baru, posisi_142);
            cout << "Data " << nama_142 << " Telah Di Ganti Dengan Data " << nama_142_baru;
            cout << endl;
            break;
        case 7: // Data (nama mahasiswa yang dihapus) berhasil dihapus
            cout << "Hapus Depan" << endl;
            hapusDepan_142(&head_142);
            cout << "Data Berhasil DIhapus!";
            cout << endl;
            break;
        case 8:
            cout << "Hapus Belakang" << endl;
            hapusBelakang_142(&head_142);
            cout << "Data Berhasil DIhapus!";
            cout << endl;
            break;
        case 9:
            cout << "Hapus Tengah" << endl;
            cout << "Masukkan Posisi : ";
            cin >> posisi_142;
            hapusTengah_142(&head_142, posisi_142);
            cout << "Data Berhasil DIhapus Pada Posisi " << posisi_142;
            cout << endl;
            ;
            break;
        case 10:
            cout << "Hapus List" << endl;
            hapusList_142(&head_142);
            cout << "Data Berhasil DIhapus!";
            cout << endl;
            break;
        case 11:
            cout << "Tampilkan" << endl;
            tampilData_142(head_142);
            cout << endl;
            break;
        case 0:
            cout << "Keluar" << endl;
            return 0;
        }
    } while (pilihan_142 != 0);

    return 0;
}