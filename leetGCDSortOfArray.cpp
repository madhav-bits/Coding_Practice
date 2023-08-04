/*
*
//******************************************************1998. GCD Sort of an Array.******************************************************

https://leetcode.com/problems/gcd-sort-of-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[7,21,3]
[5,2,6,2]
[10,5,9,3,15]
[5,7,6,5,3,2,2,3,5,5,3,76,8,65,3,6,5,43,6,6,32,23,67,67,4,8,8,56,23,345,8,87,4,34,3]



// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2+nlogn).
// Space Complexity: O(n*).	
// This algorithm is GCD+Union-Find based. Here, we calc. GCD b/w every pair of nums, if their GCD>1, we join their resp. indices using Union-Find. Later we iter. over array 
// and check if orig. index and sorted value's orig. index are connected, if not we return false, if no such case observed during iter. we return true at the end of iter.







class Solution {
public:
    
    // void sieveEratosthenes(vector<bool>&dp) {
    //     for(int i=3;i*i<=dp.size();i++) {
    //         if(dp[i]==false) continue;
    //         for(int j=2*i;j<dp.size();j+=i) dp[j]=false;
    //     }    
    // }
    
    int getParent(vector<int>&parent, int node) {							// Time: O(n)
        if(parent[node]!=node) parent[node]=getParent(parent, parent[node]);
        return parent[node];
    }
    
    bool gcdSort(vector<int>& v) {
        // int maxm=max_element(v.begin(), v.end());
        // vector<bool>dp(maxm+1, true);
        // sieveEratosthenes(dp);
        vector<int>parent(v.size(),0), rank(v.size(),1);
        vector<pair<int,int>>u;
        for(int i=0;i<v.size();i++) {
            u.push_back({v[i],i});
            parent[i]=i;
        }
        sort(u.begin(), u.end());
        
        
        for(int i=0;i<v.size();i++) {										// Time: O(n^2*logn).
            for(int j=i+1;j<v.size();j++) {
                if(v[i]%v[j]==0 || v[j]%v[i]==0 || __gcd(v[i], v[j])>1) {	// Time: O(logn).
                    int parA=getParent(parent, i), parB=getParent(parent, j);
                    if(parA==parB) continue;
                    if(rank[parA]>rank[parB]) parent[parB]=parA;
                    else if(rank[parB]>rank[parA]) parent[parA]=parB;
                    else {
                        parent[parB]=parA;
                        rank[parA]++;
                    }
                }
            }
        }
        for(int i=0;i<v.size();i++) {
            // int parOrig=getParent(parent, i);
            // cout<<"i: "<<i<<" and parent: "<<parOrig<<endl;				// If orig. index and sorted value's orig. index aren't connected, we return false.
            if(getParent(parent, i)!=getParent(parent, u[i].second)) return false;
        }
        return true;														// If sorted state can be reached, return true.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+n*logm+m).
// Space Complexity: O(m).	
// This algorithm is observation and Optimization of Sieve of EratoSthenes+Union Find based. The major observation for this algo is that all nums which are connected 
// direclty/indirectly through other nums where a connection is defined b/w nums if they share a GCD >1 -> Common prime factor>1. As, we are dealing with GCDs of nums here, 
// we need to find factors of nums quickly. We use sieve to find the Smallest Prime Factor of all nums in the given range. As nums are connected if they have common prime 
// factor>1, so we join prime factors that we extract for a given num with the given num, so tha any other num which have any common prime factors would get connected with 
// curr. num as we process other other num, we establish the connection b/w common prime and other num. After the entire process, we check if the orig. and sorted arrays have 
// connected values in each index for them to move around to their sorted position. If we observe any index where they aren't connected we return false, in case of any issues 
// with any index,we return true.






// This link has good explanation for the below approach: 
// https://leetcode.com/problems/gcd-sort-of-an-array/discuss/1445180/C%2B%2BPython-Union-Find-and-Sieve-and-Sorting-Clean-and-Concise






class Solution {
public:
    
    void sieveEratosthenes(vector<int>&spf) {
        for(int i=0;i<spf.size();i++) spf[i]=i;								// Time: O(mlog(logm))=O(m). Default SPF for all nums.
        for(int i=2;1ll*i*i<spf.size();i++) {								// Iter. over nums, primes mark all their multiples for whom these are SPF.
            if(spf[i]!=i) continue;
            for(int j=i*i;j<spf.size();j+=i) {
                if(spf[j]==j) spf[j]=i;										// If SPF not yet found, then 'i' is the SPF.
            }
        }
        return ;
    }
    
    vector<int>getFactors(int num, vector<int>&spf) {						// Time: O(logn). Get factors for a given num.
        vector<int>res;
        while(num>1) {
            int div=spf[num];
            res.push_back(div);
            while(num%div==0) num/=div;
        } 
        return res;
    }
    
    vector<int>parent;
    
    int getParent(int node) {												// Time: O(m). Find parent for the given node.
        if(parent[node]!=node) parent[node]=getParent(parent[node]);
        return parent[node];
    }
    
    bool gcdSort(vector<int>& v) {
        int maxm=*max_element(v.begin(), v.end());							// Find the max. num/range of the given nums.
        vector<int>spf(maxm+1, -1);
        sieveEratosthenes(spf);												// Time: O(mlog(logm))=O(m). Calling Sieve to get the SPF all nums in the range.
        
        parent=vector<int>(maxm+1,0);
        for(int i=0;i<parent.size();i++) parent[i]=i;
        vector<int>rank(maxm+1,1);
        vector<int>u;
        for(int i=0;i<v.size();i++) u.push_back(v[i]);
        sort(u.begin(), u.end());											// Sort the copy array to get the sorted values.
        
        for(int num:v) {													// Time: O(n*logm)
            for(int n:getFactors(num, spf)) {								// Get factors of each num and join all the factors and the num.
                int parA=getParent(n), parB=getParent(num);
                if(parA==parB) continue;
                if(rank[parA]>rank[parB]) parent[parB]=parA;
                else if(rank[parB]>rank[parA]) parent[parA]=parB;
                else {
                    parent[parB]=parA;
                    rank[parA]++;
                }
            }
        }
        
        for(int i=0;i<v.size();i++) {										// Time: O(n)
            if(getParent(u[i])!=getParent(v[i])) return false;				// If an index's orig. value and sorted value aren't connected then the sorted state can't be reached.
        }
        return true;														// If sorted state can be reached, return true.
    }
};








//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+n*logm*logm+m).
// Space Complexity: O(m).
// This algorithm is GCD/Factorization+Union-Find based. Here, we slightly tweak the parent array, if a node isn't visited as part of calc. divisors yet, it's parent remains
// zero, else it either gets assigned to itself or a parent non-zero parent is assigned. So, we continue calc. divisors for a num as long as the reduced form of number hasn't 
// been visited in the past, thus we save lots of time.







class Solution {
public:
    
    vector<int>parent;
    int getParent1(int node) {												// Time: O(logm), finds parent of the node.
        if(parent[node]==0) return parent[node]=node;						// Node is visited first time, so we update the parent node value to itself.
        if(parent[node]!=node) parent[node]=getParent1(parent[node]);
        return parent[node];
    }
    
    void join(int num, int div) {											// Time: O(logm)
        parent[getParent1(num)]=getParent1(div);
        return ;
    }
    
    bool gcdSort(vector<int>& v) {
        int maxm=*max_element(v.begin(), v.end());
        
        parent=vector<int>(maxm+1,0);
        vector<int>u(v);
        sort(u.begin(), u.end());
        
        for(int num:v) {													// Time: O(n*logm*logm).
            int val=num;
            for(int div=2;parent[val]==0 && 1ll*div*div<=num;div++) {		// As long as val hasn't been visited prior.
                if(val%div==0) {
                    join(num, div);											// Join the divisors and the num.
                    // cout<<"joining num: "<<num<<" and div: "<<div<<endl;
                    while(val%div==0) val/=div;
                }
            }
            if(val!=1) join(num, val);										// Join the last divisor and num.
        }
        
        for(int i=0;i<v.size();i++) {
            if(getParent1(u[i])!=getParent1(v[i])) return false;
        }
        return true;														// If sorted state can be reached, return true.
    }
};

