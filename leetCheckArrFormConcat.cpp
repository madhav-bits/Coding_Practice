/*
*
//****************************************1640. Check Array Formation Through Concatenation.*******************************************


https://leetcode.com/problems/check-array-formation-through-concatenation/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with question.
[85]
[[85]]
[15,88]
[[88],[15]]
[49,18,16]
[[16,18,49]]
[91,4,64,78]
[[78],[4,64],[91]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is observation based. Here, we store the indices of nums in psn array. We now iter. over pieces array, since 
// #nums in all pieces is equal to given arr. length. All the pieces contents has to be values of given array, as they are unique,
// they occur only once. The order needs to be same as given array. By the end of pieces if we are able to find that every num 
// is in given array, then it implies we can form given arrray from pieces. If a visited num is visited once again, it implies one of
// num from given array is not present in pieces, as sum(#elem. in all pirces)=leng. of given array.








class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int>psn(101,-1);												// Stores the index of each num. in given array
        for(int i=0;i<arr.size();i++)										// Storing num's index in psn array.
            psn[arr[i]]=i;
        for(int i=0;i<pieces.size();i++){									// Iter. over pieces.
            if(psn[pieces[i][0]]==-1) return false;							// If this num doesn't occur in given array, return false.
            int prev=psn[pieces[i][0]];
            psn[pieces[i][0]]=-1;											// After visiting marking num as absent.
            for(int j=1;j<pieces[i].size();j++){							// Iter. over each pieces array.
                int curr=psn[pieces[i][j]];
                if(curr==-1) return false;									// If curr. num doesn't occur then return false.
                if(curr!=prev+1) return false;								// If nums in pieces are not in seq. return false.
                prev=psn[pieces[i][j]];
                psn[pieces[i][j]]=-1;										// Marking visited num. as absent.
            }
        }
        return true;														// All the nums are visited.
    }
};
