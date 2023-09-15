/*
*
//***********************************************955. Delete Columns to Make Sorted II.**************************************************

https://leetcode.com/problems/delete-columns-to-make-sorted-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["ca","bb","ac"]
["xc","yb","za"]
["zyx","wvu","tsr"]
["aabaef","abaacd","ababbe","afoiaf","ijbpej","jrpoja"]



// Time Complexity: O(n*m).													//n-size of the array, m-length of each string.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													//n-size of the array, m-length of each string.
// Space Complexity: O(n).	
// This algorithm is observation based. Here, we use another array to track which of the adj. strings are in inc. order: isSorted[i] is true if arr[i]<arr[i+1]
// We iter. over the given array column wise, for each column we iter. over all rows and compare curr. cols of every adj. row pairs, if it's 
// arr[i][j]<=arr[i+1][j] we ignore it, if arr[i][j]>arr[i+1][j] we can't allow this column in our final version, but if isSorted[i] is true, arr[i]<arr[j]
// already so we don't have to bothered by curr. situation and we can ignore this also. If we didn't observe any case where we have to delete curr. col 
// while iter. curr col, we reiter. curr col and update isSorted array if necessary, we take the isSorted[i]=true because it allows us to safely ignore any 
// unexpected comparison in later indices while not resorting to deletions now and in the later indices and as a whole we only delete cols IF NECESSARY. 
// else we inc. res by 1 as we have to delete curr. col. We return #deletions at the end of iter.







class Solution {
public:
    int minDeletionSize(vector<string>& arr) {
        // Iter. column wise and delete cols which cause arr[i][j]>arr[i+1][j] when all prev. chars of 'i' and 'i+1' are same. There is no ther option but to delete this column.
        // If in earlier indices there is arr[i][j]<arr[i+1][j] we don't worry about later indices.
        int res=0;
        vector<bool>isSorted(arr.size(), false);							// Tracks which two adj. strings are already sorted.
        for(int j=0;j<arr[0].length();j++) {
            bool del=false;
            for(int i=0;i+1<arr.size();i++) {								// Iter over all rows for curr. col.
                if(!isSorted[i] && arr[i][j]>arr[i+1][j]) {					// If curr. str>next str, we have to delete curr. col
                    del=true;												// Marking deletion is required and inc. delestions count.
                    res++;
                    break;
                }
            }
            
            for(int i=0;!del && i+1<arr.size();i++) {						// If no deletions done in this col.
                if(!isSorted[i] && arr[i][j]<arr[i+1][j]) isSorted[i]=true;	// We update isSorted[i] if curr. str<next str.
            }
        }
        return res;															// We return min. deletions needed to sort all strs in the array.
    }
};

