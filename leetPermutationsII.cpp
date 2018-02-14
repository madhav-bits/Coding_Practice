/*
*
//*************************************************************47. Permutations II.****************************************************

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[]
[1]
[1,2,3,4]
[1,1,1,2,2,3,3,4]
[0,1,0,0,4]
[1,1,1,2,2,3,3]
[-1,-1,0,0,1,1,2]

// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			
// This is dfs, the logic is that perm of A[1,n]= sum of A[i]+perm(A[1,n]-A[i]), all perm. of a array is all perm. of else elements when one elem. 
// is chosen from them. In order to avoid dup perm. dup. num. shouldn't be swapped. The logic is that sorting state is maintained such, that
// duplicates can be easily tracked by comparing adjacent elem.


class Solution {
public:
    void findPermute(vector<int> v, vector<vector<int>> &u, int count){
        if(count==v.size()){														// Once all swaps are done, then push to result vector.
            u.push_back(v);
            return ;
        }
        
        for(int i=count;i<v.size();i++){
            if(i== count || (i!=count && v[i]!=v[count])){							// Avoids swapping dup. elem.
                swap(v[i], v[count]);												// Swap that val. with count index. As it's a possible swap.
                findPermute(v,u,count+1);											//  Calling for the next sequence of swaps to get perm.
                //swap(v[i], v[count]);
            }
                
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& v) {
        sort(v.begin(), v.end());													// Sorting the given array, to track dupli. easily.
        vector<vector<int>> u;
        findPermute(v,u,0);															// Calling the function.
        return u;																	// Returning all perm.
    }
};




//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			
// This is dfs, the logic is that perm of A[1,n]= sum of A[i]+perm(A[1,n]-A[i]), all perm. of a array is all perm. of else elements when one elem. 
// is chosen from them. In order to avoid dup perm. dup. num. shouldn't be swapped. We have to make sure that swapped valued elem. shouldn't be 
// swapped once again with count index, for that I had used map, to identify dupicate, but still it's throwing error, don't know why.
// The below used if condition won't work that properly. It can't handle full fledged dupli. elem. after few swaps.





class Solution {
public:
    void findPermute(vector<int> v, vector<vector<int>> &u, int count){
        if(count==v.size()){
            u.push_back(v);
            return ;
        }
        
        for(int i=count;i<v.size();i++){
            if(i==count || (i!=count && v[i]!=v[i-1] && v[i] != v[count])){		// It has passed 29/20 cases. 
                swap(v[i], v[count]);											// It doesn't dup. prop. after few swaps.
                findPermute(v,u,count+1);										// Used, map instead to find dupli., still failed, dont' know why?			
                swap(v[i], v[count]);
            }
                
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> u;
        findPermute(v,u,0);
        return u;
    }
};