/* the following code for
 * two stacks in one array    
 */


#include <bits/stdc++.h>
using namespace std;

typedef struct stacks{
    int size;
    int *elements;
    int top1;
    int top2;
    stacks( int size ){
        this->size = size;
        top1 = -1;
        top2 = size;
        elements = new int[size];
    }

    void push1( int val){
        if( top1 < top2-1 ){
            top1 += 1;
            elements[top1] = val;
        }
        else{
            cout<<"Stack Overflow \n";
        }
    }

    void push2( int val ){
        if(  top1 < top2-1 ){
            top2 -= 1;
            elements[top2] = val;
        }
        else{
            cout<<"Stack Overflow \n";
        }
    }

    int pop1(){

        if( top1 >= 0 ){
            int ans = elements[top1];
            top1 -= 1;
            return ans;
        }
        else{
            cout<<"Stack Underflow \n";
            exit(1);
        }
    }

    int pop2(){
        if( top2 < size ){
            int ans = elements[top2];
            top2 += 1;
            return ans;
        }else{
            cout<<"Stack Underflow\n";
            exit(1);
        }
    }


}S;

int main(){
    cout<<"Enter the size of combined stack ";
    int size; cin>>size;
    S s(size);
    
    while( true ){
        int option;
        cout<<"Enter  1 to push into stack1\n";
        cout<<"Enter -1 to push into stack2\n";
        cout<<"Enter  2 to pop from stack1\n";
        cout<<"Enter -2 to pop from stack2\n";
        cout<<"Enter  3 to get top from stack1\n";
        cout<<"Enter -3 to get top from stack2\n";
        cout<<"Enter  0 to exit\n";
        cin>>option; int val;
        if( option == 1 ){
            cin>>val;       s.push1(val);
        }else if( option == -1 ){
            cin>>val;       s.push2(val);
        }else if( option == 2 ){
            cout<<s.pop1()<<endl;
        }else if( option == -2 ){
            cout<<s.pop2()<<endl;
        }else if( option == 3 ){
            if( s.top1 < 0 ) cout<<"Stack is empty \n";
            cout<<s.elements[s.top1]<<endl;
        }else if( option == -3 ){
            if( s.top2 > size ) cout<<" Stack is empty \n";
            else cout<<s.elements[s.top2]<<endl;
        }
        else break;
    }    
    
     
}