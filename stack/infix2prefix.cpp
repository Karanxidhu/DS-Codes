#include<iostream>
using namespace std;

#define MAX 100

struct stack
{
    char element[MAX];
    int top;
};

stack init(){
    stack S;
    S.top = -1;
    return S;
}

int isEmpty(stack S){
    return (S.top == -1);
}

int isFull(stack S){
    return (S.top == MAX-1);
}

stack push(stack S, char x){
        if(isFull(S)){
            cout<<"OVERFLOW"<<endl;
        }else{
            ++S.top;
            S.element[S.top] = x;
        }
        return S;
}

int compare(char c1, char c2){
    char t1[] = {'+','-'};
    char t2[] = {'*', '/'};
    if((c1==t1[0] || c1==t1[1]) && (c2==t2[0] || c2==t2[1])){
        return -1;
    }else if((c2 == t1[0] || c2 == t1[1]) && (c1 == t2[0] || c2 == t2[1])){
        return 1;
    }else if((c2 == t1[0] || c2 == t1[1]) && (c1 == t1[0] || c2 == t1[1])){
        return 0;
    }else{
        return 0;
    }
}

stack pop(stack S, bool print = true){
    if(isEmpty(S)){
        cout<<"UNDERFLOW"<<endl;
    }else{
        char temp;
        temp = S.element[S.top];
        --S.top;
        if(print){
        cout<<temp;
        }
    }
    return S;
}

void printStack(stack S){
    cout<<endl<<"stack is:";
    for(int i = S.top; i>=0; i--){
        cout<<S.element[i];
    }
    cout<<endl;
}

void infix2prefix(string str){
    stack S;
    S = init();
    char enChar = str[0];
    for(int i = 0; i<str.length(); i++){
        enChar = str[i];
        // cout<<"encoutered: "<<enChar<<endl;
        if( enChar >= 'A' && enChar <= 'Z'){
            cout<<enChar;
        }else if(enChar == '('){
            S = push(S,enChar);
        }else if(enChar == ')'){
            while(!(S.element[S.top] =='(')){
                S = pop(S);
                // cout<<endl<<"while"<<endl;
            };
            S = pop(S, false);
        }else{
            char pC = S.element[S.top];
            int prec ;
            if(pC=='+' || pC=='-' || pC=='*' || pC=='/'){
                prec = compare(enChar, pC);
                if(prec==0 || prec == -1){
                    S = pop(S);
                    S = push(S,enChar);
                }else{
                    S = push(S,enChar);
                }
            }else{
                S = push(S,enChar);
            }
        }
        // printStack(S);
    }
}

int main(){
     string s;
     cout<<"Enter the infix :"<<endl;
     cin>>s;
     s = '('+ s +')';
     infix2prefix(s);
return 0;
}