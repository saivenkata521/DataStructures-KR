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

int cnt = 0;

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

void delWrd( tptr &T , string delStr , int i , int len ){
	
	if( T == NULL )
		return;
	
	if( i == len ){
		if( T -> wrdEnd ) T -> wrdEnd = false;
		for( int i = 0 ; i < 26 ; i++ )
			if( T->ptr[i] ) return;
		
	}
	else{
		
		delWrd( T -> ptr[delStr[i]-'a'] , delStr , i+1 , len );
		// i = 0,1,2, a,a,a
		for( int j = 0 ; j < 26 ; j++ )
			if( T -> ptr[i] and j != (int)(delStr[i]-'a') )
				return;			
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

	cout<<"Choose a option to proceed \n\n";
	cout<<"1. Already existed vector<string> into the trie insertion \n";
	cout<<"2. Search a Word in trie \n";
	cout<<"3. Get count and print strings having given string as prefix \n";
	cout<<"4. Display strings in the trie \n";
	cout<<"5. AutoComplete in trie \n";
	cout<<"6. Delete a trie \n";
	cout<<"7. Program terminated \n";
	
	cout<<"\n\nEnter a option :";
	int op; cin>>op;

	
	while( 1 ){
		
		if( op == 1 ){
			
				cout<<"How many strings would you like to insert in trie ";
				int n; cin>>n;
				cout<<" Enter "<<n<<" strings \n";
				vector<string> v(n,"");
				for( int i = 0 ; i < n ; i++ ){
					cin>>v[i];
				}
			
				for( string wrd : v ){			
					insrtWrd( T , 0, wrd , wrd.length() );
				}
			
			//cout<<"aaa , abcde , abcd , capa <- were inserted \n";
			
		}
		else if( op == 2 ){
			
			string srchWrd;
			cout<<"Enter a String to search in trie :";
			//= "abccd";
			cin>>srchWrd;
			
			if(searchWrd(T , 0 , srchWrd , srchWrd.length()))
				cout<<srchWrd<<" is present ✓ \n";
			else
				cout<<srchWrd<<" is not present ✘ \n";
			
		}
		else if( op == 3 ){
			
			string prefixStr;
			cout<<"Enter a prefix String :";
			 //= "abc";
			cin>>prefixStr;
			Print_Prefix_Strgs( T , 0 , prefixStr , prefixStr.length() ,  "", 0 );
			No_of_Prefix_Strgs( prefixStr );
			cnt = 0;
			
		}
		else if( op == 4 ){
			
			displayContent( T , ""  );
			
			cout<<endl;
		}
		else if( op == 5 ){
			
			cout<<"Enter a part String :";
			string partStr;
			 //= "c";
			cin>>partStr;
			autoComplete( T , partStr , 0 , partStr.length() ); 

			cout<<endl;
			
		}
		else if( op == 6 ){
			cout<<"Enter String to delete from trie :";
			string  delStr;
			 //= "abcde";
			cin>>delStr;
			delWrd( T , delStr , 0 , delStr.length() );	
		}
		else if( op == 7 ){
			cout<<"Program Terminated \n";	
			exit(1);		
		}
		else{
			cout<<"Program Terminated due to invalid option \n";
			exit(1);
		}
		
		cout<<"\n\nEnter a option :";
		cin>>op;
		
	}
		
	
	
}






/*

//create another way 


typedef struct tnode{
	tnode *ptr[26];
	bool wrdEnd;
	tnode(){
		this->ptr[26] = {NULL};
		wrdEnd = false;
	}
}*tptr;

void insrtWrd( tptr &T ,  int i , char ch , string wrd ){
	
	
	if( T -> ptr[ch-'a'] == NULL ){
		T -> ptr[ch-'a'] = new(tnode);
			
		if( wrd[i+1] == '\0' ){
			T -> ptr[ch-'a']->wrdEnd = true;
		}
	
	}
	else
	
		insrtWrd( T -> ptr[ch-'a'] , i , ch , wrd );		

	
}

int main(){
	
	tptr T = new(tnode);

	vector<string> v = { "abcd" ,"aaaa" , "mvs" , "acca" };

	for( string wrd : v ){
		
		int len = wrd.length();
		for( int i = 0 ; i < len ; i++ ){
			
			insrtWrd( T , i , wrd[i] , wrd );
			
		}	
		
			
	}

}

*/




















