// MA KA BHAROSA AGAR YE COPY KIA 

#include<iostream>
using namespace std;

#define MAX 100 

struct stack{
    int element[MAX];
    int top;
};

int isFull(stack S){
    return(S.top == MAX-1);
}

int isEmpty(stack S){
    return(S.top == -1);
}

stack init(){
    stack S;
    S.top = -1;
    return S;
}

stack push(stack S){
    if(isFull(S)){
        cout<<endl<<"OVERFLOW"<<endl;
    }else{
        int temp;
        cout<<"enter the number you want to push"<<endl;
        cin>>temp;
        ++S.top;
        S.element[S.top] = temp;
    }
    return S;
}

stack pop(stack S){
    if(isEmpty(S)){
        cout<<"UNDERFLOW"<<endl;
    }else{
        int temp;
        temp = S.element[S.top];
        --S.top;
        cout<<endl<<temp<<" is popped out"<<endl;
    }
        return S;
}

void peek(stack S){
    if(isEmpty(S)){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<endl<<"element at top is "<<S.element[S.top]<<endl;
    }
}

void printStack(stack S){
    cout<<"STACK is:"<<endl;
    for(int i = S.top; i>=0; i--){
        cout<<S.element[i]<<"\t";
    }
    cout<<endl;
}

int main(){
     int choice;
     stack S;
     S = init();
     while(1){
        cout<<endl<<"Enter the choice: \n\n1.push()\n2.pop()\n3.peek()\n4.print()\n5.end\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            S = push(S);
            break;
        case 2:
            S = pop(S);
            break;
        case 3:
            peek(S);
            break;
        case 4:
            printStack(S);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
     }
return 0;
}