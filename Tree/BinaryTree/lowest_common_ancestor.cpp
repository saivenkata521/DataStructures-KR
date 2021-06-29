#include <bits/stdc++.h>
using namespace std;

typedef struct btnode{
		
		int data;
		btnode *lc,*rc;
		btnode(){
			this->lc = this->rc = NULL;
		}
}*btptr;


btptr create_bt( vector<int> v , int *i , int size , int key ){
	
	if( *i > size )
		return NULL;
		
	if( key == 0 )
		return NULL;
	
	btptr T = NULL;
	T = new(btnode);
	T -> data  = key ;
	
	*i += 1;
	if( *i < size )
		T -> lc = create_bt( v , i , size , v[*i] );
	
	
	*i += 1;
	if( *i < size )
		T -> rc = create_bt( v , i , size , v[*i] );
		
	return T;
	
}
 
btptr LowestCommonAncestor( btptr T , int a , int b ){
	  
	if( T == NULL )
		return NULL;
		
	 if( T -> data == a or T -> data == b )
		return T;

	
	btptr T1 = LowestCommonAncestor( T -> lc ,  a ,  b );
	btptr T2 = LowestCommonAncestor( T -> rc ,  a ,  b );
	


	if( T1  and T2  ){
		return T;
	}
	
	
	return T1 != NULL ?  T1 : T2;
	

	
}

 
 

int main(){
	
	vector<int> v{ 5 , 2,  7, 0, 0, 4, 9, 0, 0, 6, 0, 0, 8, 3, 0, 15, 0 ,0 ,1 ,0 ,12, 0, 0 };	
	//vector<int> v{ 12 ,13 , 16 , 0 , 0 , 17 , 0 , 0 , 19 , 20 , 0 , 0 , 21 , 0 , 0 };
	
	int i = 0;
	
	btptr T = create_bt( v  , &(i) , v.size() ,  v[0] );
	
	 
	
	
	int a;
	int b;
	cout<<"Enter two node values :\n";
	cin>>a>>b;
	btptr lca = LowestCommonAncestor(  T , a , b );
	if(lca){
		cout<<lca->data<<" ";
	}
 
}


