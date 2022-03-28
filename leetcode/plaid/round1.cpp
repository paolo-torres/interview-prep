/*
    Find recurring transactions.

    Part 1:
    Minimum 3 transactions are required to consider it as a recurring transaction
    Same company, same amount, same number of days apart - recurring transactions
    
    Input: Company, Amount, Timestamp (day of the transaction)
    Output: Array of companies who made recurring transactions

    Part 2:
    Amount and timestamps - similar
    20% higher than minimum

    (minimum of all amount) $10 + 20% -> $12
    [10, 11, 12]
*/

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <float.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Transaction {
public:
    Transaction() {
        company = "";
        amount = 0.0;
        timestamp = 0;
    }

    Transaction(string newCompany, double newAmount, int newTimestamp) {
        company = newCompany;
        amount = newAmount;
        timestamp = newTimestamp;
    }

    vector<string> getCompaniesWithRecurringTransactions(
        vector<Transaction>& transactions) {
        
        vector<string> companies;
        if (transactions.empty()) {
            return {};
        }

        unordered_map<string, vector<Transaction>> m;
        for (int i = 0; i < transactions.size(); i++) {
            Transaction transaction = transactions[i];
            vector<Transaction> v = m[transaction.company];
            v.push_back(transaction);
            m[transaction.company] = v;
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            string company = it->first;
            vector<Transaction> v = m[company];
            if (v.size() < 3) {
                continue;
            }

            if (hasRecurringTransactions(v)) {
                companies.push_back(company);
            }
        }

        return companies;
    }
private:
    string company;
    double amount;
    int timestamp;

    bool hasRecurringTransactions(vector<Transaction>& transactions) {
        double minAmount = getMinimumAmount(transactions);
        double maxAmount = minAmount + (minAmount * 0.2);

        int minDays = getMinimumDays(transactions);
        int maxDays = minDays + (int) (minDays * 0.2);

        int prevTimestamp = transactions[0].timestamp;

        for (int i = 0; i < transactions.size(); i++) {
            double curr = transactions[i].amount;
            if (minAmount > curr || curr > maxAmount) {
                return false;
            }

            if (i == 0) {
                continue;
            }

            int days = transactions[i].timestamp - prevTimestamp;
            if (days == 0 || days < minDays || days > maxDays) {
                return false;
            }

            prevTimestamp = transactions[i].timestamp;
        }

        return true;
    }

    double getMinimumAmount(vector<Transaction>& transactions) {
        double minAmount = DBL_MAX;

        for (int i = 0; i < transactions.size(); i++) {
            minAmount = min(minAmount, transactions[i].amount);
        }

        return minAmount;
    }

    int getMinimumDays(vector<Transaction>& transactions) {
        int diff = INT_MAX;
        int prevTimestamp = transactions[0].timestamp;

        for (int i = 1; i < transactions.size(); i++) {
            diff = min(diff, transactions[i].timestamp - prevTimestamp);
            prevTimestamp = transactions[i].timestamp;
        }

        return diff;
    }
};

int main()
{
    Transaction* obj = new Transaction();

    vector<Transaction> transactions {
        {"Netflix", 9.99, 10},
        {"Netflix", 9.99, 20},
        {"Netflix", 9.99, 30},
        {"Amazon", 27.12, 32},
        {"Sprint", 50.11, 45},
        {"Sprint", 50.11, 55},
        {"Sprint", 50.11, 65},
        {"Sprint", 60.13, 77},
    };

    vector<string> result = obj->getCompaniesWithRecurringTransactions(transactions);
    cout << "Companies with recurring transactions: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
