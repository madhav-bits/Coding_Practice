/*
*
//**************************************************************683. K Empty Slots.********************************************************

There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be 
exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 
1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers 
between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[6,10,7,1,9,8,4,3,5,2]
3



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observaiton based. Here, we work on sets of "K" length each time. In that window, we check if any index has smaller day 
// than both both edges to bloom. This, breaks the condition required. Since, the curr./index with val breaking the cdn in that window has 
// value/day which is smaller than all prev. values in that window. So, starting a new window at those prev. indices would be of no use, as this 
// index with dist. <K and value<all those values. So, we start the new window at this index, and continue the search for window. Since, 
// an index is touhced/iterated only once. We can call it O(n).


// I guess, we need not maintain a var res to track min. day satisfying the above cdn, as the first days that satisfies the above cdn would 
// be the min. possible answer. But, this might be useful in tracking max. day satisfying cdn(I guess, Even then we can just return the last index
// satisfying the cdn in the iteration).





class Solution {
public:
    int kEmptySlots(vector<int>& v, int k) {
        vector<int>days(v.size(),0);										// Stores the days in which flowers at diff. psns blossom.
        for(int i=0;i<v.size();i++)											// Transforming given array into array wrt flower psn and blos.day.
            days[v[i]-1]=i+1;
        int left=0, right=k+1,res=INT_MAX;									// Tracks start, end of window, min. day satisfying the cdn.
        while(right<days.size()){											// Iterating till window fits in array.
            bool cont=false;												// Track whether an index breaking cdn found in curr. window or not?
            for(int i=left+1;i<right;i++){									// Iterating through the curr. window.
                if(days[i]<days[left] || days[i]<days[right]){				// If cdn breaked.
                    cont=true;												// Marking that index with value breaking the cdn found.
                    left=i;													// Updating the start of next window to be scanned.
                    right=i+k+1;											// Updating the end of next window to be scanned.
                    break;	
                }
            }
            if(cont==true) continue;										// If breaking index found, continue.
            res=min(res,max(days[left],days[right]));						// If window has no issues, then track min of max. day of the edges.
            left=right;														// Setting the start of next window to be scanned.
            right=right+k+1;												// Setting the end of next window to be scanned.
        }
        return (res==INT_MAX)?-1:res;										// If window not found, return -1 else return index.
    }
};