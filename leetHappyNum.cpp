/*
*
//**********************************************************202. Happy Number.***************************************************

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the 
squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does 
not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
1
100


// Time Complexity: O(n!).  				// Don't know.
// Space Complexity: O(1).				

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).					// Don't know.
// Space Complexity: O(1).				
// This algorithm keeps on calculating the value until we encounter a value which had been already visited. If 1 is reached, then return true.






class Solution {
public:
    int calcNext(int num){										// Calculate the next value using the curr. value.
        int res=0;
        while(num>0){
            int rem=num%10;
            num/=10;
            res+=rem*rem;
        }
        return res;
    }
    bool isHappy(int n) {
        if(n==1) return true;
        bool res;
        unordered_map<int, int> m;
        m[n]=1;
        while(n!=1){											// Waiting for one.
            n=calcNext(n);
            if(m.count(n)==1) return false;						// If already encountered value is encountered, then return false.
            m[n]=1;												// Marking the curr. value as visited.
        }
        return true;											// If 1 encountered, return true.
    }
};



