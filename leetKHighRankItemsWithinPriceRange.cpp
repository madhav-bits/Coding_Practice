/*
*
//********************************************2146. K Highest Ranked Items Within a Price Range.*******************************************

https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,0,1],[1,3,0,1],[0,2,5,1]]
[2,5]
[0,0]
3
[[1,2,0,1],[1,3,3,1],[0,2,5,1]]
[2,3]
[2,3]
2
[[1,1,1],[0,0,1],[2,3,4]]
[2,3]
[0,0]
3



// Time Complexity: O(m*n+m*n+k*log m*n+k).								// k-#number of items that should be returned.
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n+m*n+k*log m*n+k).								// k-#number of items that should be returned.
// Space Complexity: O(m*n).	
// This algorithm is BFS+ Priority Queue based. Here, we use BFS to visit indices which are reachable and with a smallest possible dist. On visiting  we 
// multiply the indices in grid array with -1 to mark that index as visited,as the range of vals are positive, so negative value means visited. When we pop
// this index from queue, if this index's value satisfies the price range condition, we push {minDist, price, row, col} list of values to PQ, which is 
// customized to sort the values based on preferences specified. We pop first K values from the PQ and add those indices to res and return them.








class Solution {
public:
    
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>>res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        queue<pair<int,int>>q;
        q.push({start[0], start[1]});
        grid[start[0]][start[1]]*=-1;
        int dist=-1, low=pricing[0], high=pricing[1];
        vector<int>dirs({-1,0,1,0,-1});
        while(!q.empty()) {
            dist++;
            int len=q.size();
            for(int i=0;i<len;i++) {
                int row=q.front().first, col=q.front().second;
                int val=-grid[row][col];
                // cout<<"current row: "<<row<<" and col: "<<col<<endl;
                q.pop();
                if(low<=val && val<=high) pq.push({dist, val, row, col});	// Pushing all the required specs for the indices which met conditions.
                for(int j=0;j<4;j++) {
                    int dx=dirs[j], dy=dirs[j+1];
                    // cout<<"adj row: "<<row+dx<<" and adj col: "<<col+dy<<endl;
                    if(row+dx<0 || row+dx>=grid.size() || col+dy<0 || col+dy>=grid[0].size() || grid[row+dx][col+dy]<=0) continue;
                    // cout<<"adding adj row: "<<row+dx<<" and adj col: "<<col+dy<<endl;
                    q.push({row+dx, col+dy});
                    grid[row+dx][col+dy]*=-1;								// Converting to neg. values to prevent revisiting in BFS.
                }
            }
        }
        while(k && !pq.empty()) {											// Take the first 'k' values and populate res with them.
            k--;
            res.push_back({pq.top()[2], pq.top()[3]});
            pq.pop();
        }
        return res;															// Return the first K high ranked items.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m+m*n*log m*n+k).
// Space Complexity: O(n*m).	
// This algorithm is BFS+Sorting baesd. This is same as the above solution except that it uses sorting to sort the values based on the preferences specified.
// We populate array here rather than PQ to arrange the values, later we take the first K values and push their indices to res and return it.










class Solution {
public:
    
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>>res;
        queue<pair<int,int>>q;
        vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));// Stores the smallest dist. of an index from source index.
        int steps=0, low=pricing[0], high=pricing[1];
        vector<int>dirs({-1,0,1,0,-1});
        vector<pair<int,int>>indices;
        
        q.push({start[0], start[1]});
        dist[start[0]][start[1]]=0;
        
        while(!q.empty()) {
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++) {
                int row=q.front().first, col=q.front().second;
                int val=grid[row][col];
                // cout<<"current row: "<<row<<" and col: "<<col<<endl;
                q.pop();
                if(low<=val && val<=high) indices.push_back({row, col});	// Pushing the indices which met the conditions into Array.
                for(int j=0;j<4;j++) {
                    int dx=dirs[j], dy=dirs[j+1];
                    // cout<<"adj row: "<<row+dx<<" and adj col: "<<col+dy<<endl;
                    if(row+dx<0 || row+dx>=grid.size() || col+dy<0 || col+dy>=grid[0].size() || 
                       grid[row+dx][col+dy]==0 || 
                       dist[row+dx][col+dy]!=INT_MAX) continue;
                    // cout<<"adding adj row: "<<row+dx<<" and adj col: "<<col+dy<<endl;
                    dist[row+dx][col+dy]=steps;
                    q.push({row+dx, col+dy});
                }
            }
        }
        sort(indices.begin(), indices.end(), [&dist, &grid](pair<int,int>&lt, pair<int,int>&rt) {// Sort based on the preferences specified.
            if(dist[lt.first][lt.second]!=dist[rt.first][rt.second]) return dist[lt.first][lt.second]<dist[rt.first][rt.second];
            if(grid[lt.first][lt.second]!=grid[rt.first][rt.second]) return grid[lt.first][lt.second]<grid[rt.first][rt.second];
            if(lt.first!=rt.first) return lt.first<rt.first;
            return lt.second<rt.second;
        });
        if(indices.size()<k) k=indices.size();
        int i=0;
        while(i<k) {														// Take the first 'k' values and populate res with them.
            res.push_back({indices[i].first, indices[i].second});
            i++;
        }
        return res;															// Return the first K high ranked items.
    }
};

