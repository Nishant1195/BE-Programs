#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	char exp;
	Node* left = NULL;
	Node* right = NULL;
};

struct Stack{
	Node* exp[50];
	int top=-1;
};

Stack s;

void push(Node* n){
	if(s.top > 49){
	s.exp[++s.top]=n;
	}
}

Node* pop() {
    if (s.top >= 0) {
        return s.exp[s.top--];
    }
    return NULL;
}

void expression(string str){
	Node* t1=NULL;
	Node* t2=NULL;
	for(int i = str.length()-1;i>=0;i--){
		if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^'){
			t1=pop();
			t2=pop();
			Node *temp = new Node();
			temp->exp = str[i];
			temp->left = t1;
			temp->right = t2;
			push(temp);
		}
		else{
			Node *temp = new Node();
			temp->exp = str[i];
			temp->left = NULL;
			temp->right = NULL;
			push(temp);
		}
	}
}

void display_post(Node* n){
	if(n == NULL){
		cout<<"Empty"<<endl;
		return;
		
	}else{
		if(n->left!=NULL){
			display_post(n->left);
		}
		if(n->right!=NULL){
			display_post(n->right);
		}
		cout<<n->exp;
	}
}

int main(){
	string str = "+-/^ABD";
	cout<<"Post Order: "<<endl;
	expression(str);
	display_post(s.exp[s.top]);
}
