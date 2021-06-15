#include <bits/stdc++.h>
using namespace std;

union Union{
		int tag;
		int *A;
};

struct Stack{
		
		int size;
		int top;
		union Union *elements;
		
		Stack( int size ){
			this->size = size;
			elements = new Union[size];
			this->top = -1;
		}
		
};

vector<int> v;

void push( struct Stack &sObj , int len  ){
		
		if( sObj.top  == sObj.size-1 ){
			cout<<"\n Stack Overflow \n\n ";
		}
		else{
			
			sObj.top += 1;
			v[sObj.top] = len;
			//sObj.elements[sObj.top].length = len;
			sObj.elements[sObj.top].A = new int[len];
			cout<<"Enter "<<len<<" elements \n";
			
			
			for( int i = 0 ; i < len ; i++ )
				cin>>sObj.elements[sObj.top].A[i];
			
		}
		
}


void pop( struct Stack &sObj ){
		
		if( sObj.top == -1 ){
			cout<<endl<<"\n Stack Underflow \n\n ";
			
		}
		else{
			for( int i = 0 ; i < v[sObj.top] ; i++ )
				cout<<sObj.elements[sObj.top].A[i]<<" ";
			cout<<endl;
			sObj.top -= 1;
			
		}
}

int main(){
	
		
		cout<<"Enter the size of the Stack ";
		int s;
		cin>>s;
		v.assign(s,0);
		struct Stack sObj(s);
		
		while( 1 ){
			int op;
			cout<<"Choose Your Option \n";
			cout<<"1. Push array into the Stack\n";
			cout<<"2. Pop  array from the Stack\n";
			cin>>op;
			
			if( op == 1 ){
				
				cout<<"Enter the length of the array ";
				int len;
				cin>>len;
				push( sObj , len );
			}
			else if( op == 2 ){
				pop( sObj );
			}
			else exit(1);
		}
			
		
	
}
