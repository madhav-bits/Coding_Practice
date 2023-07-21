/*
*
//******************************************2002. Maximum Product of the Length of Two Palindromic Subsequences.***************************************

https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"leetcodecom"
"accbcaxxcxx"
"bb"
"abcab"



// Time Complexity: O((2^n)*(n^2)).											// Solution 2 has better Time Complexity.
// Space Complexity: O(2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(3^n).
// Space Complexity: O(2^n).	
// This algorithm is Bit Manipulation+Map based. Here, there are 2^length varieties of subsequences can be formed and as the two subseq. can't have common 
// indices, we use binary rep for a subseq. where the indices of orig. string's char used in subseq. are set indicating set indices are used in subseq. We iter.
// over 2^ length possibilities and check if they are palindromes are not, if true we store length of subseq. in DP array else we set it to 0.
// Now, we iter. over all these possibilities and create disjoint indices(not used) using (allBitsMask^rep), now we have another subseq. of indices out of which
// only few combinations of those indices are palindromes which we iter. over by creating submasks of this disjoint subseq. rep and mutiply it's length with 
// dp[rep] and try to maximize the product of lengths.



// This link has detailed explanation for the Time Complexity analysis:
// https://cp-algorithms.com/algebra/all-submasks.html


// This link has detailed explanation for the solution: 
// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/discuss/1458289/Mask-DP







class Solution {
public:
    
    int findLongPalindromeSubsequence(string&s, int rep) {
        int i=0, j=s.length()-1, res=0;
        while(i<=j) {
            if((rep&(1<<i))==0) i++;
            else if((rep&(1<<j))==0) j--;
            else if(s[i]!=s[j]) return 0;
            else {
                res+=1+(i!=j);
                i++;j--;
            }
        }
        // cout<<"rep: "<<bitset<12>(rep)<<" and res: "<<res<<endl;
        return res;
    }
    
    int maxProduct(string s) {
        int n=s.length();
        int allBitsMask=(1<<n)-1;
        int dp[1<<n];
        memset(dp, 0, sizeof(dp));
        for(int rep=1;rep<=allBitsMask;rep++) {
            dp[rep]=findLongPalindromeSubsequence(s, rep);
            // cout<<"rep: "<<bitset<12>(rep)<<" and res: "<<dp[rep]<<endl;
        }
            
        
        int res=0;
        
        for(int rep=1;rep<(1<<n);rep++) {
            if(dp[rep]*min(maxLength, n-dp[rep])<res) continue;				// If the best case from below loop is still<res, we skip the loop.
																			// Pruning: min condition ensures disjoint subseq. len isn't more than max palin. subseq len from above.
            for(int mask=(allBitsMask^rep);mask;mask=((mask-1)&(allBitsMask^rep))) {// Iter. over all submasks of disjoint subseq. rep
                res=max(res, dp[rep]*dp[mask]);								// Trying to maximize the product of paindrome subseq. lengths.
            }
        }
        return res;															// Returning the max. product of disjoint palindrome subseq. lengths.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((2^n)*(n^2)).
// Space Complexity: O(2^n).	
// This algorithm is Bit Manipulation+Dynamic Programming based. This soution is same as the above one except that we get the max. subseq. length of disjoint
// indices rather than checking it's all submasks, which has higher Time Complexity. Once we get max. subseq. length of disjoint indices we multiply the
// products and try to maintain the max. product and return it at the end of iter.











class Solution {
public:
    
    
    int maxPalindromeLength(string&s, int rep) {							// Use DP to get max palin. subseq. length of indices set in rep.
        string t="";
        for(int i=0;i<s.length();i++) {
            if((rep&(1<<i))!=0) t+=s[i];
        }
        // cout<<"rep: "<<bitset<12>(rep)<<" and t: "<<t<<endl;
        
        int dp[t.length()][t.length()];
        memset(dp, 0, sizeof(dp));
        for(int i=t.length()-1;i>=0;i--) {
            dp[i][i]=1;
            for(int j=i+1;j<t.length();j++) {
                if(t[i]==t[j]) dp[i][j]=2+((i+1)==j?0:dp[i+1][j-1]);
                else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][t.length()-1];
    }
    
    int findLongPalindromeSubsequence(string&s, int rep) {
        int i=0, j=s.length()-1, res=0;
        while(i<=j) {
            if((rep&(1<<i))==0) i++;
            else if((rep&(1<<j))==0) j--;
            else if(s[i]!=s[j]) return 0;
            else {
                res+=1+(i!=j);
                i++;j--;
            }
        }
        // cout<<"rep: "<<bitset<12>(rep)<<" and res: "<<res<<endl;
        return res;
    }
    
    int maxProduct(string s) {
        int n=s.length();
        int allBitsMask=(1<<n)-1;
        int dp[1<<n];
        memset(dp, 0, sizeof(dp));
        for(int rep=1;rep<=allBitsMask;rep++) {
            dp[rep]=findLongPalindromeSubsequence(s, rep);
            // cout<<"rep: "<<bitset<12>(rep)<<" and res: "<<dp[rep]<<endl;
        }
            
        
        int res=0;
        
        for(int rep=1;rep<(1<<n);rep++) {
            if(dp[rep]*(n-dp[rep])<res) continue;// Need optimization/improvement as per the suggestion in the discussion forum.
            res=max(res, dp[rep]*maxPalindromeLength(s, (allBitsMask^rep)));// We get max. length of paindrome subseq. of disjoint indices.
            // for(int mask=(allBitsMask^rep);mask;mask=((mask-1)&(allBitsMask^rep))) {// We skip iter. over all submasks of disjoint indices.
            //     res=max(res, dp[rep]*dp[mask]);
            // }
        }
        return res;															// Returning the max. product of disjoint palindrome subseq. lengths.
    }
};

