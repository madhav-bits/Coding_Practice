/*
*
//**************************************************1399. Count Largest Group.***********************************************

https://leetcode.com/problems/count-largest-group/description/


Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 

Return how many groups have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
Example 3:

Input: n = 15
Output: 6
Example 4:

Input: n = 24
Output: 5
 

Constraints:

1 <= n <= 10^4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

34
12
200
1000
500


// Time Complexity: O(n).  
// Space Complexity: O(1).													// As maxm. sum of digits is 9*32=288.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).													// As maxm. sum of digits is 9*32=288.
// This algorithm is iteration based. Here, we iter. over all nums, we calc. sum of digits per each num. We also track the maxm. sum of
// digits. After the iter., we count #digits with maxm. sum and return it.







class Solution {
public:
    
    int getTotal(int num){													// Gives sum of digits for a number.
        int res=0;
        while(num!=0){
            res+=(num%10);
            num/=10;
        }
        return res;    
    }
    
    int countLargestGroup(int n) {
        unordered_map<int,int>m;											// Tracks sum of digits and #nums with that sum of digits.
        int maxSize=-1, groupsCount=-1;
        for(int i=1;i<=n;i++){												// Iter. over all nums.
            int total=getTotal(i);
            m[total]++;
            if(m[total]>maxSize) maxSize=m[total];							// Tracking maxm. sum of digits.
            // if(total>maxTotal){
            //     maxTotal=total;
            //     groupsCount=1;
            // }else if(total==maxTotal) groupsCount++;
        }
        int res=0;
        for(auto it=m.begin();it!=m.end();it++){							// Counting #nums with maxm. sum of digits.
            if(it->second==maxSize) res++;
        }
        return res;															// Return the count of nums with maxm. sum of digits.
    }
};
