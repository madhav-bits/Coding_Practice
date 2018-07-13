/*
*
//************************************************************531. Lonely Pixel I.*****************************************************

Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
The range of width and height of the input 2D array is [1,500].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["W","W","B","W"],["W","B","W","W"],["B","W","W","B"]]


[]


[[]]

[["B"]]



// Time Complexity: O(m*n).  
// Space Complexity: O(m+n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(m+n).	
// This algorithm is DFS based. Instead of doing DFS from each instance of "B" in all drns to find out whether it's lonely or not? Avoiding all
// unnecessary/overlapping iterations. We iterate once, the whole vector, and store #B's in each row and clmn in two diff vectors. In the second
// iteration, whenever we encounter "B", we check whether that index's row and clmn has only 1 "B", it it is, we inc. the count of lonely pixels.








class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& v) {
        if(v.size()==0 || v[0].size()==0) return 0;							// If Empty vector, return 0.
        vector<int>rows(v.size(),0), clmns(v[0].size(),0);					// Stores #B's in each row and clmn.
        int len=max(v.size(),v[0].size());									// Max. of rows/clmns.
        for(int i=0;i<len;i++){												// Iterate the entire array.
            int temp1=0,temp2=0;
            for(int j=0;j<len;j++){
                if(i<v.size() && j<v[0].size()){							// Checking for "B"'s in the curr. row.
                    if(v[i][j]=='B') temp1++;
                }
                
                if(i<v[0].size() && j<v.size()){							// Checking for "B"'s in curr. clmn.
                    if(v[j][i]=='B')temp2++;
                }
            }
            if(temp1==1) rows[i]=1;											// If it's only single "B", mark occurance of single "B" with 1.
            if(temp2==1) clmns[i]=1;
        }
        int count=0;														// #lonely pixels.
        for(int i=0;i<v.size();i++){										// Final iteration of the vector.
            for(int j=0;j<v[0].size();j++){
                if(rows[i]!=1) continue;									// If row has !=1 "B"'s skip it.
                if(v[i][j]=='B' && rows[i]==1 && clmns[j]==1) count++;		// If "B" encountered, check that index's row and clmn.
            }
        }
        return count;														// Returning total #lonely pixels.
    }
};