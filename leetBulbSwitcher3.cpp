/*
*
//*****************************************************1375. Bulb Switcher III.*****************************************************

https://leetcode.com/problems/bulb-switcher-iii/description/


There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous 
bulbs (to the left) are turned on too.

Return the number of moments in which all turned on bulbs are blue.

 

Example 1:



Input: light = [2,1,3,5,4]
Output: 3
Explanation: All bulbs turned on, are blue at the moment 1, 2 and 4.
Example 2:

Input: light = [3,2,4,1,5]
Output: 2
Explanation: All bulbs turned on, are blue at the moment 3, and 4 (index-0).
Example 3:

Input: light = [4,1,2,3]
Output: 1
Explanation: All bulbs turned on, are blue at the moment 3 (index-0).
Bulb 4th changes to blue at the moment 3.
Example 4:

Input: light = [2,1,4,3,6,5]
Output: 3
Example 5:

Input: light = [1,2,3,4,5,6]
Output: 6
 

Constraints:

n == light.length
1 <= n <= 5 * 10^4
light is a permutation of  [1, 2, ..., n]





*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



[2,1,3,5,4]

[3,2,4,1,5]


[4,1,2,3]


[2,1,4,3,6,5]


[1,2,3,4,5,6]



// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we keep track of the maxm. bulb psn that is turned on, if the maxm. bulb psn+1= #bulbs
// turned on till then, then all the bulbs starting zero in a seq. are turned on, we cnt #instances these desired scenarios have
// arised and return the cnt.








class Solution {
public:
    int numTimesAllBlue(vector<int>& v) {
//         vector<int>left(v.size(), -1), right(v.size(), -1);				// Stores leftmost bulb turned on in sequence with index 'i'.
//         int res=0;
//         for(int j=0;j<v.size();j++){
//             int i=v[j]-1;
//             left[i]=i;right[i]=i;
//             if(i-1>=0 && left[i-1]!=-1) left[i]=left[i-1];
//             if(i+1<v.size() && right[i+1]!=-1) right[i]=right[i+1];
            
//             right[left[i]]=right[i];
//             left[right[i]]=left[i];
//             // cout<<"i: "<<i<<" and right: "<<right[0]<<endl;
//             if(right[0]+1==j+1) res++;									// If rightmost index of '0'+1 equals all lights turned on, then add to final result.
//         }
//         return res;
        
        int res=0, maxm=0;													// Maxm. bulb psn that is turned on.
        for(int i=0;i<v.size();i++){
            maxm=max(maxm, v[i]);											// Trying to update the maxm. bulb psn.
            if(maxm==i+1) res++;											// If maxm bulb psn+1=all bulbs turned on till now, we inc. the cnt of instances.
        }
        return res;															// Return the total #instances where all bulbs in seq. from 0 are turned on.
    }
};
