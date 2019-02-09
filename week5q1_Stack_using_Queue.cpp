#include"Queue.cpp"
class StackQ{
	public:
		Node *top;
		Queue q1,q2;

	//contructor
	StackQ(){
		top = q1.end;
	}
	//adds element on top of stack
	void push(int v){
		q1.enqueue(v);
		top = q1.end;
	}
	//deletes element from the other side of stack
	void pop(){
		if (q1.isEmpty()==true){
			cout<<"\nThe Stack is empty"<<endl;
		}
		else{
			//pouring all elements of 1st queue into 2nd, until 1 element is left
			while(q1.size()!=1){
				q2.enqueue(q1.dequeue());
			}
			//delete last element left in 1st queue
			q1.dequeue();
			//pouring back all the elements of 2nd into 1st again
			while(q2.isEmpty()==false){
				q1.enqueue(q2.dequeue());
			}
		}
	}
	//checks if the stack is empty
	bool isEmpty(){
		q1.isEmpty();
	}
	//counts the number of elements in stack
	int size(){
		return q1.size();
	}
	//displays the stack elements serially 
	void display(){
		q1.Display();
	}
};

int main(){
	StackQ s1;
	
	while (true){
		int n;
		cout<<"\n\nChoose option : "<<endl;
		cout<<"1. Push\n"<<"2. Pop\n"<<"3. IsEmpty\n"<<"4. Count the number of elements\n"<<"5. Display\n"<<"6. Quit\n"<<endl;
		cin>>n;
		cout<<endl;
		if (n==1){
			int ele;
			cout<<"\nEnter the element to insert : ";
			cin>>ele;
			s1.push(ele);
		}
		else if(n==2){
			s1.pop();			
		}
		else if(n==3){	
			if (s1.isEmpty()==true){
				cout<<"\nThe Stack is empty"<<endl; 
			}
			else{
				cout<<"\nThe Stack is not empty"<<endl;
			}
		}
		else if(n==4){
			cout<<"\nThe number of elements in the stack is : "<<s1.size()<<endl;
		}
		else if(n==5){
			s1.display();
		}
		else{
			break;
		}
	}
	return 7;
}
