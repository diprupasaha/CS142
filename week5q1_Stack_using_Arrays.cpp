/*Lab 4

STACKS/QUEUES

Implement using C++. Use classes for each. Make sure warning messages are printed whenever required. (For example: Popping out from an empty queue.)
Stacks using Linked List (Name for class: StackLL) (push, pop, size, isEmpty, top)
Queues using Linked List (Name for class: QueueLL) (enqueue, dequeue, size, isEmpty, top)
Stacks using Arrays (Name for class: StackArr)
Queues using Arrays (Name for class: QueueArr)
Implement a queue using two stacks.
    [Hint: You already have a stack implemented (Q1). Now you have to implement a queue using not the generic setup that you did in Q1 rather implement it using the functions and data (top pointer) of two stacks]
Implement a Stack using Queue(s).


More questions on Stacks and Queues
http://www.cs.princeton.edu/courses/archive/spr01/cs126/exercises/adt.html
*/

#include<iostream>
using namespace std;

class StackArr{
	public:
	int top;
	int s[1000];

	//default constructor
	StackArr(){
		top=-1;
	}
	
	//adds element in the end(inserts at the end)
	void * push(int val){
		top+=1;
		s[top]=val;
	}
	
	//deletes last element
	void * pop(){
		if (top==-1){
			cout<<"Stack underflow"<<endl;
		}
		else{
			top-=1;
		}
	}

	//displays the entire stack
	void display(){
		if (isEmpty()==true){
			cout<<"Stack underflow"<<endl;
		}
		else{
			for(int i=0; i<=top; i++){
				cout<<s[i]<<',';
			}
			cout<<endl;
		}
	}

	//checks if the stack is empty
	bool isEmpty(){
		if(top==-1) return true;
		return false;
	}

	//returns the number of elements in the queue
	int size(){
		return top+1;
	}

	//displays the top of stack
	void top_display(){
		if (isEmpty()==false){
			cout<<"\nThe rear of Queue is : "<<s[top]<<endl;
		}
		else{
			cout<<"\nQueue underflow"<<endl;
		}
	}
};
int main(){
	StackArr s1;
	cout<<"\nThe maximum capacity of the stack is 1000"<<endl;
	while (true){
		int n;
		cout<<"\n\nChoose option : "<<endl;
		cout<<"1. Push\n"<<"2. Pop\n"<<"3. IsEmpty\n"<<"4. Display Top\n"<<"5. Count the number of elements\n"<<"6. Display\n"<<"7. Quit\n"<<endl;
		cin>>n;
		cout<<endl;
		if (n==1){
			int ele;
			cout<<"\nEnter the element to insert : ";
			cin>>ele;
			s1.push(ele);
			continue;
		}
		else if(n==2){
			s1.pop();			
			continue;
		}
		else if(n==3){	
			if (s1.isEmpty()==true){
				cout<<"\nThe Stack is empty"<<endl; 
			}
			else{
				cout<<"\nThe Stack is not empty"<<endl;
			}
			continue;
		}
		else if(n==4){
			s1.top_display();			
			continue;
		}
		else if(n==5){
			cout<<"\nThe number of elements in the stack is : "<<s1.size()<<endl;
			continue;		
		}
		else if(n==6){
			s1.display();
			continue;
		}
		else{
			break;
		}
	}
	return 7;
}
