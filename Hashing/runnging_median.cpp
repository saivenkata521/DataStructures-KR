#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap; // root >  left child and right child 
priority_queue< int , vector<int> , greater<int>> minHeap; 

/*
 * keyPoints : 
 * for Minheap we have to check condition num >= minHeap.top();
 * for MaxHeap we have to check codition num <= maxHeap.top();
 * why above two ? 
 * Reason: left sub part ( maxHeap ) having the sorted elements in [0 , n/2 ); 
 * 		   rigth sub part ( minHeap ) are greater than all the elements in maxHeap;
 * 
 * */

void update_heap( int num ){
	
	//checking whether maxHeap is empty or not 
	if( maxHeap.size() == 0 ) maxHeap.push(num);
	else if( minHeap.size() == maxHeap.size() ){
		
		if( num < maxHeap.top() ) //push into left sub part 
			maxHeap.push(num);
		else{
			maxHeap.push(minHeap.top());  //balancing and increase the size of maxHeap
			minHeap.pop(); minHeap.push(num);//inserting into minHeap bcz the number greater than root of maxHeap;
		}
	}
	else{
		
		
		//if minHeap is empty we need to balance it first so we have to push
		if( minHeap.size() == 0 ){			
			minHeap.push(num);
		}
		else{
			
			//if num greater than root of min heap we have to push
			if( num >= minHeap.top() ){
				minHeap.push(num);				
			}			
			else{
				
				if( num < maxHeap.top() ){
					
					minHeap.push(maxHeap.top());
					maxHeap.pop(); maxHeap.push(num);
					
				}
				else minHeap.push(num);
				
			}
			
		}
		
		
	}

}


int main(){

	vector<int> v{ 5,3,4,2,6};

	for( auto it : v )
		update_heap( it );
  
  
	if( maxHeap.size() > minHeap.size() )  //even 
     cout<<maxHeap.top();
  else //odd
     cout<<( minHeap.top() + maxHeap.top() )/2;
  
}
