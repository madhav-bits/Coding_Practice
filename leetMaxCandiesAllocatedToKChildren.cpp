/*
*
//********************************************2226. Maximum Candies Allocated to K Children.*********************************************

https://leetcode.com/problems/maximum-candies-allocated-to-k-children/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,8,6]
3
[2,5]
11
[4,3,5,6,7,87,85,31,32,39,46,57,8,8,7,267,78,5,43,2,37,100,31,100,222,27,2,33,4,45,77,55,44,35,77,6,74,6]
200



// Time Complexity: O(n*logm).												//n-length of the array, m-sum of vals in the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*logm).												//n-length of the array, m-sum of vals in the array.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, for every mid value in bin. search over #candies per child, we calc. #child we can provide 'mid' #candies, 
// if calc. #child>=k, we can provide mid #candies, so we search in upper half while storing the mid value in res, else we search in lower half hoping we 
// can serve a smaller #candies to k children. We return res at the end of iter. 
// We check for two base conditions, if sum of all candies<k, then we return 0 as chocolates are lesser than chidlren, so we given them 0 chocolates.
// If total chocolates=k, we return 1 directly and avoid as every heap can be broken into a single chocolate sub heap.







class Solution {
public:
    int maximumCandies(vector<int>& v, long long k) {
        long long int total=accumulate(v.begin(), v.end(), 0ll);
        if(total<k) return 0;												// If total #chocolates<children, we give them 0 chocolate each.
        if(total==k) return 1;												// If total #chocolates=children, we give them 1 chocolate each.
        int res=-1, low=1, high=total/k;
        while(low<=high) {
            int mid=(low+high)/2;
            long long int rep=0;
            for(int&num:v) rep+=num/mid;									// Calc. #children, where we can serve curr. #candies to everyone.
            if(rep>=k) {													// If calc. #children>=target #children, we search in upper half.
                res=mid;													// Storing the mid in res.
                low=mid+1;
            }																// If curr. #chocolate doesn't meet req. children count, search in lower half.
            else high=mid-1;
        }
        return res;															// Returning max. #chocolates each child can get equally.
    }
};

