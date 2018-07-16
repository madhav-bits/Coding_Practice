/*
*
//******************************************************317. Shortest Distance from All Buildings.***********************************************

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an 
increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and 
right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,0,2,0,1],[0,0,0,1,0],[0,0,1,0,0]]


[[]]

[[1,0,2,0,1]]



// Time Complexity: O((n^4)).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n^4)).
// Space Complexity: O(n^2!).	
// This algorithm is BFS based. We start BFS from all the houses, and update(add to already existing  all grids with dist. from them. We also
// store in another vector, that this index is reachable from how many houses, we mark the visited node as visited. In the second iteration,
// we iteate through distance vector(ignore dist-0) as they indicate walls/bulidings, extract the min. of the rest values.








class Solution {
public:
    int shortestDistance(vector<vector<int>>& v) {
        vector<vector<int>>dist(v.size(), vector<int>(v[0].size(),0));		// Tracks dist. from houses.
        vector<vector<int>>reachable(v.size(), vector<int>(v[0].size(),0));	// Stores #reachable houses from this index.
        queue<pair<int,int>>q;												// Store indices to be visited.
        int count=0;
        for(int i=0;i<v.size();i++){										// Iterating through entire array.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){												// Start BFS from each house.
                    count++;
                    vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(),false));
                    q.push({i,j});
                    visited[i][j]=1;
                    int len=0;
                    while(!q.empty()){										// Until there are no indices to be reached.
                        int mem=q.size();
                        len++;
                        for(int i=0;i<mem;i++){								// Traversing all indices with same dist. from node.
                            int row=q.front().first, clmn=q.front().second;
                            // cout<<"curr. row: "<<row<<" and clmn: "<<clmn<<endl;
                            q.pop();
                            vector<int>dirs({0,1,0,-1,0});
                            for(int k=0;k<4;k++){							// Iterate in 4 drns.
                                int dx=dirs[k], dy=dirs[k+1];
                                // cout<<"Curr. scanning row: "<<row+dx<<" and clmn: "<<clmn+dy<<endl;
                                if(row+dx>=0 && row+dx<v.size() && clmn+dy>=0 && clmn+dy<v[0].size() && visited[row+dx][clmn+dy]==false && v[row+dx][clmn+dy]==0){
                                    reachable[row+dx][clmn+dy]++;			// If unvisited&empty land, then traverse it.
                                    q.push({row+dx,clmn+dy});
                                    dist[row+dx][clmn+dy]+=len;				// Update the dist. to index from curr. building.
                                    visited[row+dx][clmn+dy]=true;			// Mark curr. index as visited.
                                }
                            }
                        }
                    }
                }
            }
        }
        
        int minm=INT_MAX;
        for(int i=0;i<dist.size();i++){
            for(int j=0;j<dist[0].size();j++){
                // cout<<dist[i][j]<<" ";									// If reachable from all houses&dist. !=0
                if(dist[i][j]==0 || reachable[i][j]!=count ) continue;
                minm=min(minm, dist[i][j]);	
            }
            cout<<endl;
        }
        return (minm==INT_MAX)?-1:minm;										// Returning the min. dist from all houses to an empty space.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n^4)).
// Space Complexity: O(n^2).	
// This algorithm is BFS based. We do BFS from all buildings same as in previous algo. Here,we use a optimization step, when performing dist.calc.
// using BFS, we also try to find #houses reachable from curr. house, if it's <total #houses in the vector. It means, all the indices/empty 
// spaces reachable from curr. house aren't reachable from one/more houses, thus ruling out possibility of having indices which is reachable 
// from all houses.





class Solution {
public:
    int shortestDistance(vector<vector<int>>& v) {
        if(v.size()==0 || v[0].size()==0) return -1;
        vector<vector<int>>dist(v.size(), vector<int>(v[0].size(),0));
        vector<vector<int>>reachable(v.size(), vector<int>(v[0].size(),0));
        queue<pair<int,int>>q;
        int count=0, buildings=0;
        for(int i=0;i<v.size();i++){										// Counting #houses in domain.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1) buildings++;
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){
                    count=1;												// Counting self as reachable.
                    vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(),false));
                    q.push({i,j});
                    visited[i][j]=1;
                    int len=0;
                    while(!q.empty()){
                        int mem=q.size();
                        len++;									
                        for(int i=0;i<mem;i++){
                            int row=q.front().first, clmn=q.front().second;
                            // cout<<"curr. row: "<<row<<" and clmn: "<<clmn<<endl;
                            q.pop();
                            vector<int>dirs({0,1,0,-1,0});
                            for(int k=0;k<4;k++){
                                int dx=dirs[k], dy=dirs[k+1];
                                // cout<<"Curr. scanning row: "<<row+dx<<" and clmn: "<<clmn+dy<<endl;
                                if(row+dx>=0 && row+dx<v.size() && clmn+dy>=0 && clmn+dy<v[0].size() && visited[row+dx][clmn+dy]==false){              
                                    if(v[row+dx][clmn+dy]==0){				// If it's a empty space, push into queue.
                                        reachable[row+dx][clmn+dy]++;
                                        q.push({row+dx,clmn+dy});
                                        dist[row+dx][clmn+dy]+=len;
                                    }
                                    else if(v[row+dx][clmn+dy]==1) count++;	// Inc. the count of reachable houses.
                                    visited[row+dx][clmn+dy]=true;
                                }
                            }
                        }
                    }
                    // cout<<"Count at end of search: "<<count<<endl;
                    if(count!=buildings) return -1;							// If all houses not reachable from curr. return -1.
                }
            }
        }
        
        int minm=INT_MAX;
        for(int i=0;i<dist.size();i++){
            for(int j=0;j<dist[0].size();j++){
                // cout<<dist[i][j]<<" ";
                if(dist[i][j]==0 || reachable[i][j]!=buildings) continue;	// If reachable from all houses&dist. !=0
                minm=min(minm, dist[i][j]);
            }
            // cout<<endl;
        }
        return (minm==INT_MAX)?-1:minm;										// Returning the min. dist from all houses to an empty space.
    }
};


