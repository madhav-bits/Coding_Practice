/*
*
//******************************************************2562. Find the Array Concatenation Value.***********************************************

https://leetcode.com/problems/find-the-array-concatenation-value/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[7,52,2,4]
[5,14,13,8,12]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. At every step we concatenate the nums on both ends and add the resulting number to the final result.






class Solution {
public:
    long long findTheArrayConcVal(vector<int>& v) {
        long long int res=0;
        for(int i=0, j=v.size()-1;i<=j;i++,j--) {
            string temp=to_string(v[i]);
            if(i<j) temp+=to_string(v[j]);																// Appending nums from both ends to form a concatenation number.
            res+=stoi(temp);
        }
        return res;																						// Returning the concatenation value of the given array.
    }
};


