#include <iostream>
using namespace std;

struct Mahasiswa_142
{
    string nama_142;
    string nim_142;
};

struct Node_142
{
    Mahasiswa_142 data_142;
    Node_142 *next_142;
};

class Queue_142
{
private:
    Node_142 *front_142;
    Node_142 *back_142;

public:
    Queue_142() : front_142(nullptr), back_142(nullptr) {}

    bool isEmpty_142()
    {
        return front_142 == nullptr;
    }

    void enqueue_142(const Mahasiswa_142 &mhs_142)
    {
        Node_142 *newNode_142 = new Node_142;
        newNode_142->data_142 = mhs_142;
        newNode_142->next_142 = nullptr;

        if (isEmpty_142())
        {
            front_142 = newNode_142;
            back_142 = newNode_142;
        }
        else
        {
            back_142->next_142 = newNode_142;
            back_142 = newNode_142;
        }
        cout << "Berhasil menambahkan " << mhs_142.nama_142 << " dengan NIM " << mhs_142.nim_142 << " ke dalam antrian." << endl;
    }

    void dequeue_142()
    {
        if (isEmpty_142())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node_142 *temp_142 = front_142;
        cout << "Mengeluarkan " << front_142->data_142.nama_142 << " dengan NIM " << front_142->data_142.nim_142 << " dari antrian." << endl;
        front_142 = front_142->next_142;
        delete temp_142;
    }

    void viewQueue_142()
    {
        if (isEmpty_142())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian mahasiswa:" << endl;
        Node_142 *current_142 = front_142;
        int count_142 = 1;
        while (current_142 != nullptr)
        {
            cout << count_142 << ". " << current_142->data_142.nama_142 << " (NIM: " << current_142->data_142.nim_142 << ")" << endl;
            current_142 = current_142->next_142;
            count_142++;
        }
    }
};

int main()
{
    Queue_142 queue_142;
    Mahasiswa_142 mhs1_142 = {"Andi", "2311102142"};
    Mahasiswa_142 mhs2_142 = {"Maya", "2311102143"};
    queue_142.enqueue_142(mhs1_142);
    queue_142.enqueue_142(mhs2_142);
    queue_142.viewQueue_142();
    queue_142.dequeue_142();
    queue_142.viewQueue_142();
    return 0;
}
