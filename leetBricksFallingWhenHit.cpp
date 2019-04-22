/*
*
//******************************************************803. Bricks Falling When Hit.***********************************************

We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of 
the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location 
will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input: 
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation: 
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input: 
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: 
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks 
dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
 

Note:

The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






[[1,0,0,0],[1,1,1,0]]
[[1,0]]


[[1,0,0,0],[1,1,0,0]]
[[1,1],[1,0]]


[[1,0,0,0,0,0],[1,1,1,1,0,0],[1,0,0,1,0,0],[1,0,0,0,0,0],[1,0,0,1,1,0]]
[[1,0],[2,2],[1,3]]


[[1,0,0,0,0,0],[1,1,1,1,0,0],[1,0,0,1,0,0],[1,0,0,1,1,0],[1,0,0,0,0,0]]
[[1,0],[2,2],[1,3]]


[[1],[1],[1],[1],[1]]
[[3,0],[4,0],[1,0],[2,0],[0,0]]




[[1,1,1,0,1,1,1,1],[1,0,0,0,0,1,1,1],[1,1,1,0,0,0,1,1],[1,1,0,0,0,0,0,0],[1,0,0,0,0,0,0,0],[1,0,0,0,0,0,0,0]]
[[4,6],[3,0],[2,3],[2,6],[4,1],[5,2],[2,1]]



// Time Complexity: O(m*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(1).	
// This algorithm is Depth First Search based. The main approach is that, we iter. from last deletion to first deletion. After adding every
// index, we perform joining operation using DFS on 4 adj. indices of adding index, and mark them as 2, if they are touching directly/indirectly
// to the top row. So, every iteration, we subtract #nodes attached to top prior -#nodes attached to top after joining curr. index. We do this
// for all deleted indices. We reverse the result gathered and return it.
// After deleting all deleted indices in preprocessing, we start DFS from all top row indces and mark reachable indices with 2.











class Solution {
public:
    
    int markConnected(vector<vector<int>>& v, int row, int col){			// Mark by coloring with 2, if connected to top.
        queue<pair<int,int>>q;
        vector<int>dirs({-1,0,1,0,-1});
        q.push({row, col});
        v[row][col]=2;
        int res=0;
        while(!q.empty()){													// Perform BFS to mark all indices connected to top.
            int row=q.front().first, col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=dirs[i], dy=dirs[i+1];// v[row+dx][col+dy]<=0 || v[row+dx][col+dy]==2
                if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]!=1) continue;
                v[row+dx][col+dy]=2;										// Mark as connected to Top.
                res++;														// Get count of newly connected indices to top.
                q.push({row+dx, col+dy});
            }
        }
        return res;
    }
    
    bool isConnected(vector<vector<int>>& v, int row, int col){				// Says whether curr. index is connected to Top directly/indirectly.
        if(row==0) return true;
        if(row-1>=0 && v[row-1][col]==2) return true;
        if(row+1<v.size() && v[row+1][col]==2) return true;

        if(col-1>=0 && v[row][col-1]==2) return true;
        if(col+1<v[0].size() && v[row][col+1]==2) return true;
        return false;
    }
    
    vector<int> hitBricks(vector<vector<int>>& v, vector<vector<int>>& hits) {
        vector<int>res;
        for(int i=0;i<hits.size();i++){										// Removing all deleted indices.
            int row=hits[i][0], col=hits[i][1];
            v[row][col]--;
        }
        for(int j=0;j<v[0].size();j++){										// Marking indces attached to top after all deletions.
            if(v[0][j]==1) markConnected(v,0,j);
        }
        
        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v[0].size();j++){
        //         cout<<v[i][j]<<" \t";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=hits.size()-1;i>=0;i--){									// Iter. over deletion in reverse order.
            int row=hits[i][0], col=hits[i][1];
            v[row][col]++;
            bool connected=(v[row][col]==1 && isConnected(v,row, col));		// If added index valid and is connected to Top.
            if(connected==false) res.push_back(0);
            else{															
                int group=markConnected(v,row, col);						// Get #newly added indices to top.
                res.push_back(group);										// Add newly added indices to final result vector.
            }
            // cout<<"hit row: "<<row<<" hit col: "<<col<<" and group: "<<res.back()<<endl;
        }
        reverse(res.begin(), res.end());									// Reverse the result vector.
        return res;															// Return the result vector.
    }
};
















//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(m*n).	
// This algorithm is Union-Find based. Here, we iter. over deletion in reverse order. We get #nodes connected to top prior and after connection,
// we put the difference into final result vector. We get #nodes connected to top by connecting top row valid(containing 1) indices to an 
// imaginary index v.size()*v[0].size(), as a result all indices connected to top would be part of single group.

// This link has detailed explanation regarding the below algorithm.
// https://leetcode.com/problems/bricks-falling-when-hit/solution/









class Solution {
public:
    vector<int>parent, rank, vol;
    
    int getParent(int node){												// Get core-parent of the group.
        if(parent[node]!=node)
            parent[node]=getParent(parent[node]);
        return parent[node];
    }
    
    
    int getTop(int index){													// Get #nodes connected to Top.
        int par=getParent(index);
        return vol[par];
    }
    
    
    void unions(int ind1, int ind2){										// Joining two groups.
        int parA=getParent(ind1);
        int parB=getParent(ind2);
        if(parA==parB) return ;
        if(rank[parA]<rank[parB]){
            swap(parA, parB);
        }
        if(rank[parA]==rank[parB]) rank[parA]++;
        parent[parB]=parA;
        vol[parA]+=vol[parB];												// Inc. the size of the new core-parent.
        return ;
    }
    
    vector<int> hitBricks(vector<vector<int>>& v, vector<vector<int>>& hits) {
        vector<int>res;
        int total=v.size()*v[0].size();
        parent=vector<int>(total+1,0);
        rank=vector<int>(total+1,0);
        vol=vector<int>(total+1,0);
        for(int i=0;i<v.size();i++){                                		// Init. Union-Find nodes.
            for(int j=0;j<v[0].size();j++){
                int ind=i*v[0].size()+j;
                parent[ind]=ind;
                if(v[i][j]==1){												// Can be done without this condition also.
                    rank[ind]=0;
                    vol[ind]=1;
                }
            }
        }
        
        for(int i=0;i<hits.size();i++){										// Implementing all deletions.
            int row=hits[i][0], col=hits[i][1];
            v[row][col]--;
        }
        
        for(int i=0;i<v.size();i++){										// Forming groups from all remaining indices on the board.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]!=1) continue;									// Work only on valid indices.
                int ind=i*v[0].size()+j;
                if(i-1>=0 && v[i-1][j]==1) unions(ind,(i-1)*v[0].size()+j);	// [i,j] is added to [i-1,j] and [i,j-1] valid indices.
                if(j-1>=0 && v[i][j-1]==1) unions(ind, i*v[0].size()+j-1);
                if(i==0) unions(ind, total);								// If curr. index belongs to top row, connect to imaginary index.
            }
        }
        
        int prevTop=getTop(total);											// Get #nodes connected to top after all deletions.
        // cout<<"prevTop: "<<prevTop<<endl;
        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v[0].size();j++){
        //         cout<<v[i][j]<<" \t";
        //     }
        //     cout<<endl;
        // }
        vector<int>dirs({-1,0,1,0,-1});
        for(int i=hits.size()-1;i>=0;i--){
            int row=hits[i][0], col=hits[i][1];
            v[row][col]++;
            if(v[row][col]==1){												// If deletion is on valid index.
                for(int i=0;i<4;i++){
                    int dx=dirs[i], dy=dirs[i+1];
                    if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]!=1) continue;
                    unions(row*v[0].size()+col, (row+dx)*v[0].size()+col+dy);// Join curr. index and valid adj. indices.
                }
                if(row==0) unions(col, total);								// If curr. index is in top row, connect to imaginary index.
                int currTop=getTop(total);									// Get #nodes connected to top.
                // cout<<"prevTOp: "<<prevTop<<" and curr: "<<currTop<<endl;
                res.push_back(max(0,currTop-prevTop-1));					// Push #newly connected indices to top.
                prevTop=currTop;											// Update prev. #connected indices to top.
            }else res.push_back(0);
            // cout<<"hit row: "<<row<<" hit col: "<<col<<" and group: "<<res.back()<<endl;
        }
        reverse(res.begin(), res.end());
        return res;															// Return the result vector.
    }
};



