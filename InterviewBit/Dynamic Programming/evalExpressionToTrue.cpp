/*
*
//*******************************************************Evaluate Expression To True.******************************************************

https://www.interviewbit.com/problems/evaluate-expression-to-true/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


T|F&T^T&T|F^T|T


T|F&T^T


// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, since we have three operators to work on. We will be calc. #ways to get true/false on 
// both sides of each operator and update #ways to get true/false out of left, right values substring's combined length. This way we would be calc. 
// #ways to get true where combined length of both side's values would be total string length.


// If we are working on a substring with corner indices [i,j] then we would be iter. over split/middle indices and if we have an operator over
// there, we would add to substring's #true/false values based on operator and #ways to get true/false on both sides of operator substrings which 
// are substrings of curr. substring under consideration.







int Solution::cnttrue(string s) {
    if(s.length()<1) return 0;												// Base case.
    long int mod=1003;
    vector<vector<int>>tr(s.length(), vector<int>(s.length(), 0));			// Tracks #ways to get true for each substring.
    vector<vector<int>>fl(s.length(), vector<int>(s.length(), 0));			// Tracks #ways to get false for each substring.
    for(int i=0;i<s.length();i++){											// Base case of substring of length 1.
        if(s[i]=='T') tr[i][i]=1;
        if(s[i]=='F') fl[i][i]=1;
    }
    // for(int i=0;i<s.length();i++) cout<<tr[i][i]<<" ";
    // cout<<endl;
    // for(int i=0;i<s.length();i++) cout<<fl[i][i]<<" ";
    
    for(int len=3;len<=s.length();len++){									// Iter. over all substrings possible.
        for(int i=0;i<=s.length()-len;i++){									// Iter. over all start indices.
            for(int j=i+1;j<i+len-1;j++){									// Iter. over all split indices for each substring.
                if(s[j]=='|'){												// If OR operator is encountered.
                    tr[i][i+len-1]=(tr[i][i+len-1]+(tr[i][j-1]*tr[j+1][i+len-1])%mod)%mod;// Updating the #true for substring based on split oper.
                    tr[i][i+len-1]=(tr[i][i+len-1]+(tr[i][j-1]*fl[j+1][i+len-1])%mod)%mod;
                    tr[i][i+len-1]=(tr[i][i+len-1]+(fl[i][j-1]*tr[j+1][i+len-1])%mod)%mod;
                    
                    fl[i][i+len-1]=(fl[i][i+len-1]+(fl[i][j-1]*fl[j+1][i+len-1])%mod)%mod;// Updating the #false for substring based on split oper.
                }
                else if(s[j]=='&'){
                    tr[i][i+len-1]=(tr[i][i+len-1]+(tr[i][j-1]*tr[j+1][i+len-1])%mod)%mod;// Updating the #true for substring based on split oper.
                    
                    fl[i][i+len-1]=(fl[i][i+len-1]+(tr[i][j-1]*fl[j+1][i+len-1])%mod)%mod;// Updating the #false for substring based on split oper.
                    fl[i][i+len-1]=(fl[i][i+len-1]+(fl[i][j-1]*tr[j+1][i+len-1])%mod)%mod;
                    fl[i][i+len-1]=(fl[i][i+len-1]+(fl[i][j-1]*fl[j+1][i+len-1])%mod)%mod;
                }
                else if(s[j]=='^'){
                    tr[i][i+len-1]=(tr[i][i+len-1]+(tr[i][j-1]*fl[j+1][i+len-1])%mod)%mod;// Updating the #true for substring based on split oper.
                    tr[i][i+len-1]=(tr[i][i+len-1]+(fl[i][j-1]*tr[j+1][i+len-1])%mod)%mod;
                    
                    fl[i][i+len-1]=(fl[i][i+len-1]+(tr[i][j-1]*tr[j+1][i+len-1])%mod)%mod;// Updating the #false for substring based on split oper.
                    fl[i][i+len-1]=(fl[i][i+len-1]+(fl[i][j-1]*fl[j+1][i+len-1])%mod)%mod;
                }
            }
        }
    }
    return tr[0][s.length()-1];												// Returning #ways to get true for the entire string.
}
