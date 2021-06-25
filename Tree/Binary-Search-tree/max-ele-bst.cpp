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

int Find_Max( bstptr T ){
	
	if( T == NULL )
		return -1;
		
	if( !(T -> rc) ) 
		return T->data;
	Find_Max( T -> rc );
		
		
	
}

int Find_Min( bstptr T ){
	
		if( T == NULL )	return -1;
		
		return !(T->lc) ? T->data : Find_Min(T->lc);
	
}




int main(){
		
	
	freopen( "input.txt" , "r" , stdin );
	bstptr T = NULL;
	
	int n; cin>>n;
	while( n != -1 ){
		insert( T , n );
		cin>>n;
	}
	
	cout<<Find_Max( T )<<endl;
	cout<<Find_Min( T )<<endl;
	
	
	
    
 
	
	
	
}
