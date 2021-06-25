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

void LDR_LRD_DLR( bstptr T ){

	 if( T == NULL )
		return;
	//cout<<"\n one "<<T->data<<" "; DLR
	LDR_LRD_DLR( T -> lc );
	//cout<<"\n Two "<<T->data<<" "; LDR
	LDR_LRD_DLR( T -> rc );
	//cout<<"\n Three "<<T->data<<" "; LRD
}

/*
				 5
			  /      \
			  3       8
			/  \     /  \
		   1    4   6    9
		  / \  / \ / \  / \
			 2        7
			/ \
			
			
*/
			 











int main(){
		
	
	freopen( "input.txt" , "r" , stdin );
	bstptr T = NULL;
	
	int n; cin>>n;
	while( n != -1 ){
		insert( T , n );
		cin>>n;
	}
	
	LDR_LRD_DLR( T );
	cout<<"\n";
	
}

