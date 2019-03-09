#include<iostream>
using namespace std;

//Node
class node{
	public:
		//class variables
		int data;
		node *l;
		node *r;
	
	//parameterised constructor
	node(int val){
		data=val;
		l=NULL;
		r=NULL;
	}
};

//Binary Search Tree
class BST{
	public:
		//class variables
		node *root;

	//default constructor
	BST(){
		root=NULL;
	}
	
	//insert tree elements
	void insert(int val){
		insertHelper(root,val);	
	}

	//recursive function helping insertion
	void insertHelper(node *curr, int val){

		//base case if curr is null, insert there
		if (root==NULL){
			root = new node(val);
		}

		//else compare the curr data with value
		else if(val < curr->data){

			//if val<curr->data ->
			//if left is null, insert it
			if (curr->l==NULL) curr->l = new node(val);

			//else move left and call insertH
			else insertHelper(curr->l, val);
		}

		else{
	
			if (curr->r==NULL) curr->r = new node(val);

			//else move right and call insertH
			else insertHelper(curr->r, val);
		}
	}
	
	//display tree elements
	void display(){
		display2(root);
		cout<<endl;
	}
	
	//recursive functions to display in order
	void display2(node *curr){
		//base condition
		if (curr ==NULL) return;

		//display left
		display2(curr->l);

		//display curr
		cout<<curr->data<<",";

		//display right
		display2(curr->r);
	}

	//2D tree representation
	/*node displayFancy(int spaces){
		//increase number of spaces
		//display right
		//print req spaces
		//display curr
		//display left
		/*
				16
			14
				12
		10
				8
			6
				4
		*/
	}
	*/
	
	//recursive function to traverse the tree to help in search();
	node *searchHelper(node *curr, int find){

		//if value found or reached end of tree
		if (curr == NULL || curr->data == find){
			return curr;
		}
		
		//moves to left if lesser than current
		else if (find<curr->data){
			return searchHelper(curr->l, find);
		}

		//moves to right if greater than current
		else{
			return searchHelper(curr->r, find);
		}
	}	

	//search an element in the tree
	node *search(int find){
		searchHelper(root, find);
	}
	
	//          next class
	//height();
	//deletenode();

};

//main

int main(){
    BST bst1;
    bst1.insert(4);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(3);
    bst1.insert(5);
    bst1.display();
    if(bst1.search(3) != NULL){
        cout << endl << bst1.search(3)->data << endl;
    }
}
