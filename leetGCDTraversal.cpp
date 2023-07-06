/*
*
//******************************************************2709. Greatest Common Divisor Traversal.******************************************************

https://leetcode.com/problems/greatest-common-divisor-traversal/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,6]
[3,9,5]
[4,3,12,8]
[4,6,5,7,12,15,18,20,24,26,30,42]
[10]
[42,52,18,60,55,15,60,14,91,35,84,78,60,39,70,44,78,30,65,42,66,70,35,30,22]



// Time Complexity: O(nlog(log(n))+m*logn+m).								// Time taken for Sieve+factorization of nums+Union-Find step.
// Space Complexity: O(n).													// n-range of nums in array, m- arr. size.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

// The first one is a slower algorithm, second one is a much faster alogrithm.
//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlog(log(n))+m*logn+m).								// Time taken for Sieve+factorization of nums+Union-Find step.
// Space Complexity: O(n).													// n-range of nums in array, m- arr. size.
// This algorithm is Sieve of Eratosthenes method, Union-Find based. First, we do sieve for max. number and mark and collect all the prime numbers. While 
// iterating the array, for every number, we iter. over primes and gather all it's factors from getFactors function.

// This was slow as we are running getFactors function for every number in the array, which was addressed in the second solution.
// One other solution is present in the commented section of the leetcode submissions.


// This is discussion forum link for this solution:
// https://leetcode.com/problems/greatest-common-divisor-traversal/discuss/3568580/Union-Find





class Solution {
public:
    
    int getParent(vector<int>&parent, int node) {
        if(parent[node]!=node) return parent[node]=getParent(parent, parent[node]);
        return node;
    }
    
    vector<int>sieveOfEratosthenes(vector<bool>&isPrime) {					// To gather the prime numbers till the max. number in the array.
        vector<int>res;
        int cap=isPrime.size();
        for(int i=2;i*i<cap;i++) {
            if(isPrime[i]==false) continue;
            for(int j=i*i;j<cap;j+=i) {
                isPrime[j]=false;
            }
        }
        for(int i=2;i<cap;i++) {
            if(isPrime[i]) res.push_back(i);								// Gather prime numbers after the sieve process.
        }
        return res;
    }
       
    vector<int>getFactors(int num, vector<int>primes) {
        vector<int>res;
        for(int prime:primes) {												// Iter. over primes to find factors of given number.
            if(prime*prime>num) break;										// Pruning to prevent unnecc. iter.
            if(num%prime==0) {
                res.push_back(prime);										// Gather prime factors.
                while(num%prime==0) num/=prime;
            }
        }
        if(num>1) res.push_back(num);										// If remainder still left, that would be largest prime factor.
        return res;
    }
    
    bool canTraverseAllPairs(vector<int>& v) {
        if(v.size()==1) return true;										// Base case.
        sort(v.begin(), v.end());
        if(v[0]==1) return false;											// Base case.
        vector<bool>isPrime(100001, true);
        vector<int>primes=sieveOfEratosthenes(isPrime);
    //     vector<int>primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    // 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
    // 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 
    // 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
        
        vector<int>parent(100001, -1), rank(100001, 1), indices(100001,-1);
        for(int i=0;i<parent.size();i++) parent[i]=i;
        int grps=v.size();
        for(int i=0;i<v.size();i++) {
            if(i>0 && v[i]==v[i-1]) {
                int parA=getParent(parent, i-1);
                parent[i]=parA;
                rank[parA]++;
                grps--;
                if(grps==1) return true;
                continue;
            }
            int num=v[i];
            for(int factor:getFactors(v[i], primes)) {
                if(indices[factor]!=-1) {
                    int parA=getParent(parent, i), parB=getParent(parent, indices[factor]);// We join the curr. index and the first index where this factor appeared.
                    if(parA==parB) continue;
                    grps--;
                    if(grps==1) return true;								// If the #grps is 1, all numbers are connected, so we return true.
                    if(rank[parA]>rank[parB]) parent[parB]=parA;
                    else if(rank[parA]<rank[parB]) parent[parA]=parB;
                    else {
                        parent[parB]=parA;
                        rank[parA]++;
                    }
                } else indices[factor]=i;									// We are assigning the index of the number to the factor.
                
            }
        }
        return false;
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(((N*N)/lnN)+m).											// (N/lnN) is estimate of #primes till N, N-range of nums, m-size of array.
// Space Complexity: O(N).	
// This algorithm is Sieve of Eratosthenes, Union-Find based. As the time complexity became higher because of repetitive getFactors call, we avoid that by 
// modifying Sieve process and apply Union-Find while marking the multiples of prime numbers. In this way all the numbers present in the array and their 
// factors are connected. We avoid connecting those numbers which aren't present in the array, as they can't help in traversing b/w indices.
// After sieve, we iter. over nums in the array and get their core parent, if they have more than 1 core parent, we return false.











class Solution {
public:
    
    int getParent(vector<int>&parent, int node) {
        if(parent[node]!=node) return parent[node]=getParent(parent, parent[node]);
        return node;
    }
    
	// Sieve is modified, here, we mark the nums as composite and also join prime factors and it's multiples, so we dont prune the process with conditions 
	// like i*i<=cap, j=i*i which are effective while marking composite numbers.
    void sieveOfEratosthenes(vector<bool>&isPrime, vector<int>&parent, vector<int>&rank, vector<bool>&isPresent) {
        vector<int>res;
        int cap=isPrime.size();
        for(int i=2;i<cap;i++) {											// Iter. till the max. number in the array.
            if(isPrime[i]==false) continue;									// Ignoring composite base factors.
            for(int j=2*i;j<cap;j+=i) {
                isPrime[j]=false;
                if(isPresent[j]==false) continue;							// If curr. multiple isn't present in array, we won't join with base factor.
                
                int parA=getParent(parent, i);								// Joining base factor and it's multiples.
                int parB=getParent(parent, j);
                if(parA==parB) continue;
                if(rank[parA]>rank[parB]) parent[parB]=parA;
                else if(rank[parB]>rank[parA]) parent[parA]=parB;
                else {
                    parent[parB]=parA;
                    rank[parA]++;
                }
                
            }
        }
        return ;
    }
       
    bool canTraverseAllPairs(vector<int>& v) {
        if(v.size()==1) return true;
        int maxm=*max_element(v.begin(), v.end());
        vector<int>parent(maxm+1, -1), rank(maxm+1, 1);
        vector<bool>isPrime(maxm+1, true), isPresent(maxm+1,false);
        for(int&num:v) isPresent[num]=true;									// Marking the nums. which are in the array.
        if(isPresent[1]) return false;										// Base case.
        for(int i=0;i<parent.size();i++) parent[i]=i;
        int grps=v.size();
        sieveOfEratosthenes(isPrime, parent, rank, isPresent);				// Sieve function to join all nums which have common factors and can be traversed.
        
        int prnt=-1;
        for(int&num:v) {													// Iter. over nums of the array.
            int currParent=getParent(parent, num);							// Finding core. parent of the curr. number.
            if(prnt==-1) prnt=currParent;									// Storing the first core parent.
            else if(prnt!=currParent) return false;							// If two diff. core parents exist, we return false.
        }
        return true;														// We return true as all nums are connected.
    }
};

