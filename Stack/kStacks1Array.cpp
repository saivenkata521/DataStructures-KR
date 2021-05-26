// Note : The following code for implementation of K stacks in 1 array 
// which is the most efficient algorithm to implement k stacks in one array
// Another Approach: we can divide the stack into K stacks


#include <bits/stdc++.h>
using namespace std;


typedef struct Stack{

    int size;
    int *elements;
    int *nextTop;       // inorder to maintain the next top of each stack 
    int *top;           // inorder to maintain the current top 
    int freeSlot;
    Stack( int size , int k ){
        this->size = size;
        elements = new int[size];
        nextTop = new int[size];
        top     = new int[k];
        this->freeSlot = 0;
    }

}S;




void push( S &sObj , int val , int Sno ){

    if( sObj.freeSlot >= sObj.size ){
        cout<<"\nStack Overflow\n";
        return;
    }

    sObj.elements[sObj.freeSlot] = val;
    sObj.nextTop[sObj.freeSlot] = sObj.top[Sno];
    sObj.top[Sno] = sObj.freeSlot;
    sObj.freeSlot += 1;

}


void pop( S &sObj , int Sno ){

    if( sObj.top[Sno] == -1 ){
        cout<<"\nStack underflow\n";
        return;
    }
    cout<<sObj.elements[sObj.top[Sno]]<<endl;
    int k = sObj.top[Sno];
    sObj.top[Sno] = sObj.nextTop[k];

}



//driver code
int main(){

    cout<<"\nVariables names: \n";
    cout<<"                  Sno --> represents Stack Number \n";

    cout<<"Enter the size of the Stack "; 
    int size; cin>>size;

    cout<<"\nEnter how many stacks u need ";
    int k; cin>>k;

    cout<<"\n     You had Stack Numbers of ";
    for( int i = 0 ; i < k ; i++ ) cout<<i<<",";
    cout<<"\n";

    /*
     * if k == 2 means 0th Stack , 1st Stack , 2nd Stack .
     * if k == 2 represents k+1 Stacks are alloted not k Stacks .
     */

    S sObj(size,k); 

    for( int i = 0 ; i < k ; i++ ) sObj.top[i] = -1;
    
    while( true ){

        cout<<"\n Enter 1 to push <val> and <Stack No.> \n";
        cout<<"\n Enter 2 to  <Stack No.>\n";
        cout<<"\n Enter 3 to exit\n";
        cout<<"\n Choose Your option  :";
        int op,val,Sno; cin>>op;
        if( op == 1 ){
            cout<<"Enter the val and Sno for Push operation ";   
            cin>>val>>Sno;
            if( Sno > k ){
                cout<<" Sorry "<<Sno <<" numbered Stack is not available \n";
                exit(1);
            }
            push( sObj , val , Sno );
        }
        else if( op == 2 ){
            cout<<"Enter the Sno for Pop operation ";
            cin>>Sno;
             if( Sno > k ){
                cout<<" Sorry "<<Sno <<" numbered Stack is not available \n";
                exit(1);
            }
            pop( sObj , Sno );
        }else break;

    }
    




    

}