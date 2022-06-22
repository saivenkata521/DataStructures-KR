#include <bits/stdc++.h>
using namespace std;


void dfs( vector<vector<int>> v , int s , int n , int m , vector<bool> &visited ){


    stack<int> S;
    S.push(0);


    while(!S.empty()){

        int a = S.top();
        S.pop();
        cout<<a<<endl;
        visited[a] = true;

        for( int i = 0 ; i < m ; i++ ){

            if( v[a][i] == 1 and !visited[i] ){
                S.push(i);
                visited[i] = true;
                break;
            }

        }


    }




    

}


int main(){

/*
            1 
            |  \  
            2 -  4
            |
       0 -  3

*/


    vector<vector<int>> v{

            {0,0,0,1,0},

            {0,0,1,0,1},

            {0,1,0,1,1},

            {1,0,1,0,1},

            {0,1,1,1,0}

    };


   
    vector<bool> visited(5,false);

    dfs( v , 0 , 5 , 5 , visited );

    cout<<endl;


}
