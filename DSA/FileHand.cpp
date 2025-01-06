#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


void create(){
	int RollNo;
	string Name, Div, Address;
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
	cout<<"Enter Address: ";
	cin>>Address;
	f<<RollNo<<" "<<Name<<" "<<Div<<" "<<Address<<endl;
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

void searchStudent() {
	int RollNo;
	string Name, Div, Address;
	int searchRoll;
	cout << "Enter Roll No to search: ";
	cin >> searchRoll;
	
	fstream f("file1.txt", ios::in);
	bool found = false;
	
	while(f >> RollNo >> Name >> Div >> Address) {
		if(searchRoll == RollNo) {
			cout << "\nStudent found!\n";
			cout << "Roll No: " << RollNo << "\nName: " << Name 
				 << "\nDivision: " << Div << "\nAddress: " << Address << endl;
			found = true;
			break;
		}
	}
	
	if(!found) {
		cout << "Student record not found!" << endl;
	}
	f.close();
}

int main(){
	int choice;
	do {
		cout << "\n1. Add Student\n2. Delete Student\n3. Search Student\n4. Display All\n5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		
		switch(choice) {
			case 1: create(); break;
			case 2: remove(); break;
			case 3: searchStudent(); break;
			case 4: display(); break;
			case 5: cout << "Exiting...\n"; break;
			default: cout << "Invalid choice!\n";
		}
	} while(choice != 5);
	return 0;
}