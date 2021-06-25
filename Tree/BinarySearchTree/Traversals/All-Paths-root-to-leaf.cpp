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

void print_all_paths_2_leaf( bstptr T , string s ){

		if( T == NULL )
			return;
		
		if( T -> lc )
			print_all_paths_2_leaf( T -> lc , s+to_string(T->lc->data) );
			
		if( T -> rc )
			print_all_paths_2_leaf( T -> rc , s+to_string(T->rc->data) );
		
		if( !(T->lc) and !(T->rc) ){
			for( auto it : s ){
				cout<<(int)(it-'0')<<" ";
			}
			cout<<"\n";
		}
		s.pop_back();

}


void left_most_path( bstptr T ){
	
		if( T == NULL )
			return;
		cout<<T->data<<" ";
		if( !(T -> lc) )
			return;
		left_most_path( T -> lc );
}

void right_most_path( bstptr T ){
		
		if( T == NULL )	
			return;
			
		if( !(T -> rc) )
			return;
		cout<<T->data<<" ";
		right_most_path( T -> rc );
		
	
}






int main()
{
    cout<<"Enter integers\nPlease end your input with -1 then bst will stop taking input \n";
	//freopen("input.txt" , "r" , stdin );
    bstptr T = NULL;
    
    int n; cin>>n;
    while( n != -1 ){
		insert( T , n );
		cin>>n;
	}
	
/*			
					5         
				/      \      
			   3         8    
			 /   \     /    \ 
		    1    4   6       9  
			 \        \       
			  2        7      
*/
	
	cout<<"All paths to the leaf are: \n";
	print_all_paths_2_leaf( T , ""+to_string(T->data) );
	
	cout<<"The Left Most part of the tree is :";
	left_most_path( T );
	
	cout<<"\nThe right Most part of the tree :";
	right_most_path( T );
	
	//max_sum_path( T );
	
	
}





