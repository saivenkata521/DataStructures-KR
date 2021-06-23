#include <bits/stdc++.h>
using namespace std;

typedef struct tnode{
	
	tnode *ptr[36];
	bool wrdEnd;
	tnode(){
		this->ptr[36] = {NULL};
		this->wrdEnd = false;
	}
	
	
}*tptr;

void insrtWrd( tptr &T ,  int i , string wrd , int len ){
	
	if( i == len ){
		
		T->wrdEnd = true;
		return;
		
	}
	
	if( isdigit(wrd[i]) ){
		if( T -> ptr[wrd[i]-'0'] == NULL )
			T -> ptr[wrd[i]-'0'] = new(tnode);
		insrtWrd( T -> ptr[wrd[i]-'0'] , i+1 , wrd , len );			
	}
	else{
		if( T -> ptr[wrd[i]-'a'+10] == NULL )
			T -> ptr[wrd[i]-'a'+10] = new(tnode);
		insrtWrd( T -> ptr[wrd[i]-'a'+10] , i+1 , wrd , len );			
	}
		

}


void displayContent( tptr T , string s ){
	
	
	if( T ->  wrdEnd == true ){
		cout<<s<<endl;
	}
	
	
	for( int i = 0 ;i < 36 ; i++ ){
		if( T -> ptr[i] != NULL ){
			if( i < 10 )
				s += to_string(i);
			else
				s += (char)(i-10+'a');
			displayContent( T -> ptr[i] , s  );
			s.pop_back();
		}
	}
	
}


int main(){
	
	tptr T = new(tnode);
	vector<string> v =  { "abd5c2" , "ac8b9" ,  "cdd294a1" ,  "da5b4c63" , "bd367" };
	for( string wrd : v ){			
			insrtWrd( T , 0, wrd , wrd.length() );
	}
	
	displayContent( T , "" );
		
}

