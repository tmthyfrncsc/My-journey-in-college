#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Costumer {
public:
	string userTypeName;
	int menuChoice, userTypePin, withdraw, balance = 0;

	struct DataStorage {
		string name, cardNum;
		int pin;
	};
	struct DataStorage storage[100] = {
		{"Timothy Francisco","CSD123456",123123},
		{"Lexi Lore", "BLD654321",123456}
	};

	void MainMenu() {
		system("cls");

		cout << right << setw(25) << "~~~~~~~~~~~~~~~ EMC BANK ~~~~~~~~~~~~~~~\n\n";
		cout << setw(25) << "1.Deposit\n" << setw(26) << "2.Withdraw\n"
			<< setw(30) << "3.Check Balance" << endl;

		cout << setw(34) << "Enter your choice: ";
		cin >> menuChoice;

		switch (menuChoice) {

		case 1:
			Deposit();
			break;
		case 2:
			Withdraw();
			break;
		case 3:
			CheckBalance();
			break;
		default:
			MainMenu();
			break;
		}
	}
	void Deposit() {
		int deposit;
		bool isDeposit = false;
		cout << setw(30) << "DEPOSIT" << endl;

		cout << setw(30) << "1. Deposit\n" << setw(30) << "2.Menu" << endl;
		cout << setw(30) << "Enter your choice: ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << setw(30) << "\nEnter the amount: " << setw(30);
			cin >> deposit;
			balance += deposit;

			cout << setw(30) << setw(30) << "Balance: " << setw(1) << balance;
			cout << setw(30) << "\n" << setw(35) << "1.Print receipt\n" << setw(30) << "2.Menu" << endl;

			cout << setw(30) << "Enter your choice: ";
			cin >> menuChoice;

			switch (menuChoice) {
			case 1:
				if (userTypeName == storage[0].name && userTypeName != storage[1].name) {
					cout << setw(30) << storage[0].name << endl;
					cout << setw(30) << storage[0].cardNum << endl;
					cout << setw(30) << "Balance: " << balance << "\n";
				}
				else {

					cout << setw(30) << storage[1].name << endl;
					cout << setw(30) << storage[1].cardNum << endl;
					cout << setw(30) << "Balance: " << balance << "\n";
				}
				cout << setw(30) << "1.Menu" << endl;

				cout << setw(30) << "Enter your choice: ";
				cin >> menuChoice;

				switch (menuChoice) {
				case 1:
					MainMenu();
					break;
				default:
					cout << "Invalid input! Try Again!" << endl;
					break;
				}
				break;
			case 2:
				MainMenu();
				break;
			default:
				cout << "Invalid input! Try Again!" << endl;
				break;
			}
			break;
		case 2:
			MainMenu();
			break;
		default:
			cout << "Invalid input! Try Again!" << endl;
			break;
		}
	}
	void Withdraw() {
		system("cls");
		cout << setw(30) << "WITHDRAW" << "\n\n";

		if (userTypeName == storage[0].name) {
			cout << setw(30) << "Name: " << storage[0].name << endl;
			cout << setw(30) << "Card No. : " << storage[0].cardNum << endl;
			cout << setw(30) << "Balance: " << balance << endl;

			cout << "Amount: ";
			cin >> withdraw;

			if (balance >= withdraw) {
				balance -= withdraw;
				cout << setw(30) << "New Balance: " << balance << endl;
				cout << setw(30) << "Amount withdraw: " << withdraw << endl;
				cout << setw(30) << "THANK YOU";
			}
			else {
				cout << "Insufficient Balance! Input proper amount!" << endl;
			}
		}
		else if (userTypeName == storage[1].name) {
			cout << setw(30) << "Name: " << storage[1].name << endl;
			cout << setw(30) << "Card No. : " << storage[1].cardNum << endl;
			cout << setw(30) << "Balance: " << balance << endl;

			cout << "Amount: ";
			cin >> withdraw;

			balance -= withdraw;

			if (balance >= withdraw) {
				balance -= withdraw;
				cout << setw(30) << "New Balance: " << balance << endl;
				cout << setw(30) << "Amount withdraw: " << withdraw << endl;
				cout << setw(30) << "THANK YOU";
			}
			else {
				cout << "Insufficient Balance! Input proper amount!";
			}
		}
	}
	void CheckBalance() { //2nd prob Enter amout to deposit keep showing up!
		if (userTypeName == storage[0].name) {
			cout << setw(30) << "Name: " << storage[0].name << endl;
			cout << setw(30) << "Card Number: " << storage[0].cardNum << endl;
			cout << setw(30) << "Balance: " << balance << endl;
		}
		else if (userTypeName == storage[1].name) {
			cout << setw(30) << "Name: " << storage[1].name << endl;
			cout << setw(30) << "Card Number: " << storage[1].cardNum << endl;
			cout << setw(30) << "Balance: " << balance << endl;
		}
		cout << setw(30) << "1. Menu" << endl;
		cout << setw(30) << "Enter your choice: ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			MainMenu();
		}
	}
	Costumer() {

	repeat:
		cout << "Enter your name: ";
		getline(cin, userTypeName);

		if (userTypeName == storage[0].name) {
			cout << "Name: " << storage[0].name << "\nCard Number: " << storage[0].cardNum << endl;
			cout << "Enter your pin: ";
			cin >> userTypePin;
			if (userTypePin != storage[0].pin) {
				goto repeat;
			}
			else {
				cout << "Sucessful log-in" << endl;
			}
		}
		else if (userTypeName == storage[1].name) {
			cout << "Name: " << storage[1].name << "\nCard Number: " << storage[1].cardNum << endl;
			cout << "Enter your pin: ";
			cin >> userTypePin;
			if (userTypePin != storage[1].pin) {
				cout << "Incorrect pin!";
				goto repeat;
			}
			else {
				cout << "Sucessful log-in" << endl;
			}
		}
		else {
			cout << "NOT REGISTERED NAME!!\n";
			goto repeat;
		}
	}
};
int main() {
	Costumer costumer;
	costumer.MainMenu();
}
