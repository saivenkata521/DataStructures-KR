
#include <bits/stdc++.h>
using namespace std;

typedef struct btnode{

	int data;
	btnode *lc,*rc;
	btnode(){
	   this -> lc = this -> rc = NULL;
	}

}*btptr;

void leftView( btptr T , int level ){
	
	static map<int,int> mp;
	if( T == NULL ) return;

	if( mp[level] == 0 ){
		cout<<T -> data<<" ";
		mp[level] = 1;
	}

	leftView( T -> lc , level+1 );
	leftView( T -> rc , level+1 );

}


int main(){
	freopen( "input.txt" , "r" , stdin );

	//Tree construction
	btptr T = new(btnode); T -> data = 10;
	T -> lc = new(btnode); T -> lc -> data = 4;
//	T -> lc -> lc = new(btnode);  T -> lc -> lc -> data = 12;
//	T -> lc -> rc = new(btnode);  T -> lc -> rc -> data = 123;
	T -> rc =  new(btnode); T -> rc -> data = 15;
	T -> rc -> rc = new( btnode ); T -> rc -> rc -> data = 16;

	leftView( T , 0 );


}
