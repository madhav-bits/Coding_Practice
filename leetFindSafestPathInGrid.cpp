/*
*
//******************************************************2812. Find the Safest Path in a Grid.******************************************************

https://leetcode.com/problems/find-the-safest-path-in-a-grid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,0,0],[0,0,0],[0,0,1]]
[[0,0,1],[0,0,0],[0,0,0]]
[[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
[[0,0,0,1],[0,1,0,0],[0,0,0,0],[1,0,0,0]]
[[0,0,0,0,0],[0,0,0,0,1],[1,0,0,0,0],[1,0,0,0,0],[0,1,0,0,0]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is BFS+ Priority Queue/Dijkstra based. We first collect all the indices of thiefs, we do BFS to mark all indices with min. dist from thieves. We now start 
// BFS where we pick next index which has greatest min. dist from thieves so that our path would have max. possible min. dist. from thieves. As we pick greatest dist. index
// at every step we ensure that min. dist. we get would be max. possible. We abandon/not yet explore some paths which have indices very closer to thieves/min. dist.. We track
// min. dist of all the visited indices and return it when we reach the bottom right index for the first time BECAUSE 
//********************************************************************IMPORTANT REASONING.****************************************************************
// The fact that we visited this min. val index means there is no other way/path with all indices with dist. > tracked min. dist, if such path exists that would have been 
// visited in total until target index before visiting the min. dist index. So, we can safely return the min. dist tracked over this process.







class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++) {									// Collecting indices of all thieves.
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        
        vector<int>dirs({-1,0,1,0,-1});
        while(!q.empty()) {													// Marking all indices with min. dist from thieves.
            int x=q.front().first, y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || x+dx>=grid.size() || y+dy<0 || y+dy>=grid[0].size() || (grid[x+dx][y+dy]!=0 && grid[x+dx][y+dy]<=grid[x][y]+1)) continue;
                grid[x+dx][y+dy]=grid[x][y]+1;
                q.push({x+dx, y+dy});
            }
        }
        
        int res=INT_MAX, len=grid.size(), target=(grid.size()*grid[0].size())-1;
        if(grid[0][0]==1 || grid[len-1][len-1]==1) return 0;
        
        priority_queue<pair<int,int>>pq;
        pq.push({grid[0][0],0});											
        grid[0][0]=-1;
        
        while(!pq.empty()) {												// BFS/Dijkstra to reach target index with max possible min. dist in path.
            int val=pq.top().first, rep=pq.top().second;
            int row=rep/len, col=rep%len;
            // cout<<"row: "<<row<<" and col: "<<col<<" and val: "<<val<<endl;
            pq.pop();
            if(val<res) res=val;											// Tracking the min. dist. of visited inidces.
            if(val==1) return 0;
            if(rep==target) return res-1;									// Target index reached, so we return min. dist.
            for(int i=0;i<4;i++) {
                int dx=dirs[i], dy=dirs[i+1];
                if(row+dx<0 || row+dx>=grid.size() || col+dy<0 || col+dy>=grid[0].size() || grid[row+dx][col+dy]==-1) continue;
                pq.push({grid[row+dx][col+dy], (row+dx)*len+(col+dy)});		// Add unvisited index to PQ.
                grid[row+dx][col+dy]=-1;									// Mark index as visited to avoid duplicate entries.
            }
        }
        return -1;															// If we are not able to reach target index, we return -1.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m*(m+n)).
// Space Complexity: O(n*m).
// Here, in the Dijkstra step, we use another array ans to track the min. dist in a path by time we reach index [i,j], if we revisit the with greater min. dist, then we update
// the ans[i,j] with greater min. dist and add this index to PQ as we might reach target index with greater min. dist via the second entry into PQ.



// This solution is from the Discussion forum.
// Another solution is to do Binary Search in the range [0,m+n] min. dist in the path and do DFS for this min. dist. Here, in each step, we do DFS and only consider indices 
// with min. dist to thieves>=binary_search mid dist. Thus, we reduce above time complexity to: O(m*n*log*(m+n)).









class Solution {
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        queue<int> q;
        const int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.push((i << 10) | j);
                    d[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            const int x = q.front() >> 10, y = q.front() & 1023;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                const int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && d[xx][yy] < 0) {
                    d[xx][yy] = d[x][y] + 1;
                    q.push((xx << 10) | yy);
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, -1));
        vector<vector<bool>> mark(n, vector<bool>(n));
        priority_queue<pair<int, int>> pq;
        pq.push({d[0][0], 0});
        ans[0][0] = d[0][0];
        while (!pq.empty()) {
            const int x = pq.top().second >> 10, y = pq.top().second & 1023, p = pq.top().first;
            pq.pop();
            if (mark[x][y]) {
                continue;
            }
            if (x == n - 1 && y == n - 1) {									// Return the min. dist in the path as target index is reached.
                return p;
            }
            mark[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                const int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
                    const int pp = min(p, d[xx][yy]);						// Track the min. dist. in the path.
                    if (ans[xx][yy] < pp) {									// We revisit the index if we have greater min. dist till this point in the path.
                        ans[xx][yy] = pp;									// We revisit cause this might enable us to reach target index with greater min. dist.
                        pq.push({pp, (xx << 10) | yy});						// Push {min. dist in path, index} into PQ.
                    }
                }
            }
        }
        return -1;
    }
};

