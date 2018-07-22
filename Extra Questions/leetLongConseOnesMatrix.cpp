/*
*
//****************************************************562. Longest Line of Consecutive One in Matrix.*********************************************

Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1,1,0],[0,1,1,0],[0,0,0,1]]


[[0,0,0],[0,1,0],[1,1,1]]


[[1,0,0],[0,1,0],[0,0,1]]



// Time Complexity: O(n*m).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is iteration based. We  maintain 4 DP arrays, which tracks conse. ones laterally, vertically, diagonally, anti diagonally.
// For each index, we check in 4 drns and their corres. index's DP values, and add 1 and assign it to curr. index's rep. in 4 DP arrays. We 
// comapre those values to max. to update the max. variable.








class Solution {
public:
    int longestLine(vector<vector<int>>& v) {
        vector<vector<int>>lat(v.size(),vector<int>(v[0].size(),0));		// Tracks conse. ones in hori. drn.		
        vector<vector<int>>vert(v.size(),vector<int>(v[0].size(),0));		// Tracks conse. ones in vertical drn.
        vector<vector<int>>diag(v.size(),vector<int>(v[0].size(),0));		// Tracks conse. ones in diag. drn.
        vector<vector<int>>diag2(v.size(),vector<int>(v[0].size(),0));		// Tracks conse. ones in Anti-Diag. drn.
        int res=0;															// Tracks max. conse. ones encountered till now.
        for(int i=0;i<v.size();i++){										// Iterates the entire array.
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){												// If curr. index has one.
                    vert[i][j]=1;lat[i][j]=1;diag[i][j]=1;diag2[i][j]=1;	// Set the default to curr. index' rep. in those 4 arrays.
                    if(i-1>=0) vert[i][j]=1+vert[i-1][j];					// Add the values accumulated in rep. of above index.
                    if(j-1>=0) lat[i][j]=1+lat[i][j-1];
                    if(i-1>=0 && j-1>=0) diag[i][j]=1+diag[i-1][j-1];
                    if(i-1>=0 && j+1<v[0].size()) diag2[i][j]=1+diag2[i-1][j+1];
                    res=max(res,vert[i][j]);								// Try to update the max. conse. ones var.
                    res=max(res,lat[i][j]);
                    res=max(res,diag[i][j]);
                    res=max(res,diag2[i][j]);
                }
                
            }
        }
        cout<<"The result is: "<<res<<endl;
        return res;															// Return the max. conse ones.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n).	
// This algorithm is iteration based. We  maintain 4 DP arrays, which tracks conse. ones laterally, vertically, diagonally, anti diagonally.
// For each index, we check in 4 drns and their corres. index's DP values, and add 1 and assign it to curr. index's rep. in 4 DP arrays. We 
// comapre those values to max. to update the max. variable.



// This algo. is same as the above one, except that we only create two rows, as curr. row's values depend only on prev. row.





class Solution {
public:
    int longestLine(vector<vector<int>>& v) {
        if(v.size()==0 || v[0].size()==0) return 0;
        vector<vector<int>>lat(2,vector<int>(v[0].size(),0));
        vector<vector<int>>vert(2,vector<int>(v[0].size(),0));
        vector<vector<int>>diag(2,vector<int>(v[0].size(),0));
        vector<vector<int>>diag2(2,vector<int>(v[0].size(),0));
        int res=0;
        for(int i=0;i<v.size();i++){
            // cout<<"Curr. row: "<<i<<endl;
            for(int j=0;j<v[0].size();j++){
                vert[i%2][j]=0;lat[i%2][j]=0;diag[i%2][j]=0;diag2[i%2][j]=0;// Setting the indices to default value of zero.
                if(v[i][j]==1){
                    vert[i%2][j]=1;lat[i%2][j]=1;diag[i%2][j]=1;diag2[i%2][j]=1;// If 1 present, setting to default value of one.
                    if(i-1>=0) vert[i%2][j]=1+vert[(i-1)%2][j];				// Updating based on values from prev. row.
                    if(j-1>=0) lat[i%2][j]=1+lat[i%2][j-1];
                    if(i-1>=0 && j-1>=0) diag[i%2][j]=1+diag[(i-1)%2][j-1];
                    if(i-1>=0 && j+1<v[0].size()) diag2[i%2][j]=1+diag2[(i-1)%2][j+1];
                    res=max(res,vert[i%2][j]);								// Trying to update the max. conse. ones var.
                    res=max(res,lat[i%2][j]);
                    res=max(res,diag[i%2][j]);
                    res=max(res,diag2[i%2][j]);
                    // cout<<"vert: "<<vert[i%2][j]<<" lat: "<< lat[i%2][j]<<" diag: "<< diag[i%2][j]<<" diag2: "<<diag2[i%2][j]<<endl;
                }
                
            }
        }
        // cout<<"The result is: "<<res<<endl;
        return res;															// Returning the max. conse. ones.
    }	
};