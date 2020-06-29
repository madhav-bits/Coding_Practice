/*
*
//*************************************1491. Average Salary Excluding the Minimum and Maximum Salary.*************************************

https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/


Given an array of unique integers salary where salary[i] is the salary of the employee i.

Return the average salary of employees excluding the minimum and maximum salary.

 

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500
Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000)/1= 2000
Example 3:

Input: salary = [6000,5000,4000,3000,2000,1000]
Output: 3500.00000
Example 4:

Input: salary = [8000,9000,2000,3000,6000,1000]
Output: 4750.00000
 

Constraints:

3 <= salary.length <= 100
10^3 <= salary[i] <= 10^6
salary[i] is unique.
Answers within 10^-5 of the actual value will be accepted as correct.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

[8000,9000,2000,3000,6000,1000,2599,4949]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we collect the total of all salaries and find maxm, minm salaries in the first iter. of the array.
// We remove these two nums from the total and calc. avg for the total.






class Solution {
public:
    double average(vector<int>& salary) {
        int total=0, minm=INT_MAX, maxm=INT_MIN;
        for(auto num:salary){
            total+=num;
            minm=min(minm, num);
            maxm=max(maxm, num);
        }
        double div=(int)salary.size()-2;
        total=total-maxm-minm;
        return total/div;
    }
};
