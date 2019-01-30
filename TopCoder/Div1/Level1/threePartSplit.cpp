

/*
//*********************************************************************Three Part Split.*************************************************************
https://community.topcoder.com/stat?c=problem_statement&pm=15235



Ternary search is one of many algorithms in which we need to split a range of integers into three equal (or almost equal) parts. That will be your task in this problem.

A half-open interval [x,y) is the set of integers that are greater than or equal to x and strictly less than y. Hence, [x,y) = { x, x+1, x+2, ..., y-2, y-1 }. For example, [3,7) = { 3, 4, 5, 6 }.

You are given two ints a and d. These define the half-open interval [a,d). This interval contains n = d-a numbers. Your task is to split this interval into three parts: [a,b), [b,c), and [c,d). Each of these intervals must contain at least (n div 3) elements.

Return {b, c}. That is, return a int[] with two elements, the first of which is b and the second is c. If there are multiple valid solutions, you may return any one of them.

 
Definition
    	
Class:	ThreePartSplit
Method:	split
Parameters:	int, int
Returns:	int[]
Method signature:	int[] split(int a, int d)
(be sure your method is public)
    
 
Notes
-	The formula "n div 3" means "n divided by 3, rounded down". For example, 14 div 3 = 4.
 
Constraints
-	a will be between 0 and 10^8, inclusive.
-	d will be between a+3 and 10^8, inclusive.
 
Examples
0)	
    	
0
6
Returns: {2, 4 }
We are given the range [0,6) = {0,1,2,3,4,5}. We need to split it into three parts, each containing at least (6 div 3) = 2 elements. Clearly, the only valid solution is to split it into {0,1}, {2,3}, and {4,5}, that is, intervals [0,2), [2,4), and [4,6). Thus, we must have b=2 and c=4, and we must return {2,4}.
1)	
    	
10
14
Returns: {11, 12 }
When splitting the interval [10,14) into three roughly equal parts, we have multiple valid options:
Split it into [10,11), [11,12), and [12,14).
Split it into [10,11), [11,13), and [13,14).
Split it into [10,12), [12,13), and [13,14).
Hence, there are three valid return values: {11, 12}, {11, 13}, and {12, 13}. Your solution may return any one of these three.
2)	
    	
127
345
Returns: {199, 271 }
3)	
    	
0
100000000
Returns: {33333333, 66666666 }
4)	
    	
100
105
Returns: {101, 104 }
As the original interval contains d-a = 5 elements, the requirement is that each of the three new intervals must contain at least one element. The return value of our solution corresponds to splitting the original interval into intervals of length 1, 3, and 1.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for: 
       TCO19 Single Round Match 744 Round 1 - Division II, Level One




// Time Complexity: O(1)
// Space Complexity: O(1)



*/


//*********************************************************************Solution-1.*****************************************************************
// Time Complexity: O(1)
// Space Complexity: O(1)


#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

class ThreePartSplit{
	
public:
	vector <int> split(int a, int d){
		vector<int>res;
		res.push_back(a+(d-a)/3);
		res.push_back(a+2*(d-a)/3);
		return res;
	}	
};