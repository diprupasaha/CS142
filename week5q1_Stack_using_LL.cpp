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
*/

//____________________________________using Stack with the help of Linked List_______________________________________


#include<iostream>
#include"LinkedList.cpp"

using namespace std;
class StackLL{
	public:
	Node *top;
	LinkedList l1;	
	
	//constructor
	StackLL(){
		top = l1.tail;
	}	
	//pushes on top (inserts new element at the end of the linked list)
	void push(int value){
		l1.insert(value);
		//top = new_tail
		top = l1.tail;
	}
	//pops the top (deletes last element of the linked list)
	void pop(){
		if (isEmpty()==false){
			l1.delet();
			//top = new_tail
			top = l1.tail;
		}
		else{
			cout<<"\nThe stack is empty"<<endl;
		}
	}
	//checks if the stack is empty
	bool isEmpty(){
		if(top == NULL) return true;
		return false;
	}
	//counts the number of elements in the stack
	int size(){
		return l1.countItems();
	}
	//displays the top of the stack	
	void topDisplay(){
		if (isEmpty()==false){
			cout<<"\nThe top of Stack is : "<<top->data<<endl;
		}
		else{
			cout<<"\nThe stack is empty"<<endl;
		}
	}
	//displays the whole stack elements
	void Display(){
		if (isEmpty()==false){		
			l1.display();
		}
		else{
			cout<<"\nThe stack is empty"<<endl;
		}
	}
};

int main(){
	StackLL s1;
	
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
			s1.topDisplay();			
			continue;
		}
		else if(n==5){
			cout<<"\nThe number of elements in the stack is : "<<s1.size()<<endl;
			continue;		
		}
		else if(n==6){
			s1.Display();
			continue;
		}
		else{
			break;
		}
	}
	return 7;
}
