/*CS142 Programming and Data Structures Lab - 22019 Even
Due 11:59 PM
Week 7 : Binary Search Tree - II
Subhankar Mishra Mar 15 (Edited Mar 16)
Implement Binary Search Tree
4) Node * find_min(Node *) - Gets minimum node in a subtree
5) void replace_At_Parent(Node * A, Node *B) - Replaces A with B at the parent of A. This replacement makes the B the respective child (left/right child depending if A was left or right child of its parent)
6) void deleteNode(int value) - Deletes the node with "value"

Helpful material : https://en.wikipedia.org/wiki/Binary_search_tree

Sample main() is attached.
bst.cpp
C++
Your work
Assigned
Files you add or create can be viewed and edited by your teacher
Mark as done or attach work to turn in
*/

#include<iostream>
using namespace std;


class Node{
	public:
	int data;
	Node * left;
	Node * right;
	Node * parent;

	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;
	}  
};

class BST{
	public:
	Node * root;
	//maintaining count of nodes in BST
	int count=0;	
	
	BST(){
	root = NULL;
	}
	void insert(int value){
		insertHelper(root, value);
		count++;
	}
	void insertHelper(Node *curr, int value){
		// If root is NULL, then create a node and make it root. 
		if (root == NULL) root = new Node(value);
		// Else Decide to move left or right. 
		else if (value < curr->data)  {
			// if left is already NULL, create a new node and link it. 
			if (curr->left == NULL) {
        			curr->left = new Node(value);
        			curr->left->parent = curr;
    			}
			// Move left and call insert there. 
			else insertHelper(curr->left, value);
		}
		else {
	    		// if right is already NULL, create a new node and link it. 
			if (curr->right == NULL) {
			        curr->right = new Node(value);
			        curr->right->parent = curr;
			}
			// Move right and call insert there. 
			else insertHelper(curr->right, value);
		}
	}
	void display(){
		displayHelper(root);
	}
	void displayHelper(Node * curr){
		// Case for empty tree and leaf nodes children.
		if( curr ==  NULL) return;
		// IN order print.
		// Print left. 
		displayHelper(curr->left);
		// Print myself.
		cout << curr->data << ", ";
		// Print right.
		displayHelper(curr->right);
	}
	Node * search(int value){
		return searchHelper(root, value);
	}
	Node * searchHelper(Node * curr, int value){
		// Are you the value? or Are you NULL?  if yes return curr
		if(curr == NULL || curr->data == value ) return curr;
		// else you search in right or left. 
		// Left
		else if(value < curr->data) return searchHelper(curr->left, value);
		// Right
		else  return searchHelper(curr->right, value);
	}
	void print2DUtil(Node *root, int space){  
		// Base case  
		if (root == NULL)  
			return;  
		// Increase distance between levels  
		space += 5;  
		// Process right child first  
		print2DUtil(root->right, space);  
	
		// Print current node after space  
		// count  
		cout<<endl;  
		for (int i = 5; i < space; i++)  
			cout<<" ";  
			cout<<root->data<<"\n";  
	
		// Process left child  
		print2DUtil(root->left, space);  
	}  
	
	// Wrapper over print2DUtil()  
	void print2D(){  
		cout << "******************************" << endl;
		// Pass initial space count as 0  
		print2DUtil(root, 0);  
		cout << "******************************" << endl;
	
	}
	
	//find_min
	Node *find_min(Node *c){
		//according to insertion property, the min element appears at the leftmost leaf
		//reaching the leftmost leaf		
		while(c->left != NULL){
        	    c=c->left;
        	}
        	//return the pointer at the minimum value
        	return c;
	}
	
	//height of the tree
	int height(){
        	int ht=0;
		//calling the helper function
		heighthelper(root,0,ht);
		cout<<"The height of the binary search tree is: "<<ht<<endl;
		return ht;
	}
	//helper function to find the height
	void heighthelper(Node*current,int i,int &p){
	//if nothing is parent
		if(current==NULL){
			if(p<i-1){
                		p=i-1;
			}
			else{
				return;
			}
		}
		else{
	        	//moving to the left
				heighthelper(current->left,i+1,p);
		        //moving to the right
				heighthelper(current->right,i+1,p);
		}
	}
	//Replaces A with B at the parent of A. This replacement makes the B the respective child (left/right child depending if A was left or right child of its parent)
	void replace_At_Parent(Node *A, Node *B){
		//replacing left child
		if(A->parent->left==A){
			A->parent->left==B;
		}
		//replacing right child
		else if(A->parent->right==A){
			A->parent->right=B;
		}
		//if B is present 
		else if(B!=NULL){
			B->parent=A->parent;
		}			
		//if B is empty
		else{
			A->parent=NULL;
		}
	}
	//counting all the nodes in the BST
	int tcount(){
		return count;
	}
	//range search: given two values k1 and k2, print all the elements (or keys) x in the BST such that k1 <= x <= k2. Also count the number of elements in the range from k1 to k2 and returns it.
	int rangeSearch(int k1, int k2){
		//counting the number of elements
		int c=0;
		//checking if the elements are there or not
		int flag=0;
		for(int i=k1;i<=k2;i++){
			if (search(i)!=NULL){
				flag = 1;
				c++;
				cout<<i<<" ";
			}
		}
		//message when no element falls in the range
		if(flag==0){
			cout<<"The given range does not contain any tree elements\n";
		}
		cout<<endl;	
		return c;
	}	
	//delete node
	void binary_delete(Node * curr, int key){
		//if BST is empty or reaches a leaf
		if(curr==NULL){
			if (root==NULL){
				cout<<"Binary Search is empty\n";
			}
			else{
			}
		}
		//travelling left if key is less than current's data
		else if(key < curr->data){
			binary_delete(curr->left,key);//recursive statement
		}
		//...right...more...
		else if(key > curr->data){
			binary_delete(curr->right,key);
		}
		//current's data equals key
		else{
			Node *cl=curr->left;
			Node *cr=curr->right;
			//now if this curr has children or not
			//case1 - it has no children
			if(cl==NULL && cr==NULL){
				//root case
				if (curr==root){
					root=NULL;
				}
				//leaf
				else{
					if(curr->parent->data>curr->data){
						curr->parent->left = NULL;
					}
					else{
						curr->parent->right = NULL;
					}
				}
				count--;
				delete curr;
			}
			//case 2 - it has one child
			else if(cr==NULL || cl==NULL){
				if(curr=root){
					if(root->left==NULL){
						root = root->right;
					}
					else{
						root = root->left;
					}
				}
				else{
					Node *temp = curr;
					if(cr!=NULL){
						replace_At_Parent(curr,cr);
					}
					else{
						replace_At_Parent(curr,cl);
					}
					delete temp;
				}
				count--;
			}
			//case 3 - both children are present
			else{
				//move the right subtree at the position of current, while the left subtree remains there
				Node *temp = find_min(cr);
				int cdata = temp->data;
				binary_delete(cr,cdata);
				curr->data = cdata;
			}
		}		
	}
	
};
	
int main(){

	BST bst1;
	bst1.insert(4);
	bst1.insert(2);
	bst1.insert(3);
	bst1.insert(1);
	bst1.insert(6);
	bst1.insert(5);
	bst1.insert(7);
	bst1.insert(8);
	bst1.display();

	int key;
	cout<<"\nEnter the element to search : ";
	cin>>key;
	if(bst1.search(key) != NULL){
		cout << key <<" is present in the tree\n";
	}
	else{
		cout << key <<"is NOT present in the tree\n";
	}
	cout<<"The number of elements in the tree is : "<<bst1.tcount()<<endl;
	bst1.print2D();
	bst1.height();
	cout<<"The minimum element of the tree is : "<<bst1.find_min(bst1.root)->data<<endl;
	int s=bst1.rangeSearch(4,5);
	cout<<"The number of elements of tree falling within the range is : "<<s<<endl;
	bst1.binary_delete(bst1.root,5);
	bst1.print2D();
	bst1.binary_delete(bst1.root,6);
	bst1.print2D();
	cout << "Deleting 2" << endl;
	bst1.binary_delete(bst1.root,2);
	bst1.print2D();
	bst1.binary_delete(bst1.root,4);
	bst1.print2D();
	bst1.binary_delete(bst1.root,7);
	bst1.print2D();
	bst1.binary_delete(bst1.root,8);
	bst1.print2D();
	bst1.binary_delete(bst1.root,3);
	bst1.print2D();
	bst1.binary_delete(bst1.root,1);
	bst1.print2D();
	bst1.binary_delete(bst1.root,1);
	bst1.print2D();
	
	return 7;
}

