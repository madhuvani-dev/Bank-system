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
double getBalance() { return balance; }


    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    ofstream outFile("accounts.txt");
for (auto &acc : accounts) {
    outFile << acc.getName() << " " << acc.getAccountNumber() << " " << acc.getBalance() << endl;
}
outFile.close();


    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    ofstream outFile("accounts.txt");
for (auto &acc : accounts) {
    outFile << acc.getName() << " " << acc.getAccountNumber() << " " << acc.getBalance() << endl;
}
outFile.close();


    void display() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    accounts.push_back(BankAccount("Madhu", 1001, 5000));
    accounts.push_back(BankAccount("Anu", 1002, 3000));
    vector<BankAccount> accounts;

// Load accounts from file
ifstream inFile("accounts.txt");
if (inFile) {
    string name;
    int accNo;
    double bal;
    while (inFile >> name >> accNo >> bal) {
        accounts.push_back(BankAccount(name, accNo, bal));
    }
}
inFile.close();


    int choice;
    while (true) {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Display Account\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) break;

        int accNo;
        cout << "Enter Account Number: ";
        cin >> accNo;

        bool found = false;
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                found = true;
                if (choice == 1) acc.display();
                else if (choice == 2) {
                    double amt;
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    acc.deposit(amt);
                }
                else if (choice == 3) {
                    double amt;
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    acc.withdraw(amt);
                }
            }
        }

        if (!found) cout << "Account not found!\n";
    }

    cout << "Thank you for using our bank system!\n";
    return 0;
}

