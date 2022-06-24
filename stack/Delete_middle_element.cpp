#include <bits/stdc++.h>
using namespace std;


void rmvMiddle( stack<int> &s , int cnt ,  int size  ){

    if( cnt == size/2 ){
        s.pop();
        return;
    }

    int a = s.top();
    s.pop();

    rmvMiddle( s , cnt+1 , size );

    s.push(a);

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
    s.push(2);
    s.push(3);

    rmvMiddle( s , 0 , s.size() );

    print(s);

}
