/*
*
//********************************************************694. Number of Distinct Islands.***************************************************

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or 
vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and 
not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,1,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]


[[0,0,0,1,1],[0,1,0,1,1],[1,1,1,0,0],[0,1,0,1,0],[1,0,1,1,1],[0,0,0,1,0]]




// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is DFS based. We start from the first encountered part of a island, upon traversal we change the values to 0, to prevent
// reiterations. At each index, we check it's offset, x,y axis wise from the first encountered index of this index, and push it to a string.
// After the entire iteration, we check for this string in the map, if it's not present, we inc. the count and push that str into map.
// At the end, we return the count of distinct islands(count/size of map).


// I had almost got this algo, fiding the offset wrto first encountered index, but thought that might be a lengthy idea, moreover I didn't 
// thought of using string using pass by reference to store the offsets(This was main part missing from my logic).





class Solution {
public:
    
    void extractIsland(vector<vector<int>>&v, int row, int clmn, int dx, int dy,string&s){
        if(row+dx<0 || clmn+dy<0 || row+dx>=v.size() || clmn+dy>=v[0].size() || v[row+dx][clmn+dy]==0) return ;// If no unvisited island, return.
        // cout<<"Inside the fn. with row: "<<row+dx<<" and clmn: "<<clmn+dy<<endl;
        v[row+dx][clmn+dy]=0;												// Marking as visited.
        s+=to_string(dx)+"_"+to_string(dy)+" ";								// Storing offset values into string.
        
        extractIsland(v,row,clmn, dx-1, dy, s);								// Calling recursively all adj. indices.
        extractIsland(v,row,clmn, dx+1, dy, s);
        extractIsland(v,row, clmn, dx,dy-1, s);
        extractIsland(v,row,clmn, dx,dy+1,s);
        
    }
    
    int numDistinctIslands(vector<vector<int>>& v) {
        unordered_map<string,int>m;											// Stores offset representing strings of islands.
        for(int i=0;i<v.size();i++){										// Iterates through the entire array.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){												// Fisrt encountered index of an island.
                    // cout<<"Calling fn. with index row: "<<i<<" and clmn: "<<j<<endl;
                    string s="";											// Stores the islands offset string.
                    extractIsland(v,i,j,0,0,s);								// Calling fn. to extract island.
                    // cout<<"Extracted str: "<<s<<endl;
                    if(m.count(s)==0)										// If island not present, add it to map.
                        m[s]=1;	
                    
                }
            }
        }
        return m.size();													// Return the #distinct islands(count of map).
    }
};