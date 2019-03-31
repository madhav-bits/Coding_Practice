/*
*
//******************************************************864. Shortest Path to Get All Keys.***********************************************

We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and 
("A", "B", ...) are locks.

We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the 
grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  
This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and 
locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.

 

Example 1:

Input: ["@.a.#","###.#","b.A.B"]
Output: 8
Example 2:

Input: ["@..aA","..B#.","....b"]
Output: 6
 

Note:

1 <= grid.length <= 30
1 <= grid[0].length <= 30
grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["@..aA","..B#.","....b"]



["@abcdeABCDEFf"]



["@fedcbBCDEFaA"]


["@abBCcDde.", ".##.....#f"]
 
 
 
 

// Time Complexity: O(m*n*2^k).  											// k is maxm. possible keys.
// Space Complexity: O(m*n*2^k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*2^k).												// k is maxm. possible keys.
// Space Complexity: O(m*n*2^k).	
// This algorithm is BFS and Bitmasking based solution. Here, since we need shortest path we use BFS, and it has cover all keys, while traver-
// -sing at a point, it can move through multiple keys and reach that index, so we can have pow(2,keys) states possible for each index, so
// we keeps track of pow(2,keys) per each index, if we revisit an index with same state once again, we stop search. If an index state is
// target state (all keys have been collected), we return #steps taken till that step. Since, we may have diff keys not in sequence, we create
// target key state based on keys encountered.

// visited[i][j][mask] indicates whether [i,j] index had been visited with mask state or not?
// If mask is 001010, it says second key('b) and fourth key('d') had been visited till now in the path.










class Solution {
public:
    int shortestPathAllKeys(vector<string>& v) {
        int keys=0, sRow, sCol;
        for(int i=0;i<v.size();i++){										// Counting keys, finding start index.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]>='a' && v[i][j]<='f') keys++;
                if(v[i][j]=='@'){
                    sRow=i;
                    sCol=j;
                }
            }
        }
        if(keys==0) return 0;												// If no keys present.
        if(v.size()==0) return -1;											// Base case.
        vector<int>dirs({-1,0,1,0,-1});
        int target=pow(2,keys)-1;
        vector<vector<vector<bool>>>visited(v.size(),vector<vector<bool>>(v[0].size(), vector<bool>(target,false)));// target states at each index.
        queue<pair<int,int>>q;
        q.push({0,sRow*v[0].size()+sCol});
        visited[sRow][sCol][0]=1;
        int steps=1;
        while(!q.empty()){													// Reaching all reachable indices.
            int len=q.size();
            for(int i=0;i<len;i++){											// Iter. over all indices which are at same distance from start.
                pair<int,int>curr=q.front();
                int mask=q.front().first, row=q.front().second/v[0].size(), col=q.front().second/v[0].size();
                q.pop();
                for(int j=0;j<4;j++){										// Iter. over adjacent indices.
                    int dx=dirs[j], dy=dirs[j+1];
                    if(row+dx<0 || row+dx>=v.size()|| col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]=='#') continue;
                    int newMask=mask;
                    if(v[row+dx][col+dy]>='A' && v[row+dx][col+dy]<='F'){	// If lock encountered.
                        int val=v[row+dx][col+dy]-'A';
                        if((mask&(1<<val))==0) continue;					// If key not visited, stop iteration.
                        // q.push({mask, (row+dx)*v[0].size()+col+dy});
                    }
                    if(v[row+dx][col+dy]>='a' && v[row+dx][col+dy]<='f'){	// If key encountered.
                        int val=v[row+dx][col+dy]-'a';
                        newMask=(mask|(1<<val));							// Accept the key into state.
                    }
                    if(visited[row+dx][col+dy][newMask]) continue;			// If next index is already visited with this state, stop iteraiton.
                    if(newMask==pow(2,keys)-1) return steps;				// Checking whether all keys are collected or not.
                    q.push({newMask, (row+dx)*v[0].size()+col+dy});			// Pushing the updated state, next index into queue.
                }
            }
            steps++;
        }
        return -1;
        
    }
};