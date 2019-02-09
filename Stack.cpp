#include<iostream>	
#include"LinkedList.cpp"

using namespace std;
class Stack{
	public:
	Node *top;
	LinkedList l1;	
	
	//constructor
	Stack(){
		top = l1.tail;
	}	
	
	//pushes on top
	void push(int value){
		l1.insert(value);
		//top = new_tail
		top = l1.tail;
	}

	//pops the top
	int pop(){
		int popped=top->data;
		l1.delet();
		//top = new_tail
		top = l1.tail;
		return popped;
	}
	//checks if the stack is empty
	bool isEmpty(){
		if(top == NULL) return true;
		return false;
	}
	//the number of elements in the stack
	int size(){
		return l1.countItems();
	}
	//top display
	void topDisplay(){
		cout<<"\nThe top of Stack is : "<<top->data<<endl;
	}
	//displaying the stack elements serially
	void Display(){
		l1.display();
	}
};
/*
int main(){
	Stack s1;
	for(int i=0;i<5;i++){
		s1.push(i);
	}
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	cout<<s1.pop();
	s1.Display();
	
}
*/
