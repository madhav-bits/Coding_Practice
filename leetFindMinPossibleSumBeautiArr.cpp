/*
*
//****************************************2834. Find the Minimum Possible Sum of a Beautiful Array.**************************************

https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
3
3
6
5
6
5
7
5
9
5
13
5
17
6
12
6
13
6
16
6
17
1
1
3
3
10102
45
19283
48495
100000
100000
100000
1
92924
39393
39393
92924



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation+Greedy based. For us to get least sum of nums, we have to greedily pick the smallest nums from starting 1. As sum of two diff.
// nums in the arr can't be equal to target,  we only take the first half of [1,target-1] and skip the second half as they can be paired with their complement
// in first half leading to a total of target. As we are picking nums greedily we chose first half over second half. If 'n'<=target/2, we use n first num, if 
// greater, we pick rem. nums from [target,INT_MAX] as we can't pick nums second half(target/2, target). We use func. to calc. sum of nums in the range and
// return the total of nums in the selected range.






class Solution {
public:

    long long int getSum(int start, int length) {							// Calc. sum of nums in the range.
        int end=start+length-1;
        return (1ll*length*(start+end))/2;
    }

    long long minimumPossibleSum(int n, int target) {
        long long int res=0;
        if(n<=target/2) return getSum(1,n);									// We pick req. nums in first half of [1, target].
        return getSum(1,target/2)+getSum(target, n-target/2);				// Returning sum of nums in first half of [1,target] and rem. nums range.
    }
};

