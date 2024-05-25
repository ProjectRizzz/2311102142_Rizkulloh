// Dibuat oleh Rizkulloh Alpriyansah dengan NIM 2311102142
#include <iostream>
#include <string>

using namespace std;

// Fungsi buat nyari huruf vokal
bool isVowel_142(char c_142)
{
    c_142 = tolower(c_142); // Biar gak case-sensitive
    return (c_142 == 'a' || c_142 == 'e' || c_142 == 'i' || c_142 == 'o' || c_142 == 'u');
}

int countVowels_142(const string &sentence_142)
{
    int vowelCount_142 = 0;

    for (char c_142 : sentence_142)
    {
        if (isVowel_142(c_142))
        {
            vowelCount_142++;
        }
    }

    return vowelCount_142;
}

int main()
{
    string sentence_142;

    // Input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, sentence_142);

    // Hitung jumlah huruf vokal
    int vowelCount_142 = countVowels_142(sentence_142);

    cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount_142 << endl;

    return 0;
}
