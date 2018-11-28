/*
*
//**************************************************947. Most Stones Removed with Same Row or Column.********************************************

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]

[[0,1],[1,0]]

[[1,1],[1,2],[3,1],[6,6],[4,3],[3,1],[7,5],[4,9]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Union-Find based. Here, a main observation is that, if we have group of points, which can be related through common row/
// clmn values through directly or indirectly, then all but one can be removed, when having another stone with same row/clmn. So, this sln
// boils down to finding #islands. At the end, #moves to #stones-#islands. 
// Here, we iterate and compare every stone's psn to every other stone's psn and join the islands they are part of. At the end, we iterate 
// through, track count of island's representatives encount.(#islands), then return #moves=#stones-#islands.







class Solution {
public:
    
    void joinPoints(int x, int y, unordered_map<int,int>&parent){			// Join the islands the two stones are part of.
        int parX=findParent(x,parent);
        int parY=findParent(y, parent);
        parent[parY]=parX;
        return;
    }
    
    int findParent(int x, unordered_map<int,int>&parent){					// Return the Rep. of islands, the curr. stone is part of.
        if(parent[x]==x) return x;
        return findParent(parent[x], parent);
    }
    
    int removeStones(vector<vector<int>>& v) {
        unordered_map<int,int>parent;										// Links every stone to it's island parent(Representative).
        for(int i=0;i<v.size();i++)											// Init. all stones with their parents.
            parent[i]=i;
        int res=0;															// Tracks #islands.
        for(int i=0;i<v.size();i++){										// Here, every stone is compared to every other stone and islands are
            for(int j=i+1;j<v.size();j++){									// -formed.
                if(v[i][0]==v[j][0] || v[i][1]==v[j][1]) joinPoints(i,j,parent);// If they have common row/clmn, join those islands.
            }
        }
        for(int i=0;i<v.size();i++){										// Finding the parents of each stone.
            if(parent[i]==i) res++;											// If curr. stone is rep., inc. the #islands count.
        }
        return v.size()-res;												// Returning max. #moves possible.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Union-Find based. Here, a main observation is that, if we have group of points, which can be related through common row/
// clmn values through directly or indirectly, then all but one can be removed, when having another stone with same row/clmn. So, this sln
// boils down to finding #islands. At the end, #moves to #stones-#islands.

// Here, we have issues with merging with rows, clmns. We make clmns unique by converting them into neg. values(~1=-2, ~0=-1) and so on. Thus,
// we can clearly differentiate which rows and clmns are merged. Here, we iterate over stones and merge the corres. rows, clmns the stone
// belongs to. At the end, we iterate over stones, then find the representatives(#islands), then return the result.


// Even detailed explanatin of this sln is at:
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)



class Solution {
public:
    
    int findParent(int x, unordered_map<int,int>&parent){					// Find parent of the axis.
        if(parent[x]==x) return x;
        return findParent(parent[x], parent);
    }
    
    
    void formParent(int row, int clmn, unordered_map<int,int>&parent){
        if(parent.count(row)==0) parent[row]=row;							// If parent's are assigned, then make itself a parent(rep.).
        if(parent.count(clmn)==0) parent[clmn]=clmn;
        int parX=findParent(row, parent);									// Extracting parent(rep.) of this co-ordinate(axis).
        int parY=findParent(clmn, parent);									// Extracting parent(rep.) of this co-ordinate(axis)
        parent[parY]=parX;													// Make parent of X, the parent of Y.
        return;
    }
    
    
    int removeStones(vector<vector<int>>& v) {
        int res=0;
        unordered_map<int,int>parent;										// Tracks stones and their island's representatives.
        for(int i=0;i<v.size();i++){										// Iter. over stones.
            int currRow=v[i][0], currClmn=v[i][1];
            formParent(currRow, ~currClmn, parent);							// Join the rows, clmns these stone belongs to.
        }
        unordered_set<int>groups;											// Tracks #unique representatives.
        for(int i=0;i<v.size();i++){										// Iter. over all stones.
            groups.insert(findParent(v[i][0], parent));
        }
        return v.size()-groups.size();										// Return max. #moves possible.
        //[[3,2],[3,1],[4,4],[1,1],[0,2],[4,0]]
    }
};









//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Union-Find based. Here, a main observation is that, if we have group of points, which can be related through common row/
// clmn values through directly or indirectly, then all but one can be removed, when having another stone with same row/clmn. So, this sln
// boils down to finding #islands. At the end, #moves to #stones-#islands.

// Here, we have issues with MERGING WITH ROWS/CLMNS. We make clmns unique by converting them into neg. values(~1=-2, ~0=-1) and so on. Thus,
// we can clearly differentiate which rows and clmns are merged. Here, we iterate over stones and merge the corres. rows, clmns the stone
// belongs to. At the end, we iterate over stones, then find the representatives(#islands), then return the result.

// Here, we inc. the count of islands, when we create parent for a axis(row/clmn), dec. the count when we make one's parent, parent to parent of
// other axis, as we are merging rows and clmns here.


// This is even more simplified version of above sln.



// Even detailed explanatin of this sln is at:
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)








class Solution {
public:
    
    int findParent(int x, unordered_map<int,int>&parent){
        if(parent.count(x)==0){												// Creating new axis representatives(island).
            parent[x]=x;
            res++;
        }
        if(parent[x]==x) return x;
        return findParent(parent[x], parent);
    }
    
    
    void formParent(int row, int clmn, unordered_map<int,int>&parent){
        int parX=findParent(row, parent);
        int parY=findParent(clmn, parent);
        if(parX!=parY) res--;												// As, we are merging two axis's representatives.
        parent[parY]=parX;
        return;
    }
    
    int res=0;																// Tracks #non-intersecting axis(islands).
    int removeStones(vector<vector<int>>& v) {
        unordered_map<int,int>parent;
        for(int i=0;i<v.size();i++){
            int currRow=v[i][0], currClmn=v[i][1];
            formParent(currRow, ~currClmn, parent);
        }
        return v.size()-res;												// Returning max. #moves possible.
    }
};