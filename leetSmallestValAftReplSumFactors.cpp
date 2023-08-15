/*
*
//**************************************2507. Smallest Value After Replacing With Sum of Prime Factors.***************************************

https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
15
20
100000
3939
48449
99999
97
84837
4



// Time Complexity: O(sqrt(n)).												// Solution 2 has best Time and Space Complexities.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*sqrt(n)).
// Space Complexity: O(n).	
// This algorithm is Sieve + Smallest Prime Factorization based. Here, I used a variation of sieve to get Smallest Prime Factors for all nums in the range, I 
// tried this to avoid iter. over all nums in the range and checking whether if they are factors of given number. I know that doing so would still be a
// better option, but I wanted to try SPF Sieve, despite knowing it would be redudant to calc. SPF for all nums in the range, thereby effectively inc. Time
// Complexity a lot. 
// We run the process until the number to be processed is a prime number, because sum of it's factors is=number, so we stop the process. For every number, we
// divide it by it's spf leading to modified number and we continue in the loop until modified number shrinks to 1. We add sum of factors along the way and 
// return the sum of factors.








class Solution {
public:
    
    void findSmallestPrimeFactors(vector<int>&spf) {
        int num=spf.size()-1;
        for(int i=2;i*i<=num;i++) {
            if(spf[i]!=-1) continue;
            for(int j=i*i;j<=num;j+=i) {
                if(spf[j]==-1) spf[j]=i;
            }
        }    
        return ;
    }
    
    
    int getSumOfFactors(vector<int>&spf, int num) {
        int res=0;
        
        while(spf[num]!=-1) {												// We continue the process until given number shrinks to 1.
            res+=spf[num];
            num/=spf[num];													// Dividing given num by it' spf.
            
        }
        return res+num;														// Returning sum of it's factors.
    }
    
    int smallestValue(int n) {
        vector<int>spf(n+1,-1);
        findSmallestPrimeFactors(spf);										// Calc. SPF of all nums in the given range of nums.
        
        while(spf[n]!=-1) {													// Continue until num becomes a prime number.
            int total=getSumOfFactors(spf, n);
            // cout<<"n: "<<n<<" and total: "<<total<<endl;
            n=total;														// Setting number equal to sum of factors of prev. number.
            if(n==4) return 4;												// Corner case.
        }
        return n;															// Returning the final number in the process.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(sqrt(n)).
// Space Complexity: O(1).	
// This algorithm is Factorization based. Here, for every num in the process, we iter. over nums from [2,sqrt(num)] to find it's factors and divide the number,
// add the factors to res, we add any remaining part of the number to res, if it's >1 as this could be last prime factor>sqrt(n) that divides given number,
// we also get this case in case of prime number. If we observe that the given number and sum of it's factors is the same, that means we reached end of process
// and we return the number.







class Solution {
public:
    
    int smallestValue(int n) {
        while(n!=-1) {
            int total=0, temp=n;
            while(temp%2==0) {												// Dividing by 2, if it's a factor.
                total+=2;
                temp/=2;
            }
            for(int i=3;temp!=1 && i*i<=n;i+=2) {							// Iter. over possible range of factors.
                while(temp%i==0) {											// If 'i' is a prime factor, we add it to res.
                    total+=i;
                    temp/=i;
                }
            }
            if(temp>1) total+=temp;											// If n is a prime number, or temp could be last prime factor>sqrt(n) of 'n'.
            if(total==n) return total;										// If sum of factors =given number, we stop the process.
            n=total;														// Else we make the sum of factors as new number for next iter.
        }
        return n;															// Returning the final number in the process.
    }
};

