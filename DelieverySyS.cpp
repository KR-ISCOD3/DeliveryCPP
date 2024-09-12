#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoy(){
	cout<<"\n\n\n\n\n";
}

void LoadingBar(){
	char a = 219;
	gotoy();
	cout<<"\t\t\t\t\tWelcome...."<<endl;
	cout<<"\t\t\t\t\t";
	for(int i = 0 ; i < 26;i++){
		Sleep(80);
		cout<<a;
	}
}

class Register{
	private:
		char username[20];
		char email[20];
		char pass[20];
	public:
		void Input(){
			regis:
				gotoy();
				cout<<"\t\t\t\t  -------------- Register form ----------------"<<endl<<endl;
				cout<<"\t\t\t\t\t   Enter Email   : ";gets(email);
				cout<<"\t\t\t\t\t   Enter Username: ";gets(username);
				cout<<"\t\t\t\t\t   Enter Password: ";gets(pass);
				cout<<"\t\t\t\t  ---------------------------------------------"<<endl<<endl;
				if(strlen(pass) < 8 ){
					cout<<"\t\t\t\t  Your password must be 8 charactors...";
					getch();
					system("cls");
					goto regis;
				}
		}
		char *getUsername(){
			return username;
		}	
		char *getEmail(){
			return email;
		}	
		char *getPass(){
			return pass;
		}	
};

void Regis(){
	Register re;
	fstream file;
	file.open("UserRecord.bin",ios::app | ios::binary);
	
	re.Input();
	file.write((char*)&re,sizeof(re))<<endl;
	file.close();
}

void Login(){	
	Register arr[100],re;
	fstream file;
	int count = 0;
	
	char nameoremail[20],password[20];
	
	file.open("UserRecord.bin",ios::in | ios::binary);
	
	while(file.read((char*)&re,sizeof(re))){
		arr[count] = re;
		count++;
	}
	again:
	gotoy();
	cout<<"\t\t\t\t  ----------------- Login form ----------------"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter Email Or Username : ";gets(nameoremail);
	cout<<"\t\t\t\t\tEnter Your Password     : ";gets(password);
	cout<<"\t\t\t\t  ---------------------------------------------"<<endl<<endl;
	
	for(int i = 0 ; i < count ; i++){
		if( ( (strcmp(nameoremail,arr[i].getUsername()) == 0) || (strcmp(nameoremail,arr[i].getEmail()) == 0) ) &&  (strcmp(password,arr[i].getPass()) == 0)){
			system("cls");
			LoadingBar();
			break;
		}
		else{
			cout<<"\t\t\t\t\t    Invalid username email or password.";
			getch();
			system("cls");
			goto again;
		}
	}
	
	file.close();
	
}


void Form(){
	int op;	
	sys:
	gotoy();
	cout<<"\t\t\t\t----------------------------------------------"<<endl;
	cout<<"\t\t\t\t|                                            |"<<endl;
	cout<<"\t\t\t\t|              DELIEVERY SYSTEM              |"<<endl;
	cout<<"\t\t\t\t|                                            |"<<endl;
	cout<<"\t\t\t\t----------------------------------------------"<<endl;
	cout<<"\t\t\t\t|[1. Sign in]                    [2. Sign up]| "<<endl;
	cout<<"\t\t\t\t----------------------------------------------"<<endl;
	cout<<"\t\t\t\t Chose one option: ";cin>>op;
	
	if(op == 1){
		system("cls");	
		cin.ignore();
		Login();
	}else if(op == 2){
		system("cls");
		cin.ignore();
		Regis();
		getch();
		goto sys;
	}else{
		system("cls");
		goto sys;
	}
}

void Menu(){
		gotoy();
		cout<<"\t\t\t\t  ----------------- Input form ----------------"<<endl;
		cout<<"\t\t\t\t  | 1. Write Data                             |"<<endl;
		cout<<"\t\t\t\t  ---------------------------------------------"<<endl;
		cout<<"\t\t\t\t  | 2. Read Data                              |"<<endl;
		cout<<"\t\t\t\t  ---------------------------------------------"<<endl;
		cout<<"\t\t\t\t  | 3. Update Data                            |"<<endl;
		cout<<"\t\t\t\t  ---------------------------------------------"<<endl;
		cout<<"\t\t\t\t  | 4. Delete Data                            |"<<endl;
		cout<<"\t\t\t\t  ---------------------------------------------"<<endl<<endl;
}
class Customer{
	private:
		int id;
		char name[20];
		char tel[20];
		char location[20];
		char time[20];
	public:
		Customer(){
			id = 0;
			strcpy(name,"undifine");
			strcpy(tel,"undifine");
			strcpy(location,"undifine");
			strcpy(time,"undifine");
		}
		void Input(){
			cout<<"\t\t\t\t  ----------------- Input form ----------------"<<endl<<endl;
			cout<<"\t\t\t\t\t  Enter ID       : ";cin>>id;
			cout<<"\t\t\t\t\t  Enter Name     : ";cin.ignore();gets(name);
			cout<<"\t\t\t\t\t  Enter Tel      : ";gets(tel);
			cout<<"\t\t\t\t\t  Enter Time     : ";gets(time);
			cout<<"\t\t\t\t\t  Enter Location : ";gets(location);
			cout<<"\t\t\t\t  ---------------------------------------------"<<endl<<endl;
		}
		void Input(int id){
			cout<<"\t\t\t\t  ----------------- Input form ----------------"<<endl<<endl;
			this->id = id;
			cout<<"\t\t\t\t\t  Enter Name     : ";cin.ignore();gets(name);
			cout<<"\t\t\t\t\t  Enter Tel      : ";gets(tel);
			cout<<"\t\t\t\t\t  Enter Time     : ";gets(time);
			cout<<"\t\t\t\t\t  Enter Location : ";gets(location);
			cout<<"\t\t\t\t  ---------------------------------------------"<<endl<<endl;
		}
		void Output(){		
			cout<<"\t\t "<<id<<"\t\t"<<name<<"\t\t"<<tel<<"\t\t\t"<<time<<"\t\t"<<location<<endl;
		}
		int getID(){
			return id;
		}
};

int main(){
	Customer cus;
	fstream file;
	Form();
	system("cls");
	int op;
	do{
		Menu();
		cout<<"\t\t\t\t   Enter One optione: ";cin>>op;
		switch(op){
			case 1:{
				system("cls");
				gotoy();
				file.open("CustomerRecord.bin",ios::app | ios::binary);
				cus.Input();
				file.write((char*)&cus,sizeof(cus));	
				cout<<"\t\t\t\t  Data was recorded...";
				file.close();
				break;
			}
			case 2:{
				system("cls");
				gotoy();
				file.open("CustomerRecord.bin",ios::in | ios::binary);
				cout<<"\t\t                                    [- Record Data -] "<<endl;
				cout<<"\t\t --------------------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t  ID\t\tName\t\tTel\t\t\t\tTime\t\tLocation"<<endl;
				cout<<"\t\t --------------------------------------------------------------------------------------------"<<endl;
				while(file.read((char*)&cus,sizeof(cus))){
					cus.Output();
					cout<<"\t\t --------------------------------------------------------------------------------------------"<<endl;
				}
				file.close();
				break;
			}
			case 3:{
				int sid;
				fstream tmp;
				
				system("cls");
				
				file.open("CustomerRecord.bin",ios::in | ios::binary);				
				tmp.open("Tmp.bin",ios::out | ios::binary);
				updateagain:
				gotoy();
				int check = 0;	
				cout<<"\t\t\t\t  ----------------- Update form ----------------"<<endl<<endl;
				cout<<"\t\t\t\t\t Enter ID you want to update: ";cin>>sid;cout<<endl;
				cout<<"\t\t\t\t  ---------------------------------------------"<<endl;
				
				while(file.read((char*)&cus,sizeof(cus))){
					if(sid == cus.getID()){
						system("cls");
						gotoy();
						cus.Input(sid);
						tmp.write((char*)&cus,sizeof(cus));
						check=1;
						cout<<"\t\t\t\t\t  Update success...!"<<endl;
					}else{
						tmp.write((char*)&cus,sizeof(cus));
					}
				}
				if(check == 0){
					gotoy();
					system("cls");
					cout<<"\t\t\t\t\t 404 Not found please try again..."<<endl;
				}
				
				file.close();
				tmp.close();			
				remove("CustomerRecord.bin");
				rename("Tmp.bin","CustomerRecord.bin");	
				break;
			}
			case 4:{
				int sid;
				fstream tmp;
				system("cls");
			
				int check = 0;
					
				file.open("CustomerRecord.bin",ios::in | ios::binary);				
				tmp.open("Tmp.bin",ios::out | ios::binary);
				gotoy();	
				cout<<"\t\t\t\t  ----------------- Delete form ----------------"<<endl<<endl;
				cout<<"\t\t\t\t\t Enter ID you want to delete: ";cin>>sid;cout<<endl;
				cout<<"\t\t\t\t  ---------------------------------------------"<<endl;
				
				while(file.read((char*)&cus,sizeof(cus))){
					if(sid == cus.getID()){
						system("cls");
						gotoy();
						check=1;
						cout<<"\t\t\t\t\t  Delete success...!"<<endl;
					}else{
						tmp.write((char*)&cus,sizeof(cus));
					}
				}
				if(check == 0){
					system("cls");
					gotoy();
					cout<<"\t\t\t\t\t 404 Not found please try again..."<<endl;
				}
				
				file.close();
				tmp.close();			
				remove("CustomerRecord.bin");
				rename("Tmp.bin","CustomerRecord.bin");	
				break;
			}
		}
		getch();
		system("cls");
		
	}while(op < 5);
}