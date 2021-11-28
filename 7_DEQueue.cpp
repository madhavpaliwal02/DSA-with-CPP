#include <iostream>
using namespace std;

struct queue
{
    int size;
    int front, rear;
    int *arr;
};

struct queue *enqueueR(struct queue *q, int val)
{
    if (q->rear == q->size - 1)
    {
        cout << "Queue is Full !!" << endl;
    }
    else
    {
        q->arr[++q->rear] = val;
        cout << "Enqueued : " << q->arr[q->rear];
        cout << "\nFront : " << q->front << "\tRear : " << q->rear << endl;
    }
    return q;
}

struct queue *enqueueF(struct queue *q, int val)
{
    if (q->front == -1)
    {
        cout << "Queue is Full !!" << endl;
    }
    else
    {
        q->arr[q->front] = val;
        cout << "Enqueued : " << q->arr[q->front];
        cout << "\nFront : " << q->front-- << "\tRear : " << q->rear << endl;
    }
    return q;
}

struct queue *dequeueF(struct queue *q)
{
    if (q->front == q->rear)
    {
        cout << "Queue is Empty !!" << endl;
    }
    else
    {
        cout << "Dequeued : " << q->arr[++q->front];
        cout << "\nFront : " << q->front << "\tRear : " << q->rear << endl;
    }
    return q;
}

struct queue *dequeueR(struct queue *q)
{
    if (q->front == q->rear)
    {
        cout << "Queue is Empty !!" << endl;
    }
    else
    {
        cout << "Dequeued : " << q->arr[q->rear--];
        cout << "\nFront : " << q->front << "\tRear : " << q->rear << endl;
    }
    return q;
}

void display(struct queue *q)
{
    if (q->front == q->rear)
    {
        cout << "Queue is empty !!!" << endl;
    }
    {
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            cout << q->arr[i] << " ";
        }
    }
    cout << endl;
    // cout << "\nFront : " << q->front << " Rear : " << q->rear;
}

int main()
{
    struct queue q;
    q.size = 5;
    q.arr = new int[q.size];
    q.front = q.rear = -1;

    enqueueR(&q, 25);
    enqueueR(&q, 45);
    enqueueR(&q, 72);
    enqueueR(&q, 64);
    enqueueR(&q, 72);
    display(&q);

    dequeueF(&q);
    dequeueF(&q);
    dequeueR(&q);
    // display(&q);

    enqueueF(&q, 45);
    enqueueF(&q, 78);
    enqueueF(&q, 45);
    // enqueueF(&q, 78);
    // display(&q);

    // dequeue(&q);

    return 0;
}