#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>


using UnixTS = unsigned int;

const unsigned short TRANSACTION_COL_N = 6;
const unsigned short ACCOUNT_COL_N = 3;

struct Transaction {
    std::string id;
    UnixTS date;
    std::string type;
    std::string from;
    std::string to;
    double amount;
    bool operator<(const Transaction& other) const;
};

class Account
{
public:
    Account();// default constructor
    Account(const std::string& id, const std::string& name, UnixTS validity_dt = UINT_MAX);
    void addTransaction(const Transaction& transaction);
    double getBalance(UnixTS = UINT_MAX) const;
    void printInfo() const;
    size_t getTransactionsCount() const;

private:
    std::string id;
    std::string name;
    std::set<Transaction> transactions;
    UnixTS validity_dt;
};

void Account::printInfo() const
{
    std::cout << "--------------------------------\n"
              << "id: " << id << '\n'
              << "name: " << name << '\n'
              << "validity datetime: " << validity_dt << '\n'
              << "--------------------------------\n";
}

size_t Account::getTransactionsCount() const
{
    return transactions.size();
}

Account::Account()
{
    id = "00000000-0000-0000-0000-000000000000";
    name = "Noname";
    validity_dt = 0;
}
// Task 1 (5 points)
// Implement Account constructor with arguments
Account::Account(const std::string& id,
                 const std::string& name,
                 UnixTS validity_dt) : id(id), name(name), validity_dt(validity_dt) {}

// Task 2 (10 points)
// Implement operator< overloading for Transaction
bool Transaction::operator<(const Transaction& other) const
{
    if (this->date != other.date)
    {
        return this->date < other.date;
    }
    else if (this->type != other.type)
    {
        if (this->type == "deposit" and other.type == "withdraw")
        {
            return this->type < other.type;
        }
        else if (this->type == "deposit" and other.type == "transfer")
        {
            return this->type < other.type;
        }
        else if (this-> type == "withdraw" and other.type == "deposit")
        {
            return this->type < other.type;
        }
        else if (this->type == "withdraw" and other.type == "transfer")
        {
            return this->type > other.type; 
        }
        else if (this->type == "transfer" and other.type == "deposit")
        {
            return this->type > other.type;
        }
        else if (this->type == "transfer" and other.type == "withdraw")
        {
            return this->type > other.type;
        } 
    }
    return false;
}

// Task 3 (10 points)
// Implement get balance to date method (default max value)
double Account::getBalance(UnixTS timestamp) const
{
    double balance = 0;
    for (auto tr : transactions)
    {
        if (tr.date <= timestamp)
        {
            if (tr.type == "deposit" and tr.to == id)
            {
                balance += tr.amount;
            }
            else if (tr.type == "withdraw" and tr.from == id)
            {
                balance -= tr.amount;
            }
            else if (tr.type == "transfer" and tr.to == id)
            {
                balance += tr.amount;
            }
            else if (tr.type == "transfer" and tr.from == id)
            {
                balance -= tr.amount;
            }
            else if (tr.type == "transfer" and (tr.from == id and tr.to == id))
            {
                balance += 0;
            }
        }
    }
    return balance;
}

// Task 4 (15 points)
// Implement adding transaction to Account
void Account::addTransaction(const Transaction& transaction)
{
    transactions.insert(transaction);
    validity_dt = transaction.date;
}

// Task 5 (20 points)
// Implement transaction and account reading from csv and fill accounts by transactions
using AccountContainer = std::unordered_map<std::string, Account>;
using TransactionContainer = std::set<Transaction>;

TransactionContainer readTransactions(std::ifstream& fileStream)
{
    TransactionContainer transactions;

    std::string line;
    std::getline(fileStream, line);
    size_t transactionsCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < transactionsCount; ++i)
    {
        std::getline(fileStream, line);
        std::stringstream ss(line);
        std::string field;
        Transaction transaction;

        std::getline(ss, transaction.id, ';');
        std::getline(ss, field, ';');
        transaction.date = std::stoul(field);
        std::getline(ss, transaction.type, ';');
        std::getline(ss, transaction.from, ';');
        std::getline(ss, transaction.to, ';');
        std::getline(ss, field, ';');
        transaction.amount = std::stod(field);

        transactions.insert(transaction);
    }

    return transactions;
}

AccountContainer readAccounts(std::ifstream& fileStream)
{
    AccountContainer accounts;

    std::string line;
    std::getline(fileStream, line);
    int accountsCount = std::stoi(line);
    std::getline(fileStream, line);

    for (int i = 0; i < accountsCount; i++)
    {
        std::getline(fileStream, line);
        std::stringstream ss(line);
        std::string field;
        
        std::string id;
        std::string name;
        UnixTS validity_dt;

        std::getline(ss, id, ';');
        std::getline(ss, name, ';');
        std::getline(ss, field, ';');
        validity_dt = std::stoul(field);

        Account account(id, name, validity_dt);

        accounts[id] = account;
    }
    return accounts;
}

void fillAccounts(AccountContainer& accounts, const TransactionContainer& transactions)
{
    for (auto tr: transactions)
    {
        for (auto& acc: accounts)
        {
            if (acc.first == tr.from or acc.first == tr.to)
            {
                acc.second.addTransaction(tr);
            }
        }
    }
}
