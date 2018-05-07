/*
*
//**********************************************************808. Soup Servings.***************************************************

There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B
Serve 75 ml of soup A and 25 ml of soup B
Serve 50 ml of soup A and 50 ml of soup B
Serve 25 ml of soup A and 75 ml of soup B
When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal 
probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once 
we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.  

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.

 

Example:
Input: N = 50
Output: 0.625
Explanation: 
If we choose the first two operations, A will become empty first. For the third operation, A and B will become empty at the same time. For 
the fourth operation, B will become empty first. So the total probability of A becoming empty first plus half the probability that A and B 
become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Notes:

0 <= N <= 10^9. 
Answers within 10^-6 of the true value will be accepted as correct.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


50
100
101
1
10000001



// Time Complexity: O(4^n).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(4^n).
// Space Complexity: O(n^2).	
// This algorithm is Pruning and observation based, If volumes >5000 the prob. are close to 1 else we will calculate the results, and we will
// employ memoization to reuse the calc./observ. made.


class Solution {
private:
    unordered_map<int, unordered_map<int, double>> store;
public:
    double soupServings(int N) {
        if (N >= 5000)													// This is the pruning part, as in the qsn it's mentioned that certain
            return 1.0;													// error is allowed, moreover upon observation, this is the result.
        else															// Else, calc. the prob. through recursion.
            return helper(N, N);
    }
    double helper(int A, int B) {
																		// Full probablity when A becomes empty first
        if (A == 0 && B != 0)
            return 1;
																		// Half probablity when A and B become empty at the same time
        else if (A == 0 && B == 0)
            return 0.5;
																		// Zero probablity when B becomes empty first
        else if (A != 0 && B == 0)
            return 0;
						
																		// If the code reaches here, it implies that neither A nor B is empty yet. 
																		// If there exist previous calculated result, return it.
        if (store[A][B] != 0)											// Using the memoization results.
            return store[A][B];
			
																		// Otherwise, recursive for 4 possible selections
        double prob = 0;
        prob += 0.25 * helper(A - min(A, 100), B);
        prob += 0.25 * helper(A - min(A, 75), B - min(B, 25));
        prob += 0.25 * helper(A - min(A, 50), B - min(B, 50));
        prob += 0.25 * helper(A - min(A, 25), B - min(B, 75));
				
																		// Store the calculated result
        store[A][B] = prob;
        return prob;
    }
};
