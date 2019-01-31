

/*
//*********************************************************************NumbersChallenge.*************************************************************
https://community.topcoder.com/stat?c=problem_statement&pm=13166



Your friend Lucas gave you a sequence S of positive integers.



For a while, you two played a simple game with S: Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas. For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.



Lucas now wants to trick you by choosing a number X such that there will be no valid answer. For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.



You are given the int[] S. Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.



 
Definition
    	
Class:	NumbersChallenge
Method:	MinNumber
Parameters:	int[]
Returns:	int
Method signature:	int MinNumber(int[] S)
(be sure your method is public)
    
 
Constraints
-	S will contain between 1 and 20 elements, inclusive.
-	Each element of S will be between 1 and 100,000, inclusive.
 
Examples
0)	
    	
{5, 1, 2}
Returns: 4
These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8. (We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.) The smallest positive integer not present in the above list is 4.
1)	
    	
{2, 1, 4}
Returns: 8
We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.
2)	
    	
{2, 1, 2, 7}
Returns: 6
The example given in the problem statement.
3)	
    	
{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}
Returns: 1092
4)	
    	
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}
Returns: 56523
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for: 
       Single Round Match 621 Round 1 - Division II, Level Two




// Time Complexity: O(n)													// n is sum of elements in the array.
// Space Complexity: O(1)



*/


//*********************************************************************Solution-1.*****************************************************************
// Time Complexity: O(n)													// n is sum of elements in the array.
// Space Complexity: O(1)
// Ths is similar to KnapSack Problem.

//   https://community.topcoder.com/stat?c=problem_statement&pm=14191

#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

class NumbersChallenge{
	
public:
	int MinNumber(vector<int> v){
		int sum=0;
		for(auto num: v) sum+=num;

		vector<bool>dp(sum+1, false);
		dp[0]=true;
		for(int i=0;i<v.size();i++){
			vector<bool>temp=dp;
			for(int j=0;j<=sum;j++){
				if(j-v[i]>=0 && dp[j-v[i]]==true) temp[j]=true;
			}
			dp=temp;
		}
		for(int i=0;i<dp.size();i++){
			if(dp[i]==false) return i;
		}
        return sum+1;
	}	
};