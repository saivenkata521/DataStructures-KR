/*
 * Problem statement: construct bst from given level order
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct bstnode{
	
	int data;
	struct bstnode *lc;
	struct bstnode *rc;
	
	bstnode( int n ){
		this -> lc = this -> rc = NULL;
		this -> data = n;
	};
	

}*bstptr;

struct rangeNode{
	bstptr ptr;
	int Min;
	int Max;
};


void traversal( bstptr T ){
	
	if( T != NULL ){
		
		traversal( T -> lc );
		
		cout<<T -> data<<" ";
		
		traversal( T -> rc ); 
	}
	
}

bstptr createBST( vector<int> v,  int n ){
	
	queue<rangeNode> Q; int i = 0;
	bstptr T = new bstnode(v[i]);
	Q.push({T,INT_MIN,v[i]}); Q.push({T,v[i],INT_MAX});
	
	while( !Q.empty() ){
				
		
		if( i+1 == n ) break;
		
		if( v[i+1] < Q.front().ptr->data ){
			
			if( v[i+1] > Q.front().Min and v[i+1] < Q.front().Max ){
				Q.front().ptr -> lc = new bstnode( v[i+1] );
				Q.push( { Q.front().ptr->lc, Q.front().Min ,v[i+1] } );
				Q.push( { Q.front().ptr->lc, v[i+1], Q.front().ptr->data} );
				i++;
				Q.pop();
			}
			else Q.pop();
			
		}
		else if( v[i+1] > Q.front().Min and v[i+1] < Q.front().Max ){
		
				Q.front().ptr -> rc = new bstnode( v[i+1] );
				Q.push( { Q.front().ptr->rc, Q.front().ptr->data ,v[i+1] } );
				Q.push( { Q.front().ptr->rc, v[i+1], Q.front().Max });
				i++;
				Q.pop();
									
		}
		else{
			Q.pop();
		}
		
		
	}
	
	return T;
	
	
	
}

int main(){
	
	//vector contains level order to the bst
	vector<int> v{ 7,4,12,3,6,8,1,5,10 };
	
	//funtion to create BST	
	bstptr T = createBST( v , v.size() );

	traversal( T );
	
	
}
