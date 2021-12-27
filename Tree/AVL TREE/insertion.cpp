

#include <bits/stdc++.h>
using namespace std;

//binary search tree node
typedef struct bstnode{

	int data;
	bstnode *lc;
	bstnode *rc;
	int height;
	bstnode(int data){
		this -> data = data;
		this -> lc =  this -> rc = nullptr;
		this -> height = 0;
	}

}*bstptr;

//& means made changes to the whole tree 
// if we look at the print function we didnt need & 
//because we need to print not to make changes

int Height( bstptr T ){

	return (!T) ? -1 : T -> height;

}

void maintainHeights( bstptr &T ){

	if( T != nullptr ){

		maintainHeights( T -> lc );
		maintainHeights( T -> rc );

		T -> height = max( Height(T -> lc ) , Height( T -> rc) )+1;

	}

}


//https://i.imgur.com/DtPwlT0.png
bstptr rightRotation( bstptr &T ){

	bstptr temp = T -> lc;
	T -> lc = temp -> rc;
	temp -> rc = T;
	T = temp;

	maintainHeights( T );

	return T;
	
}


//https://i.imgur.com/BloK7rt.png
bstptr leftRotation( bstptr &T ){

	bstptr temp = T -> rc;
	T -> rc = temp -> lc;
	temp -> lc = T;
	T = temp; 

	maintainHeights( T );

	return T;
	

}


// void LeftRightDoubleRotation( bstptr &T ){

// 	bstptr Temp = T -> lc;
// 	T -> lc = Temp -> rc;
// 	T -> lc -> lc = Temp;
// 	T -> lc -> lc -> rc = nullptr;
// 	leftRotation(T);

// }


// void RightLeftDoubleRotation( bstptr &T ){

// 	bstptr Temp = T -> rc;
// 	T -> rc = Temp -> lc;
// 	T -> rc -> rc = Temp;
// 	T -> rc -> rc -> lc = nullptr;
// 	rightRotation(T);

// }

// https://i.imgur.com/kl9Iq0U.png --> difficult method 
//https://i.imgur.com/OvnNv5j.png --> easy method

bstptr LeftRightDoubleRotation( bstptr &T )
{
    bstptr temp = T -> lc;
	bstptr temp2 = T -> lc -> rc;
	T -> lc = temp -> rc -> rc;
	temp -> rc = temp2 -> lc;
	temp2 -> lc = temp;
	temp2 -> rc = T;
	T = temp2;

	maintainHeights( T );

	return T;
}

//change lc = rc  and rc = lc in the above function to  
// to get RightLeftDoubleRotation

//https://i.imgur.com/KIQgGQQ.png --> difficult method 
bstptr RightLeftDoubleRotation( bstptr &T )
{
    bstptr temp = T -> rc;
	bstptr temp2 = T -> rc -> lc;
	T -> rc = temp -> lc -> lc;
	temp -> lc = temp2 -> rc;
	temp2 -> rc = temp;
	temp2 -> lc = T;
	T = temp2;

	maintainHeights( T );

    return T;
  
}




//insert elements to bst
bstptr insert( bstptr &T , int n ){

	if( T == nullptr ){

		//create a new node having data n
		T = new bstnode(n);

	}
	else if( n < T -> data ){
		
		T -> lc = insert( T -> lc , n );

		//after creating a node 
		//T points to the parent node

		//since n < T -> data which makes 
		//sense that we are in left side of tree
		//i.e., the weight on left subtree so height also more 
		if( Height( T -> lc ) - Height( T -> rc ) == 2 ){

			//n is the value of new node inserted
			//where T -> lc is the parent of new node creation
			if( n < T -> lc -> data )
				return rightRotation( T );
			else
				return LeftRightDoubleRotation( T );
		}

	}
	else if( T -> data < n ){

		T -> rc = insert( T -> rc , n );

		//after creating a node 
		//T points to the parent node

		//since T -> data < n which makes
		//sense that we are in the right side of tree
		//i.e., the weight on rightsubtree is more than left

		if( Height( T -> rc) - Height(T -> lc ) == 2 ){

			if( T -> rc -> data < n ) 
				return leftRotation( T );
			else 
				return RightLeftDoubleRotation( T );

		}
	}

	T -> height = max( Height(T->lc),Height(T->rc) )+1;

	return T;

}

void print( bstptr T ){

	if( T ){
		// cout<<"dafas";
		cout<< T -> data << " ";
		print( T -> lc );
		print( T -> rc );
	}

}



int main(){

	
	bstptr T = nullptr;

	int n; cin>>n;

	while( n != -1 ){
		insert( T , n );
		cin>>n;
	}

	print( T );





}


//https://www.youtube.com/watch?v=jDM6_TnYIqE 
