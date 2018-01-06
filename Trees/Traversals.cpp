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

//InOrder LNR(Left,Node,Right)
void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

//Post Order is LRN(Left,Right,Node)
void printPostOrder(Node* root){
    if(root==NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

int height(Node* root){
    if(root==NULL){
        return -1;
    }
    else{
        int ldepth=height(root->left);
        int rdepth=height(root->right);
        if(ldepth>rdepth){
            return ldepth+1;
        }
        else{
            return rdepth+1;
        }
    }
}

int main(){
Node* root=newNode(1);
root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
cout<<"Preorder: ";
printPreOrder(root);
cout<<endl<<"Inorder: ";
printInOrder(root);
cout<<endl<<"PostOrder: ";
printPostOrder(root);
int heightTree=height(root);
cout<<endl<<"Height of the tree: "<<heightTree;
return 0;
}
