#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void registerUser(){
	string username,password;
	string u,p;
	
	cout<<"Enter new username:";
	cin>>username;
	
	ifstream file("users.txt");
	
	while(file>>u>>p){
		if(u==username){
			cout<<"Username already exists!"<<endl;
			file.close();
			return;
			
		}
	}
	file.close();
	
	cout<<"Enter new password";
	cin>>password;
	
	ofstream out("users.txt",ios::app);
	  out<<username<<" "<<password<<endl;
	  out.close();
	
	cout<<"registration successful!"<<endl;
	
}
void loginUser(){
	string username,password;
	string u,p;
	bool found = false;
	
	cout<<"Enter username:";
	cin>> username;
	
	cout<<"Enter password:";
	cin>> password;
	
	ifstream file("users.txt");
	while(file>>u>>p){
		if (u==username&&p==password){
			found=true;
			break;
		}
	}
	file.close();
	
	if(found)
	   cout<<"Login successful!"<<endl;
	else
	   cout<<"Invalid username or password!"<<endl;
	
}
int main(){
	int choice;
	do{
		cout<<"\n1. Register";
		cout<<"\n2. Login";
		cout<<"\n3. Exit";
		cout<<"\nEnter choice: ";
		cin>>choice;
		
		if (choice ==1)
		   registerUser();
		else if(choice==2)
		     loginUser();
		else if(choice==3)
		     cout<<"Goodbye!"<<endl;
		else
		    cout<<"Inavlid choice!"<<endl;
	}while(choice!=3);
	return 0;
}