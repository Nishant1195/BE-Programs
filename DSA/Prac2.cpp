#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void create(){
	int RollNo;
	string Name, Div;
	fstream f;
	int no;
	f.open("file1.txt", ios::app);
	cout<<"Enter no of Students: ";
	cin>>no;
	for(int i=1; i<=no; i++){
	
	cout<<"Enter Roll No: ";
	cin>>RollNo;
	cout<<"Enter Name: ";
	cin>>Name;
	cout<<"Enter Division: ";
	cin>>Div;
	f<<RollNo<<" "<<Name<<" "<<Div<<endl;
	}
}

void display(){
	int RollNo;
	string Name, Div;
	
	fstream f("file1.txt", ios::in);
	
	string s;
	while(!f.eof()){
	getline(f,s);
	cout<<s<<endl;
	}
}



int main(){

	create();
	
	display();

}
