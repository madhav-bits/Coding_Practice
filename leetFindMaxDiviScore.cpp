/*
*
//******************************************************2644. Find the Maximum Divisibility Score.******************************************************

https://leetcode.com/problems/find-the-maximum-divisibility-score/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,7,9,3,9]
[5,2,3]
[20,14,21,10]
[5,7,5]
[12]
[10,16]


// Time Complexity: O(n*m).																				//n-length of nums, m-length of the divisors.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).																				//n-length of nums, m-length of the divisors.
// Space Complexity: O(1).	
// This algorithm is iteration based. For every divisor, we iterate over all nums, get cnt of #divisible nums and try to update the res based on number of divisible nums.







class Solution {
public:
    int maxDivScore(vector<int>& v, vector<int>& divs) {
        int maxScore=-1, res=-1;
        for(int i=0;i<divs.size();i++) {																// Iter. over all divisors.
            int score=0;
            for(int j=0;j<v.size();j++) {																// Iter. over all nums for every divisor to check divisibility.
                if(v[j]%divs[i]==0) score++;															// If curr. num is divi, we inc. the cnt of divi nums.
            }
            if(score>maxScore || (score==maxScore && divs[i]<res)) {									// Trying to update res based on #divisible nums for the current divisor.
                res=divs[i];																			// Updating res and max #divisible nums tracker.
                maxScore=score;
            }
        }
        return res;																						// Returing divisor with largest #divisible nums.
    }
};

