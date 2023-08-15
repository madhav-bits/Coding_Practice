/*
*
//**********************************************2818. Apply Operations to Maximize Score.********************************************

https://leetcode.com/problems/apply-operations-to-maximize-score/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[8,3,9,3,8]
2
[19,12,14,6,10,18]
3
[20,18,25,3,7,9,12,14,10,9]
5



// Time Complexity: O(n*sqrt(m)+n+nlogn).										//n-#ints in the array, m-maxm. int in the array.
// Space Complexity: O(m+n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*sqrt(m)+n+nlogn).										//n-#ints in the array, m-maxm. int in the array.
// Space Complexity: O(m+n).	
// This algorithm is Priority Queue+Factorization+Stack based. Here, we first calc. the factors of a number which haven't been calc. before using prime factors
// until sqrt(num) and count the unique factors count. As, a number can be used in those many substrings in which curr. num has the maxm. #factors, we use 
// stack to figure out how many adj. indices to the left and right, our v[i] would have max. prime factors count. To the left we stop once we find a num with 
// primeCount>=primeCount[v[i]], on the right we stop once we find a number with primeCount>primeCount[v[i]]. While popping indices from stack, we calc. 
// #substrs that curr. num would have max. primeCount and push the {num, #substrs} into PQ, we do the same with all indices in the array. We now take take 
// vals from PQ with highest val having highest priority, we decided how many instances of curr. val to use based on rem. oper and #substrs curr. num has to 
// use, we use the minm of the both and cal. power of our number to the exp of minm of both values, we repeat this process until either oper./nums are exhausted.






class Solution {
public:
    int getPrimeFactorCount(int num) {										// Calc. #uniq. prime factors for a given number.
        int temp=num;
        int res=(temp%2==0);												// Counting whether 2 is a factor of given number.
        while(temp%2==0) temp/=2;
        
        for(int i=3;i*i<=num;i+=2) {
            if(temp%i!=0) continue;
            res++;															// Counting  prime factor if it divides curr. num
            while(temp%i==0) temp/=i;
        }
        if(temp>1) res++;
        return res;															// Returning #uniq. prime factors for a given number.
    }
    
    int pwr(int base, int exp) {											// Calc. value of power(base, exp).
        int res=1, mod=1000000007;
        while(exp>0) {
            if(exp%2==1) res=(1ll*res*base)%mod;
            exp>>=1;
            base=(1ll*base*base)%mod;
        }
        return res;    
    }
    
    int maximumScore(vector<int>& v, int k) {
        int maxm=*max_element(v.begin(), v.end()), res=1, mod=1000000007;
        int pfCount[maxm+1];
        memset(pfCount, -1, sizeof(pfCount));
        
        stack<int>st;
        priority_queue<pair<int, long long int>>pq;
        for(int i=0;i<=v.size();i++) {
            if(i<v.size() && pfCount[v[i]]==-1) pfCount[v[i]]=getPrimeFactorCount(v[i]);// If primefactors not counted, we calc. it now.
            // if(i<v.size()) cout<<"num: "<<v[i]<<" and pfCount: "<<pfCount[v[i]]<<endl;
            while(!st.empty() && 
                  (i==v.size() || pfCount[v[st.top()]]<pfCount[v[i]])) {// Pop all nums which have smaller prime count than curr. number.
                int ind=st.top();
                st.pop();
                int left=ind-(st.empty()?-1:st.top()), right=i-ind;			// Calc. #substrs in which pop val has greatest primeCount.
                pq.push({v[ind], 1ll*left*right});							// Adding {num, #substrs num has max. factors} pair to PQ.
            }
            st.push(i);														// Pushing curr. index into PQ.
        }
        
        while(k>0) {
            long long int used=min(0ll+k, pq.top().second);					// Calc. how many powers of base can we use.
            // cout<<"base: "<<pq.top().first<<" and dup: "<<used<<endl;
            res=(1ll*res*pwr(pq.top().first, used))%mod;					// Calc. power of {curr. base/number, #substrs} and add it to res.
            k-=used;
            pq.pop();														// Remove the curr. number from the top of PQ.
        }
        return res;															// Returning the max. score after K oper.
    }
};

