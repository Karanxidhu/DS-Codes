#include <iostream>
using namespace std;

#define MAX 8

struct que
{
    int element[MAX];
    int front, rear;
};

que init()
{
    que Q;
    Q.front = Q.rear = -1;
    return Q;
}

int isFull(que Q){
    return (Q.front == (Q.rear + 1)%MAX);
}

int isEmpty(que Q){
    return (Q.front == Q.rear && Q.rear == -1);
}

que enque(que Q){
    int x;
    cout << "enter the number to be added"<<endl;
    cin >> x;
    if(isFull(Q)){
        cout<<"Que is full"<<endl;
    }else{
        Q.rear = (Q.rear + 1)%MAX;
        Q.element[Q.rear] = x;
        cout<<"front:"<<Q.front<<"\n rear:"<<Q.rear<<endl;
    }
    if(Q.front == -1){
        Q.front = 0;
        cout<<"front:"<<Q.front<<"\n rear:"<<Q.rear<<endl;
    }
    return Q;
}

void printQue(que Q){
    for(int i = Q.front; i<= Q.rear; i++){
        cout<< Q.element[i]<< "\t";
    }
    cout<<endl;
}

que deque(que Q){
    if(isEmpty(Q)){
        cout<<"Que is empty"<<endl;
    }else{
        int item = Q.element[Q.front];
        if(Q.front == Q.rear){
            Q.front = Q.rear = -1;
        }else{
            Q.front = (Q.front + 1)%MAX;
        }
    }
    return Q;
}

int main()
{
    que Q;
    Q = init();
    int choice;
    while(1){
    cout << "Enter the operation:\n1.enque\n2.deque\n3.front\n4.print\n";
    cin>>choice;
    switch (choice)
        {
        case 1:
            Q = enque(Q);
            break;

        case 2:
            Q = deque(Q);
            break;
        case 3:
            // cout<<front(q);
            break;

        case 4:
            printQue(Q);
            break;
        default:
            break;
        }
    }
    return 0;
}