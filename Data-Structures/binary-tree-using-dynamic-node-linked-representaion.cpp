#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

int main(){
    Node* root = new Node(0);
    
    root->left = new Node(1);
    root->right = new Node(2);
    
    cout<<root->data<<" "<<root->left<<" "<<root->right<<endl;
    cout<<&root->left->data<<" "<<root->left->left<<" "<<root->left->right<<endl;
    cout<<root->right->data<<" "<<root->right->left<<" "<<root->right->right<<endl;
}
