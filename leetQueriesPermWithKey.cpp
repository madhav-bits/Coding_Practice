/*
*
//***********************************************1409. Queries on a Permutation With Key.*********************************************

https://leetcode.com/problems/queries-on-a-permutation-with-key/description/

Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) 
according to the following rules:

In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the 
permutation P. Notice that the position of queries[i] in P is the result for queries[i].
Return an array containing the result for the given queries.

 

Example 1:

Input: queries = [3,1,2,1], m = 5
Output: [2,1,2,1] 
Explanation: The queries are processed as follow: 
For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
Therefore, the array containing the result is [2,1,2,1].  
Example 2:

Input: queries = [4,1,2,2], m = 4
Output: [3,1,2,0]
Example 3:

Input: queries = [7,5,5,8,3], m = 8
Output: [6,5,0,7,5]
 

Constraints:

1 <= m <= 10^3
1 <= queries.length <= m
1 <= queries[i] <= m



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with test cases in the question.



// Time Complexity: O(n*m).													// m- #Queries, n-range of nums.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// m- #Queries, n-range of nums.
// Space Complexity: O(n).	
// This algorithm is based on the fact that we store the indices of all nums in an array. While going through queries, we get their indices
// directly by looking psns[num] and re-assigning it to 0, while inc. the index values of all nums which are to the left of curr. num. by
// 1.








class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>res;														// Stores the psns of querie's num.
        vector<int>psns(m+1,-1);											// Stores psns of all nums.
        for(int i=1;i<=m;i++) psns[i]=i-1;									// Init. the psns of all nums.
        for(int i=0;i<queries.size();i++){									// Iter. over all queries.
            int num=queries[i];												
            res.push_back(psns[num]);										// Pushing psn. of curr. num.
            int val=psns[num];												
            for(int j=1;j<=m;j++){											// Inc. the psns of nums to the left of curr. num by 1.
                if(psns[j]<val) psns[j]++;
            }
            psns[num]=0;													// Placing curr. num at index-0.
        }
        return res;															// Returning the collected psns of querie's nums.
    }
};