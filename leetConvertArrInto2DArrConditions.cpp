/*
*
//******************************************************2610. Convert an Array Into a 2D Array With Conditions.******************************************************

https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,4,1,2,3,1]
[1,2,3,4]
[1,1,1,2,2,2,3,3,3,3]
[1,2,3,3,3,3,3,3]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is sorting based. Here, as we have ensure no duplicates values in an array in 2D array. We need to have #rows equal to max. freq of nums. So, we store the freq. of nums and also track the max. freq. and create
// an array of max. freq rows. We iter. occur array push all the num's each occurance into each row, thus we avoid duplicates in each row. We return res at the end of iteration.







class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& v) {
        vector<int>occur(v.size()+1, 0);																// Freq. arr to store freq. of each num.
        int maxm=0;
        for(int&num:v) {																				// Iter. over array and store #occur in freq. array.
            if(++occur[num]>maxm) maxm=occur[num];
        }
        vector<vector<int>>res(maxm);																	// Res array with rows=max. freq.of nums.
        for(int i=0;i<occur.size();i++) {
            for(int j=0;j<occur[i];j++) {																// Each num's multiple occur has to be store in each of the row to avoid duplicates in each row.
                res[j].push_back(i);
            }
        }
        return res;																						// Returning the res 2D array.
    }
};

