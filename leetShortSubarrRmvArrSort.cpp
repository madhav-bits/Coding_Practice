/*
*
//**************************************1574. Shortest Subarray to be Removed to Make Array Sorted.**************************************

https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,2,3,10,4,2,3,5]
[5,4,3,2,1]
[1,2,3]
[1]
[2,2,2,1,1,1]




// Time Complexity: O(n).	  												// n- length of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, after removing the subarr, the remaining has to be sorted, which is combi. of
// two sorted arr starting from '0' and ending at 'v.size()-1' or only one of them might remain. So, we iter. till last index of 
// this sorted arrays. Take iter. from 0 and rt and try to maximize the remaining sorted arrays from both ends/minimize deleting arr.

// One critical observation is that whenever we try to maximize the joined sorted subarrays length, we need to compare them from 
// the start indices and try to maximize the subarr. length at all possible positions.


// This dicussion link contains the most detailed explanation of this approach.
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830480/C%2B%2B-O(N)-Sliding-window-Explanation-with-Illustrations





class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& v) {
        int lt=0, rt=v.size()-1;
        while(lt+1<v.size() && v[lt]<=v[lt+1]) lt++;						// Left sorted subarr.
        while(rt-1>=0 && v[rt-1]<=v[rt]) rt--;								// Right sorted subarr.
        if(lt==v.size()-1) return 0;
        // cout<<"lt: "<<lt<<" and rt: "<<rt<<endl;
        int i=0, j=rt, delWindow=min(rt, (int)v.size()-lt-1);
        while(i<=lt && j<v.size()){											// Mini. delwindow->maximizing the remaining sorted subarr.
            // cout<<"i: "<<i<<" and j: "<<j<<endl;
            if(v[i]<=v[j]){													// Keeping intact the sorted nature of remain subarr.
                delWindow=min(delWindow, j-i-1);
                i++;
            }else j++;														// Not sorted so inc. the lower value.
        }
        return delWindow;													// Return the minm. delWindow size.
    }
};
