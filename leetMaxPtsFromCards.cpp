/*
*
//********************************************1423. Maximum Points You Can Obtain from Cards.*****************************************

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/


There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array 
cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total 
score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
Example 4:

Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 
Example 5:

Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202
 

Constraints:

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,2,3,4,5,6,1]
3


[2,2,2]
2

[1,79,80,1,1,1,200,1]
3

[1,1000,1]
1


[9,7,7,9,7,7,9]
7



// Time Complexity: O(n).  													// n- length of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is Observation+ Sliding Window based. Here, as we can take cards from both the ends. We might be taking k cards from
// the back or front or mix of front and back. Instead of focusing of picked cards from both the ends, we think of subarray that would
// be remaining at the end of process. This subarray would either be starting at '0' or finishing at last index or somewhere in middle
// with size of len-k, so we form a window of this size, calc. it's total, slide it and try to minimize it's total over the possible 
// indices it can be([0, len-k-1] to [k,len-1]). At the end of iter. since we want maxm. total obtained from cards, we calc. total-minm
// and return it.







class Solution {
public:
    
    int getMax(vector<int>&v, unordered_map<string,int>&m, int start, int end, int k){// DFS+Memoization function call.
        if(k==0) return 0;
        string rep=to_string(start)+"#"+to_string(end);
        if(m.count(rep)==1) return m[rep];
        int maxm=INT_MIN;
        int val1=v[start]+getMax(v,m, start+1, end, k-1);
        int val2=v[end]+getMax(v, m, start, end-1, k-1);
        maxm=max(val1, val2);
        m[rep]=maxm;
        return maxm;
    }
    
    int maxScore(vector<int>& v, int k) {
        // unordered_map<string,int>m;										// This approach is DFS with Memoization, this gives TLE.
        // return getMax(v,m,0,v.size()-1, k);
        
        int minm=INT_MAX, start=0, total=0, sum=0;							// Tracks minm. total of subarray, start index of window.
        for(int i=0;i<v.size();i++){										// Iter. over given array.
            sum+=v[i];														// Calc. sum of the array's elems.
            total+=v[i];													// Calc. window's total.
            if(i>=v.size()-k) total-=v[start++];							// Removing out of window's index's contribution.
            if(i>=(int)v.size()-k-1 && total<minm) minm=total;				// Trying to update the minm. total possible.
        }
        // cout<<"minm: "<<minm<<endl;
        return sum-minm;													// Returning total-minm-> maxm. total obtained from cards.
    }
};
