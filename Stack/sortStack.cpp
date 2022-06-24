#include <bits/stdc++.h>
using namespace std;


void sortStack( stack<int> &s , int cnt , int size ){


    if( cnt == size-1 ){

        s.push(s.top());
        s.pop();
        return;

    }



    int a = s.top();
    s.pop();

    sortStack( s , cnt+1 , size );


    if( s.top() > a ){
        int c = s.top();
        s.pop();
        s.push(a);
        s.push(c);
    }
    else{
        s.push(a);
    }
    


}


void print(stack<int> s){

    if( s.empty ())  return;
    
    cout<<s.top()<<" ";
    s.pop();
    print( s );
}

int main(){


    stack<int> s;

    s.push(1);
    s.push(100);
    s.push(90);
    s.push(1000);
    s.push(410);

    sortStack( s , 0 , s.size() );

    print(s);

    cout<<endl;

}