/*
*
//******************************************************2680. Maximum OR.******************************************************

https://leetcode.com/problems/maximum-or/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[12,9]
1
[8,1,2]
2
[4,6,5,3,3,6,7,8,6,5,3,2,2,7,6,8,8,7,6,5]
5
[5,7,4,3,3,5,6,7,8,9,5,4,2,5,6,8,8,6,3,2,4,7,8,7,6]
2
[36,21,21,33]
2



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This algorithm is iteration based. If we multiply a num by 2^x, all bits will shift to let by 'x', the bit which had max. contributed is MSB, it's sole 
// contribution is > rest all bits if they were set. So, in the given array, if we split the 'k' left shifts to more than 1 num, for ex:2, both these nums 
// with highest MSB in the array would have a left shift of < 'k' bits and OR of these two and rest all nums would still be< The sole MSB bit any of the 2 nums 
// if it was left shift by 'k' bits as the combined OR wouldn't have MSB+K bit set in their combined OR. So, in order to get a max OR it should be given to a
// single num among any of the nums which have greatest MSB set in the array. As it would time taking to find out greatest MSB in arr, we iter. over array 
// and assign 'k' left shits to all the nums and OR it with rest all nums(we use prefix and suffix OR to easy the process), calc. OR in every step and track the 
// max OR and return the max OR at the end of iter.







class Solution {
public:
    long long maximumOr(vector<int>& v, int k) {
        long long int total=0;
        long long int suffix[v.size()];
        memset(suffix, 0, sizeof(suffix));
        suffix[v.size()-1]=v.back();
        for(int i=v.size()-2;i>=0;i--) suffix[i]=v[i]|suffix[i+1];			// Suffix array which stores OR of all nums from [i, v.size()-1].
        long long int res=suffix[0], prefix=0;
        for(int i=0;i<v.size();i++) {										// Iter. over array.
            long long int num=v[i];
            num<<=k;														// Applying 'k' left shits to curr. num.
            long long int suf=(i+1<v.size())?suffix[i+1]:0;					// Extracting suffix OR of curr. index.
            if((prefix|num|suf)>res) res=(prefix|num|suf);					// Tracking max OR of all nums in the arr.
            // cout<<"i: "<<i<<" and val: "<<(prefix|num|suf)<<endl;
            prefix|=v[i];													// Updating the prefix OR of nums.
        }
        return res;															// Returning the max OR possible.
    }
};

