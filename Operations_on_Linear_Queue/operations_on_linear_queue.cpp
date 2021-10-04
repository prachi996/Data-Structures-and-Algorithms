#include <iostream>
using namespace std;
#define MAX 5

class Linear_queue
{
private:
    int front, rear;
    int ele[MAX];

public:
    Linear_queue()
    {
        front = 0;
        rear = -1;
    }

    int isFull();
    int isEmpty();
    void insertion(int item);
    int deletion(int *item);
};

int Linear_queue::isFull()
{
    int full = 0;

    if (rear == MAX - 1)
        full = 1;

    return full;
}

int Linear_queue::isEmpty()
{
    int empty = 0;

    if (front == rear + 1)
        empty = 1;

    return empty;
}

void Linear_queue::insertion(int item)
{
    if (isFull())
    {
        cout << "\nQueue OverFlow" << endl;
        return;
    }

    ele[++rear] = item;
    cout << "\ninserted Value :" << item;
}

int Linear_queue::deletion(int *item)
{
    if (isEmpty())
    {
        cout << "\nQueue Underflow" << endl;
        return -1;
    }

    *item = ele[front++];
    return 0;
}

int main()
{
    int item = 0;

    Linear_queue q = Linear_queue();

    q.insertion(10);
    q.insertion(20);
    q.insertion(30);
    q.insertion(40);
    q.insertion(50);
    q.insertion(60);

    if (q.deletion(&item) == 0)
        cout << "\nDeleted item : " << item;

    if (q.deletion(&item) == 0)
        cout << "\nDeleted item : " << item;

    if (q.deletion(&item) == 0)
        cout << "\nDeleted item : " << item;

    if (q.deletion(&item) == 0)
        cout << "\nDeleted item : " << item;

    if (q.deletion(&item) == 0)
        cout << "\nDeleted item : " << item;

    if (q.deletion(&item) == 0)
        cout << "\nDeleted item : " << item;

    cout << endl;
    return 0;
}