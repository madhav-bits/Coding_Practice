/*
*
//******************************************************643. Maximum Average Subarray I.***********************************************

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to 
output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
1

[]
0

[1,-2,4,2,5,-1,5,2,9]
4




// Time Complexity: O(n).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(k).	
// This algorithm is iteration/Window based. We first calc. sum of first k indices and it's avg. Then we add the next index's value and 
// remove the i-k indexed value. We calc. avg. for this new sum, if it's greater than prev. avg, we update the greatest avg. 





class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        if(v.size()<k) return 0;
        double avg=0, sum=0;
        for(int i=0;i<k;i++) sum+=v[i];											// Calc. sum and avg. of first k indices.
        avg= sum/k;																// Avg. of first k indices.
        for(int i=k;i<v.size();i++){											// Updating the sum after moving the window forward by a index.
            sum=sum-v[i-k]+v[i];	
            avg=max(avg, sum/k);												// Udpating the avg. if new avg is greater than prev. greatest avg.
        }
        //cout<<"The amax vg is: "<<avg<<endl;
        return avg;																// Returning the greatest avg. of the array.
    }
};