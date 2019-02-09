#include"Stack.cpp"

using namespace std;

class QueueS{
	public:
	Stack s1;
	Node *front;
	Node *end;
	
	//constructor
	QueueS(){
		front=NULL;
		end = NULL;
	}
	//adds element on top of the stack, ie, adds element to the queue
	void enqueue(int val){
		s1.push(val);
		//update end 
		end = s1.top;
	}
	//returns the deleted element, as well as deletes the first element
	int dequeue(){
		//if one element
		if(s1.size()==1){
			return s1.pop();
		}
		//if empty
		else if(s1.size()==0){
			cout<<"The Queue is empty"<<endl;
		}
		else{
			//pops the data from the stack while going ahead
			int data = s1.pop();
			//recursion statement
			dequeue();
			//pushes the data back to the stack while returning
			s1.push(data);
		}
	}
	//displays the queue elements
	void display(){
		s1.Display();
	}
	//checks if queue is empty
	bool isEmpty(){
		if(size()==0) return true;
		return false;
	}
	//returns the number of elements of the queue
	int size(){
		return s1.size();
	}
};
int main(){
	QueueS q1;
	while (true){
		int n;
		cout<<"\n\nChoose option : "<<endl;
		cout<<"1. Enqueue\n"<<"2. Dequeue\n"<<"3. IsEmpty\n"<<"4. Count the number of elements\n"<<"5. Display\n"<<"6. Quit\n"<<endl;
		cin>>n;
		cout<<endl;
		if (n==1){
			int ele;
			cout<<"\nEnter the element to insert : ";
			cin>>ele;
			q1.enqueue(ele);
		}
		else if(n==2){
			q1.dequeue();			
		}
		else if(n==3){	
			if (q1.isEmpty()==true){
				cout<<"\nThe Queue is empty"<<endl; 
			}
			else{
				cout<<"\nThe Queue is not empty"<<endl;
			}
		}
		else if(n==4){
			cout<<"\nThe number of elements in the queue is : "<<q1.size()<<endl;
		}
		else if(n==5){
			q1.display();
		}
		else{
			break;
		}
	}
	return 7;
}

