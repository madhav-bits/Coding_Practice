/*
*
//******************************************************334. Increasing Triplet Subsequence.***********************************************

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[5, 4, 3, 2, 1,6,7]
[]
[1,2,2]
[3,4,1,5]
[4,3,1,2,3]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm maintains the two least inc. subsequence of numbers, then compares the curr. scanning number with them, and decide if a triplet
// inc. subsequence can be formed or not. If the curr. vlaue > second min. number then triplet can be formed.


class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        if(v.size()<3) return false;
        int min1=v[0], min2=INT_MAX;
        for(int i=1;i<v.size();i++){
            if(v[i]>min2) return true;							// If the curr. vlaue > second min. then triplet is formed.
            if(v[i]>min1) min2=v[i];							// If the curr. value <second min. and > first min. then second min. is updated.
            else min1=v[i];										// If the curr. value is lesser than first min. then first min. is updated.
        }
        return false;											// If after entire iteration, no triplet subsequence is formed, then return false.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n).	
// This algorithm is similar to longest increasing subsequence. Iterates through the entire array, and checks for inc. numbers after that index
// We check for subsequence of length of 3 , here. Once, we attain that, we return true. If after entire iteration, no triplet subsequence is
// found, then false is returned.
// I didin't look for Time Complexity asked in this question and wrote this code.


class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        if(v.size()<3) return false;
        vector<int> dp(v.size(),1);
        bool stop=false;
        int maxm=v[v.size()-1];
        for(int begin=v.size()-2;begin>=0;begin--){
            if(v[begin]>=maxm){												// If the curr. value> all values following it, no need to scan-
                maxm=max(v[begin],maxm);									//- following elements even.
                continue;
            } 
            for(int end=begin+1;end<v.size();end++){						// Scanning the following elements.
                if(v[end]>v[begin] && dp[begin]-1<dp[end]){					// If the value> curr. value and subseq. len> curr. value's subseq.
                    dp[begin]=dp[end]+1;									// then subseq. length is updated.
                    if(dp[begin]==3) return true;							// Once, lenght of 3 is attained, then return true.
                }
            }
            maxm=max(maxm,v[begin]);										// Updating the max value from the curr. index to the end.
            //cout<<"Maxm. value at: index: "<<begin<<" is: "<<maxm<<endl;
        }
        return false;														// If not found, return false.
    }
};