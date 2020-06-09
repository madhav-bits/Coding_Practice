/*
*
//*********************************************************1402. Reducing Dishes.***************************************************

https://leetcode.com/problems/reducing-dishes/description/


A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its 
satisfaction level  i.e.  time[i]*satisfaction[i]

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). 
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.
Example 4:

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-10^3 <= satisfaction[i] <= 10^3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[-1,-8,0,5,-7]

[4,3,2]

[-1,-4,-5]

[-2,5,-1,0,3,-3]




// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is Sorting based. To get maxm. weighted sum, we have to maxm. weights to greater values. So, we sort the array, we 
// iter. from greatest to lowest. values. In the process we re-add the prev. total, thus increasing the weightage of the prev. nums. 
// We add the curr. num to total. We add curr. num to prev. num. If the prev. total is neg., then in the next iter., the total value 
// would dec. and the next adding num. would also be neg., thus dec. total value. We track maxm. total using the res var and return it.








class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end());											// Sort the given array.
        int res=0, total=0, val=0;											// Tracks maxm. total, curr. total, weighted total.
        for(int i=v.size()-1;i>=0;i--){										// Iter. from greatest to lowest.
            val+=total;														// Adding prev. sum till now.
            val+=v[i];														// Adding curr.val.
            res=max(res, val);												// Updating maxm. weighted total.
            total+=v[i];													// Adding curr. num to prev. total.
            if(total<0) break;												// If total is neg. then here on the weighted total would dec.
        }
        return res;															// Returning the maxm. weighted total.
    }
};
