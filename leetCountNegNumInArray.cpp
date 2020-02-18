/*
*
//*********************************************1351. Count Negative Numbers in a Sorted Matrix.***************************************

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Not any test cases that I particularly created to test.


// Time Complexity: O(mlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mn).
// Space Complexity: O(1).	
// This algorithm is Linear Search based. In each row, we iter. and find the first occurance of neg. value and add the #neg. into
// the final result. 








class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int res=0;
        for(int i=0;i<v.size();i++){
            int j=0;
            while(j<v[i].size() && v[i][j]>=0) j++;
            res+=v[i].size()-j;
        }
        return res;
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogn).
// Space Complexity: O(1).	
// This algorithm is binary search based algorithm. Here, in each row, we search for first neg.number and add the #neg. values to 
// final count and return the total neg. values.








class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int res=0;
        for(int i=0;i<v.size();i++){
			if(v[i].back()>=0) continue;
            int start=0, close=v[i].size()-1;
            while(start<close){												// Bin. Search to find the first neg. value.
                int mid=(start+close)/2;
                if(v[i][mid]>=0) start=mid+1;
                else close=mid;
            }
            res+=(v[i].size()-start);
        }
        return res;
    }
};