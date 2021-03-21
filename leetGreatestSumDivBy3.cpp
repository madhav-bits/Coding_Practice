/*
*
//******************************************************1262. Greatest Sum Divisible by Three.*****************************************************

https://leetcode.com/problems/greatest-sum-divisible-by-three/


Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

Constraints:

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[3,6,5,1,8]
[4]
[1,2,3,4,4]
[3,6,9,15,18,23,1,1,1]
[3,6,9,12,34,2,2,2]
[2,3,36,8,32,38,3,30,13,40]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we calc. total of all nums. If the total%3==1, then we have to remove nums contributing to remainder, so
// remove min num. which gives remainder 1 or remove two nums where each gives remainder of 2 adding to remainder 1, we pick the minm. of these two
// possibilities and remove it from the total. We do the same with total%3==2 and return the final total. If the total%3==0, we return the total.











class Solution {
public:
    int maxSumDivThree(vector<int>& v) {
        int total=0;
        int min11=10001, min12=10001, min21=10001, min22=10001;
        for(int num:v){
            total+=num;
            if(num%3==1){													// If curr. num. give rem of 1.
                if(num<=min11){												// If curr. num<=least num. with rem 1.
                    min12=min11;											// Updating second least num with rem 1.
                    min11=num;
                }else if(num<min12) min12=num;								// If curr. num is <second least num, we update it.
            }else if(num%3==2){												// If curr. num gives rem of 2.
                if(num<=min21){
                    min22=min21;
                    min21=num;
                }else if(num<min22) min22=num;
            }
        }
        // cout<<"total: "<<total<<endl;
        // cout<<"min11: "<<min11<<" and min12: "<<min12<<endl;
        // cout<<"min21: "<<min21<<" and min22: "<<min22<<endl;
        if(total%3==0) return total;
        if(total%3==1){														// If total%3==1, we remove minm. nums contributing to rem 1.
            if(min11<min21+min22) total-=min11;
            else total-=(min21+min22);	
        }else{																// If total%3==2, we remove minm. nums contributing to rem 2.
            if(min21<min11+min12) total-=min21;
            else total-=(min11+min12);
        }
        return total;														// Returning the total whose rem is 0.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we calc. total of all nums. If the total%3==1, then we have to remove nums contributing to remainder, so
// remove min num. which gives remainder 1 or remove two nums where each gives remainder of 2 adding to remainder 1, we pick the minm. of these two
// possibilities and remove it from the total. We do the same with total%3==2 and return the final total. If the total%3==0, we return the total.








class Solution {
public:
    int maxSumDivThree(vector<int>& v) {
        
        vector<int>dp(3,0);													// Stores the max. sum that gives that index valued remainder.
        for(int num:v){
            vector<int>temp=dp;												// Temp DP array to store maxm. totals and avoid overlapping update and reads.
            for(int val:temp){
                dp[(val+num)%3]=max(dp[(val+num)%3], val+num);				// Updating totals that gives index valued remainders involving curr. num.
            }
        }
        return dp[0];														// Returning max. total that gives remainder 0.
    }
};

