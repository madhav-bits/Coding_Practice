/*
*
//******************************************************2557. Maximum Number of Integers to Choose From a Range II.***********************************************

https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,6]
6
4
[4,3,5,6]
7
18
[1,5]
5
6
[1,2,3,4,5,6,7]
8
1
[1,2,3,4,5,5,6,7]
8
1
[6]
7
50
[3,5,9,14,7,10,4]
20
100
[87,193,85,55,14,69,26,133,171,180,4,8,29,121,182,78,157,53,26,7,117,138,57,167,8,103,32,110,15,190,139,16,49,138,68,69,92,89,140,149,107,104,2,135,193,87,21,194,192,9,161,188,73,84,83,31,86,33,138,63,127,73,114,32,66,64,19,175,108,80,176,52,124,94,33,55,130,147,39,76,22,112,113,136,100,134,155,40,170,144,37,43,151,137,82,127,73]
1079
87
[1,4,5]
5
5



// Time Complexity: O(nlogn+logm*logn).  																		// n-#banned nums, m-range of allowed nums.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+logm*logn).																			// n-#banned nums, m-range of allowed nums.
// Space Complexity: O(1).	
// This algorithm is Greedy+ Binary Search based. Here, we remove the duplicates in the banned nums first. Here, we greedily pick the least valued allowed nums so that we can get max. nums resulting in
// least total. As the range of nums in large, we can do a binary search over the range to find the max. of nums whose total<=maxSum. We calc. prefixSum for the unique banned nums. For the mid in
// binary search, we calculate the total of all nums till that number(mid). We do a upper_bound to find the next greater num. to mid, move to it's prev. banned num, we will remove the sum of all banned 
// nums till then from the total_till_mid, if the result >=0, then this mid can be highest of the range of nums that satisfies the condition. So, we will focus on the upper half to find an even bigger
// mid that satisfies the condition, else we will focus on the lower half. At the end of iter., we fill find the number of banned nums <=result and we will remove the #such banned nums from the res
// and return the res.







class Solution {
public:
    
    bool isPossible(int nums, vector<int>&banned, vector<long long int>&prefixSum, long long int maxSum) {
        long long int total=(1ll*nums*(nums+1))/2;														// Calc. total of nums till mid.
        int ind=upper_bound(banned.begin(), banned.end(), nums)-banned.begin();							// Finding the index of banned nums>curr. mid.
        ind--;																							// We move to it's prev. index.
        
        total-=(ind==-1)?0:prefixSum[ind];																// Removing the banned nums prefixSum from the total of nums till mid.
        return total<=maxSum;
    }
    
    int maxCount(vector<int>& banned, int cap, long long maxSum) {
        
        vector<int>::iterator it;
        sort(banned.begin(), banned.end());																// Sorting the banned nums.
        it=unique(banned.begin(), banned.end());														// Removing the duplicate banned nums.
        banned.resize(it-banned.begin());
        
        vector<long long int>prefixSum;
        prefixSum.assign(banned.begin(), banned.end());													// Calc. the prefixSum for the banned nums.
        for(int i=1;i<banned.size();i++) {
            prefixSum[i]+=prefixSum[i-1];
        }
        int low=1, high=cap, res=-1;
        
        while(low<=high) {
            int mid=(low+high)/2;
            bool possible=isPossible(mid, banned, prefixSum, maxSum);									// Checking if the total of nums till mid would be <=maxSum.
            
            if(possible) {
                res=mid;																				// Marking the mid as res, we will focus on upper half.
                low=mid+1;
            }else high=mid-1;																			// Doesn't satisfy the total<=maxSum condition, we will focus on the lower half.
        }
        res-=upper_bound(banned.begin(), banned.end(), res)-banned.begin();								// Removing the banned nums <=res and returning the #nums whose total<=maxSum.
        return res;																						// Returning the #nums whose total<=maxSum
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+m).																			// n-#banned nums, m-range of allowed nums.
// Space Complexity: O(1).	
// The solution is Greedy based. We sort the banned nums array first, we greedily keep on picking the least possible allowed values, as long as their total<=maxSum, we skip banned nums
// by tracking the next greatest banned nums in sorted banned nums array. The instance the total>maxSum, we exit the iter and return the total #nums picked till then.
// As we are iterating over a very large range of values, the time complexity would be large, so not advisable.






class Solution {
public:
    int maxCount(vector<int>& banned, int cap, long long maxSum) {
        sort(banned.begin(), banned.end());
        int j=0, res=0;
        long long int currTotal=0;
        for(int i=1;i<=cap;i++) {
            if(j<banned.size() && banned[j]==i) {														// If the curr. num is banned, we skip it.
                while(j<banned.size() && banned[j]==i) j++;
                continue;
            }
            if(currTotal+i>maxSum) break;																// If currTotal+i>maxSum, any next number would also make the sum>maxSum, so we break the iter.
            currTotal+=i;																				// Inc. the total by curr. num.
            // cout<<"num: "<<i<<" and currTotal: "<<currTotal<<endl;
            res++;																						// Inc. picked nums count by one as curr. num is included.
        }
        return res;																						// Returning the #picked nums whose total<=maxSum.
    }
};



