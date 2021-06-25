#include<bits/stdc++.h>
using namespace std;
typedef struct bstnode{
    int data;
    bstnode *lc;
    bstnode *rc;
}*bstptr;

int Min = INT_MAX;

vector<int> v{};

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

void  min_sum_path( bstptr T , string s   ){
	
	
	if( T == NULL )
		return;
		
	if( T -> lc )
		min_sum_path( T -> lc , s+to_string(T->lc->data) );
	
	if( T -> rc )
		min_sum_path( T -> rc , s+to_string(T->rc->data) );
		
		
	if( !(T->lc) and !(T->rc) ){
		int sum = 0;
		for( auto it : s ){
			sum += (int)(it-'0');
		}
		if( sum < Min ){
				
			while( !v.empty() ){
				v.pop_back();
			}

			for( auto it : s ){
				v.push_back( (int)(it-'0') ); 
			}
			Min = sum;
		}
	}
	
	s.pop_back();
	
	



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
	
/*			
					5         
				/      \      
			   3         8    
			 /   \     /    \ 
		    1    4   6       9  
			 \        \       
			  2        7      
*/
	
	//cout<<"All paths to the leaf are: \n";
	//print_all_paths_2_leaf( T , ""+to_string(T->data) );
	
	
	cout<<"Min Sum path is ";
	min_sum_path( T , ""+to_string(T->data) );
	
	for( auto it : v ){
		cout<<it<<" ";
	}
	
	
	
}







