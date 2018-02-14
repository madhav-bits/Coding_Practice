/*
*
//*************************************************************46. Permutations.****************************************************

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[]
[1]
[1,2,3,4]




// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			
// This is dfs, the logic is that perm of A[1,n]= sum of A[i]+perm(A[1,n]-A[i]), all perm. of a array is all perm. of else elements when one elem. 
// is chosen from them.





class Solution {
public:
    void findPermute(vector<int> v, vector<vector<int>> &u, int count){
		
        if(count==v.size()){									// When all combinatins at all indices are done.
            u.push_back(v);										// Pushing the permutated array into final result vector.
            return ;
        }
        
        for(int i=count;i<v.size();i++){
            swap(v[count], v[i]);
            //if(count==v.size()-1)								// I tried to check and avoid loop here itself, but inc. exec. time, Why??
            //    u.push_back(v);
            //else
                findPermute(v,u,count+1);						// Choosing curr. elem. and calling to get perm. of following elem.
            swap(v[count], v[i]);								// Reverse swap, as there are other possible combi. at curr. index.
        }
    }
    
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>>u;									// Stores final array of prem. vectors.
        findPermute(v,u,0);										// Calling the perm. function.
        return u;												// Returns all possible perm. combinations.
    }
};