/*
*
//**************************************2177. Find Three Consecutive Integers That Sum to a Given Number.*************************************

https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


33
0
1
2
3
4
232
23
2
64
56856
3254347
5685
68



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. When we add three consec. nums, their total would be 3*middle number. If the given number is not multiple of 3, we can't
// form it as total of three consec. nums. If given num is div by 3, we calc. middle num of the 3 nums, calc. it's adj. two nums and return the nums triplet.







class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0) return {};												// If given num isn't div by 3, we can't form triplet whose total is given num.
        long long int ans=num/3;											// Calc. middle num of triplet.
        return {ans-1, ans, ans+1};											// Calc. triplet and return them.
    }
};

