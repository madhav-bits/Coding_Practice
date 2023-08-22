/*
*
//******************************************************2269. Find the K-Beauty of a Number.******************************************************

https://leetcode.com/problems/find-the-k-beauty-of-a-number/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


240
2
430043
2



// Time Complexity: O(n*k).  
// Space Complexity: O(n+k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).													//n-length of the stringified num, k-substr length.
// Space Complexity: O(n+k).	
// This algorithm is iteration based. Here, while iter. over stringified version of num, we form substrs of length 'k' and convert them to ints and check if 
// they are not equal to zero and are a divisor of num, if yes we inc. res by 1.







class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int res=0;
        for(int i=0;i+k<=s.length();i++) {
            int curr=stoi(s.substr(i,k));									// Forming substr starting at 'i'.
            if(curr!=0 && num%curr==0) res++;								// If curr. substr val is non-zero and a divisor of num, we inc. res by 1.
        }
        return res;															// Returning #substrs of len 'k' that divides the num.
    }
};

