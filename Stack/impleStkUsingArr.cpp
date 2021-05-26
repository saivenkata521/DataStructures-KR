#include <bits/stdc++.h>
using namespace std;

typedef struct stacks{
    int top;
    int size;
    int *elements;
public:
    stacks( int size ){
        this->size = size;
        elements = new int[size];
    }
}S;

 
void push( S &stk , int val ){
    if( stk.top ==  stk.size - 1 ) cout<<"Stack Overflow\n";
    else{
        stk.top++;
        stk.elements[stk.top] = val;
    }
}

void pop(S &stk){
    if( stk.top == -1 ) cout<<"Stack Underflow\n";
    else{
        stk.top--;
    }
}

//driver code
int main(){

    cout<<"Enter the maximum Capacity of Stack ";
    int size; cin>>size;
    S stk(size);
    stk.top = -1;
    while( true ){
        int option;
        cout<<"Enter 1 to push elements into stack\n";
        cout<<"Enter 0 to pop elements from stack\n";
        cout<<"Enter -1 to get the top element of stack\n";
        cout<<"Enter 2 to exit\n"; 
        cin>>option;
        if( option == 1 ){
            int val; cin>>val;
            push( stk , val);
        }else if( option == 0 ){
            pop( stk );
        }else if(option == -1){
            if( stk.top == -1 ) cout<<"Stack is empty \n";
            else cout<<stk.elements[stk.top];
        }else break;
    }
}