/*
*
//*********************************************************305. Number of Islands II.**************************************************

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at 
position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island 
is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are 
all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3
3
[[0,0],[0,1],[1,2],[2,0],[2,2],[1,0],[1,1],[2,1]]


1
2
[[0,1],[0,0]]


// Time Complexity: O(m*n*k).  
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*k).												k=length of psns given in the question.
// Space Complexity: O(m*n).	
// This algorithm is Union-Find based. Whenever water is converted into land at an index, we check it's neighbouring four indices and check
// whether they are water or land? If land, we extract the core parent of that Island and merge all neighbouring islands and curr. index into
// one island. We make the core parent of one of adj. island's parent as core parent of combined island. Thus number of islands is prev. count-
// #adj. islands before merging+1.









class Solution {
public:
    
    int findParent(int node, unordered_map<int,int>&parent){				// Find the core parent of the node.
        while(parent[node]!=node)
            node=parent[node];
        return node;
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& u) {		
        unordered_map<int,int>parent;										// Stores the core parents of the islands.
        vector<int>res;
        vector<vector<int>>v(m,vector<int>(n,0));							// Tracks islands and water.
        int count=1, islands=0;												// One for  marking islands, other for couting #islands.
        for(int i=0;i<u.size();i++){
            // cout<<"Curr. index: "<<i<<endl;
            int row=u[i].first, clmn=u[i].second;							// Indices of island.
            int sum=0;
            vector<int>par;													// Stores island marking of adj. islands.
            unordered_map<int,int>m;										// Tracks unique adj. islands.
            if(row-1>=0 && v[row-1][clmn]!=0){
                int par1=findParent(v[row-1][clmn], parent);				// Extracing core parent of adj. island.
                if(m.count(par1)==0){										// If enocuntered island for first time, then first adj.'s core as 
                    m[par1]=1;												// core parent of this adj. island.
                    par.push_back(par1);
                }
                
            }
            
            if(row+1<v.size() && v[row+1][clmn]!=0){
                int par1=findParent(v[row+1][clmn], parent);
                if(m.count(par1)==0){
                    m[par1]=1;
                    par.push_back(par1);
                }
            }
            
            if(clmn-1>=0 && v[row][clmn-1]!=0){
                int par1=findParent(v[row][clmn-1], parent);
                // cout<<"Extracted parent: "<<par1<<endl;
                if(m.count(par1)==0){
                    m[par1]=1;
                    par.push_back(par1);
                }
            }
            
            if(clmn+1<v[0].size() && v[row][clmn+1]!=0){
                int par1=findParent(v[row][clmn+1], parent);
                if(m.count(par1)==0){
                    m[par1]=1;
                    par.push_back(par1);
                }
            }
            v[row][clmn]=count;												// Marking as visited with unique number.
            parent[count]=count;											// Setting the parent to itself.
            count++;														// INc. the Unique number.
            if(par.size()==0){												// If no adj. islands.
                res.push_back(++islands);									// #Islands inc. by one.
                // cout<<"Pusing islands in middle: "<<endl;
                continue;
            }
            int parFirst=findParent(par[0], parent);						// Extract the first adj. island.
            for(int j=par.size()-1;j>0;j--){
                parent[par[j]]=parFirst;								// Make first adj. island's core parent as else adj. island's core parent
            }
            parent[count-1]=parFirst;										// Change core parent of curr. index.
            islands=islands-m.size()+1;										// Extracint island's count.
            // cout<<"Pushing islands at end."<<endl;
            res.push_back(islands);											// Pushing #islands into final result vector.
            // cout<<"End. of iteration."<<endl;
        }
        return res;															// Returning the final result vector.
    }
};













//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*k).													k=length of psns given in the question.
// Space Complexity: O(m*n).	
// This algorithm is Union-Find based. Whenever water is converted into land at an index, we check it's neighbouring four indices and check
// whether they are water or land? If land, we extract the core parent of that Island and merge all neighbouring islands and curr. index into
// one island. We make the core parent of curr. index as core parent of combined island. Thus number of islands is prev. count-
// #adj. islands before merging+1.

// This algo. is almost same as the above one, except that curr. index is made as core parent of all adj. islands. Has a higher time complexity
// as this would add one more layer of finding core parent for all further calls for many of the island indices. 




class Solution {
public:
    
    int findParent(int node, unordered_map<int,int>&parent){
        while(parent[node]!=node)
            node=parent[node];
        return node;
    }
    
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& u) {
        unordered_map<int,int>parent;//,value;
        vector<int>res;
        if(m==0) return res;
        vector<vector<int>>v(m,vector<int>(n,0));
        int count=1, islands=0;
        for(int i=0;i<u.size();i++){
            // cout<<"Curr. index: "<<i<<endl;
            int row=u[i].first, clmn=u[i].second;
            vector<int>par;
            unordered_map<int,int>m;
            v[row][clmn]=count;
            // cout<<"curr. node's parent: "<<count<<endl;
            parent[count]=count;
            m[count]=1;
            
            if(row-1>=0 && v[row-1][clmn]!=0){
                int par1=findParent(v[row-1][clmn], parent);
                m[par1]=1;
                parent[par1]=count;											// Setting curr. index as parent of adj. island indices.
                
            }
            
            if(row+1<v.size() && v[row+1][clmn]!=0){
                int par1=findParent(v[row+1][clmn], parent);
                m[par1]=1;
                parent[par1]=count;
            }
            
            if(clmn-1>=0 && v[row][clmn-1]!=0){
                int par1=findParent(v[row][clmn-1], parent);
                m[par1]=1;
                parent[par1]=count;
            }
            
            if(clmn+1<v[0].size() && v[row][clmn+1]!=0){
                int par1=findParent(v[row][clmn+1], parent);
                m[par1]=1;
                parent[par1]=count;
            }
            count++;
            islands+=1-m.size();
            // cout<<"map size: "<<m.size()<<endl;
            // cout<<"Push back islands: "<<islands<<endl;
            res.push_back(++islands);										// Storing the updated #islands.
            
        }
        return res;															// Returning the final result vector.
    }
};