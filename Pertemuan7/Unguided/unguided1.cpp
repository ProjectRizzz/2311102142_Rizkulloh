#include <iostream>
using namespace std;

struct Node_142
{
    string data_142;
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

    void enqueue_142(const string &data_142)
    {
        Node_142 *newNode_142 = new Node_142;
        newNode_142->data_142 = data_142;
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
        cout << "Berhasil menambahkan " << data_142 << " ke dalam antrian." << endl;
    }

    void dequeue_142()
    {
        if (isEmpty_142())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node_142 *temp_142 = front_142;
        cout << "Mengeluarkan " << front_142->data_142 << " dari antrian." << endl;
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
        cout << "Data antrian teller:" << endl;
        Node_142 *current_142 = front_142;
        int count_142 = 1;
        while (current_142 != nullptr)
        {
            cout << count_142 << ". " << current_142->data_142 << endl;
            current_142 = current_142->next_142;
            count_142++;
        }
    }
};

int main()
{
    Queue_142 queue_142;
    queue_142.enqueue_142("Andi");
    queue_142.enqueue_142("Maya");
    queue_142.viewQueue_142();
    queue_142.dequeue_142();
    queue_142.viewQueue_142();
    return 0;
}
