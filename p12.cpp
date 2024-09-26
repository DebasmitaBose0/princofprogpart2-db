//C++ class that stimulates and ATM managing account number balance and transactions like mini statement
#include <iostream>

class ATM
{
private:
    int accountNumber;
    float balance;
    float transactions[10]; // Stores last 10 transactions
    int transactionCount;

public:
    ATM(int accNum, float initialBalance = 0.0) : accountNumber(accNum), balance(initialBalance), transactionCount(0)
    {
        for (int i = 0; i < 10; i++)
        {
            transactions[i] = 0; // Initialize transactions to 0
        }
    }

    void deposit(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
            addTransaction(amount);
            std::cout << "Deposited: $" << amount << "\n";
        }
        else
        {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(float amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            addTransaction(-amount); // Negative for withdrawal
            std::cout << "Withdrawn: $" << amount << "\n";
        }
        else
        {
            std::cout << "Invalid withdrawal amount or insufficient balance!\n";
        }
    }

    void checkBalance() const
    {
        std::cout << "Current balance: $" << balance << "\n";
    }

    void printMiniStatement() const
    {
        std::cout << "Mini Statement for Account #" << accountNumber << ":\n";
        std::cout << "Balance: $" << balance << "\n";
        std::cout << "Last 10 transactions:\n";
        for (int i = 0; i < transactionCount; i++)
        {
            if (transactions[i] > 0)
                std::cout << "Deposit: $" << transactions[i] << "\n";
            else
                std::cout << "Withdraw: $" << -transactions[i] << "\n"; // Display positive for withdrawal
        }
        if (transactionCount == 0)
        {
            std::cout << "No transactions yet.\n";
        }
    }

private:
    void addTransaction(float amount)
    {
        if (transactionCount < 10)
        {
            transactions[transactionCount++] = amount;
        }
        else
        {
            // Shift transactions to make room for new one
            for (int i = 0; i < 9; i++)
            {
                transactions[i] = transactions[i + 1];
            }
            transactions[9] = amount;
        }
    }
};

int main()
{
    ATM myATM(123456); // Creating ATM object with account number

    myATM.deposit(500);  // Deposit $500
    myATM.withdraw(100); // Withdraw $100
    myATM.deposit(300);  // Deposit $300

    myATM.checkBalance();       // Check balance
    myATM.printMiniStatement(); // Print mini statement

    myATM.withdraw(1000); // Attempt to withdraw more than balance (should fail)

    return 0;
}
