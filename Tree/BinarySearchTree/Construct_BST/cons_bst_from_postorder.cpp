#include <bits/stdc++.h>
using namespace std;


typedef struct bstnode{
	
	int data;
	bstnode *lc,*rc;
	bstnode(){
		this->lc = this->rc = NULL;
	}
		
}*bstptr;

bstptr create(  int *v , int key , int Min , int Max , int *ptrLst  ){
	
	if( *ptrLst < 0 )
		return NULL;
	
	bstptr T = NULL;
	if( key > Min and key < Max ){
		
		T = new(bstnode);
		T -> data = key;
		*ptrLst -= 1;
		
		T -> rc = create( v ,  v[*ptrLst] , key , Max , ptrLst  );
		T -> lc = create(  v , v[*ptrLst]  , Min , key , ptrLst  );
	 
				
	}
	return T;
	
}



void traversal( bstptr T ){

	if( T != NULL ){
		traversal( T -> lc );
		cout<<T->data<<" ";
		traversal( T -> rc );
	}
	
}

int main(){
	
	freopen( "input.txt" , "r" , stdin );
	
	int n; cin>>n;
	int v[n];
	for( int i = 0 ; i < n ; i++ ){
		cin>>v[i];
	}
	
	int size = n-1; 
	int b = v[size];
	bstptr T = create( v , b , INT_MIN , INT_MAX , &(size));
	traversal( T );
	
}

