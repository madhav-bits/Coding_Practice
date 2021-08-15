/*
*
//******************************************************1499. Max Value of Equation.***********************************************

https://leetcode.com/problems/max-value-of-equation/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,3],[2,0],[5,10],[6,-10]]
1
[[0,0],[3,0],[9,2]]
3
[[-19,9],[-15,-19],[-5,-8]]
10
[[-15,-1],[-14,-5],[-11,1],[-9,7],[-8,18],[-7,-5],[-3,3],[4,14],[12,-4],[13,15],[14,-19],[19,-1]]
8



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													
// Space Complexity: O(n).	
// This algorithm is Deque based. If we observe the equation. yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length. As xj>xi
// based on the question, this equation translates to yi + yj - xi + xj where i<j. So, we need a index with max. xi + xj in the window where 
// xi-xj<=k. As xi>xj when i>j we can use deque to track the indices with max. -xj+yj values to maximize the equation. While pushing the curr. total
// into Deque we remove all indices whose total<=curr. Total as curr. index would be part of all windows that these deleted indices are part of from
// now. As, we are removing indices with lower values, the index with greater total in this window would be at the front of the queue. So, we have
// to add yi-xi with queue front and try to maximize the res value.








class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res=INT_MIN;													// Tracks max. value of equation.
        deque<pair<int,int>>q;												// Stores all indices and values in the curr. window of consideration.
        q.push_back({points[0][1]-points[0][0], points[0][0]});				// Push the first coordinate.
        for(int i=1;i<points.size();i++){
            while(!q.empty() && points[i][0]-q.front().second>k) q.pop_front(); // Removing all indices whose x co-ordinate is out of curr. window.
            int currTotal=points[i][1]+points[i][0];
            if(!q.empty() && currTotal+q.front().first>res)					// Calc. equation value with curr. index.
                res=currTotal+q.front().first;
            
            while(!q.empty() && points[i][1]-points[i][0]>=q.back().first) q.pop_back();// Removing indices with lower -xi+yi value
            q.push_back({points[i][1]-points[i][0], points[i][0]});			// Pushing curr. index and it's contribution(-xi+yi)
        }
        return res;															// Returning the max. value of equation.
    }
};
