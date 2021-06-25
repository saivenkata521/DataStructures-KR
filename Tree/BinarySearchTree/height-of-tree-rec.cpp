#include<bits/stdc++.h>
using namespace std;
typedef struct bstnode{
    int data;
    bstnode *lc;
    bstnode *rc;
    bstnode(){
		this->lc = this->rc = NULL;
	}
}*bstptr;



void insert( bstptr &T , int n )
{
    if( T == NULL )
	{
		T = new(bstnode);
		T -> data = n;
	}
	else{
		
		if( T -> data > n ){
			insert( T -> lc , n );
		}
		else{
			insert( T -> rc , n );
		}
			
	}
}


int Height( bstptr T )
{
    if( T == NULL ) return -1;
    return( max( Height(T->lc) , Height(T->rc) ) + 1 );

}


//void height-itr-trav( bstptr T , stack<bstptr> s ){
	
		
		//if( s.empty() )
			//return;
		
		
	
	
//}

//5 8 3 4 1 9 6 7 2 -1

void itr_height( bstptr T ){

		stack<bstptr> s;
		s.push(T);
		//return height-itr-trav( T , s );
		
		
	
}


int main(){
		
	
	freopen( "input.txt" , "r" , stdin );
	bstptr T = NULL;
	
	int n; cin>>n;
	while( n != -1 ){
		insert( T , n );
		cin>>n;
	}
	
	
    //Recursive
    cout<<Height( T )<<"\n";
    
    //Iterative
    //cout<<itr_height( T );
	
	
	
}
