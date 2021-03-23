#include <bits/stdc++.h>
using namespace std;

class Node{
  	public:
        int data;
        Node *left, *right;
  	    Node(){}
  	    
        Node(int val){
          data = val;
          left = nullptr;
          right = nullptr;
        }
};

/* Inorder traversal of a binary tree*/
void inorder(Node* temp){
	if (!temp) return;
	
	inorder(temp->left);
	cout << temp->data << " ";
	inorder(temp->right);
}

//Insertion in a Binary Tree in level order
Node* insertNode(Node* root, int data){
	// If the tree is empty, assign new node address to root
	if(!root){
		root = new Node(data);
		return root;
	}

	// Else, do level order traversal until we find an empty
	// place, i.e. either left child or right child of some
	// node is pointing to NULL.
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* temp = q.front();
		q.pop();

		if(temp->left) q.push(temp->left);
		else{
			temp->left = new Node(data);
			return temp->left;
		}

		if(temp->right) q.push(temp->right);
		else{
			temp->right = new Node(data);
			return temp->right;
		}
	}

    return root;
}
//function to delete deepest node
void delDeepest(Node* root, Node* deepNode){
    queue<Node*> q;
    q.push(root);

    // Do level order traversal until last node
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp == deepNode){
            temp = nullptr;
            delete(deepNode);
            return;
        }
        if(temp->right){
            if(temp->right == deepNode){
                temp->right = nullptr;
                delete(deepNode);
                return;
            }
            q.push(temp->right);
        }

        if(temp->left){
            if(temp->left == deepNode){
                temp->left = nullptr;
                delete(deepNode);
                return;
            }
            q.push(temp->left); 
        }
    }
}

// function to delete element in binary tree
Node* deletion(Node* root, int key){
    if(!root) return root;

    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* keyNode = nullptr;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (keyNode)
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == key) keyNode = temp;

        if(temp->left) q.push(temp->left);

        if(temp->right) q.push(temp->right);
    }

    if(keyNode){
        if(keyNode == root && keyNode == temp){ // if tree consists of root only then delete the root, don't replace root with itself
            delete(temp);
            return nullptr;
        }
        else{
            keyNode->data = temp->data; //replace to be deleted node with the deepest node
            delDeepest(root, temp);
        }
    }
    
    return root;
}

int main(){
	Node *root, *node;
	root = new Node(1);
	root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    cout<<"Inorder traversal before insertion: ";
    inorder(root);
    cout<<endl;
 
    int key = 8;
    node = insertNode(root, key);
	cout<<"Node "<<key<<" inserted at: "<<node<<endl;
	
	cout<<"Inorder traversal after insertion: ";
    inorder(root);
	cout<<endl;
	
	cout<<"Inorder traversal before deletion: ";
	inorder(root);
    cout<<endl;
    
	key = 1;
	root = deletion(root, key);

	cout<<"Inorder traversal after deletion of "<<key<<": ";
	inorder(root);

	return 0;
}
