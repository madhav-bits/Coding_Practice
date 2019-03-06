/*
*
//******************************************************407. Trapping Rain Water II.***********************************************

Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of 
water it is able to trap after raining.

 

Note:

Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

 

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.


The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.

 



After the rain, water is trapped between the blocks. The total volume of water trapped is 4.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]



// Time Complexity: O(m*nlog(m*n)).  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*nlog(m*n)).
// Space Complexity: O(m*n).	
// This algorithm is Priority Queue based. Here, the main issue is that an index takes the min Height of water that can be supported 
// by four adj. sides. Here, indices on edges decides the height of water. So, we need min. height, so we start working from least
// height to greatest height on the edges. We extract indices from Priority Queue based on the water heights supported by them.
// We perform BFS, while working on an index, if it's adjacent index is visited, then this index's height would be the least height
// of water supported by adj. index, we calc. height for it and push it into Qeueue to visit indices, which it influences. Thus, at the
// end of iteration, we get the volume of water stored in all indices.





// These links contains good description of algo. used here:
// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89495/How-to-get-the-solution-to-2-D-%22Trapping-Rain-Water%22-problem-from-1-D-case
// https://tinyurl.com/y6l776t5
// https://leetcode.com/problems/trapping-rain-water-ii/description/










class Solution {
public:

    struct Cell{															// Data structure to be pushed into Queue.
        int x,y,height;
        
        Cell(int a, int b, int c){
            x=a;
            y=b;
            height=c;
        }
    };
    
    struct comp{															// Custom comparator to get cells with min. height. 
        bool operator()(Cell &lt, Cell &rt){
            return lt.height>rt.height;
        }
    };
    
    int trapRainWater(vector<vector<int>>& v) {
        if(v.size()<=2) return 0;
        int cols=v[0].size();
        priority_queue<Cell,vector<Cell>, comp>pq;
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));// TO prevent revisitig indices.
        vector<int>dirs({-1,0,1,0,-1});
        for(int i=0;i<v.size();i++){										// Push all corner indices into queue for BFS.
            pq.push(Cell(i,0, v[i][0]));
            pq.push(Cell(i,cols-1, v[i][cols-1]));
            visited[i][0]=true;												// Mark those indices as visited.
            visited[i][cols-1]=true;
        }
        for(int j=1;j<cols-1;j++){											// Push all corner indices into queue for BFS.
            pq.push(Cell(0,j, v[0][j]));
            pq.push(Cell(v.size()-1,j, v[v.size()-1][j]));
            visited[0][j]=true;												// Mark those indices as visited.
            visited[v.size()-1][j]=true;
        }
        int res=0;
        while(!pq.empty()){
            Cell curr=pq.top();
            int x=curr.x, y=curr.y;
            pq.pop();
            for(int i=0;i<4;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || y+dy<0 || x+dx>=v.size() || y+dy>=cols || visited[x+dx][y+dy]) continue;
                res+=max(0, curr.height-v[x+dx][y+dy]);						// Obtain the water stored(As water level can't be neg. we use max here).
                pq.push(Cell(x+dx, y+dy, max(curr.height, v[x+dx][y+dy])));	// Push into Queue to renewed height(As given height would be min. height possible).
                visited[x+dx][y+dy]=true;									// Mark as visited.
            }
        }
        return res;															// Returning total volume of water collected.
    }
};

