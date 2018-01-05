#include <iostream>
using namespace std;

struct Node{
int data;
Node* left;
Node* right;
};

Node* newNode(int data){
Node* node=new Node;
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
}

//Post order NLR(Node,Left,Right)
void printPreOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main(){
Node* root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
cout<<"Preorder: ";
printPreOrder(root);
return 0;
}
