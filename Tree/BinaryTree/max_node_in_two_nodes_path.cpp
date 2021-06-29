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
	
	btptr left  = LowestCommonAncestor( T -> lc , a , b );
	btptr right = LowestCommonAncestor( T -> rc , a , b );
	
	if( left and right )
		return T;
	
	return (left) ?  left : right;
	
}

int Max = INT_MIN;

btptr get_path( btptr T , int a , int b ){
	
	if( T == NULL )
		return NULL; 
		
	if( T -> data == a or T -> data == b ){
		return T;
	}
	
	btptr left = get_path( T -> lc , a , b );
	btptr right = get_path( T -> rc , a , b );
	
	if( left or right )
	{
		if( T -> data > Max ){
			Max = T -> data;
		}
		return T;
	}
	
	return (left) ? left:right;
	
	 
	
}

int main(){
	
	vector<int> v{ 12 ,13 , 16 , 0 , 0 , 17 , 0 , 0 , 19 , 20 , 0 , 0 , 21 , 0 , 0 };
	
	int i = 0;
	
	btptr T = create_bt( v  , &(i) , v.size() ,  v[0] );
	
	int a,b;
	
	cout<<"Enter 2 nodes :";
	cin>>a>>b;
	
	btptr lca = LowestCommonAncestor( T , a , b );
	
	if( lca == NULL ){
		cout<<"path doestn't exist ";
	}
	else{
		
		get_path( lca -> lc , a , b );
		
		if( lca -> data != a and lca -> data != b and lca -> data > Max )
				Max = lca->data;
				
		get_path( lca -> rc , a , b );
		
		
		if( Max != INT_MIN ){
			
			cout<<Max;
		}
		else{
			
			cout<<"Sorry, didn't find any Max ";
		}
			
	}
	
	
}

