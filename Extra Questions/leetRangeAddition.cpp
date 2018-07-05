/*
*
//************************************************************370. Range Addition.*****************************************************

Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] 
(startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
[[1,3,2],[2,4,3],[0,2,-2]]


20
[[7,12,-2],[1,10,3],[13,17,1],[10,16,6]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We store the start and end psns of increments provided in maps with the increment as value. We iterate the 
// given length of indices, and if the curr. index is from start/end or both we increment the total by that amount and we assign the curr.
// index with that amount.








cclass Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& v) {
        vector<int>res(length,0);											// Final result vector.
        unordered_map<int,int>start,end;									// Stores all start and end indices.
        for(int i=0;i<v.size();i++){										// Iterate all intervals provided.
            start[v[i][0]]+=v[i][2];										// Store the increment corres. to that start index.
            end[v[i][1]]+=v[i][2];
        }
        int sum=0;															// Sum of active interval's at curr. index's increment values. 
        for(int i=0;i<length;i++){
            if(start.count(i)==1) sum+=start[i];							// If start of interval found, increment` the value.
            if(end.count(i-1)==1) sum-=end[i-1];							// If prev. index is where an interval ended, dec. the value.
            res[i]=sum;														// Assign curr. index the sum value.
        }
        return res;															// Returning the final result vector.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is summation based. As, we are working on intervals corners. We, store the inerval's increment value at corner indices. Now,
// we start from the 1 index, add sum attained at prev. index to the incre. stored in curr. index and assign the sum to curr. index.



class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& v) {
        vector<int>res(length,0);											// Final result vector.
        for(int i=0;i<v.size();i++){
            res[v[i][0]]+=v[i][2];											// Storing increment at start of interval.
            if(v[i][1]+1<length)res[v[i][1]+1]-=v[i][2];					// Storing decrement at end of interval.
        }
        int sum=0;															// Sum of active interval's at curr. index's increment values. 
        for(int i=1;i<length;i++){
            res[i]+=res[i-1];												// Sum of prev. index's sum value and curr. index's incre/decre value.
        }
        return res;															// Returning the final result vector.
    }
};