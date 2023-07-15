/*
*
//****************************************2358. Maximum Number of Groups Entering a Competition.*****************************************

https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,6,12,7,3,5]
[8,8]
[2,2,2,2,2,2,2,2,2,2,2,2,2]
[5,4,3,6,5,4,3,2,4,5,7,6,5,4,8,7,6,5,6,7,5,4,3,2]



// Time Complexity: O(logn).												// n-size of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// n-size of the array.
// Space Complexity: O(1).	
// This algorithm is Greedy+Binary Search based. The condition for sum of values in group[i+1>group[i] can be satisfied easily by using sorted values in a 
// sequence.We satisfy length of group[i+1>group[i] by using inc. seq. length by 1 for every bigger group we create greedily. As the sum of values in a group
// doesn't become a matter of concern now, we are mainly focused on whether we have enough #nums that could help us in creating as many groups as possible. We 
// can see a monotonic nature in the feasibility of the #groups possible, if we can't make 'k' groups, we also can't make 'k+1' groups as it would need more 
// nums. We use binary search to find the greatest #groups that can be formed by given array of nums.






class Solution {
public:
    int maximumGroups(vector<int>& v) {
        int low=1, high=v.size();
        while(low<=high) {
            long long int mid=(low+high)/2;									// Testing if mid #groups are possible to form.
            long long int usedNums=(mid*(mid+1))/2;							// Calc. #nums required to form 'mid' #groups.
            if(usedNums<=v.size()) low=mid+1;								// If we can form 'mid' groups, we search in upper half.
            else high=mid-1;												// Else we search in lower half for lesser #groups.
        }
        return low-1;														// Returning the max. #groups that can be formed by using given nums.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(sqrt(n)).												// n-size of the array.
// Space Complexity: O(1).	
// This solution is Greedy+Iteration based. From the above explanation of sum of values in group is not a concern now and we greedily inc. the grp size by 1
// for every next greater group. So, we iter. inc. grp size by 1 in every iter. and add the grp size to total sum of grp sizes till now, if sum<=v.size(),
// we can form this group and we inc. the res and inc. the grp size by 1 for next group and repeat the process until we can't form a new group and return 
// #groups formed till then.








class Solution {
public:
    int maximumGroups(vector<int>& v) {
        int grps=0, curr=1, total=0;
        while(total+curr<=v.size()) {										// We iter. as long as we can form new groups of greater size.
            total+=curr;													// Adding curr. grp size to sum of all grp sizes.
            curr++;													 		// Inc. grp size by 1 for next grp.
            grps++;															// Inc. the #grps formed tracker by 1.
        }
        return grps;														// Returning the max. #groups that can be formed by using given nums.
    }
};



