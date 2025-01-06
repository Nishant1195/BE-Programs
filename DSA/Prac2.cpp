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
	f.close();
}

void remove(){
int RollNo;
string Name, Div;
 fstream f("file1.txt", ios::in);
 fstream f1("temp.txt", ios::app);
 int roll;
 cout<<"Enter Your Roll No: ";
 cin>>roll;
 
 while(!f.eof()){
 	f >> RollNo >> Name >> Div;
 	if(roll != RollNo){
 		f1<<RollNo<<" "<<Name<<" "<<Div<<endl;
 	}
 }
 remove("file1.txt");
 rename("temp.txt", "file1.txt");
 f1.close();
 f.close();
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
	f.close();
}



int main(){

	create();
	
	display();
	
	remove();
}
