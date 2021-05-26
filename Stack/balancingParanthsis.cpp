#include <bits/stdc++.h>
using namespace std;


bool isBalance( char a , char b ){
    return( (a=='(' and b==')') or (a=='{' and b=='}') or (a=='[' and b==']') );
}

bool isValid(string s) {
    stack<char> stk;
    for( int i = 0 ; i < s.length() ; i++ ){
        if( s[i] == '[' or s[i] == '{' or s[i] == '(' ) stk.push(s[i]);
        else{
            if( stk.empty() ) return false;
            else if( isBalance( stk.top() , s[i] ) == false ) return false;
            else stk.pop();
        }
    }
    if( stk.empty() ) return true;
    else return false;
}


//driver code 
int main(){
        cout<<"Enter the String ";
        string s; cin>>s;
        if(isValid(s)) cout<<"Yup, it is balanced ";
        else cout<<" No, not Balanced ";
}