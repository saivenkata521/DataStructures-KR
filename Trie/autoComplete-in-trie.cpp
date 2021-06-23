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

void displayContent( tptr T , string s ){
	
	
	if( T ->  wrdEnd == true ){
		cout<<s<<endl;
	}
	
	
	for( int i = 0 ;i < 26 ; i++ ){
		if( T -> ptr[i] != NULL ){
			s += (char)(i+'a');
			displayContent( T -> ptr[i] , s  );
			s.pop_back();
		}
	}
	
}

void autoComplete( tptr T , string partStr , int i , int len ){
	
	if( T == NULL )
		return;
	
	if( i == len ){
		displayContent( T , partStr );
		return;
	}
	else{
		autoComplete( T -> ptr[partStr[i]-'a'] , partStr , i+1 , len );
		
	}
	
	
	
}



int main(){
			
			tptr T = new(tnode);
			
			cout<<"How many strings would you like to insert in trie ";
			int n; cin>>n;
			cout<<"Enter "<<n<<" string(s) \n";
			vector<string> v(n,"");
			for( int i = 0 ; i < n ; i++ ){
				cin>>v[i];
			}
			
			//traversing through each string in vector
			for( string wrd : v ){			
				insrtWrd( T , 0, wrd , wrd.length() );
			}	
			cout<<"Enter a part String :";
			string partStr;

			cin>>partStr;
			autoComplete( T , partStr , 0 , partStr.length() ); 

			cout<<endl;
	
}


