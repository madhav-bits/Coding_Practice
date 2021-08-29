/*
*
//****************************************1368. Minimum Cost to Make at Least One Valid Path in a Grid.**************************************

https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
[[1,1,3],[3,2,2],[1,1,4]]
[[1,2],[4,3]]
[[2,2,2],[2,2,2]]
[[4]]



// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m(log(m*n))).
// Space Complexity: O(n*m).	
// This algorithm is BFS+ Priority Queue based. Here, we use BFS to get the shortest cost path to bottom right. We use PQ to get the min. cost 
// index. The first instance we touch the bottom right index, that's the minm. cost as all the indices in the PQ will be of atleast curr. cost.
// We use few optimizations like marking the PQ pop index with 0 to indicate that this has been already processed and need not reprocess it once 
// again.











class Solution {
public:
    
    struct comp{
        bool operator()(vector<int>&lt, vector<int>&rt){
            return lt[0]>rt[0];
        }    
    };
    
    vector<int>dirsX, dirsY;
    int minCost(vector<vector<int>>& grid) {
        dirsX=vector<int>({0,0,1,-1});
        dirsY=vector<int>({1,-1,0,0});
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        // deque<vector<int>>pq;
        // pq.push_front(vector<int>({0,0,0}));
        while(!pq.empty()){
            int currCost=pq.top()[0], x=pq.top()[1], y=pq.top()[2];
            pq.pop();
            // int currCost=pq.front()[0], x=pq.front()[1], y=pq.front()[2];
            // pq.pop_front();
            if(grid[x][y]==0) continue;
            if(x==grid.size()-1 && y==grid[0].size()-1) return currCost;
            for(int i=0;i<4;i++){
                int dx=dirsX[i], dy=dirsY[i];
                if(x+dx<0 || x+dx>=grid.size() || y+dy<0 || y+dy>=grid[0].size() || grid[x+dx][y+dy]==0) continue; 
                
                if(i+1==abs(grid[x][y])) pq.push_front({currCost, x+dx, y+dy});
                else pq.push_back({currCost+1, x+dx, y+dy});
            }
            grid[x][y]=0;
        }
        return -1;
    }
};













//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This approach is based on BFS+Deque. As the cost would increase by only 1 or zero at every index. If the increase is by 1, we add the new index
// at the end of the deque or if the cost is same, we would add it at the front of the deque as it's got the minm. cost of all the indices in 
// queue. In this way the first instance of touching bottom right would be the minm. cost path.











class Solution {
public:
    
    vector<int>dirsX, dirsY;
    int minCost(vector<vector<int>>& grid) {
        dirsX=vector<int>({0,0,1,-1});
        dirsY=vector<int>({1,-1,0,0});
        deque<vector<int>>pq;
        pq.push_front(vector<int>({0,0,0}));
        while(!pq.empty()){
            int currCost=pq.front()[0], x=pq.front()[1], y=pq.front()[2];
            pq.pop_front();
            if(grid[x][y]==0) continue;
            if(x==grid.size()-1 && y==grid[0].size()-1) return currCost;
            for(int i=0;i<4;i++){
                int dx=dirsX[i], dy=dirsY[i];
                if(x+dx<0 || x+dx>=grid.size() || y+dy<0 || y+dy>=grid[0].size() || grid[x+dx][y+dy]==0) continue; 
                
                if(i+1==abs(grid[x][y])) pq.push_front({currCost, x+dx, y+dy});
                else pq.push_back({currCost+1, x+dx, y+dy});
            }
            grid[x][y]=0;
        }
        return -1;
    }
};

