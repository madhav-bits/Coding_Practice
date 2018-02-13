/*
*
//*************************************************************77. Combinations.****************************************************

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
	

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

0
8

8
0

9
4

0
0

// Time Complexity: O(nck).
// Space Complexity: O(nck).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).			
// This algorithm is dfs, keeps on adding vlaues to temp. vector until the length of it becomes equal to the target length, once reached it 
// won't go for another recursion call. On reaching the length , it will push the temp. vector contents to final result vector array.
//  Thus ending the dfs traversal.


class Solution {
public:
    
    vector<vector<int>> v;
    void findCombi(int n, int k, int curr, int count, vector<int>u){
                
        for(int i=curr;i<=n;i++){
            u.push_back(i);									// Pushing a possible elem. into vector to attain the target length.
            if(count+1==k) v.push_back(u);
            else											// Once, the desired len. is reached, it won't make further dfs recursive calls.
                findCombi(n,k,i+1, count+1,u);
            u.pop_back();									// Removing a possible elem. to substitute it with another possible elem.
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k==0) return v;
        vector<int> u;
        findCombi(n,k,1,0,u);									// Calling the dfs function.
        return v;
    }
};