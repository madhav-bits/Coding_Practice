/*
*
//******************************************2572. Count the Number of Square-Free Subsets.********************************************

https://leetcode.com/problems/count-the-number-of-square-free-subsets/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,4,4,5]
[1]
[1,1,1,1,1,1,1]
[1,2,1,1,1,2,1,2,3,5]
[3,23,2,22,2,3,5,6,6,3,7,7,6,3,3,19,23,26,7,12,19,27,25,6,8,8,6,4,4]



// Time Complexity: O(n*1024).												// n-#nums in the array.
// Space Complexity: O(n+n*1024).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*1024).												// n-#nums in the array.
// Space Complexity: O(n+n*1024).	
// This algorithm is Dynamic Programming and DP based. Here, while forming subsets we have to pick them in a way such that no two nums in subarr have a common
// factor. Other observation is that range of nums is small, so we calc. prime factors of each num and mark it's prime factor on rep and store in array. When 
// checking if two nums have any common prime factor, we simply do (rep[i]&rep[num2])==0, this means no common prime factor, we set rep[num]=-1 for nums who
// have multiple prime factors of same value. We use Knapsack approach to iter. over nums in the array and pick/skip each index, but since the range of nums
// is small the rep of any subset would be in the range [0, 1024] as there are only 10 prime factors for nums in [1,31]. We use dp array to avoid recalc., when
// at an recursive call with dp[index][rep], we add #subsets that we can from index+1 with same rep and #substrs that we can from index+1 with 
// rep&primeRep[v[i]] and return this sum to parent call. After the entire process, we return dp[0][0] as this is the start of the process, we remove 1 from the 
// total as we are forming non-empty substrs, there would be 1 instance where we haven't picked any num, so we remove that instance and return res.


// Doing Knapsack would blow Time Complexity out of proportions 2^n=2^1001, but since we have limited prime factors to take care of we use rep of subset to 
// prevent revisits and bring down Time Complexity.



// dp[index][rep] stores #subsets that we can form using indices>= index on top of preloaded subset rep(formed by using earlier indices). 



// This discussion forum link has good explanation for the approach:
// https://leetcode.com/problems/count-the-number-of-square-free-subsets/discuss/3203707/DP-%2B-Bitmask-(C%2B%2B)-Prime-factorization









class Solution {
public:
    int mod=1000000007;
    vector<vector<int>>dp;
    
    int formSubsets(int index, int rep, vector<int>&v, vector<int>&primeRep) {
        if(index==v.size()) return 1;										// Terminating condition, as we formed subset by now.
        if(dp[index][rep]!=-1) return dp[index][rep];						// If already calc. prevent recalc.
        long long int res=0;
        res+=formSubsets(index+1, rep, v, primeRep);						// Skip using curr. num.
        // cout<<"index: "<<index<<" and skip res: "<<res<<endl;
        if(primeRep[v[index]]!=-1 && (rep&primeRep[v[index]])==0)			// If prev. nums in curr. subset and curr. num don't have common factors.
            res+=formSubsets(index+1, rep|primeRep[v[index]], v, primeRep);	// We update rep of curr. subset and call dfs on next index with new rep.
        // cout<<"index: "<<index<<" and after using res: "<<res<<endl;
        res=res%mod;
        dp[index][rep]=res;													// Update dp with #substrs that we can form with 'rep' from curr. index. 
        return res;
    }
    
    int squareFreeSubsets(vector<int>& v) {
        vector<int>primes({2,3,5,7,11,13,17,19,23,29});						// Primes<31.
        vector<int>primeRep(31,-1);
        for(int i=1;i<=30;i++) {											// Calc. prime factors for each of the nums in the range.
            int rep=0, bit=1, temp=i;
            bool valid=true;
            for(int j=0;j<primes.size() && primes[j]<=i;j++) {				// We iter. over primes for each num and check divisibility.
                while(temp%primes[j]==0) {
                    if((rep&bit)!=0) {
                        valid=false;
                        break;
                    }
                    temp/=primes[j];
                    rep|=bit;												// Marking curr. prime as factor of curr. num.
                }
                bit<<=1;
            }
            if(!valid) continue;
            // cout<<"i: "<<i<<" and rep: "<<bitset<10>(rep)<<endl;
            primeRep[i]=rep;												// Storing rep of prime factors for curr. num.
        }

        dp=vector<vector<int>>(1001, vector<int>(1024, -1));
        int res= formSubsets(0, 0, v, primeRep);							// DSF call to form subsets.
        res=(res-1+mod)%mod;												// Removing empty subset case.
        return res;															// Returning #subsets that we can form from '0' index.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*1024).												// n-#nums in the array.
// Space Complexity: O(n+n*1024).
// This solution is Dynamic Programming and Factorization based. This soution is same as above on except that we use Bottom-Top build approach.



// dp[index][rep] stores #subsets that we can form using indices>= index on top of preloaded subset rep(formed by using earlier indices). 






class Solution {
public:
    int mod=1000000007;

    int squareFreeSubsets(vector<int>& v) {
        vector<int>primes({2,3,5,7,11,13,17,19,23,29});
        vector<int>primeRep(31,-1);
        for(int i=1;i<=30;i++) {											// Calc. prime factors for each of the nums in the range.
            int rep=0, bit=1, temp=i;
            bool valid=true;
            for(int j=0;j<primes.size() && primes[j]<=i;j++) {
                while(temp%primes[j]==0) {
                    if((rep&bit)!=0) {
                        valid=false;
                        break;
                    }
                    temp/=primes[j];
                    rep|=bit;
                }
                bit<<=1;
            }
            if(!valid) continue;
            // cout<<"i: "<<i<<" and rep: "<<bitset<10>(rep)<<endl;
            primeRep[i]=rep;
        }
        
        int dp[1001][1024];
        memset(dp, 0, sizeof(dp));
        for(int j=0;j<1024;j++) dp[v.size()][j]=1;							// Base values when we reached end of array forming subsets.
        for(int i=v.size()-1;i>=0;i--) {
            for(int j=0;j<1024;j++) {										
                dp[i][j]=dp[i+1][j];										// If we skip curr. index.
                if(primeRep[v[i]]!=-1 && (j&primeRep[v[i]])==0) 			// If we add curr. num to this rep.
                    dp[i][j]=(0ll+dp[i][j]+dp[i+1][j|primeRep[v[i]]])%mod;
            }    
        }
        dp[0][0]=(dp[0][0]-1+mod)%mod;
        return dp[0][0];													// Returning #subsets that we can form from '0' index.
    }
};

