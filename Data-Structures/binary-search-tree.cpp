#include <bits/stdc++.h>
using namespace std;

class BST{
    public:
        int data;
        BST* left;
        BST* right;
        
		BST(){}

        BST(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

BST* insert(BST* root, int key){
	if(!root) return new BST(key); //if the current pointer is NULL insert the node here

	if(key >= root->data) root->right = insert(root->right, key); //exploring the right subtree till NULL
	else root->left = insert(root->left, key); ///exploring the left subtree till NULL

	return root;
}

//at every node maintain left-root-right
void inorder(BST* root){
	if(!root) return;
	inorder(root->left); //starts printing from leftmost leaf
	cout<<root->data<<endl; //after printing left subtree it will print the root as the function was first called by root
	inorder(root->right); //lastly it will print the right subtree
}

BST* search(BST* root, int key){
    if(!root || root->data == key) return root;
    
    if(key > root->data) return search(root->right, key);
    else return search(root->left, key);
}

int main(){
	BST b;
	BST* root = nullptr;
	BST* s;

	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    inorder(root);

	s = search(root, 10);
	
	if(s) cout<<"Found!"<<endl;
	else cout<<"Not found!"<<endl;

    return 0;
}