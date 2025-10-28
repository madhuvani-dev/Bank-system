#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string n, int acc, double bal) {
        name = n;
        accountNumber = acc;
        balance = bal;
    }

    string getName() { return name; }
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;

    // Load existing accounts from file
    ifstream inFile("accounts.txt");
    if (inFile) {
        string name;
        int accNo;
        double bal;
        while (inFile >> accNo >> bal) {
            inFile.ignore();
            getline(inFile, name);
            accounts.push_back(BankAccount(name, accNo, bal));
        }
    }
    inFile.close();

    int choice;
    while (true) {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Display Accounts\n2. Deposit\n3. Withdraw\n4. Add New Account\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (auto &acc : accounts)
                acc.display();
        } 
        else if (choice == 2) {
            int accNo;
            double amount;
            cout << "Enter account number: ";
            cin >> accNo;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.deposit(amount);
                }
            }
        } 
        else if (choice == 3) {
            int accNo;
            double amount;
            cout << "Enter account number: ";
            cin >> accNo;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.withdraw(amount);
                }
            }
        } 
        else if (choice == 4) {
            string name;
            int accNo;
            double bal;

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Balance: ";
            cin >> bal;

            accounts.push_back(BankAccount(name, accNo, bal));
            cout << "New account added successfully!\n";
        } 
        else if (choice == 5) {
            // Save all accounts to file before exit
            ofstream outFile("accounts.txt");
            for (auto &acc : accounts) {
                outFile << acc.getAccountNumber() << " " << acc.getBalance() << " " << acc.getName() << endl;
            }
            outFile.close();

            cout << "All data saved. Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

