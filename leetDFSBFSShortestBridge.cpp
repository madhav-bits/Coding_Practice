/*
*
//**********************************************************934. Shortest Bridge.***************************************************

In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: [[0,1],[1,0]]
Output: 1
Example 2:

Input: [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Note:

1 <= A.length = A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[[1,1,0,0,0],[1,0,0,0,0],[1,0,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]


[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS+DFS based. Even though the question was asked for 2 islands, I had written it for an generalized case of multiple 
// islands. Here, in the first iteration, we mark each island with numbers in inc. order. In the process of DFS, we note down the coast
// indices of each island. Then, we start BFS from all the islan's coast indices at the same time, we mark the visited ocean indices with the 
// smallest coast dist. from it and the closest island's marked number. So, in the BFS process, if a visited ocean index is visited once again
// by an island other than closest island, then that path is shortest bridge path.








class Solution {
public:
    
    void fillQueue(vector<vector<int>>& v, int row, int clmn, vector<vector<bool>>&visited, queue<pair<int,int>>&q, int group, vector<vector<pair<int,int>>>&dist){
        // cout<<"row: "<<row<<" and clmn: "<<clmn<<endl;
        // visited[row][clmn]=true;
        v[row][clmn]=group;													// Marking the curr. island with a number.
        dist[row][clmn].second=group;										// Storing the marking of that island in dist. array.
        if(row-1>=0 && v[row-1][clmn]==1 && visited[row-1][clmn]==false){	// Visiting adjacent island nodes.
            visited[row-1][clmn]=true;
            fillQueue(v,row-1,clmn, visited,q, group, dist);
        }
        if(clmn-1>=0 && v[row][clmn-1]==1 && visited[row][clmn-1]==false){
            visited[row][clmn-1]=true;
            fillQueue(v,row,clmn-1, visited,q, group, dist);
        }
        if(row+1<v.size() && v[row+1][clmn]==1 && visited[row+1][clmn]==false){
            visited[row+1][clmn]=true;
            fillQueue(v,row+1,clmn, visited,q, group, dist);
        }
        if(clmn+1<v[0].size() && v[row][clmn+1]==1 && visited[row][clmn+1]==false){
            visited[row][clmn+1]=true;
            fillQueue(v,row,clmn+1, visited,q, group, dist);
        }
        if((row-1>=0 && v[row-1][clmn]==0) || (row+1<v.size() && v[row+1][clmn]==0)|| (clmn-1>=0 && v[row][clmn-1]==0) || (clmn+1<v[0].size() && v[row][clmn+1]==0)){
            q.push({row,clmn});												// Pushing coast indices into queue.
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& v) {
        int res=100001;
        // unordered_map<string,int>visited;
        vector<vector<pair<int,int>>>dist(v.size(), vector<pair<int,int>>(v[0].size(),{-1,-1}));// Has min. dist to an island, mark of that island.
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));// Tracks visited indices.
        queue<pair<int,int>>q;												// Stores indices to be scanned.
        int group=1;														// Marking number.
        for(int i=0;i<v.size();i++){										// Iter. all indices and marking the islands.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1 && visited[i][j]==false){
                    visited[i][j]=true;
                    fillQueue(v,i,j,visited,q, group,dist);
                    group++;
                }
            }
        }
        // for(auto nums:v){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        int len=0;
        while(!q.empty()){													// Visiting all ocean indices are reached/ Bridge found.
            int quan=q.size();												// #Indices with same shortest dist. from islands.
            len++;
            for(int i=0;i<quan;i++){										// Iter. over all curr. indices.
                pair<int,int>curr=q.front();
                q.pop();
                int row=curr.first, clmn=curr.second;
                // cout<<"Curr. row: "<<row<<" and clmn: "<<clmn<<endl;
                int sign=dist[row][clmn].second;							// Storing the sign/Mark of the island.
                if(row-1>=0 && v[row-1][clmn]==0){							// If next/adj. index is ocean.
                    if(dist[row-1][clmn].first!=-1 && dist[row-1][clmn].second!=sign){// If next index is visited twice.
                        // cout<<"res row: "<<row-1<<" and clmn: "<<clmn<<endl;
                        // cout<<"len: "<<len<<" and dist: "<<dist[row-1][clmn].first<<endl;
                        return len+dist[row-1][clmn].first-1;    			// Returning the Shortest Bridge length.
                    } 
                    else if(v[row-1][clmn]==0 && dist[row-1][clmn].first==-1 && dist[row-1][clmn].second!=sign){// If next index is visited 1st time.
                        dist[row-1][clmn].first=len;						// Storing the shorest dist. to island from that index.
                        dist[row-1][clmn].second=sign;						// Storing the closest island's mark.
                        // cout<<"pushing row: "<<row-1<<" and clmn: "<<clmn<<endl;
                        q.push({row-1,clmn});								// Pushing into Queue.
                    }
                }

                if(clmn-1>=0 && v[row][clmn-1]==0){
                    if(dist[row][clmn-1].first!=-1 && dist[row][clmn-1].second!=sign){
                        // cout<<"res row: "<<row<<" and clmn: "<<clmn-1<<endl;
                        // cout<<"len: "<<len<<" and dist: "<<dist[row][clmn-1].first<<endl;
                        return len+dist[row][clmn-1].first-1;    
                    } 
                    else if(v[row][clmn-1]==0 && dist[row][clmn-1].first==-1 && dist[row][clmn-1].second!=sign){
                        dist[row][clmn-1].first=len;
                        dist[row][clmn-1].second=sign;
                        // cout<<"pushing row: "<<row<<" and clmn: "<<clmn-1<<endl;
                        q.push({row,clmn-1});
                    }
                }

                if(row+1<v.size() && v[row+1][clmn]==0){
                    if(dist[row+1][clmn].first!=-1 && dist[row+1][clmn].second!=sign){
                        // cout<<"res row: "<<row+1<<" and clmn: "<<clmn<<endl;
                        // cout<<"len: "<<len<<" and dist: "<<dist[row+1][clmn].first<<endl;
                        return len+dist[row+1][clmn].first-1;    
                    } 
                    else if(v[row+1][clmn]==0 && dist[row+1][clmn].first==-1 && dist[row+1][clmn].second!=sign){
                        dist[row+1][clmn].first=len;
                        dist[row+1][clmn].second=sign;
                        // cout<<"pushing row: "<<row+1<<" and clmn: "<<clmn<<endl;
                        q.push({row+1,clmn});
                    }
                }

                if(clmn+1<v[0].size() && v[row][clmn+1]==0){
                    if(dist[row][clmn+1].first!=-1 && dist[row][clmn+1].second!=sign ){
                        // cout<<"res row: "<<row<<" and clmn: "<<clmn+1<<endl;
                        // cout<<"len: "<<len<<" and dist: "<<dist[row][clmn+1].first<<endl;
                        return len+dist[row][clmn+1].first-1;    
                    } 
                    else if(v[row][clmn+1]==0 && dist[row][clmn+1].first==-1){
                        dist[row][clmn+1].first=len;
                        dist[row][clmn+1].second=sign;
                        // cout<<"pushing row: "<<row<<" and clmn: "<<clmn+1<<endl;
                        q.push({row,clmn+1});
                    }
                }

                // cout<<"queue row: "<<curr.first<<" and second: "<<curr.second<<endl;
            }
            
        }
        return -1;															// If not possible to build bridge, return -1.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS+BFS based. This is same as above one, except that it's modified into visually smaller code with same logic and small
// improvizations.






class Solution {
public:
    
    void fillQueue(vector<vector<int>>& v, int row, int clmn, vector<vector<bool>>&visited, queue<pair<int,int>>&q, int group, vector<vector<pair<int,int>>>&dist){
        // cout<<"row: "<<row<<" and clmn: "<<clmn<<endl;
        v[row][clmn]=group;
        dist[row][clmn].second=group;
        vector<int>dirs({-1,0,1,0,-1});
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if((row+dx)>=0 && (row+dx)<v.size() && (clmn+dy)>=0 && (clmn+dy)<v[0].size() && v[row+dx][clmn+dy]==1 && visited[row+dx][clmn+dy]==false){
                visited[row+dx][clmn+dy]=true;
                fillQueue(v,row+dx,clmn+dy, visited, q,group, dist);
            }
        }
            
        if((row-1>=0 && v[row-1][clmn]==0) || (row+1<v.size() && v[row+1][clmn]==0)|| (clmn-1>=0 && v[row][clmn-1]==0) || (clmn+1<v[0].size() && v[row][clmn+1]==0)){
            q.push({row,clmn});
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& v) {
        int res=100001;
        // unordered_map<string,int>visited;
        vector<vector<pair<int,int>>>dist(v.size(), vector<pair<int,int>>(v[0].size(),{-1,-1}));
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
        vector<int>dirs({-1,0,1,0,-1});
        queue<pair<int,int>>q;
        int group=1;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1 && visited[i][j]==false){
                    visited[i][j]=true;
                    fillQueue(v,i,j,visited,q, group,dist);
                    group++;
                }
            }
        }
        // for(auto nums:v){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        int len=0;
        while(!q.empty()){
            int quan=q.size();
            len++;
            for(int i=0;i<quan;i++){
                pair<int,int>curr=q.front();
                q.pop();
                int row=curr.first, clmn=curr.second;
                // cout<<"Curr. row: "<<row<<" and clmn: "<<clmn<<endl;
                int sign=dist[row][clmn].second;
                for(int j=0;j<4;j++){
                    int dx=dirs[j], dy=dirs[j+1];
                    if((row+dx)>=0 && (row+dx)<v.size() && (clmn+dy)>=0 && (clmn+dy)<v[0].size() && v[row+dx][clmn+dy]==0){
                        if(dist[row+dx][clmn+dy].first!=-1 && dist[row+dx][clmn+dy].second!=sign){
                            // cout<<"res row: "<<row-1<<" and clmn: "<<clmn<<endl;
                            // cout<<"len: "<<len<<" and dist: "<<dist[row-1][clmn].first<<endl;
                            return len+dist[row+dx][clmn+dy].first-1;    
                        } 
                        else if(dist[row+dx][clmn+dy].first==-1 ){
                            dist[row+dx][clmn+dy].first=len;        
                            dist[row+dx][clmn+dy].second=sign;
                            // cout<<"pushing row: "<<row-1<<" and clmn: "<<clmn<<endl;
                            q.push({row+dx,clmn+dy});
                        }
                    }
                }
                // cout<<"queue row: "<<curr.first<<" and second: "<<curr.second<<endl;
            }
            
        }
        return -1;
    }
};