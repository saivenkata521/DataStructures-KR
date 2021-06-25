
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

bool check = false;

void get_path_with_given_sum( bstptr T , string s , int target ){

		if( T == NULL )
			return;
		
		if( T -> lc )
			get_path_with_given_sum( T -> lc , s+to_string(T->lc->data) , target  );
			
		if( T -> rc )
			get_path_with_given_sum( T -> rc , s+to_string(T->rc->data) , target );
		
		if( !(T->lc) and !(T->rc) ){
			
			int sum = 0;
			for( auto it : s ){
				sum += (int)(it-'0');
			}
			if( sum == target ){
				
				for( auto it : s ){
					cout<<(int)(it-'0')<<" ";
				}
				check = true;
				return;
			}
		}
		s.pop_back();

}



int main()
{
	//freopen("input.txt" , "r" , stdin );	
    bstptr T = NULL;
    cout<<"Enter integers\nPlease end your input with -1 then bst will stop taking input \n";
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
	
	cout<<"Enter the target :";
	int target; cin>>target;
	get_path_with_given_sum( T , ""+to_string(T->data) , target );
	
	if( !(check) ){
		cout<<" Sorry , Path with given target sum is not present :\n";
	}
		
	//max_sum_path( T );
	
	
}





