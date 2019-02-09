#include<iostream>
#include"LinkedList.cpp"

using namespace std;
class Queue{
	public:
	Node *front;
	Node *end;
	LinkedList l1;	
	
	//constructor
	Queue(){
		end = l1.tail;
		front = l1.head;
	}
	
	//pushes on top(inserts at the end)
	void enqueue(int value){
		l1.insert(value);
		//update head and tail
		end = l1.tail;
		front = l1.head;
	}

	//pops the top(deletes from the start)
	int dequeue(){
		int popped;
		if (isEmpty()){
			//cout<<"\nThe queue is empty"<<endl;
		}
		else{
			popped = l1.deleteAt(1);
			//top = new_tail
			end = l1.tail;
			front = l1.head;
			return popped;
		}
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
		cout<<"\nThe front of Queue is : "<<front->data<<endl;
	}
	
	//prints end value
	void end_display(){
		cout<<"\nThe end of Queue is : "<<end->data<<endl;
	}
	
	//prints the queue
	void Display(){
		l1.display();
	}
};

/*int main(){
	Queue q1;
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
*/
