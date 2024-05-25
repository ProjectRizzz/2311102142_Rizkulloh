// Dibuat oleh Rizkulloh Alpriyansah dengan NIM 2311102142
#include <iostream>

using namespace std;

// Fungsi buat menghitung jumlah angka 4 menggunakan Sequential Search
int countNumber_142(const int data_142[], int size_142, int target_142)
{
    int count_142 = 0;
    for (int i_142 = 0; i_142 < size_142; ++i_142)
    {
        if (data_142[i_142] == target_142)
        {
            count_142++;
        }
    }
    return count_142;
}

int main()
{
    int data_142[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size_142 = sizeof(data_142) / sizeof(data_142[0]);
    int target_142 = 4;

    int count_142 = countNumber_142(data_142, size_142, target_142);

    cout << "Jumlah angka " << target_142 << " dalam array: " << count_142 << endl;

    return 0;
}
