/*
*
//*********************************2672. Number of Adjacent Elements With the Same Color.************************************

https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
[[0,2],[1,2],[3,1],[1,1],[2,1]]
1
[[0,100000]]
10
[[0,4],[2,3],[3,4],[1,4],[2,4],[6,4]]



// Time Complexity: O(m+n).													// m-#queries, n-length of the array with nums.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).													// m-#queries, n-length of the array with nums.
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step finds the greater following value, also makes sure that duplicates are avoided. Thus includes
// a greater following value and calls the func. to find further greater following values. Thus ,we get increasing subsequences(include only
// whose length is >= 2).







class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>res(queries.size(),0), u(n,0);
        int cnt=0;
        for(int i=0;i<queries.size();i++) {
            if(u[queries[i][0]]==queries[i][1]) {							// If curr. value at index is same as the new value, we use the same cnt value.
                res[i]=cnt;
                continue;
            }
            int ind=queries[i][0];
            if(ind>0 && u[ind]!=0 && u[ind]==u[ind-1]) cnt--;				// If prev. adj. values are !=0 and same as u[i], we dec. the cnt.
            if(ind+1<n && u[ind]!=0 && u[ind]==u[ind+1]) cnt--;
            
            u[queries[i][0]]=queries[i][1];
            if(ind>0 && u[ind]!=0 && u[ind]==u[ind-1]) cnt++;				// If new adj. values are !=0 and same as u[i], we inc. the cnt.
            if(ind+1<n && u[ind]!=0 && u[ind]==u[ind+1]) cnt++;
            res[i]=cnt;														// We update res array with new cnt value.
        }
        return res;															// Returning res array with #same adj. values counts.
    }
};

