/*
*
//******************************************************2043. Simple Bank System.******************************************************

https://leetcode.com/problems/simple-bank-system/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Bank","withdraw","transfer","deposit","transfer","withdraw"]
[[[10,100,20,50,30]],[3,10],[5,1,20],[5,20],[3,4,15],[10,50]]
["Bank","withdraw","transfer","withdraw","transfer","withdraw","transfer","withdraw"]
[[[10,100,20,50,30]],[3,21],[5,2,20],[5,11],[3,4,25],[10,50],[4,3,10],[1,11]]



// Time Complexity: O(1).													// O(1) for deposit, transfer, withdraw requests.
// Space Complexity: O(n).													// n-#accounts in the bank.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// O(1) for deposit, transfer, withdraw requests.
// Space Complexity: O(n).													// n-#accounts in the bank.
// This algorithm is array based. We first initiate an array to store balances of all accounts in the array. For all types of requests we check if the account
// numbers provided are valid, if not valid we return false and for withdraw and transfer request we check whether if the sender has atleast the trasnfer 
// amount, if no we return false. If all checks are valid, we transfer, withdraw the amount from the specified account to specified account(for transfer req.). 
// Deposit the balance in case of deposit request.







class Bank {
public:
    vector<long long int>accounts;
    Bank(vector<long long>& balance) {
        accounts=balance;													// Init. array to track balances in all accounts.
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>accounts.size() || account2>accounts.size() || accounts[account1-1]<money) return false;// In case of invalid accounts/insufficient amount.
        accounts[account2-1]+=money;										// Inc. balance in receiver account.
        accounts[account1-1]-=money;										// Dec. balance in sender account.
        return true;														// Returning true as request is successfully processed.
    }
    
    bool deposit(int account, long long money) {
        if(account>accounts.size()) return false;							// In case of invalid account number.
        accounts[account-1]+=money;											// Inc. balance in receiver account.
        return true;														// Returning true as request is successfully processed.
    }
    
    bool withdraw(int account, long long money) {
        if(account>accounts.size() || accounts[account-1]<money) return false;// In case of invalid account/insufficient amount.
        accounts[account-1]-=money;											// Dec. balance in sender account.
        return true;														// Returning true as request is successfully processed.
    }
};

