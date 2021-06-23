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

void delWrd( tptr &T , string delStr , int i , int len ){
	
	if( T == NULL )
		return;
	
	if( i == len ){
		if( T -> wrdEnd )
			T -> wrdEnd = false;
		for( int i = 0 ; i < 26 ; i++ ){
			if( T->ptr[i] )
				return;
		}
		
	}
	else{
		
		delWrd( T -> ptr[delStr[i]-'a'] , delStr , i+1 , len );
		// i = 0,1,2, a,a,a
		for( int j = 0 ; j < 26 ; j++ ){
			if( T -> ptr[i] and j != (int)(delStr[i]-'a') )
				return;			
		}
		T -> ptr[(int)(delStr[i]-'a')] = NULL;
		
	}
	
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


int main(){
	
	tptr T = new(tnode);
		
	vector<string> v = { "aaa" , "abcde" , "abcd" , "capa" };
	displayContent( T , ""  );
	
	for( string wrd : v ){			
		insrtWrd( T , 0, wrd , wrd.length() );
	}
	
	//cout<<"Enter the string to search :\n";
	string  delStr = "abcde";
	delWrd( T , delStr , 0 , delStr.length() );	
	displayContent( T , ""  );

	
}
