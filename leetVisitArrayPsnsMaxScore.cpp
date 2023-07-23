/*
*
//*****************************************2786. Visit Array Positions to Maximize Score.******************************************

https://leetcode.com/problems/visit-array-positions-to-maximize-score/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,6,1,9,2]
5
[2,4,6,8]
3
[23,4,2,3,6,7,54,4,67,76,43,3,6,78,8,67,5,3,13,8,89,66,54,3,33,56,7,88,9,76,5,13,22,13,20,17,78,76,54,42,52,56,34,3,6,6,8,98,96]
20



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, when deciding to visit a num it's total with sum until then depends on the fact that the last value before
// it is a even/odd so we can check parity for both last val and curr. index and decide on the total, if the total<maxEven/maxOdd until then we skip including
// curr. index. for even/oddMaxScore based on curr. num's parity. We return the largest of even/oddMaxScore at the end of iter.







class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long int evenMaxScore=INT_MIN, oddMaxScore=INT_MIN;
        if(nums[0]%2==0) evenMaxScore=nums[0];
        else oddMaxScore=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            bool isEven=(nums[i]%2==0);
																			// As curr. num can be preceeded by an even/odd number, we try to add curr. num to 
																			// even/oddMaxScore until prev. index.
            long long int evenScore=evenMaxScore+nums[i];
            if(!isEven) evenScore-=x;										// Score if curr. num is preceeded by even number.
            
            long long int oddScore=oddMaxScore+nums[i];						// Score if curr. num is preceeded by odd number.
            if(isEven) oddScore-=x;
            
            long long int maxScore=max(evenScore, oddScore);				// Getting max. of the both.
            if(isEven) {													// Trying to update  the even/oddMaxScore based on curr. num's parity. 
                if(maxScore>evenMaxScore) evenMaxScore=maxScore;
            }else if(maxScore>oddMaxScore) oddMaxScore=maxScore;
        }
        return max(evenMaxScore, oddMaxScore);								// Returning the max. of the even/oddMaxScore.
    }
};

