/*
*
//*****************************************************200. Number of Islands.********************************************

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by 
connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","1","0"]]

[["1","0","1","0","1"],["0","1","0","0","0"],["1","0","1","0","1"],["0","0","0","0","0"],["1","0","1","0","1"]]

[]

[["1","0","1","0","1"],["0","1","0","0","0"],["0","0","0","0","0"],["1","0","1","0","1"]]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algortihm is DFS, checks all possible going ahead, and comebacks if any hindrance is faced. Here, as we go deep into the array, we mark
// those which have been already visited by changing their values. So, that we don't revisit them and might lead to recount of islands.
// We get into iterating the array, when the start value is "1" and inc. count by one each time. As Island's pieces are connected only in hori.
// and vertical we check only four possibilities( 4 drns).



class Solution {
public:
    
    
    void findCount(vector<vector<char>> &v, int i, int j){
        if(v[i][j]=='0')												// Says that it is already visited or it's water(So, we don't visit).			
            return ;
        v[i][j]='0';													// Modify, values so that we don't visit once again.
        
        if(i-1>=0)                                             		 	//Checking for connection in the up direction.
            findCount(v,i-1,j);
        if(i+1<v.size())                                            	//Checking for connection in the down direction.
            findCount(v,i+1,j);	
        if(j-1>=0)                                              		//Checking for connection in the left direction.
            findCount(v,i,j-1);
        if(j+1<v[0].size())                                            	//Checking for connection in the right direction.
            findCount(v,i,j+1);
        
        
    }
    
    
    int numIslands(vector<vector<char>>& v) {
        if(v.size()==0) return 0;
        int row=v.size();
        int clmn=v[0].size();
        int count=0;
        for(int i=0;i<row;i++){										// Calling the func. from all possible land indices.
            for(int j=0;j<clmn;j++){
                if(v[i][j]=='1'){									// Function is called only if the curr. land is unvisited.
                    count++;										// Count is increased accordingly.
                    findCount(v,i,j);								// Function is called by current index.
                }													// When passing values to func. pass as less as possible(Effects time complexity).
            }
        }
        return count;												// Returning the total no. of islands.
    }
};