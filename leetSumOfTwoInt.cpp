/*
*
//**********************************************************371. Sum of Two Integers.***************************************************

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
0

0
1


12
11

10
12

3
5


3
4

// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is iteration based algo. We first calc. the sum(not including carry ons) of two ints using XOR, we calculate the carry using 
// AND oper. b/w two ints. Do it a bit shift to right and make it the second int for next iteration, we do this until all carry is died down.



class Solution {
public:
    int getSum(int a, int b) {
        
        int carry=0;
        while(b!=0){
            //cout<<"Inside while with a: "<<a<<" and b: "<<b<<endl;
            carry=a&b;																			// Calc. the carry b/w two ints.
            a=a^b;																				// Calc. the sum(excl. carry) b/w two ints.
            //cout<<"New a: "<<a<<" new carry is: "<<carry<<endl;	
            b=carry<<1;																			// Do a right shift and make it the second int.
            //cout<<"New b is: "<<b<<endl;
            
        }
        
        return a;																				// Return the answer.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Recursion based algo. We first calc. the sum(not including carry ons) of two ints using XOR, we calculate the carry using 
// AND oper. b/w two ints. Do it a bit shift to right and make it the second int for next call, we do this until all carry is died down.






class Solution {
public:
    
    int getSum(int a, int b) {
        if(b==0) return a;
        int carry;
        carry=a&b;														/						// Calc. the carry of the sum.
        a=a^b;																					// Calc. the sum excl. the carry ons.
        b=carry<<1;																				// Updating the second int value.
        return getSum(a,b);																		// Returning the result(sum).
    }
};