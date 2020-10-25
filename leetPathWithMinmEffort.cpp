/*
*
//******************************************************1631. Path With Minimum Effort.*************************************************

https://leetcode.com/problems/path-with-minimum-effort/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked with test cases provided with the question.

[[1,2,2],[3,8,2],[5,3,5]]
[[1,2,3],[3,8,4],[5,3,5]]
[[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]



// Time Complexity: O(n*m*log(m*n).  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m*log(m*n).  
// Space Complexity: O(m*n).
// This algorithm is Priority Queue based. This is Dijkstra's algorithm. Here, we use DP array to store minm. effort to reach that
// index. If we encounter a path, whose effort is < minm. effort observed till now. We include to reach curr. index and add it to PQ.
// This way we reach the bottom right index, the first time we extract that index from PQ, it means their is no path of smaller effort
// than curr. extracted one and we return it.







class Solution {
public:
    
    int minimumEffortPath(vector<vector<int>>& v) {
        auto comp=[](vector<int>&lt, vector<int>&rt){						// Lambda custom sorting for Priority Queue.
          return lt[2]>=rt[2];  
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>pq(comp);
        pq.push({ 0, 0, 0});
        vector<int>dirs({-1,0,1,0,-1});
        vector<vector<int>>visited(v.size(), vector<int>(v[0].size(), INT_MAX));
        while(!pq.empty()){
            vector<int>temp=pq.top();
            if(temp[0]==v.size()-1 && temp[1]==v[0].size()-1) return temp[2];	// If bottom right index is of minm. effort return it.
            pq.pop();
            // if(visited[temp[0]][temp[1]]) continue;
            // cout<<"x: "<<temp[0]<<" and y: "<<temp[1]<<" and effort: "<<temp[2]<<endl;
            // visited[temp[0]][temp[1]]=true;
            for(int i=0;i<4;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(temp[0]+dx<0 || temp[0]+dx>=v.size() || temp[1]+dy<0 || temp[1]+dy>=v[0].size()) continue;
                // visited[temp[0]+dx][temp[1]+dy]=true;
                int newDiff=max(temp[2], abs(v[temp[0]+dx][temp[1]+dy]-v[temp[0]][temp[1]]));
                if(newDiff>=visited[temp[0]+dx][temp[1]+dy]) continue;		// If new path is costlier than old observed path ignore it.
                pq.push({temp[0]+dx, temp[1]+dy, newDiff});
                visited[temp[0]+dx][temp[1]+dy]=newDiff;
            }
        }
        return -1;
    }
};
