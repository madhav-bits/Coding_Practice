/*
*
//**********************************************************254. Factor Combinations.***************************************************

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
2
32
132
64
31
3



// Time Complexity: O(n*logn!).  											// Not sure about both complexities.
// Space Complexity: O(logn *logn!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*logn!).
// Space Complexity: O(logn*logn!).	
// This algorithm iterates the array, at each step we check if num divides target or not, if yes, we forward the updated target, min. value of 
// divisor can be used. We start from min. possible divisor to equal to target num. while checking out divisors. As, the target get reduced 
// to 1, we got all our divisors stored in temp. divisors vector, we push that into final result vector.








class Solution {
public:
    vector<vector<int>>fin;
    void findFact(int target,vector<int>&res, int start){
        if(target==1){														// If target is 1, then all divisors are obtained.
            if(res.size()>1) fin.push_back(res);							// Push divisors into final result vector.
            return ;
        }
        
        for(int i=start;i<=target;i++){
            if(target%i==0){												// If target divisible by curr. num.
                res.push_back(i);											// Push the divisor into temp. divisor vector.
                findFact(target/i,res,i);									// Update the target, min. possible divisor, divisor vector.
                res.pop_back();												// Remove the curr. divisor from the divisor vector.
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if(n==1) return fin;												// If num=1, return empty vector.
        vector<int>res;														// Stores divisors temporarily.
        findFact(n,res,2);													// Call. fn. to extract vectors.
        return fin;															// Return the final result vector.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn* logn!).											// Not sure about both complexties.
// Space Complexity: O(logn* logn!).							
// This algorithm iterates the array, at each step, we iterate through numbers and check whether it divides the num or not? If it divides, we dec.
// the target value and forward the curr.divisor, so that next divisors would be greater then curr. one. In case of last factor, as we won't be 
// dividing that with a num, we directly take it into result vector(Check if value is greater than curr. min. divisor && len of vector>0), as 
// shouldn't push the number itself into result vector.



class Solution {
public:
    vector<vector<int>>fin;
    void findFact(int target,vector<int>&res, int start){
        if(target==1){														// If target achieved, we stop recursion.
            // if(res.size()>1) fin.push_back(res);
            return ;
        }
        if(target>=start && res.size()>0){									// Check target>=min. divisor in loop, len>0(avoids given num).
            res.push_back(target);											// Push into final result vector.
            fin.push_back(res);
            res.pop_back();
        }
        
        for(int i=start;i*i<=target;i++){									// Iter. through values, use divisible nums to update target.
            if(target%i==0){		
                res.push_back(i);											// Pushing divisor into vector.
                findFact(target/i,res,i);									// Calling. fn. to extract further divisors.
                res.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if(n==1) return fin;												// Base cases.
        vector<int>res;														// Temp. vector to store divisors.
        findFact(n,res,2);													// Call fn. to get divisors.
        return fin;															// Return the final result vector.
    }
};