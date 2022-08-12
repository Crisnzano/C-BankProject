//bankingproject
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void deposit(double & balance, double value){
	cout << "Starting balance:$" <<balance<<endl;
	balance +=value;
	cout <<"Deposit amount : $ "<<value<<endl;
	cout << "Your balance is :$"<<balance<<endl;
	 
}
bool withdraw(double & balance, double value){
	if(balance >= value){
		balance = balance + value;
		return true;
	}
	else {
		return false;
	}
}
void displayBalance(double balance, double value){
	double value1 = balance;
	if (value < 0){
		balance = value1 - value;
		cout << "Starting balance:$"<<balance<<endl;
		cout<<"Withdraw amount :$"<<value<<endl;
		cout<<"Your Balance is :$"<<value1<<endl;
	}
	else {
		balance =-value;
		cout<<"Starting balance:$"<<balance<<endl;
		cout<<"Deposit amount:$"<<value<<endl;
		cout<<"Your balance is :$"<<value1<<""<<endl;
	}
}
void normaluserbankingMenu(){
	double balance = 0, amount;
	string password, newpassword;
	while(true){
		cout<<"Please select an option:"<<endl;
		cout<<"1 -> Withdraw Money"<<endl;
		cout<<"2 -> Request Balance"<<endl;
		cout<<"3 -> Reset your password"<<endl;
		cout<<"4 -> Quit"<<endl;
		char ch;
		cin >> ch;
		switch(ch){
			
			case '1':
				cout <<"Enter amount of withdrawl:$";
				cin >> amount;
				if(amount > balance){
					cout<<"Sorry withdrawl amount exceeds the balance"<<endl;
				}
				else{
					amount = -amount;
					withdraw(balance,amount);
				}
				break;
			case '2':
				displayBalance(balance,amount);
				break;
			case '3':
				cout<<"Enter new password:";
				cin >> newpassword;
				if(newpassword != password){
					cout<<"You have a new password:";
					cout << newpassword;
				}
				break;
			case '4':
				return;
			default:
				cout<<"Wrong option"<<endl;
				break;
		}
		cout << endl;
	}
}
void administratorbankingMenu(){
	double balance = 0, amount;
	string newpassword, password, username;
	while(true){
		cout<<"Please select an option:"<<endl;
		cout<<"1 -> Deposit Money for client"<<endl;
		cout<<"2 -> Register new Client"<<endl;
		cout<<"3 -> Reset your password"<<endl;
		cout<<"4 -> Quit"<<endl;
		char ch;
		cin >> ch;
		switch(ch){
			case'1':
				cout << "Enter amount of deposit:$";
				cin >> amount;
				deposit(balance,amount);
				cout <<"Enter name of client:";
				cin >> username;
				cout << "$"<<amount<<"was deposited to "<< username<<endl;
				break;
			case '2': {
				cout <<"Enter name of new client.\n";
				cin >> username;
				cout <<"Enter password of new client.\n";
				cin >> password;
				cout <<"Enter amount of deposit for new client.\n";
				cin >> amount;
				deposit(balance,amount);
				cout << "$"<< amount <<"was deposited ."<<endl;
				cout <<"Check balance of new user.\n";
				displayBalance(balance,amount);
				ofstream fileOut;
				fileOut.open("userDB.txt");
				fileOut << username;
				fileOut << password;
				fileOut << balance;
				cout<<"Access Granted client is registered -"<<username<<endl;
				fileOut.close();
				break;
			        }
			case '3':
				cout<<"Enter new password:";
				cin >> newpassword;
				if(newpassword != password){
					cout<<"You have Reset your passsword:";
					cout << newpassword;
				}
				break;
			case '4':
				return;
			default:
				cout<<"Wrong option"<<endl;
				break;
		}
		cout << endl;
	}
}
void mainMenu(){
	string un,pw,username,password,newpassword;
	while(true){
		cout<<"Please select an option from menu below:"<<endl;
		cout<<"1.Normal User Login"<<endl;
		cout<<"2.Administrator Login"<<endl;
		cout<<"3.Quit"<<endl;
		cout<<">";
		char ch;
		cin >>ch;
		switch(ch){
			case '1':{
				cout<<"Welcome to the Normal User Login page:\n";
				cout<<"Enter username:";
				cin>>un;
				cout<<"Enter password:";
				cin>>pw;
				ifstream fileIn;
				fileIn.open("userDB.txt", ios::out | ios::app);
				fileIn >> username;
				fileIn >> password;
				if(pw == password && un == username ){
					cout<<"Access Granted-"<<un<<endl;
					normaluserbankingMenu();
					fileIn.close();
				}
				else{
					cout<<"******LOGIN FAILED!******"<<endl;
				}
				break;
			}
			case '2':{
				cout<<"Welcome the Registration and Deposit page\n";
				cout<<"Enter usernane:";
				cin>>un;
				cout<<"Enter password:";
				cin>>pw;
				
				ifstream fileIn;
				fileIn.open("admin.txt");
				fileIn >> username;
				fileIn >> password;
				if(pw == password && un == username){
					cout<<"Access Granted-"<<un<<endl;
					administratorbankingMenu();
					fileIn.close();
				}
				else{
					cout<<"******LOGIN FAILED!******"<<endl;
				}
				break;
			}
			case '3':
				cout <<"Thanks for banking with us"<<un<<endl;
				break;
				default:
					cout<<"Wrong option"<<endl;
		}
		cout<<endl;
	}
}int main(){
	cout<<"*****Welcome to BBIT2020 E-CASH SERVICES*****\n";
	mainMenu();
	return 0;
}
