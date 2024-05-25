// Dibuat oleh Rizkulloh Alpriyansah dengan NIM 2311102142
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi buat binary search
int binarySearch_142(const string &sorted_str_142, char target_142)
{
    int left_142 = 0;
    int right_142 = sorted_str_142.size() - 1;

    while (left_142 <= right_142)
    {
        int mid_142 = left_142 + (right_142 - left_142) / 2;

        if (sorted_str_142[mid_142] == target_142)
        {
            return mid_142;
        }
        else if (sorted_str_142[mid_142] < target_142)
        {
            left_142 = mid_142 + 1;
        }
        else
        {
            right_142 = mid_142 - 1;
        }
    }
    return -1;
}

int main()
{
    string sentence_142;
    char target_142;

    // Input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, sentence_142);

    // Input huruf yang mau dicari
    cout << "Masukkan huruf yang mau dicari: ";
    cin >> target_142;

    // Hilangin spasi dari kalimat
    sentence_142.erase(remove(sentence_142.begin(), sentence_142.end(), ' '), sentence_142.end());

    // Ubah kalimat jadi huruf kecil semua
    transform(sentence_142.begin(), sentence_142.end(), sentence_142.begin(), ::tolower);

    // Urutkan kalimat
    sort(sentence_142.begin(), sentence_142.end());

    // Lakukan binary search
    int result_142 = binarySearch_142(sentence_142, target_142);

    if (result_142 != -1)
    {
        cout << "Huruf '" << target_142 << "' ditemukan di indeks " << result_142 << " dalam kalimat yang sudah diurutkan.\n";
    }
    else
    {
        cout << "Huruf '" << target_142 << "' tidak ditemukan dalam kalimat.\n";
    }

    return 0;
}
