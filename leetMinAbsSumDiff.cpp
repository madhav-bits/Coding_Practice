/*
*
//******************************************************1818. Minimum Absolute Sum Difference.******************************************************

https://leetcode.com/problems/minimum-absolute-sum-difference/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,7,5]
[2,3,5]
[2,4,6,8,10]
[2,4,6,8,10]
[1,10,4,4,2,7]
[9,3,5,1,7,4]



// Time Complexity: O(nlogn+nlogn)=O(nlogn).								// nlogn for sorting+nlogn for binary search in every step of iteration.					
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+nlogn)=O(nlogn).								// nlogn for sorting+nlogn for binary search in every step of iteration.					
// Space Complexity: O(n).	
// This algorithm is Sorting based. Here, as we have to get closest value to v[i] at every step in u-array, we store the u-array in temp array and sort to be able to perform
// Binary Search on it. For every iter., we do binary search to find the value in u-array which is closest to v[i], we calc. the dist to the closest greater and lesser value
// and try to maximize the diff b/w orig. diff and gap b/w modified value and v[i], so that when we substract this value from the cumulative diff of pairs, we get min. 
// abs. diff.







class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& u, vector<int>& v) {
        vector<int>arr(u);
        sort(arr.begin(), arr.end());										// Storing u-array to be able to perform Binary Search on it.
        int res=0, mod=1000000007, maxDec=0;
        for(int i=0;i<u.size();i++) {
            int diff=abs(u[i]-v[i]);										// Calc. diff b/w curr. pair.
            res=(res+diff)%mod;												// Adding curr. pair dist to res.
            int ind=upper_bound(arr.begin(), arr.end(), v[i])-arr.begin();	// Finding closest greater value to v[i].
            if(ind<u.size() && diff-(arr[ind]-v[i])>maxDec) maxDec=diff-(arr[ind]-v[i]);// Calc. diff b/w closest greater u val and v[i] and maximizing the change after modify
            // if(ind<u.size()) cout<<"curr. num: "<<v[i]<<" and greater val: "<<arr[ind]<<endl;
            if(--ind>=0 && diff-(v[i]-arr[ind])>maxDec) maxDec=diff-(v[i]-arr[ind]);// Calc. diff b/w closest lesser u val and v[i] and maximizing the change after modify
            //  if(ind>=0) cout<<"curr. num: "<<v[i]<<" and greater val: "<<arr[ind]<<endl;
            // cout<<"maxDec: "<<maxDec<<endl;
        }
        res=(res-maxDec+mod)%mod;											// Dec. the cumulative diff by maxDec
        return res;															// Returning the min. abs sum diff
    }
};

