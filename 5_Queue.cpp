#include <iostream>
using namespace std;

struct queue
{
    int size;
    int front, rear;
    int *arr;
};

void enqueue(struct queue *q, int val)
{
    if (q->rear == q->size - 1)
    {
        cout << "\nQueue is full !!!" << endl;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
        cout << "\n\nEnqueued : " << q->arr[q->rear] << endl;
        cout << "Front : " << q->front << " Rear : " << q->rear;
    }
}

void dequeue(struct queue *q)
{
    if (q->rear == q->front)
    {
        cout << "\nQueue is empty !!!" << endl;
    }
    else
    {
        q->front++;
        cout << "\n\nDequeued : " << q->arr[q->front] << endl;
        cout << "Front : " << q->front << " Rear : " << q->rear;
        q->arr[q->front] = 0;
    }
}

void print(struct queue *q)
{
    if (q->front == q->rear)
    {
        cout << "Queue is empty !!!" << endl;
    }
    else
    {
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            cout << q->arr[i] << " ";
        }
    }
    cout << "\nFront : " << q->front << " Rear : " << q->rear;
}

int main()
{
    struct queue q;
    q.size = 4;
    q.front = q.rear = -1;
    q.arr = new int(q.size);
    cout << "Front : " << q.front << " Rear : " << q.rear;
    enqueue(&q, 25);
    enqueue(&q, 78);
    enqueue(&q, 56);
    enqueue(&q, 82);

    cout << "\n\nThe elements in the queue is :";
    print(&q);

    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);

    // cout << "\n\nThe elements in the queue is :";
    // print(&q);

    return 0;
}