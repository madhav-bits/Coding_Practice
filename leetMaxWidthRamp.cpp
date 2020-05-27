/*
*
//******************************************************962. Maximum Width Ramp.*************************************************

https://leetcode.com/problems/maximum-width-ramp/description/


Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
 

Note:

2 <= A.length <= 50000
0 <= A[i] <= 50000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting based. Here, we want pairs with v[i]<=v[j] where i<j. So, we sort the array based on their values, if 
// values are same, then we sort them based on their indices. As, we want non-decreasing pair, we iter. over sorted array we keep track
// of least index encountered. When we are at index 'i', we calc. i-minIndex and try to update the res. As, the values are already sorted
// the indices diff. would give width length.







class Solution {
public:
    int maxWidthRamp(vector<int>& v) {
        vector<pair<int,int>>u;												// Array to store vals and their indices.
        for(int i=0;i<v.size();i++)											// Push vals, index to new array.
            u.push_back({v[i],i});
        sort(u.begin(), u.end(),[](pair<int,int>lt, pair<int,int>rt){		// Sort the array.
            return (lt.first<rt.first) || (lt.first==rt.first && lt.second<=rt.second);
        });
        int res=0, minIndex=u.size();										// Tracks max. width ramp and minIndex of lesser value.
        for(int i=0;i<u.size();i++){										// Iter. over new sorted array.
            res=max(res, u[i].second-minIndex);								// Update the max. width ramp.
            minIndex=min(minIndex, u[i].second);							// Minimize the index encountered value.
        }
        return res;															// Return the max. width ramp.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. We store the indices in stack with vals of indices being dec. order, top being the least value. In the
// second iter. we iter. from end to start, at every step, we move from least to greater value in stack until top val. is <= curr. val.
// At every step, we maximize the result. If the next val. is smaller than prev. val, we had already covered pairs which it would have
// been part of. If it is greater num. we look into stack for more possible non-dec. pairs. In this way we calc. the max. width ramp.







class Solution {
public:
    int maxWidthRamp(vector<int>& v) {
        stack<int>st;														// We store the indices of dec. order vals.
        int res=0;															// Tracks max. width ramp.
        for(int i=0;i<v.size();i++){										// Storing indices with dec. order vals.
            if(st.empty() || v[st.top()]>v[i]) st.push(i);
        }
        for(int i=v.size()-1;i>=0;i--){										// Iter. in reverse drn.
            while(!st.empty() && v[st.top()]<=v[i]){						// Iter. over all lesser val. with smaller indices.
                res=max(res, i-st.top());									// Try to update the max. width ramp val.
                st.pop();
            }
        }
        return res;															// Return the max. width ramp val.
    }
};