/*Lab 3. 

LINKED LIST

Note: 
Try to reuse as many functions as possible.Sample C++ Files is attached for your reference, you may use it build your solution] 

Due : Sunday Jan 20 

Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 

*/


//add the library
#include<iostream>
using namespace std;

class Node{
	public:
	//data
	int data;
	//pointer to the next node
	Node *next;
	//pointer to the previous node
	Node *prev;
	//constructor that makes the pointer to NULL
	Node(){
		next = NULL;
		prev = NULL;
	}
};

class DoubleLL{
	//Head + Nodes linked with each other
	public:
		Node *head;
		Node *tail;
	//Contructor
	DoubleLL(){
		head = NULL;
		tail = NULL;
	}
	
	//insert
	void insert(int val){
		//if 1st node is added
		Node *temp = new Node;
		//insert value in the node
		temp->data = val;
		//for 1st node
		if (head == NULL){
			head = temp;
		}
		//for any other node
		else{
			temp->prev = tail;
			tail->next = temp;
		}
		tail = temp;
	}
	//insertAt
	void insertAt(int pos, int val){
		//reach the place before the pos
		Node *current = head;
		int  i = 1;
		while (i<pos-1){
			i++;
			current = current->next;
		}
		//create a new node
		Node *temp = new Node;
		//insert value in the node
		temp->data = val;
		//for insertion at 1st position
		if (pos == 1){
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
		else{
			temp->prev = current;
			temp->next = current->next;
			(current->next)->prev = temp;
			current->next = temp;
		}	
	}
	//delete
	void delet(){
		if (head == NULL){
			cout<<"\nThe double linked list is empty\n";
		}
		else{
			//store the tail in temp
			Node *temp = tail;
			//before tail has to point to null
			Node *current = head;
			while(current->next != tail){
				current = current->next;
			}
			current->next = NULL;
			//update tail
			tail = current;
			//delete temp
			delete temp;
		}
	}
	//deleteAt
	void deleteAt(int pos){
		if (pos!=1){
			//node present before pos position
			Node *current = head;
			Node *temp = new Node;
			int i=1;
			//current is the node to be deleted
			while (i<pos-1){
				i++;
				current = current->next;
			}
			temp = current->next;
			//to delete the last element
			current->next = current->next->next;
			current->next->prev = current;
			//delete node
			delete temp;
		}
		else{
			Node *curr = head;
			Node *temp = head;
			curr = curr->next;
			curr->prev = NULL;
			head = curr;
 			delete temp;
		}
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
	//display
    	void display(){
    		Node * current = head;
    	  	while(current != NULL){
    	        	cout << current->data << "->";
    	       		current = current->next;
    	   	}	
    	   	cout <<"NULL"<<endl;
    	}
};	


//main
/*int main(){
	DoubleLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insertAt(3,7);
	l1.display();
	l1.delet();
	l1.display();
	cout<<"The number of elements in the double linked list is : "<<l1.countItems()<<endl;
	l1.deleteAt(1);
	l1.display();

	return 7;

}		
*/
int main(){
	DoubleLL l1;
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
				else if(l1.countItems()==pos){
					l1.delet();
				}
				else{
					l1.deleteAt(pos);
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
}
