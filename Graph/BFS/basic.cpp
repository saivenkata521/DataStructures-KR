#include <bits/stdc++.h>
using namespace std;


void bfs( vector<vector<int>> v , int s , int n , int m , vector<bool> &visited ){


    queue<int> q;

    q.push(0);

    while(!q.empty()){


        int a = q.front();
        visited[a] = true;
        cout<<a<<" ";
        q.pop();

        for( int i = 0 ; i < m ; i++ ){
            if( v[a][i] == 1 and !visited[i] ){
                visited[i] = true;
                q.push(i);
            }
        }


    }

    

}


int main(){


/*
            1 
         /  |  \  
        0   2 -  4
         \  |   /
            3

    o/p =  0 1 3 2 4

*/

    vector<vector<int>> v{

            {0,1,0,1,0},

            {1,0,1,0,1},

            {0,1,0,1,1},

            {1,0,1,0,1},

            {0,1,1,1,0}

    };


   
    vector<bool> visited(5,false);

    bfs( v , 0 , 5 , 5 , visited );

    cout<<endl;


}
