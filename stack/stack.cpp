#include<iostream>
using namespace std;
#define MAX 100

struct stack
{
    int element[MAX];
    int top;
};

stack init(){
    stack S;
    S.top = -1;
    return S;
}

int isEmpty(stack S){
    return(S.top == -1);
}

int isFull(stack S){
    return(S.top == MAX-1);
}

int peek(stack S){
    if(isEmpty(S)){
        cout<<"Empty stack"<<endl;
        return -1;
    }else{
        return(S.element[S.top]);
    }
}

stack push(stack S, int x){
    if(isFull(S)){
        cout<<"OVERFLOW"<<endl;
    }else{
        ++S.top;
        S.element[S.top] = x;
    }
    return S;
}

stack pop(stack S){
    int temp;
    if(isEmpty(S)){
        cout<<"UNDERFLOW"<<endl;
    }else{
        temp = S.element[S.top];
        --S.top;
        cout<<temp<<" is popped out"<<endl;
    }
    return S;
}

void printStack(stack S){
    if(isEmpty(S)){
        cout<<"Empty stack"<<endl;
    }else{
    for(int i = S.top; i>=0; i--){
        cout<<S.element[i]<<"\t";
    }
    }
}

int main(){
    stack S;
    S = init();
    S = push(S,5);
    S = push(S,1);
    S = push(S,3);
    S = push(S,5);
    S = push(S,78);
    printStack(S);
    S = pop(S);
    printStack(S);
    cout<<endl<<isFull(S)<<endl;
return 0;
}