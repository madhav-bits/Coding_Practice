/*
*
//******************************************************964. Least Operators to Express Number.***********************************************

Given a single positive integer x, we will write an expression of the form x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. is 
either addition, subtraction, multiplication, or division (+, -, *, or /).  For example, with x = 3, we might write 3 * 3 / 3 + 3 - 3 which is 
a value of 3.

When writing such an expression, we adhere to the following conventions:

The division operator (/) returns rational numbers.
There are no parentheses placed anywhere.
We use the usual order of operations: multiplication and division happens before addition and subtraction.
It's not allowed to use the unary negation operator (-).  For example, "x - x" is a valid expression as it only uses subtraction, but "-x + x" 
is not because it uses negation.
We would like to write an expression with the least number of operators such that the expression equals the given target.  Return the least 
number of expressions used.

 

Example 1:

Input: x = 3, target = 19
Output: 5
Explanation: 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.
Example 2:

Input: x = 5, target = 501
Output: 8
Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 8 operations.
Example 3:

Input: x = 100, target = 100000000
Output: 3
Explanation: 100 * 100 * 100 * 100.  The expression contains 3 operations.
 

Note:

2 <= x <= 100
1 <= target <= 2 * 10^8




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.





3
19



99
100000000



// Time Complexity: O(logx).  												// As, we are specifically calc. #oper. for each power of x till target.
// Space Complexity: O(logx).												// As, space is allocated for each power value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logx).												
// Space Complexity: O(logx).	
// This algorithm is Backtracking based. Here, we need to write target in terms of x. So, we will be basically reaching close to target through
// multiplying num with num, once we are within reach of target pow(num, exp)<=target<=pow(num, exp+1). Then, we given recursive call to find
// num. of operations to get target-pow(num, exp) and pow(num, exp+1)-target respectively and add them to #operations for calc. powers and return
// the min. of two operations.

// One, tricky part is that don't take pow(2,exp+1) if it is >2*target, as we would be using lot of operatins to get pow(num,exp+1)-target>target
// which are >target-pow(num,exp).







class Solution {
public:
    unordered_map<int,int>m;												// Used to track states that are already calculated.
    
    int leastOpsExpressTarget(int x, int target) {
        // cout<<"x: "<<x<<" and target: "<<target<<endl;
        if(target==x) return 0;												// Base case.
        if(target<x) return min(2*target-1,(x-target)*2);					// If target<x, then that's achieved through +/- of (x/x)s.
        if(m.count(target)==1) return m[target];							// If this state already met, return value.
        double l=log(target)/log(x);
        if(abs(l-round(l))<0.00001){										// If target is power of x, then return #exp. value directly.
            m[target]=(int)round(l)-1;
        }else{
            int num=(int)floor(l);											// Lower bound of exp. value.
            int res=num+leastOpsExpressTarget(x,target-(int)pow(x,num));	// Giving recursive call to find #operations for rest of target value.
            if(pow(x,num+1)<(double)target*2){								// IF upper bound is too far, then don't consider it.
                res=min(res, num+1+leastOpsExpressTarget(x,(int)pow(x,num+1)-target));
            }
            m[target]=res;													// Assign the min. value to map.
        }
        // cout<<"target: "<<target<<" and count: "<<m[target]<<endl;
        return m[target];													// Return the min. of operations to get the target value.
    }
};