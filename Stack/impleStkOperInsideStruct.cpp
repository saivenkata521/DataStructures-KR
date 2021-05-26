#include <iostream>
#include <climits>
using namespace std;

class stack
{
	int top;
	int size;
	int * arr;
public:
	stack(int size)
	{
		top = -1;
		this->size = size;
		arr = new int[size];
	}

	int isEmpty()
	{
		if (top==-1)
			return 1;
		else return 0;
	}

	int isFull()
	{
		if (top==this->size-1)
			return 1;
		else
			return 0;
	}

	bool push(int x)
	{
		if (!isFull())
		{
			arr[++top]=x;
			return true;
		}
		else
		{
			cout<<"Stack overflow\n";
			return false;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			return INT_MIN;
		}
		else
		{
			int temp;
			temp  = arr[top];
			--top;
			return temp;
		}
	}

	int siz()
	{
		return top+1;
	}

	void display()
	{
		cout<<"current stack is : \n";
		for (int i=top;i>=0;--i)
		{
			cout<<arr[i]<<"\n";
		}
	}	

	int peek()
	{
		return arr[this->top];
	}
};


int main()
{
	unsigned n;
	cout<<"Enter max size of stack buffer : ";
	cin>>n;
	stack s(n);
	bool flg;
    string op;int val,k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the stack : "<<"\n";
    cout<<"To push integer <val> into stack :\n$ push <val>\n ";
    cout<<"To pop value from the stack\n$ pop\n";
    cout<<"To display the content of stack \n$ view\n";
    cout<<"To break the operation\n$ exit\n";
    cout<<"\n\n";
    
    while(true)
    {
    	cin>>op;
    	if (op=="push")
    	{
    		cin>>val;
    		flg = s.push(val);
    		if (flg == false)
    		{
    			cout<<"Overflow\n";
    		}
    	}
    	else if (op=="pop")
    	{
    		int k = s.pop();
    		if (k==INT_MIN)
    		{
    			cout<<"Stack underflow :/\n";
    		}
    		else
    		{
    			cout<<k<<" popped from stack\n";
    		}
    	}
    	else if (op=="view")
    	{
    		s.display();
    	}
    	else if (op=="exit")
    	{
    		break;
    	}
    }

	return 0;
}