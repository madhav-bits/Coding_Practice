/*
*
//***********************************************************296. Best Meeting Point.*****************************************************

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 
marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input: 

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6 

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance 
             of 2+2+2=6 is minimal. So return 6.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]


[[1,1]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^*m*#houses).
// Space Complexity: O(n*m).	
// This algorithm is mostly similar to Smallest Dist to All Buildings. Except that it doesn't have any obstructions(we can meet at someone's house
// we can travel through someone's house to reach other's house/ other place.  I had applied BFS to get the result. My algo had passed through
// all test cases except one with large dimentsions, where I was getting TLE error.


// We maintain a visited vector to track visited nodes, preventing infi. loops, we also maitain a dist vector to track dist. from that index to all
// houses. We start BFS from all houses, at each BFS step, we add the dist. to curr. house in that index. At the end of iteration, we scan 
// through all indices, extract the min. dist.

// This is a Correct and suitable algo, it just has TLE for one very large test case.




class Solution {
public:
    int minTotalDistance(vector<vector<int>>& v) {
        vector<vector<int>>dist(v.size(),vector<int>(v[0].size(),0));		// Stores the dist. from all indices to all houses.
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                int path=-1;
                if(v[i][j]==1 ){											// Starting BFS from all houses.
                    // cout<<"Matched row: "<<i<<" and clmn: "<<j<<endl;
                    vector<vector<bool>>visited(v.size(),vector<bool>(v[0].size(),false));
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j]=true;
                    vector<int>dirs({0,-1,0,1,0});
                    while(!q.empty()){										// Until no more indices to be visited.
                        int len=q.size();
                        path++;												// Dist. of curr. index to curr. house.
                        // cout<<"len: "<<len<<endl;
                        for(int a=0;a<len;a++){								// Iter. indices at same dist. from curr. house.
                            int x=q.front().first;
                            int y=q.front().second;
                            q.pop();
                            // cout<<"curr row: "<<x<<" and clmn: "<<y<<endl;
                            dist[x][y]+=path;
                            for(int k=0;k<4;k++){							// Checking out 4 drns.
                                int dx=dirs[k],dy=dirs[k+1];
                                // cout<<"dx: "<<x+dx<<" and dy: "<<y+dy<<" and count: "<<count<<endl;
                                if(x+dx>=0 && y+dy>=0 && x+dx<v.size() && y+dy<v[0].size() && visited[x+dx][y+dy]==false){//&& visited[x+dx][y+dy]==count-1
                                    visited[x+dx][y+dy]=true;
                                    // cout<<"pushed row: "<<x+dx<<" and clmn: "<<y+dy<<endl;
                                    q.push({x+dx,y+dy});
                                }
                            } 
                        }
                        
                    }
                    
                }
                
            }
            
        }
        int res=INT_MAX;													// Tracks min. dist to all houses.
        for(int i=0;i<v.size();i++){										// Iter. dist array and extract min. dist.
            for(int j=0;j<v[0].size();j++){
                // cout<<dist[i][j]<<" ";
                // if(visited[i][j]==count) 
                    res=min(res,dist[i][j]);
            }
            // cout<<endl;
        }
        return res;															// Returning the min. dist to all houses.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).
// Since, there are no restrictions in travelling around. As,we want a index with Min. Manhattan Dist. to all nodes. This requirement is ideally
// pointing towards median of all values in rows and clmns wrto their psns, As median is a index with value which has min. sum of dist. to 
// all elem in that array.


// We iterate the given array and store the rows, clmn of houses in two seprate vectors. We extract the Median row, Median clmn, whose combi. 
// would give the required dist(minm dist). from Median Row, Median Clmn to all houses.






class Solution {
public:
    
    
    int getMin(vector<int>v){												// Extract the dist. to all values from median of this array.
        int i=0,j=v.size()-1,sum=0;											// Tracks first, last index and sum of dist. from median.
        while(i<j){															// Covers all indices.
            sum+=v[j]-v[i];													// Adding dist. to median to v[i] and median to v[j].
            j--;i++;
        }
        return sum;															// Returning the overall dist. to median val.
    }
    
    int minTotalDistance(vector<vector<int>>& v) {
        vector<int>rows,clmns;												// Stores rows,clmns in which houses are present.
        for(int i=0;i<v.size();i++){										// Iter. the given array.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1)												// If house encountered.
                    rows.push_back(i);										// Store the row.
            }
        }
        
        for(int j=0;j<v[0].size();j++){										// Iter. the given array.
            for(int i=0;i<v.size();i++){
                if(v[i][j]==1)												// If house ecountered.
                    clmns.push_back(j);										// Store the clmn.
            }
        }
        
        return getMin(rows)+getMin(clmns);									// Get dist. from Median Row, Median Clmn to all houses.
    }
};