#include<iostream>
using namespace std;

//Generic Programming
//to store elements of different data-type

//circle-type class
class Node{//creates the node,ie, circle in my diagram of copy
	public:

	//Data
	int data;

	//Pointer to the next node
	Node *next;//ptr to next node is also a node type data
	
	//Constructor that makes the ptr to NULL
	Node(){
		next = NULL;
	}			
};

class LinkedList{//linked list just states how the nodes will be connected
	//head + circles inside linked with each other
	public:
	//head______//the only variable in linked list
	//head -> Node-type ptr
	Node *head;
	Node *tail;//to store the last element
	
	//Constructor;
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	//circles inside linked with each other
	//rules how circles will be linked


	//insert
	void insert(int value){
		//If 1st node is added
		Node *temp = new Node;//creates a Node type data in heap and returns the address of the same : hence the '*' pointer____temp is in stack

		//Insert data in the node		
		temp->data = value;//goes to the nameless object in heap using its address 'temp' and stores the value given in its data parameter 
		
		//putting the node in a linked list, ie, we are making the pointer to node as the head of linked list,ie ,the 1st element
		//1st Node only
		if (head==NULL){
			head = temp;
		}
		
		//Any other node only
		else{	
			tail->next = temp;
		}
		tail = temp;	
	}
	//insert at a particular position
	void insertAt(int pos, int value){
		//insertion in between
		if (pos!=1){
			//Reach the place before the pos
			Node *current = head;
			int i = 1;
			while (i<pos-1){
				i++;
				current=current->next;
			}
			//Create a node for insertion
			Node *temp = new Node;
			
			//Insert value
			temp->data = value;
			
			//move pointers
			temp->next = current->next;
			current->next=temp;
		}
		//insertion at first place
		else{
			//changing head to new node
			Node *temp = new Node;
			temp->data = value;
			temp->next=head;
			head = temp;
		}
	}
	
	//deletion of the last element only
	void delet(){
		if(head!=tail){
			//store tail in temp
			Node *temp = tail;
			//before tail has to point to null
			Node *current = head;
			while(current->next != tail){
				current = current->next;
			}
			current->next=NULL;
			
			//update tail to 2nd last element
			tail = current;
		}
		else{
			head=NULL;
			tail=NULL;
			//cout<<"\nIt becomes empty now";
		}
	}
	//display
	
	/*
	___logic___
		cout<<head->data<<"->"<<endl;	
		temp = head->next;
		cout<<temp->data<<"->"<<<endl;
		temp = temp->next;	
	*/
	void display(){
		Node *current = head;
		while(current != NULL){
			cout<<current->data<<"->";
			current = current->next;
		}
		cout<<endl;
	}
	
	//countItems
	int countItems(){
		Node *current = head;
		int c=0;
		while(current !=NULL){
			current = current->next;
			c++;
		}
		return c;
	}
	
	//delete at a particular position
	int deleteAt(int pos){
		if(pos!=1){
			int temp;
			//node present just after pos position
			Node *after = head;
			//node present just before pos position
			Node *before = head;
			
			int i = 1;
			int j = 1;
			while (i<pos+1){
				i++;
				after=after->next;
			}
			while (j<pos-1){
				j++;
				before=before->next;
			}
			temp = before->next->data;
			//pointing before's next to after
			before->next=after;
			return temp;
		}
		else{
			Node *curr = head;
			int temp = head->data;
			curr = curr->next;
			head = curr;
			return temp;
		}
	}
};

/*int main(){
	LinkedList l1;
	while (true){
		int n;
		cout<<"\n\nChoose option : "<<endl;
		cout<<"1. Insert\n"<<"2. Delete\n"<<"3. Insert at a particular position\n"<<"4. Delete at a particular position\n"<<"5. Count the number of elements\n"<<"6. Display\n"<<"7. Quit\n"<<endl;
		cin>>n;
		cout<<endl;
		if (n==1){
			int ele;
			cout<<"\nEnter the element to insert : ";
			cin>>ele;
			l1.insert(ele);
			continue;
		}
		else if(n==2){
			if(l1.countItems()==0){
				cout<<"\nThe linked list is empty";
			}
			else{
				l1.delet();
			}
			continue;
		}
		else if(n==3){	
			if(l1.countItems()==0){
				cout<<"\nThe linked list is empty";
			}
			else{
				int pos, value;
				cout<<"\nEnter the position to insert : ";
				cin>>pos;
				if (pos>l1.countItems()){
					cout<<"\nThe linked list does not have that many elements";
				}
			
				else{
					cout<<"\nEnter the value to be inserted : ";
					cin>>value;
			
					l1.insertAt(pos,value);
				}
			}
			continue;
		}
		else if(n==4){
			if(l1.countItems()==0){
				cout<<"\nThe linked list is empty";
			}
			else{
				int pos;
				cout<<"\nEnter the position to delete : ";
				cin>>pos;
				if (pos>l1.countItems()){
					cout<<"\nThe linked list does not have that many elements";
				}
			
				else{
					int deleted=l1.deleteAt(pos);
					cout<<"deleted"<<deleted<<endl;
				}
			}
			continue;
		}
		else if(n==5){
			cout<<"\nThe number of elements in the linked list is : "<<l1.countItems()<<endl;
			continue;		
		}
		else if(n==6){
			l1.display();
			continue;
		}
		else{
			break;
		}
	}
	return 7;
}*/
