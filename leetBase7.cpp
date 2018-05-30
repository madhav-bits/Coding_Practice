/*
*
//**********************************************************504. Base 7.***************************************************

Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
-1
-100
100
-232299
232299



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is division based. At each step we get values from end in 7 base representation. We store them in a vector and extract them
// them from the back to get the reversed version of extracted values.







class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return to_string(0);									// If 0, return "0".
        int sign=1;
        if(num<0) sign=-1;												// For neg. values, as we need to put this sign in res we store the sign.
        num=abs(num);													// We work on abs. values.
        vector<int> v;													// To store base 7 values.
        while(num!=0){													// Extracting the 7 base rep. values starting from the LSBits.
            v.push_back(num%7);											
            num=num/7;													// Reducing the provided value to 0.
        }
        string res="";													// Final result.
        if(sign==-1) res+="-";											// If given val. is neg, we add sign to result.
        while(!v.empty()){												// Forming a str of base 7 representation bits.
            //cout<<"Curr. pushed string: "<<v.back()<<endl;
            res+=to_string(v.back());									// Forming 7 base str.
            v.pop_back();												// Extra LSB to get next most significant bit.
        }
        return res;														// Returning the 7 base representation.
    }
};