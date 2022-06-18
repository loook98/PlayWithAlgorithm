#include <bits/stdc++.h>

using namespace std;

class Bank {
public:
    vector<long long> myBalance;
    int accountNum;

    Bank(vector<long long> &balance) {
        myBalance = vector<long long>(balance.begin(), balance.end());
        accountNum = myBalance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if ((account1 < 1 || account1 > accountNum) || (account2 < 1 || account2 > accountNum))
            return false;
        if (myBalance[account1 - 1] < money)
            return false;
        myBalance[account1 - 1] -= money;
        myBalance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > accountNum)
            return false;
        myBalance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > accountNum)
            return false;
        if (myBalance[account - 1] < money)
            return false;
        myBalance[account - 1] -= money;
        return true;
    }
};