/*
*
//******************************************************1863. Sum of All Subset XOR Totals.******************************************************

https://leetcode.com/problems/sum-of-all-subset-xor-totals/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3]
[5,1,6]
[3,4,5,6,7,8]
[3,4,5]
[3,3,4,4,5,5]
[3,3,4,4,4,5,5,5]
[11,2,3,4,14,3,2,5,15,3,13,5]
[6,15,3,12,6,16,17,6]



// Time Complexity: O(2^n).													// n-length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).													// n-length of the array.
// Space Complexity: O(1).	
// This algorithm is Brute Force apprach based. We form every possible subset and calc their XOR totals and add them to res and return res at the end of
// process.







class Solution {
public:
    int subsetXORSum(vector<int>& v) {
        int res=0, len=v.size(), cap=(1<<v.size());
        
        for(int rep=0;rep<cap;rep++) {										// Iter. over all possible ways to choose indices for subsets.
            int currRep=rep, total=0, ind=0;
            while(currRep) {												// Iter. over curr. subset rep and picking indices.
                if((currRep&1)!=0) total^=v[ind];							// If curr. index is picked in the rep, we add curr. num to XOR total.
                ind++;
                currRep>>=1;												// Moving to next index in rep.
            }
            res+=total;														// Adding curr. XOR total to sum of all XOR totals.
        }	
        
        return res;															// Returning the sum of XOR totals of all subsets.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).													// n-length of the array.
// Space Complexity: O(n).	
// This algorithm is DFS+Brute Force Approach based. We form all possible subsets and calc. their XOR total and add it to the sum of all XOR totals and
// return it at the end of process.








class Solution {
public:
    
    void formSubset(vector<int>&v, int index, int total, int&res) {
        if(index==v.size()) {												// All indices chosen for this subset.
            res+=total;														// Adding curr. XOR total to sum of all XOR totals.
            return ;
        }     	
        formSubset(v, index+1, total^v[index], res);						// Pikcing the curr. index.
        formSubset(v, index+1, total, res);									// Skipping the curr. index.
        return ;
    }
    
    int subsetXORSum(vector<int>& v) {
        int res=0;
        formSubset(v, 0, 0, res);											// DFS to form all possible subsets and add their XOR totals.
        return res;															// Returning the sum of XOR totals of all subsets.
    }
};

