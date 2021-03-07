/*
*
//******************************************************992. Subarrays with K Different Integers.***********************************************

https://leetcode.com/problems/subarrays-with-k-different-integers/


Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that 
subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,1,2,3]
2
[1,1,2,2,1,3,4]
1



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. Here, since we are find #substrings which have exact K uniq chars, this can be restructured as diff. b/w
// num. of substrings with at max k uniq. chars and #substrings with k-1 uniq. chars. We use sliding window to calc. #substr with 'x' uniq. chars.



// This link has great explanation for the below approach.
// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window







class Solution {
public:
    
    int getSubArrCount(vector<int>&v, int k){
        vector<int>occur(v.size()+1,0);										// Tracks count of each char in the substrings.
        int uniq=0, start=0, res=0;
        for(int i=0;i<v.size();i++){
            if(occur[v[i]]++==0) uniq++;									// If it's a new char into window, inc. the uniq. chars count.
            while(uniq>k){													// Remove chars until #uniq. chars<=k
                if(--occur[v[start++]]==0) uniq--;
            }
            if(uniq<=k) res+=(i-start+1);									// If #uniq. chars<=k, curr. char forms substr starting all indices in window.
        }
        return res;															// Returning #substr with uniq. chars<=k.
    }
    
    int subarraysWithKDistinct(vector<int>& v, int k) {
        return getSubArrCount(v, k)-getSubArrCount(v, k-1);					// Returning #substr with K uniq. chars.
    }
};