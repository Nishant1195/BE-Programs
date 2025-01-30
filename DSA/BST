#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

class BST{
public:
	Node *root;
	BST(){
		root = NULL;		
	}
	
	void create(int data){
		Node *newNode = new Node();
		if(root==NULL){
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;
			root=newNode;
		}
	}
	
	void insert(int data, Node *root){
		Node *insertNode = new Node();
		if(root==NULL){
			create(data);
		}else{
		if(root->data<data){
			if(root->right==NULL){
				root->right=insertNode;
			}else{
				insert(data,root->right);
			}
		}
		else(root->data>data){
			if(root->left==NULL){
				root->left=insertNode;
			}else{
				insert(data,root->left);
			}
		}}
	}
	
	void display(Node *root){
		Node *displayNode = new Node();
		if(root!=NULL){
			cout<<"Root Node: "<<root->data<<endl;
		}
		if(root->left!=NULL){
			displayNode=root->left;
			cout<<"Root Left: "<<displayNode->data<<endl;
		}
		if(root->right!=NULL){
			displayNode=root->right;
			cout<<"Root Right: "<<displayNode->data<<endl;
		}
	}
	
	
};

int main(){
	BST bt;
	bt.create(25);
	bt.insert(15, bt.root);
	bt.insert(35, bt.root);
	bt.display(bt.root);
}
