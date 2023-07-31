/*
*
//*****************************************2044. Count Number of Maximum Bitwise-OR Subsets.*****************************************

https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1]
[2,2,2]
[3,2,1,5]



// Time Complexity: O(2^n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(n).	
// This algorithm is DFS based. Here, we use DFS and form all possible subsets, calc. OR and count the ones that match the criteria.







class Solution {
public:
    
    void formSubstrs(vector<int>&v, int index, int rep, int maxOR, int& res) {
        if(index==v.size()) return ;
        
        formSubstrs(v, index+1, rep, maxOR, res);							// DFS call where curr. index is skipped.
        rep|=v[index];														// Adding curr. index to OR calc.
        if(rep==maxOR) res++;												// If curr. XOR matches max OR, inc. the res.
        formSubstrs(v, index+1, rep, maxOR, res);							// DFS call where curr. index is chosen.
        return ;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0, len=nums.size(), cap=(1<<len);
        for(int&num:nums) maxOr|=num;										// If we do OR of all nums, that gives max OR.
        int res=0;
        formSubstrs(nums, 0, 0, maxOr, res);								// DFS call to get #subsets with max OR.
        return res;															// Returning #subsets with max OR.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(n).	
// This algorithm is DFS based. This is same as the above one but with slight improvement. Here, when we observe that curr. OR =max OR, we avoid iterating to later indices as
// performing OR on them would also lead to same value, so we use pow(2, rem. len) and add all of them in a single step to res. The next we observe curr. OR=max OR in the DFS,
// it already means that nums chosen for this OR has been unique and the substrs which we form from the later indices would be unique too and we can safely count them towards
// res, we continue DFS and we return res at the end of iter.










class Solution {
public:
    
    void formSubstrs(vector<int>&v, int index, int rep, int maxOR, int& res) {
        if(index==v.size()) return ;
        
        formSubstrs(v, index+1, rep, maxOR, res);
        rep|=v[index];
        if(rep==maxOR) {													// If curr. OR =max OR.
            res+=pow(2, v.size()-1-index);									// Add all possib. ways to choose later indices to res.
            return ;														// As later indices are accounted for, we skip visiting them with curr. selection of nums.
        }
        formSubstrs(v, index+1, rep, maxOR, res);
        return ;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0, len=nums.size(), cap=(1<<len);
        for(int&num:nums) maxOr|=num;
        int res=0;
        formSubstrs(nums, 0, 0, maxOr, res);
        return res;
    }
};

