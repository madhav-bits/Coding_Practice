/*
*
//**********************************************************695. Max Area of Island.***************************************************

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or 
vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]


[[1,1,1,1,1],[1,0,0,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1]]


[]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DFS based. We start from indices which were not visited, from there it's adjacent nodes which are land and not visited and
// add count which we get from them. After all DFS calls, we return the curr. islan's area. We maintain maxm var to store maxm. area of islands
// visited till now. After all indices are iterated, we return maxm. area of island.(Deafult value of maxm var=0(no island exists)).








class Solution {
public:
    
    int findArea(vector<vector<int>>&v, int row, int clmn){
        int count=1;																	// Taking into count, curr. index's land.
        v[row][clmn]=-1;																// Marking it so, that it's not visited once again.
        if(row-1>=0 && v[row-1][clmn]==1) count+=findArea(v,row-1, clmn);				// Visiting adj. unvisited lands.
        if(clmn-1>=0 && v[row][clmn-1]==1) count+=findArea(v,row, clmn-1);
        
        if(row+1<v.size() && v[row+1][clmn]==1) count+=findArea(v,row+1, clmn);
        if(clmn+1<v[0].size() && v[row][clmn+1]==1) count+=findArea(v,row, clmn+1);
        return count;																	// Return unvisited land adj. to this index+self(1).
    }
    
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int maxm=0;
        for(int i=0;i<v.size();i++){													// Iterating through all indices.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1) maxm=max(maxm,findArea(v,i,j));							// Maintians maxm. area of islands.
            }
        }
        // for(auto nums:v){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        // cout<<"The result is: "<<maxm<<endl;
        return maxm;																	// Return the maxm. area of island.
    }
};


