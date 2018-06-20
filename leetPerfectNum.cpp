/*
*
//************************************************************507. Perfect Number.*****************************************************

We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1000000000
1
123123



// Time Complexity: O(n^0.5).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^0.5).
// Space Complexity: O(1).	
// This algorithm is Mathematics based. As, at sqrt, the smaller and bigger factor gets reversed, we iterate till then. If in b/w, if the curr. 
// factor divides num, then add factor and factor pair to the result sum. If in b/w the sum> num, then return false directly.








class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;											// If num=1, return false, base case.
        int lim=sqrt(num);													// Upper limit for factors.
        int count=1;														// Result sum.(Including the factor:1).
        for(int i=2;i<=lim;i++){											// Iterates upto sqrt(num).
            // cout<<"i: "<<i<<" and sec: "<<sec<<endl;
            if(num%i==0) count+=i+(num/i);									// If factor divides num, inc. the count.
            if(count>num) return false;										// If sum>num, return false, as , we need sum to be equal to num.
        }
        // cout<<"The count is: "<<count<<endl;
        return count==num;													// Checker whether sum==num.
    }
};