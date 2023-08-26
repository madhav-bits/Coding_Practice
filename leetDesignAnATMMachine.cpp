/*
*
//******************************************************2241. Design an ATM Machine.******************************************************

https://leetcode.com/problems/design-an-atm-machine/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["ATM","deposit","withdraw","deposit","withdraw","withdraw"]
[[],[[0,0,1,2,1]],[600],[[0,1,0,1,1]],[600],[550]]
["ATM","deposit","withdraw","deposit","withdraw","withdraw","deposit","withdraw","withdraw","withdraw","withdraw","withdraw"]
[[],[[0,0,1,2,1]],[600],[[0,1,0,1,1]],[600],[550],[[4,7,6,5,3]],[450],[2140],[1000],[740],[300]]



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is iteration based. We maintain array to sore denominations we have and #notes per denomination available. 
// For a deposit request, we iterate over deposit array and add these new notes count to the already existing notes count.
// For withdraw request,  we try to use the larger values first by calc. #notes of larger denom. used first followed by lower denom. notes in dec. order. We 
// also ensure we only use at max available #notes per denomination. After calc. #notes for each denomination, if the req. amount is still not-zero, that means 
// we can't disbruse the amount requested using available count of notes and we return -1. If it becomes =0, we subtract #notes used(which we calc. earlier) 
// from the #notes available and return the #notes used array.







class ATM {
public:
    vector<long long int>currency, notes;
    ATM() {
        notes=vector<long long int>(5,0);									// #notes available array.
        currency={20,50,100,200,500};										// Denominations available.
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<currency.size();i++) notes[i]+=banknotesCount[i];		// Updating the #notes available array.
        return ;
    }
    
    vector<int> withdraw(int amount) {
        vector<int>res(5,0);
        for(int i=4;i>=0;i--) {
            res[i]=min(amount/currency[i], notes[i]);						// Calc. #notes of curr. denomination used.
            amount-=res[i]*currency[i];										// Removing the value of notes used of this denomination from req. amount.
        }
        if(amount!=0) return {-1};											// If we can't disburse req. amount, we return -1.
        for(int i=0;i<=4;i++) notes[i]-=res[i];								// Substracting #notes used from the #notes available array.
        return res;															// Returning #notes used array whose total value adds up to req. amount.
    }
};

