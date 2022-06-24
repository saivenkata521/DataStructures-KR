#include <bits/stdc++.h>
using namespace std;


void insertBottomStack( stack<int> &s,  int insertEle   ){

    if( s.size() == 0 ){
        s.push(insertEle);
        return;
    }

    int a = s.top();
    s.pop();

    insertBottomStack( s , insertEle  );

    

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

    insertBottomStack( s , 10 );

    print(s);

}