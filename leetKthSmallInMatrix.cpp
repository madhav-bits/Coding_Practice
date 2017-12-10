/*

//*********************************************378. Kth Smallest Element in a Sorted Matrix.****************************************

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.



//Time Complexity: O(logn). //n= range of the matrix's values.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
// This is solved using Binary Search ALgorithmic Pradigm.

  
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int len=matrix[0].size();
        int left=matrix[0][0], right=matrix[len-1][len-1], mid;	//Storing the first and last values in the matrix.
        while(left<right){									
            mid=(left+right)/2;									// Storing the mid value of the matrix range.	
            int psn=0,num=0;
            for(int i=0;i<len;i++){
                psn=upper_bound(matrix[i].begin(), matrix[i].end(),mid)-matrix[i].begin();
                num+=psn;										//Calc. the psn of mid value in the matrix.
            }
            if(num<k)											// If the psn of mid value is more than req. psn "k", then the req. integer-
                left=mid+1;										// is certainly to the left of mid value.
            else												// If the psn of mid value is >= req. psn "k", then the req. int is to right-
                right=mid;										// of the mid value.
        }
        return left;											//Returning the left value, which contains the req. integer value.
    }
};