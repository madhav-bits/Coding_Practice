/*
*
//******************************************************675. Cut Off Trees for Golf Event.***********************************************

You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
 

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And 
after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off 
all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
 

Example 2:

Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
 

Example 3:

Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
 

Hint: size of the given matrix will not exceed 50x50.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[0,0,4],[6,7,5]]


[[1,2,3],[0,0,4],[7,6,5]]



// Time Complexity: O(m^2*n^2).  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m^2*n^2).												// Calc. dist b/w two indices may take O(m*n) time.
// Space Complexity: O(m*n).	
// This algorithm is Priority Queue+BFS based. Here, sicne we need to add distance between all pair of points which are next to each other if in-
// -dices are sorted by heights. So, we push all indices into Priority Queue, extract them one by one as a result consecutive height indices are
// extracted one after another. So, we calc. dist. b/w prev. smallest height point to curr. index using BFS. If there is no possible path,
// we return -1, else we add the dist. to final result.









class Solution {
public:
    
    int findDistance(vector<vector<int>>& v, int startRow, int startCol, int destRow, int destCol){// Calc. minm. dist. b/w two points.
        if(startRow==destRow && startCol==destCol) return 0;
        int steps=0;
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
        queue<pair<int,int>>q;
        q.push({startRow, startCol});
        visited[startRow][startCol]=true;
        vector<int>dirs({-1,0,1,0,-1});
        while(!q.empty()){
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int dx=dirs[j], dy=dirs[j+1];
                    if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size() || visited[x+dx][y+dy]==true || v[x+dx][y+dy]==0) continue;
                    if(x+dx==destRow && y+dy==destCol) return steps;
                    visited[x+dx][y+dy]=true;
                    q.push({x+dx, y+dy});
                }
            }
        }
        return -1;
    }
    
    
    
    int cutOffTree(vector<vector<int>>& v) {
        int res=0;
        if(v.size()==0 || v[0].size()==0) return res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;// PQ sorts points in inc. order based on their heights.
        vector<pair<int,int>>indices;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]>1) pq.push({v[i][j], i*v[0].size()+j});			// Pushing all valid points into Priority Queue.
            }
        }
        
        
        int prevRow=0, prevCol=0;
        while(!pq.empty()){
            int currRow=pq.top().second/v[0].size(), currCol=pq.top().second%v[0].size();
            pq.pop();
            int dist=findDistance(v,prevRow, prevCol, currRow, currCol);	// Calc. dist b/w prev. and curr. point.
            if(dist<0) return -1;
            // cout<<"prev row: "<<prevRow<<" and prevCol: "<<prevCol<<" targetrow: "<<currRow<<" and  targetCol: "<<currCol<<endl;
            // cout<<"dist: "<<dist<<endl;
            res+=dist;
            prevRow=currRow;
            prevCol=currCol;
        }
        
        
        return res;															// Return sum of distances b/w all pairs.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m^2*n^2).												// Calc. dist b/w two indices may take O(m*n) time.
// Space Complexity: O(m*n).	
// This algorithm is Sorting+BFS based. Here, sicne we need to add distance between all pair of points which are next to each other if indices
// are sorted by heights. So, we push all indices into Priority Queue, extract them one by one as a result consecutive height indices are
// extracted one after another. So, we calc. dist. b/w prev. smallest height point to curr. index using BFS. If there is no possible path,
// we return -1, else we add the dist. to final result.







class Solution {
public:
    
    int findDistance(vector<vector<int>>& v, int startRow, int startCol, int destRow, int destCol){
        if(startRow==destRow && startCol==destCol) return 0;
        int steps=0;
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
        queue<pair<int,int>>q;
        q.push({startRow, startCol});
        visited[startRow][startCol]=true;
        vector<int>dirs({-1,0,1,0,-1});
        while(!q.empty()){
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int dx=dirs[j], dy=dirs[j+1];
                    if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size() || visited[x+dx][y+dy]==true || v[x+dx][y+dy]==0) continue;
                    if(x+dx==destRow && y+dy==destCol) return steps;
                    visited[x+dx][y+dy]=true;
                    q.push({x+dx, y+dy});
                }
            }
        }
        return -1;
    }
    
    
    
    int cutOffTree(vector<vector<int>>& v) {
        int res=0;
        if(v.size()==0 || v[0].size()==0) return res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<pair<int,int>>indices;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]>1) indices.push_back({v[i][j], i*v[0].size()+j});
            }
        }
        
        sort(indices.begin(), indices.end());
        
        int prevRow=0, prevCol=0;
        for(int i=0;i<indices.size();i++){
            int currRow=indices[i].second/v[0].size(), currCol=indices[i].second%v[0].size();
            int dist=findDistance(v,prevRow, prevCol, currRow, currCol);
            if(dist<0) return -1;
            // cout<<"prev row: "<<prevRow<<" and prevCol: "<<prevCol<<" targetrow: "<<currRow<<" and  targetCol: "<<currCol<<endl;
            // cout<<"dist: "<<dist<<endl;
            res+=dist;
            prevRow=currRow;
            prevCol=currCol;
            
        }
        
        return res;
    }
};

