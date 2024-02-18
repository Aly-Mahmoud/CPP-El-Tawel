#include <iostream>
#include <vector> // Include the vector header to store Bank objects

class Bank
{
private:
    int Account_number;
    std::string Account_HolderName;
    std::string Account_Type;
    int Account_Balance;

public:
    // Constructors
    Bank() : Bank(0000, "NoName", "NoType", 0)
    {
        std::cout << "The default constructor has been called" << std::endl;
    }

    Bank(int Account_number_src, std::string Account_HolderName_src, std::string Account_Type_src, int Account_Balance_src) 
    : Account_number(Account_number_src), Account_HolderName(Account_HolderName_src), Account_Type(Account_Type_src), Account_Balance(Account_Balance_src)
    {
        std::cout << "The parameterized constructor has been called" << std::endl;
    }

    // Setters and Getters

    // AccountNumber
    void Set_AccountNumber(int Account_number_src)
    {
        Account_number = Account_number_src;
    }

    int Get_AccountNumber()
    {
        return Account_number;
    }

    // Account Holder Name
    void Set_AccountHolder(std::string AccountHolder_src)
    {
        Account_HolderName = AccountHolder_src;
    }

    std::string Get_AccountHolder()
    {
        return Account_HolderName;
    }

    // Account Type
    void Set_AccountType(std::string AccountType_src)
    {
        Account_Type = AccountType_src;
    }

    std::string Get_AccountType()
    {
        return Account_Type;
    }

    // AccountBalance
    void Set_AccountBalance(int AccountBalance_src)
    {
        Account_Balance = AccountBalance_src;
    }

    int Get_AccountBalance()
    {
        return Account_Balance;
    }

    // Deposit and Withdraw functions
    void Deposit(int Deposit_src)
    {
        Account_Balance += Deposit_src;
    }

    void Withdraw(int Withdraw_src)
    {
        if (Withdraw_src <= Account_Balance)
        {
            Account_Balance -= Withdraw_src;
        }
        else
        {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    // Display Account Info
    void Display_Accountinfo() const
    {
        std::cout << "Account Number: " << Account_number << std::endl;
        std::cout << "Account Holder: " << Account_HolderName << std::endl;
        std::cout << "Account Type: " << Account_Type << std::endl;
        std::cout << "Account Balance: " << Account_Balance << std::endl;
    }

    // Destructor
    ~Bank()
    {
        std::cout << "The default destructor has been called" << std::endl;
    }
};

int main()
{
    std::vector<Bank> accounts; // Vector to store Bank objects

    int choice;
    do
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Create an account" << std::endl;
        std::cout << "2. Deposit funds" << std::endl;
        std::cout << "3. Withdraw funds" << std::endl;
        std::cout << "4. Total balance" << std::endl;
        std::cout << "5. Display all accounts" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int account_number, balance;
            std::string holder_name, account_type;
            std::cout << "Enter account number: ";
            std::cin >> account_number;
            std::cout << "Enter account holder name: ";
            std::cin >> holder_name;
            std::cout << "Enter account type: ";
            std::cin >> account_type;
            std::cout << "Enter initial balance: ";
            std::cin >> balance;
            Bank new_account(account_number, holder_name, account_type, balance);
            accounts.push_back(new_account);
            break;
        }
        case 2:
        {
            int account_number, deposit_amount;
            std::cout << "Enter account number: ";
            std::cin >> account_number;
            std::cout << "Enter deposit amount: ";
            std::cin >> deposit_amount;
            for (auto &account : accounts)
            {
                if (account.Get_AccountNumber() == account_number)
                {
                    account.Deposit(deposit_amount);
                    std::cout << "Deposit successful" << std::endl;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            int account_number, withdraw_amount;
            std::cout << "Enter account number: ";
            std::cin >> account_number;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> withdraw_amount;
            for (auto &account : accounts)
            {
                if (account.Get_AccountNumber() == account_number)
                {
                    account.Withdraw(withdraw_amount);
                    std::cout << "Withdrawal successful" << std::endl;
                    break;
                }
            }
            break;
        }
        case 4:
        {
            int total_balance = 0;
            for (auto &account : accounts)
            {
                total_balance += account.Get_AccountBalance();
            }
            std::cout << "Total balance of all accounts: " << total_balance << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Displaying all accounts:" << std::endl;
            for (const auto &account : accounts)
            {
                account.Display_Accountinfo();
            }
            break;
        }
        case 6:
            std::cout << "Exiting program" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
