/*
*
//**********************************************************97. Interleaving String.***************************************************

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aabcc"
"dbbca"
"aadbbcbcac"



""
"b"
"b"




// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Dynamic Programming  based. This follows Classic way of handling DP in string related problems. We maintain a DP array to 
// track whether the result string can be obtained from curr. strings of length i,j or not? Index i,j indicates/stores index of final string
// which can be formed from given strings of length i and j. We maintain the maximum index of final string possible in each index. If, we are at 
// each index i,j. If we have value-'k' at index i-1,j, then we check value of string s1[i-1] and s3[k+1]. If, they are equal we update the value
// of curr. index in DP array. Same applies to value in i,j-1 index and s2[j-1] and s3[k+1]. If at the end of iteration, if we have len-1 of 
// target string in the last index of DP array, then return true, else return false.

// We could have done using boolean values where index of s3 can be obtained by row,clmn values index=row+clmn-1.








class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=(s1.length()+s2.length())) return false;			// If lens doesn't sum up, return false.
        // if(s1.length()==0) return (s2==s3);								// This optimizes execution, but haven't used in orig. submission.
        // if(s2.length()==0) return (s1==s3);
        vector<vector<int>>dp(s2.length()+1,vector<int>(s1.length()+1,-1));	// Declaring a DP array.
        for(int i=1;i<=s1.length();i++){									// First row init.	
            int ind=dp[0][i-1];												// Extracting saved val. in prev. clmn.
            if(s3[ind+1]==s1[i-1]){											// If saved val.+1 index in target and #row-1 index in s1 matches.
                dp[0][i]=ind+1;												// Assign val+1 in curr. index in DP array.
                // cout<<"Assigned new val at clmn: "<<i<<" of: "<<ind+1<<endl;
            }                 
        }
        
        for(int i=1;i<=s2.length();i++){									// First clmn init.
            int ind=dp[i-1][0];
            if(s3[ind+1]==s2[i-1]){											// If saved val+1 index in target and #clmn-1 index in s2 matches.
                dp[i][0]=ind+1;												// Assign val+1 in curr. index in DP array.
                // cout<<"Assigned new val at row: "<<i<<" of: "<<ind+1<<endl;
            } 
        }
        
        // for(auto nums:dp){												// Checking out DP array values.
        //     for(auto num:nums){
        //         cout<<num<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        for(int i=1;i<=s2.length();i++){
            for(int j=1;j<=s1.length();j++){
                int ind=dp[i-1][j];											// Store s3 index from prev. row.
                if(s3[ind+1]==s2[i-1]){										// If curr. chars in both strs match.
                    dp[i][j]=max(dp[i][j],ind+1);							// Assign max index of s3 possible in curr. index of DP array.
                }
                
                ind=dp[i][j-1];												// Store s3 index from prev. clmn.
                if(s3[ind+1]==s1[j-1]){										// If curr. chars in both strs match.
                    dp[i][j]=max(dp[i][j],ind+1);							// Assign max. index of s3 possible in curr. index of DP array.
                }
                
            }
        }
        
        
        // for(auto nums:dp){												// Checking out DP array values.
        //     for(auto num:nums){
        //         cout<<num<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return (dp[s2.length()][s1.length()]==s3.length()-1);				// If we have len-1 of s3 in last index of DP array, then return true.
    }																		// Else, return false.
};