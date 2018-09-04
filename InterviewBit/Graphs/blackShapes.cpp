/*
*
//****************************************************************Black Shapes.*********************************************************

https://www.interviewbit.com/problems/black-shapes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3 OOOXOOO OOXXOXO OXXXXXO






// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is Depth First Search based. We iter. over given 2D array. When we encounter a 'X', we start a DFS search from here, in search 
// of 'X's connected to it, and change them to 'O' as we pass through them, such that those connected 'X's won't be counted again. We encounter 
// other Blacks Shapes unconnected to curr. ones in the iteration. Thus, at the end of iter. we get the count of all Unconnected Black Shapes.


// Here,I am changing 'X's to 'O's, such that they won't be visited once again. If we want maintain the given array in it's orig. state, we have
// to take another 2D array of same size, where we mark visited 'X's indices with zeroes, such that those indices won't be visited once again.






void maskBlacks(vector<string>&v,int row, int clmn){						// Does DFS iteration over all connected 'X's.
    if(row<0 || clmn<0 || row>=v.size() || clmn>=v[0].size() || v[row][clmn]=='O') return ;// If index out of bounds/not a 'X', then skip call.
    v[row][clmn]='O';														// Change 'X' to 'O', such that it won't be visited once again.
    maskBlacks(v,row-1,clmn);												// Iter. int 4 drns.
    maskBlacks(v,row+1,clmn);
    maskBlacks(v,row,clmn-1);
    maskBlacks(v,row,clmn+1);
    
}

int Solution::black(vector<string> &v) {
    if(v.size()==0) return 0;												// If empty 2D array given, then return 0.
    int count=0;															// Init. the count to 0.
    for(int i=0;i<v.size();i++){											// Iter. over 2D array.
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]=='X'){												// If 'X' encountered.
                count++;													// Inc. the count.
                maskBlacks(v,i,j);											// Start a DFS, in search of connected 'X's.
            }
        }
    }
    return count;															// Return the count of Black Shapes.
}
