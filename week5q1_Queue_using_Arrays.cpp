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

class QueueArr{
	public:
	int front;
	int rear;
	int q[1000];

	//default constructor
	QueueArr(){
		rear=-1;
		front=-1;
	}
	
	//adds element in the end(inserts at the end)
	void * enqueue(int val){
		if (rear==-1){
			front+=1;
		}
		else{
		}
		rear+=1;
		q[rear]=val;
	}
	
	//deletes first element
	void * dequeue(){
		if (front ==-1){
			cout<<"Queue underflow"<<endl;
		}
		else if(rear==0){
			front = -1;
			rear-=1;
		}
		else{	
			for(int i=0; i<rear; i++){
				q[i]=q[i+1];
			}
		rear-=1;		
		}
	}

	//displays the entire queue
	void display(){
		if (isEmpty()==true){
			cout<<"Queue underflow"<<endl;
		}
		else{
			for(int i=0; i<=rear; i++){
				cout<<q[i]<<',';
			}
			cout<<endl;
		}
	}

	//checks if the queue is empty
	bool isEmpty(){
		if(front==-1) return true;
		return false;
	}

	//returns the number of elements in the queue
	int size(){
		return rear+1;
	}

	//displays the front of queue
	void front_display(){
		if (isEmpty()==false){
			cout<<"\nThe front of Queue is : "<<q[front]<<endl;
		}
		else{
			cout<<"\nQueue underflow"<<endl;
		}
	}

	//displays the rear of queue
	void rear_display(){
		if (isEmpty()==false){
			cout<<"\nThe rear of Queue is : "<<q[rear]<<endl;
		}
		else{
			cout<<"\nQueue underflow"<<endl;
		}
	}
};

//main
int main(){
	QueueArr q1;	
	cout<<"\nThe maximum capacity of the queue is 1000"<<endl;
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
			q1.rear_display();
		}
		else if(n==6){
			cout<<"\nThe number of elements in the queue is : "<<q1.size()<<endl;
			continue;		
		}
		else if(n==7){
			q1.display();
			continue;
		}
		else{
			break;
		}
	}
	return 7;
}

