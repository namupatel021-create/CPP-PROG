#include <iostream>
#include <string>
using namespace std;

// ===== Base Class =====
class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo = 0, string holder = "", double bal = 0.0)
    {
        accountNumber = accNo;
        accountHolderName = holder;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber
             << "\nAccount Holder: " << accountHolderName
             << "\nBalance: " << balance << endl;
    }
};

// ===== Derived Class: SavingsAccount =====
class SavingsAccount : public BankAccount
{
    double interestRate; // percentage
public:
    SavingsAccount(int accNo, string holder, double bal, double rate)
        : BankAccount(accNo, holder, bal), interestRate(rate) {}

    void calculateInterest()
    {
        double interest = balance * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};

// ===== Derived Class: CheckingAccount =====
class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string holder, double bal, double limit)
        : BankAccount(accNo, holder, bal), overdraftLimit(limit) {}

    void checkOverdraft(double withdrawAmount)
    {
        if (withdrawAmount > balance + overdraftLimit)
            cout << "Overdraft limit exceeded!" << endl;
        else
            cout << "Within overdraft limit. You can withdraw safely." << endl;
    }
};

// ===== Derived Class: FixedDepositAccount =====
class FixedDepositAccount : public BankAccount
{
    int term; // months
    double interestRate;

public:
    FixedDepositAccount(int accNo, string holder, double bal, int t, double rate)
        : BankAccount(accNo, holder, bal), term(t), interestRate(rate) {}

    void calculateInterest()
    {
        double interest = (balance * interestRate * term) / (12 * 100);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }
};

// ===== Main Function =====
int main()
{
    cout << "=== Bank Account System ===\n";

    // Create one object of each type
    SavingsAccount s1(101, "Vivaan", 100000, 3.5);
    CheckingAccount c1(102, "Agastya", 50000, 25000);
    FixedDepositAccount f1(103, "Prem", 250000, 12, 8.5);

    // Demonstrate functionality
    cout << "\n--- Savings Account ---";
    s1.displayAccountInfo();
    s1.deposit(2000);
    s1.calculateInterest();

    cout << "\n--- Checking Account ---";
    c1.displayAccountInfo();
    c1.withdraw(3500);
    c1.checkOverdraft(4500);

    cout << "\n--- Fixed Deposit Account ---";
    f1.displayAccountInfo();
    f1.calculateInterest();

    cout << "\n=== End of Program ===\n";
    return 0;
}