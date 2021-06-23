#include <bits/stdc++.h>
using namespace std;

typedef struct tnode{
	tnode *ptr[26];
	bool wrdEnd;
	tnode(){
		this->ptr[26] = {NULL};
		this->wrdEnd = false;
	}
}*tptr;


void insrtWrd( tptr &T ,  int i , string wrd , int len ){
	
	if( i == len ){
		
		T->wrdEnd = true;
		return;
		
	}
		
	if( T -> ptr[wrd[i]-'a'] == NULL ){
		
		T -> ptr[wrd[i]-'a'] = new(tnode);	
		
	}
	
	insrtWrd( T -> ptr[wrd[i]-'a'] , i+1 , wrd , len );		

}

bool searchWrd( tptr T , int i , string srchWrd , int len ){
	
	if( T == NULL )
		return false;
	
	if( i == len )
		return ( T -> wrdEnd == true );
		
	
	if( T -> ptr[srchWrd[i]-'a'] != NULL )
		return searchWrd( T -> ptr[srchWrd[i]-'a'] , i+1 , srchWrd , len );
	else 
		return false;
}


int main(){
			
			tptr T = new(tnode);
			
			cout<<"How many strings would you like to insert in trie ";
			int n; cin>>n;
			cout<<" Enter "<<n<<" strings \n";

			vector<string> v(n,"");
			for( int i = 0 ; i < n ; i++ ){
				cin>>v[i];
			}
			
			//traversing through each string in vector
			for( string wrd : v ){			
				insrtWrd( T , 0, wrd , wrd.length() );
			}	
			
			
			string srchWrd;
			cout<<"Enter a String to search in trie :";
			cin>>srchWrd;
			
			if(searchWrd(T , 0 , srchWrd , srchWrd.length()))
				cout<<srchWrd<<" is present ✓ \n";
			else
				cout<<srchWrd<<" is not present ✘ \n";
	
}
