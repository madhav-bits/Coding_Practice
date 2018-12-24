/*
*
//******************************************************961. N-Repeated Element in Size 2N Array.***********************************************


In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5
 

Note:

1) 4 <= A.length <= 10000
2) 0 <= A[i] < 10000
3) A.length is even




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.







// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, as all values except 1 had occured only once and the last one had occured N times. So, we extract the 
// val which occured more than 1 time. At the end of iteration, we return the extracted value.








class Solution {
public:
    int repeatedNTimes(vector<int>& v) {
        vector<int>occur(10000,0);											// DP array to track the number of occurances of each num.
        int res=0;															// Stores final result.
        for(int i=0;i<v.size();i++){										// Iter. the array.
            occur[v[i]]++;													// Inc. the #occurances value.
            if(occur[v[i]]>1) res=v[i];										// If the #occurances>1, we store the value.
        }
        return res;															// Returning the final result.
    }
};