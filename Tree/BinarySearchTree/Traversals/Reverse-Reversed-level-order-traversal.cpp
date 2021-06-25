#include<bits/stdc++.h>
using namespace std;
typedef struct bstnode{
    int data;
    bstnode *lc;
    bstnode *rc;
}*bstptr;

void insert( bstptr &T , int n )
{
   if( T == NULL )
	{
		T = new(bstnode);
		T -> data = n;
		//cout<<T->data<<endl;
	}
	else{
		
		if( T -> data > n ){
			insert( T -> lc , n );
			//cout<<T->data<<" ";
		}
		else{
			insert( T -> rc , n );
			//cout<<endl<<T->data<<endl;
		}
			
	}
}

void rev_lvl_ord_trvsl( bstptr T , int level ){
		
	if( T == NULL )
		return;
	
	if( level == 1 )
		cout<<T->data<<" ";
	
	rev_lvl_ord_trvsl( T -> rc , level-1 );
	rev_lvl_ord_trvsl( T -> lc , level-1 );
	
}


int Height( bstptr T ){
		
		if( T == NULL )
			return -1;
		
		int a = Height( T -> lc );
		int b = Height( T -> rc );
		return max(a,b)+1;
	
	
}

void rev_lvl_ord( bstptr T ){
	
	for( int i = Height(T)+1 ; i >= 1 ; i-- ){
		
		rev_lvl_ord_trvsl( T , i );
		cout<<endl;
		
	}

}

int main()
{
	freopen("input.txt" , "r" , stdin );
    bstptr T = NULL;
    
    int n; cin>>n;
    while( n != -1 ){
		insert( T , n );
		cin>>n;
	}
	
	rev_lvl_ord( T );
}

