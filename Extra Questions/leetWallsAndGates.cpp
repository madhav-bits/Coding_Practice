/*
*
//**********************************************************286. Walls and Gates.***************************************************

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is 
less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




// Worked on modified versions of given test case.




// Time Complexity: O(m^2*n^2).  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m^2*n^2).
// Space Complexity: O(m*n).	
// This algorithm is Depth First Search based. We start from all the Empty Rooms, in all directions until we reach a gate. We extract all the values
// and update the empty room's index's value with min. of those values. We use the previously calculated empty room's shortest dist. values, which
// covers only very few overlapping subproblems.So, that won't be that useful in reducing time complexity. 








class Solution {
public:
    
    int extractDist(vector<vector<int>>&v, vector<vector<int>> & visited, int row, int clmn){
        //if(v[row][clmn]==0) return 0;
        if(v[row][clmn]>=0 && v[row][clmn]<INT_MAX) return v[row][clmn];	// If this val. has already assigned min. value.
        int len=INT_MAX;													// Def. value of dist. extrac from adj. nodes.
        visited[row][clmn]=1;												// Marks the curr. node as visited.
        if(row-1>=0 && v[row-1][clmn]!=-1 && visited[row-1][clmn]==0) len=min(len,extractDist(v,visited,row-1,clmn));
        if(clmn-1>=0 && v[row][clmn-1]!=-1 && visited[row][clmn-1]==0) len=min(len,extractDist(v,visited,row,clmn-1));
        if(row+1<v.size() && v[row+1][clmn]!=-1 && visited[row+1][clmn]==0) len=min(len,extractDist(v,visited,row+1,clmn));
        if(clmn+1<v[0].size() && v[row][clmn+1]!=-1 && visited[row][clmn+1]==0) len=min(len,extractDist(v,visited,row,clmn+1));
        // cout<<"Extracted min. dist at row: "<<row<<" and clmn: "<<clmn<<" is: "<<len<<endl;
        visited[row][clmn]=0;												// Unmarks the curr. node as visited.
        return (len!=INT_MAX)?1+len:INT_MAX;								// IF obtained value=INT_MAX, return INT_MAX, else return 1+value.
    }
    void wallsAndGates(vector<vector<int>>& v) {
        if(v.size()==0) return ;
        vector<vector<int>> visited(v.size(), vector<int>(v[0].size(),0));	// Tracks visited nodes in curr. search.
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==INT_MAX) v[i][j]=extractDist(v,visited,i,j);	// We extr. curr. node's shortest dist. to gate.
            }
        }
        return ;
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m^2*n^2).
// Space Complexity: O(m*n).	
// This algorithm is Breadth First Search based. We start from all the Gates, and update all the room's distance from it. From the following Gates,
// we update only rooms, whose values can be updated using the dist. from the curr. node. Thus, reducing number of calls.







class Solution {
public:
    
    void wallsAndGates(vector<vector<int>>& v) {
        if(v.size()==0) return ;
        // cout<<"row size: "<<v.size()<<" and clmn size: "<<v[0].size()<<endl;
        int dist=0,len;
        queue<pair<int,int>>q;												// Stores indices of curr. pixel. 
        for(int i=0;i<v.size();i++){										// Iterates the entire matrix.
            for(int j=0;j<v[0].size();j++){
                // cout<<"Curr. row: "<<i<<" and clmn: "<<j<<endl;
                if(v[i][j]==0){												// We start from all gates.
                    // visited=vector<vector<int>>(v.size(), vector<int>(v[0].size(),0));
                    q.push(make_pair(i-1,j));								// Push all gate's adj. pixels.
                    q.push(make_pair(i,j-1));
                    q.push(make_pair(i+1,j));
                    q.push(make_pair(i,j+1));
                    
                    dist=0;len=q.size();
                    while(!q.empty()){										// Till queue gets empty.
                        if(len==0){
                            len=q.size();
                            dist++;
                        }
                        int row=q.front().first;							// Get. curr. pixel.
                        int clmn=q.front().second;
                        q.pop();
                        len--;												// If the value is updatable, then go ahead, else continue to.
                        if(row<0 || clmn<0 || row>=v.size() || clmn>=v[0].size() ||  v[row][clmn]==-1 || v[row][clmn]< 1+dist) continue;
                        v[row][clmn]=1+dist;								//  Update the curr. pixel value.
                        //visited[row][clmn]=1;
                        q.push(make_pair(row-1,clmn));						// Pass all it's adj. values.
                        q.push(make_pair(row,clmn-1));	
                        q.push(make_pair(row+1,clmn));
                        q.push(make_pair(row,clmn+1));
                    }
                    //v[i][j]=extractDist(v,visited,i,j);    
                } 
            }
        }
        
        
        return ;
    }
};