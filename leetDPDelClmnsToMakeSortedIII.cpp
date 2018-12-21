/*
*
//******************************************************960. Delete Columns to Make Sorted III.***********************************************

We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["babca","bbazb"] and deletion indices {0, 1, 4}, then the final array after deletions is ["bc","az"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has every element (row) in lexicographic order.

For clarity, A[0] is in lexicographic order (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in lexicographic 
order (ie. A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]), and so on.

Return the minimum possible value of D.length.

 

Example 1:

Input: ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
Note that A[0] > A[1] - the array A isn't necessarily in lexicographic order.
Example 2:

Input: ["edcba"]
Output: 4
Explanation: If we delete less than 4 columns, the only row won't be lexicographically sorted.
Example 3:

Input: ["ghi","def","abc"]
Output: 0
Explanation: All rows are already lexicographically sorted.
 

Note:

1) 1 <= A.length <= 100
2) 1 <= A[i].length <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["babca","bbazb"]


["ghi","def","abc"]


["cbbdabc"]



// Time Complexity: O(n^3).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, as we need remove min #clmns to get remaining chars in a sorted way. This can be thought of 
// as finding max. length subsequence in all given strings with same indices. We find the max. length subsequence and remove this length from the
// string length to get min. #deletions.

// In finding the max. length subsequence, we iterate through all given strings with two indices to compare, if we are able to iterate through 
// all strings with str[i]<=str[j] valid in all strings, then these two indices can form increasing subsequence of length dp[i]+1. So, we update
// the max. length subsequence ending at index 'j' and also update the final max. length subsequence var.



// dp[i] -> max. length of subsequence ending at index-'i' in all given strings.






class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        vector<int>dp(v[0].length(), 1);									// Tracks max. length subseq. ending at each index 'i' in all strings.
        int res=1;															// Init. subseq to 1(Base Case).
        for(int j=0;j<v[0].length();j++){									// Iter. through all subseq. finishing indices.
            // cout<<"Current j: "<<j<<endl;
            for(int i=0;i<j;i++){											// Iter. through all possible last but one subseq. indices.
                // cout<<"i: "<<i<<endl;
                int k=0;													// Init. string iterator value.
                for(;k<v.size();k++){										// Iter. through all strings possible.
                    if(v[k][i]>v[k][j]) break;								// If sorting condition doesn't satisfy, then break.
                }
                if(k==v.size()){											// If all strings satisfy sorted condition.
                    res=max(res, dp[i]+1);									// We update the max. length subseq of entire strings.
                    dp[j]=max(dp[j], dp[i]+1);								// We also update the max. length subseq. ending at index 'j'.
                } 
                // cout<<"k: "<<k<<" and temp: "<<temp<<" and res: "<<res<<endl;
            }
                
        }
        // for(auto num: dp) cout<<num<<" ";
        // cout<<endl;
        // cout<<"res: "<<res<<endl;
        return v[0].length()-res;											// Returning min. #deletions.
        
    }
};