/*
*
//**********************************************************827. Making A Large Island.***************************************************

In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
 

Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,0],[1,0,0],[0,0,1]]
[[0,0],[0,0]]
[[0,0],[0,1]]
[[1,1],[1,1]]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DFS based. First we iterate through the entire 2D array and mark/number the islands and get count of ones(size) of the island 
// and store the island mark/number and count in map. In the second iteration we scan for indices with "0" and scan it's adjacent indices, if they
// are part of an island, we get count from map and add the islands size +1(curr index with "0) and update the max. size of new island. The case of 
// all ones in the entire 2D array is covered by updating the maxm. size of the new island var in the first iteration with island size->count.



class Solution {
public:
    
    int markPixel(vector<vector<int>> &grid, int mark, int row, int clmn){			// Calc. the island size and mark them.
        int count=0;
        grid[row][clmn]=mark;														// Marking the curr. index/island.
        if(row+1<grid.size() && grid[row+1][clmn]==1) count+=markPixel(grid, mark, row+1, clmn);	// Extr. the size of island from adj. indices.
        if(clmn+1<grid[0].size() && grid[row][clmn+1]==1) count+=markPixel(grid, mark, row, clmn+1);
        if(row-1>=0  && grid[row-1][clmn]==1) count+=markPixel(grid, mark, row-1, clmn);
        if(clmn-1>=0  && grid[row][clmn-1]==1) count+=markPixel(grid, mark, row, clmn-1);
        
        return count+1;																// Returning the island size.
    }
    
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int res;
        int maxm=INT_MIN;
        unordered_map<int, int> m;													// Saves and maps the marked island with it's size.
        //m[0]=0;
        int mark=2, count=0;														// Island's mark and size of island.
        for(int i=0;i<grid.size();i++){                                             //Marking the islands.
            for(int j=0;j<grid[0].size();j++){
                //cout<<"The curr. index is i: "<<i<<" and j: "<<j<<" value is: "<<grid[i][j]<<endl;
                if(grid[i][j]==1){													// If the curr. index is not marked.
                    count=markPixel(grid,mark,i,j);									// Extracting the marked island size.
                    //cout<<"The count of mark: "<<mark<<" is: "<<count<<endl;
                    maxm=max(maxm,count);											// Updating the new island size var.
                    m[mark]=count;													// Mapping the mark and island size.
                    mark++;															// Inc. the mark value.
                }
            }
        }
        
        
        
        
        set<int>s;
        vector<int> rec;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //cout<<"The curr. index is i: "<<i<<" and j: "<<j<<" value is: "<<grid[i][j]<<endl;
                if(grid[i][j]!=0) continue;
                rec.clear();
                s.clear();
                if(i-1>=0 && grid[i-1][j]!=0) s.insert(grid[i-1][j]);				// Pushing the island mark of adj. index.
                if(j-1>=0 && grid[i][j-1]!=0) s.insert(grid[i][j-1]);
                if(i+1<grid.size() && grid[i+1][j]!=0) s.insert(grid[i+1][j]);
                if(j+1<grid[0].size() && grid[i][j+1]!=0) s.insert(grid[i][j+1]);
                int total=0;                                            			// Calc. the final expanded island's size.
                for(auto it=s.begin();it!=s.end();it++) total+=m[*it];
                maxm=max(maxm,total+1);												// Updating the largest new island size var.
                
            }
        }
        //cout<<"The result is: "<<maxm<<endl;
        return maxm;																// Returning the largest new island size.
    }
};