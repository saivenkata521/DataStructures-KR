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

void LvlOrdPrnt( bstptr T , int level )
{
    if(T == NULL)
        return;
    if(level == 1)
        cout<<T->data<<" ";
    else if (level > 1){
        LvlOrdPrnt( T -> lc , level-1 );
        LvlOrdPrnt( T -> rc , level-1 );
    }
}
//5 8 3 4 1 9 6 7 2 -1

int Height( bstptr T )
{
    if( T == NULL ) return -1;
    return( max( Height(T->lc) , Height(T->rc) ) + 1 );
   
}

void LvlOrdTr( bstptr T )
{
    for( int i = 1 ; i <= Height(T)+1; i++ ){
        LvlOrdPrnt( T , i );
        cout<<endl;
    }
} 


int main()
{
	freopen("input.txt","r",stdin);
    bstptr T = NULL;
   
    int n; cin>>n;
    
    while( n != -1 ){
		insert( T , n );
		cin>>n;
	}
	
    LvlOrdTr( T );
}
