/*
*
//*******************************************1886. Determine Whether Matrix Can Be Obtained By Rotation.****************************************

https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1],[1,0]]
[[1,0],[0,1]]
[[0,1],[1,1]]
[[1,0],[0,1]]
[[0,0,0],[0,1,0],[1,1,1]]
[[1,1,1],[0,1,0],[0,0,0]]



// Time Complexity: O(n*n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we rotate the matrix by 90 deg. in every iter. and check if modified matrix == target, if yes we return true. If 
// matrices aren't equal in 4 turns, we return false as we had rotated it by 360 deg. bringing to it's original form.







class Solution {
public:
    
    
    bool isSame(vector<vector<int>>&u, vector<vector<int>>&v) {				// Checks if both matrices are the same.
        for(int i=0;i<u.size();i++) {
            for(int j=0;j<v.size();j++) {
                if(u[i][j]!=v[i][j]) return false;
            }
        }    
        return true;
    } 
    
    void rotate90CW(vector<vector<int>>&v) {								// Rotates the matrix by 90 CW.
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<i;j++) {
                swap(v[i][j], v[j][i]);
            }
        }    
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v.size()/2;j++) {
                swap(v[i][j], v[i][v[0].size()-1-j]);
            }
        }
        return ;
    }
    
    void printMatrix(vector<vector<int>>&v) {
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v.size();j++) {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++) {
            if(isSame(mat, target)) return true;							// Func. call to check if matrices are the same.
            rotate90CW(mat);												// Rotate the matrix by 90 degrees.
            // printMatrix(mat);
        }
        return false;														// Return false if matrices aren't the same.
    }
};

