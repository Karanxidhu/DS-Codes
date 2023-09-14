#include <iostream>
using namespace std;

#define MAX 100

struct queue
{
    int element[MAX];
    int front, rear;
};

queue init()
{
    queue q;
    q.front = q.rear = -1;
    return q;
}

int size(queue q)
{
    return (q.rear - q.front + 1);
}

int isEmpty(queue q)
{
    return (q.front == -1 || q.front > q.rear);
}

int isFull(queue q)
{
    return (q.rear == MAX - 1);
}

int front(queue q)
{
    if (isEmpty(q))
    {
        cout << "Empty queue" << endl;
        return -1;
    }
    else
    {
        return (q.element[q.front]);
    }
}

queue enque(queue q)
{
    int x;
    cout << "enter the number to be inserted" << endl;
    cin >> x;
    if (isFull(q))
    {
        cout << "Full queue" << endl;
    }
    else if (isEmpty(q))
    {
        q.front = 0;
        q.rear = 0;
        q.element[q.rear] = x;
    }
    else
    {
        ++q.rear;
        q.element[q.rear] = x;
    }
    return q;
}

void printQueue(queue q)
{
    for (int i = q.front; i <= q.rear; i++)
    {
        cout << q.element[i] << "\t";
    }
    cout << endl;
}

queue dequeue(queue q){
    if(isEmpty(q)){
        cout<<"Empty queue"<<endl;
    }else{
        q.front++;
    }
        return q;
}

int main()
{
    queue q;
    q = init();
    int choice;
    while (1)
    {
        cout << "Enter the operation:\n1.enque\n2.deque\n3.front\n4.print\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            q = enque(q);
            break;

        case 2:
            q = dequeue(q);
            break;
        case 3:
            cout<<front(q);
            break;

        case 4:
            printQueue(q);
            break;
        default:
            break;
        }
    }

    return 0;
}