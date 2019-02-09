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

//____________________________________using Queue with the help of Linked List_______________________________________


#include<iostream>
#include"LinkedList.cpp"

using namespace std;
class QueueLL{
	public:
	Node *front;
	Node *end;
	LinkedList l1;	
	
	//constructor
	QueueLL(){
		end = l1.tail;
		front = l1.head;
	}
	
	//adds element in the end(inserts at the end)
	void enqueue(int value){
		l1.insert(value);
		//update head and tail
		end = l1.tail;
		front = l1.head;
	}

	//deletes first element(deletes from the start)
	void dequeue(){
		if (isEmpty()){
			cout<<"\nThe Queue is empty"<<endl;
		}
		else{
			l1.deleteAt(1);
		}
		//top = new_tail
		end = l1.tail;
		front = l1.head;
	}
	
	//checks if queue is empty
	bool isEmpty(){
		if(front == NULL) return true;
		return false;
	}
	
	//returns the number of elements of queue
	int size(){
		return l1.countItems();
	}
		
	//prints front value
	void front_display(){
		if (isEmpty()==false){
			cout<<"\nThe front of Queue is : "<<front->data<<endl;
		}
		else{
			cout<<"\nThe Queue is empty"<<endl;
		}
	}
	
	//prints end value
	void end_display(){
		if (isEmpty()==false){
			cout<<"\nThe end of Queue is : "<<end->data<<endl;
		}
		else{
			cout<<"\nThe Queue is empty"<<endl;
		}
	}
	
	//prints the queue
	void Display(){
		if (isEmpty()==false){		
			l1.display();
		}
		else{
			cout<<"\nThe Queue is empty"<<endl;
		}
	}
};

int main(){
	QueueLL q1;
	while (true){
		int n;
		cout<<"\n\nChoose option : "<<endl;
		cout<<"1. Enqueue\n"<<"2. Dequeue\n"<<"3. IsEmpty\n"<<"4. Display Front\n"<<"5. Display Rear\n"<<"6. Count the number of elements\n"<<"7. Display\n"<<"8. Quit\n"<<endl;
		cin>>n;
		cout<<endl;
		if (n==1){
			int ele;
			cout<<"\nEnter the element to insert : ";
			cin>>ele;
			q1.enqueue(ele);
			continue;
		}
		else if(n==2){
			q1.dequeue();			
			continue;
		}
		else if(n==3){	
			if (q1.isEmpty()==true){
				cout<<"\nThe Queue is empty"<<endl; 
			}
			else{
				cout<<"\nThe Queue is not empty"<<endl;
			}
			continue;
		}
		else if(n==4){
			q1.front_display();			
			continue;
		}
		else if(n==5){
			q1.end_display();
		}
		else if(n==6){
			cout<<"\nThe number of elements in the queue is : "<<q1.size()<<endl;
			continue;		
		}
		else if(n==7){
			q1.Display();
			continue;
		}
		else{
			break;
		}
	}
	return 7;
}

