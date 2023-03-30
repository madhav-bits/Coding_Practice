/*
*
//******************************************************2133. Check if Every Row and Column Contains All Numbers.******************************************************

https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[3,1,2],[2,3,1]]
[[1,1,1],[1,2,3],[1,2,3]]
[[2,2,2],[2,2,2],[2,2,2]]



// Time Complexity: O(n*n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(n).	
// This algorithm is BitSet based. Here, we iterate over the given matrix, for every iteration, we track the nums in ith row and ith col with two bitset arrays.We set those arrays while iterating, if the #bits set in any of the
// two arrays is <length of the array, that means there were duplicates in that row or col, which doesn't meet our requirement, so we return false. If no such cases found in our iteration, we return true at the end of iter.







class Solution {
public:
    bool checkValid(vector<vector<int>>& v) {
        int len=v.size();
        for(int i=0;i<v.size();i++) {																	// Iter. over ith row and ith col and marking the visited nums in the bitset arrays.
            bitset<101>row, col;																		// Tracks nums in ith row and ith col.
            for(int j=0;j<v.size();j++) {
                row[v[i][j]]=true;																		// Marking nums in ith row.
                col[v[j][i]]=true;																		// Marking nums in ith col.
            }
            if(min(row.count(), col.count())<len) return false;											// If any duplicates are present, few nums would also be missing, if any duplicates observed, we return false.
        }
        
        return true;																					// If no duplicates found in any row or col, we return true.
    }
};

