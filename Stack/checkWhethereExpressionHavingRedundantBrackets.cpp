#include <bits/stdc++.h>
using namespace std;


bool isRedundant( stack<int> &s, string exp , int i ){

    if( i == exp.size() ){
        return false;
    }

    //if exp[i] == '(' or any operator
    if( exp[i] != ')' and !( exp[i] >= 'a' and exp[i] <= 'z' ) ){
        s.push(exp[i]);
    }
    else{

        //represents that there is nothign between the braces like ()
        // not like (+)

        bool flag = false;
        while( s.top() != '(' ){
            if( s.top() == '+' or s.top() == '-' or s.top() == '+' or s.top() != '/' ){
                flag = true;
            }
            s.pop();
        }
        s.pop();
        if( flag == false ) return true;

    }

   return isRedundant( s , exp , i+1 );


    
    
    

}



int main(){


    stack<int> s;

    string exp = "((a+b))";

    cout<<(isRedundant( s , exp , 0 ))<<endl;

    

}