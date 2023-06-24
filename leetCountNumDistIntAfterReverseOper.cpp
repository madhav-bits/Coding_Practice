/*
*
//******************************************************2442. Count Number of Distinct Integers After Reverse Operations.******************************************************

https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,13,10,12,31]
[2,2,2]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. Here, we use a set to keep track of number of distinct integers encountered in the iteration. For every number we calc. the reversed integer for it and store
// it in the set. At the end of iter. we return the size of the set, which is the number of distinct integers.







class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>st;												// Set to track number of distinct integers.
        for(int num:nums) {
            int num1=0;
            st.insert(num);													// Storing curr. num in set.
            while(num) {													// Reversing curr. number.
                num1=num1*10+num%10;
                num/=10;
            }
            st.insert(num1);												// Storing reversed number in the set.
        }
        return st.size();													// Returning total number of distinct integers.
    }
};

