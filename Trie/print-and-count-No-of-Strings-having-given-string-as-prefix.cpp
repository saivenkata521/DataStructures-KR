#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

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

//vector<string> v = { "aaa" , "abcde" , "abcd" , "capa" };

void Print_Prefix_Strgs( tptr T , int i , string prefixStr , int len , string s , int count ){
	
	
		
	if( i == len ){
		
		if( T -> wrdEnd  ){
			cout<<s<<endl;
			cnt++;
		}
			
		for( int j = 0 ; j < 26 ; j++ ){
			
			if( T -> ptr[j] ){
					s += (char)(j+'a');
					Print_Prefix_Strgs( T -> ptr[j] , i , prefixStr , len , s , count );
					if( !s.empty() )
						s.pop_back();
			}
			
		}
			
		
	}
	else{
			
		if( T -> ptr[prefixStr[i]-'a'] ){
			s += prefixStr[i];
			Print_Prefix_Strgs( T -> ptr[prefixStr[i]-'a'] , i+1 , prefixStr , len , s , count );
			if( !s.empty()) 
				s.pop_back();
			
		}
	}
	
	//count;
	
}

void No_of_Prefix_Strgs( string prefixStr ){
	
	cout<<"No.of Strings having ("<< prefixStr<<") as prefix is "<<cnt<<endl;
		
}

int main(){
	
	tptr T = new(tnode);
		
	vector<string> v = { "aaa" , "abcde" , "abcd" , "capa" };
	
	for( string wrd : v ){			
		insrtWrd( T , 0, wrd , wrd.length() );
	}
	
	string prefixStr = "a";
	Print_Prefix_Strgs( T , 0 , prefixStr , prefixStr.length() ,  "", 0 );
	No_of_Prefix_Strgs(prefixStr );

	
}


/*
void No_of_PrefixStrgs( tptr T , int i , string prefixStr , int len , string s ){
		
				
		if( i == len ){
		
			for( int j = 0 ; j < 26 ; j++ ){
				
				if( T -> ptr[j] ){
					
					s += (char)('a'+j);
					
					if( T -> wrdEnd ){
						cout<<s<<endl;
					}
					else{
						No_of_PrefixStrgs( T -> ptr[j] , i , prefixStr , len  , s );
						if( !s.empty() )
							s.pop_back();
					}
				}
				
			}
				
    	}
    	
    	
		if( T -> ptr[prefixStr[i]-'a'] ){
				s += (char)('a'+i);
			    No_of_PrefixStrgs( T -> ptr[prefixStr[i]-'a'] , i+1 , prefixStr , len , s );		
			    if( !s.empty() )
			        s.pop_back();
		}
			
			
		return;
}

*/


