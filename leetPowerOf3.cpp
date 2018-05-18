/*
*
//**********************************************************326. Power of Three.***************************************************

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
1
2
3
4
243
244




// Time Complexity: O(logn/log3).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log3).
// Space Complexity: O(1).	
// This algorithm is iteration/loop based. We dec. the value until it is <=1. If it is =1, return true else return false. As, only in case of 
// powers of 3, we can get =1, after all those diivsions.



class Solution {
public:
    bool isPowerOfThree(int n) {
        double x=double(n);
        while(x>1){															// Converting into double for precision.
            x/=3;															// Dividing by 3, to reach 1.
            //cout<<"New val. is: "<<x<<endl;
        }
        if(x==1.0) return true;												// If 1 obtained, return true.
        return false;
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log3).
// Space Complexity: O(1).	
// This algorithm is iteration/loop based. We dec. the value iff the curr. value is div. by 3, else exit loop. The cdn outside loop expects 1
for powers of 3, if 1 not obtained, return false.







class Solution {
public:
    bool isPowerOfThree(int x) {
        if(x>1)															// Red. values until it is >=1.
            while(x%3==0) x/=3;											// Reduce val. iff div. by 3.
        if(x==1) return true;											// If val==1, return true.
        return false;													// Else return false.
    }
};