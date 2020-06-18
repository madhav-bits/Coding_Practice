/*
*
//******************************************************1390. Four Divisors.******************************************************

https://leetcode.com/contest/weekly-contest-181/problems/four-divisors/


Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
 

Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked with the examples provided in the question.



// Time Complexity: O(n*(m^0.5)).						// n- nums in arr, m-highest prime in the arr., arr filled with high. prime val.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*(m^0.5)).						// n- nums in arr, m-highest prime in the arr., arr filled with high. prime val.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iter. over all nums in the arr. For every num., we find all its divisors, if the #divisors
// are 4, we return the sum of divisors for that num., we repeat the same process for all nums, we return the sum of divisors at the 
// end of iter.







class Solution {
public:
    
    int getDivisors(int&num){												// Counting #divisors for each num.
        if(num<=2) return 0;
        int total=0, divs=0;
        for(int div=1;div*div<=num;div++){									// Finding divisors for curr. num.
            if(num%div==0){													// Divisor found.
                int digit=num/div;
                total+=div+digit;
                divs+=2;
                if(digit==div){												// If two divisors are the same.
                    divs--;													// Remove the dup. count.
                    total-=div;
                }
            }
			if(divs>4) return 0;											// If #divisors>4, return 0.
        }
        if(divs==4) return total;											// If #divisors=4, we return sum of divisors.
        return 0;															// If #divisors!=4, we return 0.
    }
    
    int sumFourDivisors(vector<int>& v) {
        int res=0;															// Stores sum of 4 divisors for nums.
        for(auto num:v){													// Iter. over all nums.
            res+=getDivisors(num);
        }
        return res;															// Return the total sum of 4 divisors.
    }
};