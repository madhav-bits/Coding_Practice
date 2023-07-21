/*
*
//******************************************************2119. A Number After a Double Reversal.******************************************************

https://leetcode.com/problems/a-number-after-a-double-reversal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


526
1800
0
20
21
525
546
1000000



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. We observe that when we reverse a number it looses trailing zeroes as they would become leading zeroes which don't 
// have any value. When we reverse it once again, the orig. number looses it trailing zeroes. We use this observation that nums divisible by zeroes(which have
// trailing zeroes) can't be the same after double reversal, one exception to this is number: '0', which is covered in base condition. Nums not divisible by
// 10 would retain their orig. form.








class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num<=9) return true;												// Base condition.
        return (num%10!=0);													// Nums not divisible by 10(no trailing zeroes) would retain orig. form, so we return true.
    }
};

